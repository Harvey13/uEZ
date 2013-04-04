/*-------------------------------------------------------------------------*
 * File:  LPC1756_SSP.c
 *-------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------
 * uEZ(R) - Copyright (C) 2007-2010 Future Designs, Inc.
 *--------------------------------------------------------------------------
 * This file is part of the uEZ(R) distribution.  See the included
 * uEZLicense.txt or visit http://www.teamfdi.com/uez for details.
 *
 *    *===============================================================*
 *    |  Future Designs, Inc. can port uEZ(tm) to your own hardware!  |
 *    |             We can get you up and running fast!               |
 *    |      See http://www.teamfdi.com/uez for more details.         |
 *    *===============================================================*
 *
 *-------------------------------------------------------------------------*/
/**
 *    @addtogroup LPC1756_SSP
 *  @{
 *  @brief     uEZ LPC1756 SSP Interface
 *  @see http://www.teamfdi.com/uez/
 *  @see http://www.teamfdi.com/uez/files/uEZLicense.txt
 *
 *    HAL implementation of the LPC1756 SSP Bus Interface.                                                                  
 * Implementation:
 *      Two SSPs are created, SSP0 and SSP1.
 *
 * @par Example code:
 * Example task to 
 * @par
 * @code
 * #include <uEZ.h>
 * TODO
 * @endcode
 */
#include <uEZ.h>
#include <uEZTypes.h>
#include <uEZProcessor.h>
#include <uEZPlatform.h>
#include <HAL/GPIO.h>
#include <HAL/Interrupt.h>
#include <Source/Processor/NXP/LPC1756/LPC1756_SSP.h>

/*---------------------------------------------------------------------------*
 * Types:
 *---------------------------------------------------------------------------*/
typedef struct {
    TVUInt32 iICR0;  /** 0x00 */
        #define SSP_FRF_SPI (0<<4)      /** Frame format: SPI */
        #define SSP_FRF_TI  (1<<4)      /** Frame format: TI */
        #define SSP_FRF_MW  (2<<4)      /** Frame format: Microwire */
        #define SSP_CPOL    (1<<6)      /** Clock Polarity */
        #define SSP_CPHA    (1<<7)      /** Clock Phase */
    TVUInt32 iICR1;  /** 0x04 */
        #define SSP_LBM     (1<<0)      /** Loop back mode */
        #define SSP_SSE     (1<<1)      /** SSP Enable */
        #define SSP_MS      (1<<2)      /** Master/Slave Mode (master=0) */
        #define SSP_SOD     (1<<3)      /** Slave Output Disable */
    TVUInt32 iDR;   /** 0x08 */
    TVUInt32 iSR;   /** 0x0C -- read only */
        #define SSP_TFE     (1<<0)      /** Transmit FIFO Empty */
        #define SSP_TNF     (1<<1)      /** Transmit FIFO Not Full */
        #define SSP_RNE     (1<<2)      /** Receive FIFO Not Empty */
        #define SSP_RFF     (1<<3)      /** Receive FIFO Full */
        #define SSP_BSY     (1<<4)      /** Busy */
    TVUInt32 iCPSR; /** 0x10 */
    TVUInt32 iIMSC; /** 0x14 */
        #define SSP_RORIM   (1<<0)      /** Receive overrun interrupt */
        #define SSP_RTIM    (1<<1)      /** Receive timeout */
        #define SSP_RXIM    (1<<2)      /** Rx FIFO is at least half full */
        #define SSP_TXIM    (1<<3)      /** Tx FIFO is at least half empty */
    TVUInt32 iRIS;  /** 0x18 */
        #define SSP_RORRIS  (1<<0)      /** Raw Receive overrun interrupt */
        #define SSP_RTRIS   (1<<1)      /** Raw Receive timeout */
        #define SSP_RXRIS   (1<<2)      /** Raw Rx FIFO is at least half full */
        #define SSP_TXRIS   (1<<3)      /** Raw Tx FIFO is at least half empty */
    TVUInt32 iMIS;  /** 0x1C */
        #define SSP_RORMIS  (1<<0)      /** Mask (1=on) Receive overrun interrupt */
        #define SSP_RTMIS   (1<<1)      /** Mask (1=on) Receive timeout */
        #define SSP_RXMIS   (1<<2)      /** Mask (1=on) Rx FIFO is at least half full */
        #define SSP_TXMIS   (1<<3)      /** Mask (1=on) Tx FIFO is at least half empty */
    TVUInt32 iICR;   /** 0x20 */
        #define SSP_RORIC   (1<<0)      /** Clears SSP_RORIM interrupt */
        #define SSP_RTIC    (1<<1)      /** Clears SSP_RTRIS interrupt */
    TVUInt32 iDMACR;/** 0x24 */
        #define SSP_RXDMAE  (1<<0)      /** When 1, DMA enabled for Rx FIFO */
        #define SSP_TXDMAE  (1<<1)      /** When 1, DMA enabled for Tx FIFO */
} T_LPC1756_SSP_Registers;

typedef struct {
    const HAL_SPI *iHAL;
    T_LPC1756_SSP_Registers *iReg;
    T_spiCompleteCallback iCompleteCallback;
    void *iCompleteCallbackWorkspace;
    SPI_Request *iRequest;
    T_irqChannel iIRQChannel;
    TBool iIsBusy;
} T_LPC1756_SSP_Workspace;

/*---------------------------------------------------------------------------*
 * Function Prototypes:
 *---------------------------------------------------------------------------*/
IRQ_ROUTINE( ISSP0IRQ );
IRQ_ROUTINE( ISSP1IRQ );
static void ISSPEnd(SPI_Request *aRequest);
static void ISSPProcessInterrupt(T_LPC1756_SSP_Workspace *aW);
static void ISSPOutput(T_LPC1756_SSP_Workspace *aW);

/*---------------------------------------------------------------------------*
 * Globals:
 *---------------------------------------------------------------------------*/
static T_LPC1756_SSP_Workspace *G_SSP0Workspace;
static T_LPC1756_SSP_Workspace *G_SSP1Workspace;

/*---------------------------------------------------------------------------*
 * Routine:  ISSPStart
 *---------------------------------------------------------------------------*/
/**
 *  SSP is going to start -- chip select enabled for device
 *
 *  @param [in]    *aRequest   	Configuration of SSP device
 *
 *  @par Example Code:
 *  @code
 *  #include <uEZ.h>
 *  
 *  TODO
 *  @endcode
 */
/*---------------------------------------------------------------------------*/
static void ISSPStart(SPI_Request *aRequest)
{
    if (aRequest->iCSPolarity)  {
        (*aRequest->iCSGPIOPort)->Set(
                aRequest->iCSGPIOPort,
                aRequest->iCSGPIOBit);
    } else {
        (*aRequest->iCSGPIOPort)->Clear(
                aRequest->iCSGPIOPort,
                aRequest->iCSGPIOBit);
    }
}

/*---------------------------------------------------------------------------*
 * Routine:  ISSPEnd
 *---------------------------------------------------------------------------*/
/**
 *  SSP is going to end -- chip select disabled for device
 *
 *  @param [in]    *aRequest  	Configuration of SSP device
 *
 *  @par Example Code:
 *  @code
 *  #include <uEZ.h>
 *  
 *  TODO
 *  @endcode
 */
/*---------------------------------------------------------------------------*/
static void ISSPEnd(SPI_Request *aRequest)
{
    if (aRequest->iCSPolarity)  {
        (*(aRequest->iCSGPIOPort))->Clear(
                aRequest->iCSGPIOPort,
                aRequest->iCSGPIOBit);
    } else {
        (*(aRequest->iCSGPIOPort))->Set(
                aRequest->iCSGPIOPort,
                aRequest->iCSGPIOBit);
    }
}

/*---------------------------------------------------------------------------*
 * Routine:  ISSPConfig
 *---------------------------------------------------------------------------*/
/**
 *  Configure the SSP for the particular SSP request.
 *
 *  @param [in]    *aW 			Particular SSP workspace
 *
 *  @param [in]    *aRequest	Configuration of SSP device
 *
 *  @par Example Code:
 *  @code
 *  #include <uEZ.h>
 *  
 *  TODO
 *  @endcode
 */
/*---------------------------------------------------------------------------*/
static void ISSPConfig(T_LPC1756_SSP_Workspace *aW, SPI_Request *aRequest)
{
    T_LPC1756_SSP_Registers *p = aW->iReg;
    TUInt32 scr;

    // Disable for the moment
    p->iICR = 0;

    // Set pins for use with SSP
    //    (*(aRequest->iCSGPIOPort))->Activate(
    //            aRequest->iCSGPIOPort,
    //            aRequest->iCSGPIOBit);

    // Set the CS as an output io pin
    (*(aRequest->iCSGPIOPort))->SetOutputMode(
            aRequest->iCSGPIOPort,
            aRequest->iCSGPIOBit);

    // Calculate the scr divider (rounding up to the next even number)
//    scr = (((((Fpclk/1000)+(aRequest->iRate-1))/(aRequest->iRate)))+1)&0xFFFE;
    scr = (((Fpclk/1000)+(aRequest->iRate-1))/(aRequest->iRate))-1;
    // Minimum of 2 divide factor
    if (scr < 2)
        scr = 2;

    // Make sure the SSP clock is PCLK/2
    p->iCPSR = 2;

    p->iICR0 =
        // Number of bits per transaction
        (aRequest->iBitsPerTransfer-1) |
        // SPI interface only
        SSP_FRF_SPI |
        // Clock out polarity
        (aRequest->iClockOutPolarity?SSP_CPOL:0) |
        (aRequest->iClockOutPhase?SSP_CPHA:0) |
        (scr << 8);

    // Enable the SSP
    p->iICR1 = SSP_SSE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LPC1756_SSP_TransferPolled
 *---------------------------------------------------------------------------*/
/**
 *  Do a SSP transfer (both read and write) out the SSP port using
 *      the given request.
 *
 *  @param [in]    *aWorkspace      	Particular SSP workspace
 *
 *  @param [in]    *aRequest   			Request to perform
 *
 *  @return        T_uezError       	Error code
 *  @par Example Code:
 *  @code
 *  #include <uEZ.h>
 *  
 *  TODO
 *  @endcode
 */
/*---------------------------------------------------------------------------*/
T_uezError LPC1756_SSP_TransferPolled(void *aWorkspace, SPI_Request *aRequest)
{
    TUInt32 i;
    T_LPC1756_SSP_Workspace *aW = (T_LPC1756_SSP_Workspace *)aWorkspace;
    T_LPC1756_SSP_Registers *p = aW->iReg;
    TUInt8 *p_dataMISO8;
    TUInt8 *p_dataMOSI8;
    TUInt16 *p_dataMISO16;
    TUInt16 *p_dataMOSI16;

    // Setup SSP for this configuration
    ISSPConfig(aW, aRequest);

    // Start SSP
    ISSPStart(aRequest);

    // Are we transferring byte sized or word sized?
    if (aRequest->iBitsPerTransfer <= 8)  {
        // Doing bytes
        p_dataMISO8 = (TUInt8 *)(aRequest->iDataMISO);
        p_dataMOSI8 = (TUInt8 *)(aRequest->iDataMOSI);

        for (i=0; i<aRequest->iNumTransfers; i++)  {
            // Wait for SSP to be no longer busy and transmit to be empty
            while ((p->iSR & SSP_BSY) || (!(p->iSR & SSP_TFE)))  {
                // TBD: Polling here instead of interrupt
            }

            // Send the SSP data (this also triggers a read in)
            if ((i+4)<=aRequest->iNumTransfers) {
                // Do 4 at one time
                p->iDR = (TUInt32) *(p_dataMOSI8++);
                p->iDR = (TUInt32) *(p_dataMOSI8++);
                p->iDR = (TUInt32) *(p_dataMOSI8++);
                p->iDR = (TUInt32) *(p_dataMOSI8++);
            } else {
                p->iDR = (TUInt32) *(p_dataMOSI8++);
            }

            // Wait until SSP done  (transmit empty)
            while ((p->iSR & SSP_BSY) || ((p->iSR & SSP_TFE)==0))  {
                // TBD: For polling this is fine, but we may need to yield at some point?
            }

            // Store the SSP received over the data sent
            if ((i+4)<=aRequest->iNumTransfers) {
                // Do 4 at one time
                *(p_dataMISO8++) = p->iDR;
                *(p_dataMISO8++) = p->iDR;
                *(p_dataMISO8++) = p->iDR;
                *(p_dataMISO8++) = p->iDR;
                i+=3;
            } else {
                *(p_dataMISO8++) = p->iDR;
            }
        }
    } else {
        // Doing words
        p_dataMISO16 = (TUInt16 *)(aRequest->iDataMISO);
        p_dataMOSI16 = (TUInt16 *)(aRequest->iDataMOSI);

        for (i=0; i<aRequest->iNumTransfers; i++)  {
            // Wait for SSP to be no longer busy and transmit to be empty
            while ((p->iSR & SSP_BSY) || (!(p->iSR & SSP_TFE)))  {
                // TBD: Polling here instead of interrupt
            }

            // Send the SSP data (this also triggers a read in)
            p->iDR = (TUInt32) *(p_dataMOSI16++);

            // Wait until SSP done
            while ((p->iSR & SSP_BSY) || ((p->iSR & SSP_TFE)==0))  {
                // TBD: For polling this is fine, but we may need to yield at some point?
            }

            // Store the SSP received over the data sent
            *(p_dataMISO16++) = p->iDR;
        }
    }
    // End SSP
    ISSPEnd(aRequest);

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LPC1756_SSP_SSP0_InitializeWorkspace
 *---------------------------------------------------------------------------*/
/**
 *  Setup the LPC1756 SSP0 workspace.
 *
 *  @param [in]    *aWorkspace  	Particular SSP workspace
 *
 *  @return        T_uezError     	Error code
 *  @par Example Code:
 *  @code
 *  #include <uEZ.h>
 *  
 *  TODO
 *  @endcode
 */
/*---------------------------------------------------------------------------*/
T_uezError LPC1756_SSP_SSP0_InitializeWorkspace(void *aWorkspace)
{
    T_LPC1756_SSP_Workspace *p = (T_LPC1756_SSP_Workspace *)aWorkspace;
    p->iReg = (T_LPC1756_SSP_Registers *)SSP0_BASE;

    G_SSP0Workspace = p;
    p->iIsBusy = EFalse;
    p->iIRQChannel = SSP0_IRQn;

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LPC1756_SSP_SSP1_InitializeWorkspace
 *---------------------------------------------------------------------------*/
/**
 *  Setup the LPC1756 SSP1 workspace.
 *
 *  @param [in]    *aWorkspace       	Particular SSP workspace
 *
 *  @return        T_uezError          	Error code
 *  @par Example Code:
 *  @code
 *  #include <uEZ.h>
 *  
 *  TODO
 *  @endcode
 */
/*---------------------------------------------------------------------------*/
T_uezError LPC1756_SSP_SSP1_InitializeWorkspace(void *aWorkspace)
{
    T_LPC1756_SSP_Workspace *p = (T_LPC1756_SSP_Workspace *)aWorkspace;
    p->iReg = (T_LPC1756_SSP_Registers *)SSP1_BASE;

    G_SSP1Workspace = p;
    p->iIsBusy = EFalse;
    p->iIRQChannel = SSP1_IRQn;

    return UEZ_ERROR_NONE;
}








/*---------------------------------------------------------------------------*
 * Routine: ISSPxIRQ
 *---------------------------------------------------------------------------*
 * Description:
 *      Capture the SSPx interrupts and forward to ISSPProcessInterrupt.
 *---------------------------------------------------------------------------*/
IRQ_ROUTINE( ISSP0IRQ )
{
    IRQ_START();
    ISSPProcessInterrupt(G_SSP0Workspace);
    IRQ_END();
}

IRQ_ROUTINE( ISSP1IRQ )
{
    IRQ_START();
    ISSPProcessInterrupt(G_SSP1Workspace);
    IRQ_END();
}

/*---------------------------------------------------------------------------*
 * Routine: ISSPProcessInterrupt
 *---------------------------------------------------------------------------*
 * Description:
 *      Generic routine for handling any of the SSP interrupts.
 *      NOTE: This routine is ALWAYS processed inside of a interrupt
 *              service routine.
 * Inputs:
 *      T_SerialPortEntry *p      -- Port's definition to process interrupt
 *---------------------------------------------------------------------------*/
static void ISSPProcessInterrupt(T_LPC1756_SSP_Workspace *aW)
{
    T_LPC1756_SSP_Registers *p = aW->iReg;
    SPI_Request *r = aW->iRequest;
    TUInt8 ris;
    TUInt32 data;

    while (1) {
        // Do we have any interrupts to process now?
        ris = p->iMIS;
        if (!ris)
            break;

        // Is data waiting to be received?
        if (ris & (SSP_RTMIS | SSP_RXMIS)) {
            // Pull the data out of the SSP peripheral
            if (r->iNumTransferredIn < r->iNumTransfers) {
                data = p->iDR;
                if (r->iDataMISO)
                    ((TUInt8 *)r->iDataMISO)[r->iNumTransferredIn++] = data;
            }

            // If we have reached the end, we are done
            if (r->iNumTransferredIn >= r->iNumTransfers) {
                // No more processing.  Stop here.
                InterruptDisable(aW->iIRQChannel);

                // Clear any remaining interrupts
                p->iICR = SSP_RORIC|SSP_RTIC;

                // Mask out all interrupts
                p->iIMSC &= 0;

                // End the chip select
                ISSPEnd(aW->iRequest);

                // Note we are done
                aW->iIsBusy = EFalse;

                // Call the completion callback (if any)
                if (aW->iCompleteCallback) {
                    aW->iCompleteCallback(aW->iCompleteCallbackWorkspace,
                        aW->iRequest);
                }

                break;
            } else {
                // Not done yet.
                // Ensure if we had an interrupt on a stalled receive, clear it
                p->iICR = SSP_RORIC;
            }
        } else if (ris & (SSP_TXRIS)) {
            ISSPOutput(aW);
        } else {
            // Some other interrupt.  Just clear it.  Possibly an error.
            p->iICR = ris;
        }
    }

}

/*---------------------------------------------------------------------------*
 * Routine:  LPC1756_SSP_Start
 *---------------------------------------------------------------------------*
 * Description:
 *      Start a SSP transfer by putting the chip select in the active state
 *      after configuring the SSP speed and other settings.
 * Inputs:
 *      void *aW                    -- Particular SSP workspace
 *      SPI_Request *aRequest       -- SSP request being processed
 *---------------------------------------------------------------------------*/
void LPC1756_SSP_Start(void *aWorkspace, SPI_Request *aRequest)
{
    // Setup SSP for this configuration
    ISSPConfig(aWorkspace, aRequest);
    ISSPStart(aRequest);
}

/*---------------------------------------------------------------------------*
 * Routine:  LPC1756_SSP_TransferInOut
 *---------------------------------------------------------------------------*
 * Description:
 *      Do a single SSP transfer to the SSP device.
 * Inputs:
 *      void *aW                    -- Particular SSP workspace
 *      SPI_Request *aRequest       -- SSP request being processed
 *      TUInt32 aSend               -- Item to transfer
 * Outputs:
 *      T_uezError                   -- Error code
 *---------------------------------------------------------------------------*/
static TUInt32 LPC1756_SSP_TransferInOut(
        void *aWorkspace,
        SPI_Request *aRequest,
        TUInt32 aSend)
{
    TUInt32 recv;
    T_LPC1756_SSP_Workspace *aW = (T_LPC1756_SSP_Workspace *)aWorkspace;
    T_LPC1756_SSP_Registers *p = aW->iReg;

    // Are we transferring byte sized or word sized?
    if (aRequest->iBitsPerTransfer <= 8) {
        // Send the SSP data (this also triggers a read in)
        p->iDR = aSend;

        // Wait until SSP done
        while (((p->iSR & SSP_TFE) == 0) || (p->iSR & SSP_BSY)) {
            // TBD: For polling this is fine, but we may need to yield at some point?
        }

        // Store the SSP received over the data sent
        recv = p->iDR;
    } else {
        // Send the SSP data (this also triggers a read in)
        p->iDR = (TUInt32)*((TUInt16 *)aSend);

        // Wait until SSP done
        while ((p->iSR & SSP_RNE) == 0) {
            // TBD: For polling this is fine, but we may need to yield at some point?
        }

        // Store the SSP received over the data sent
        recv = p->iDR;
    }

    return recv;
}

/*---------------------------------------------------------------------------*
 * Routine:  LPC1756_SSP_Stop
 *---------------------------------------------------------------------------*
 * Description:
 *      End a SSP transfer by putting the chip select in the done state.
 * Inputs:
 *      void *aW                    -- Particular SSP workspace
 *      SPI_Request *aRequest       -- SSP request being processed
 *---------------------------------------------------------------------------*/
static void LPC1756_SSP_Stop(void *aWorkspace, SPI_Request *aRequest)
{
    ISSPEnd(aRequest);
}

/*---------------------------------------------------------------------------*
 * Routine:  LPC1756_SSP_SSP1_InitializeWorkspace
 *---------------------------------------------------------------------------*
 * Description:
 *      Transfer a set of SSP bytes (in the request) to the given
 *      target.  Works similarly to TransferPolled except this routine
 *      does not affect the chip select state.
 * Inputs:
 *      void *aW                    -- Particular SSP workspace
 *      SPI_Request *aRequest       -- SSP request being processed
 * Outputs:
 *      T_uezError                   -- Error code
 *---------------------------------------------------------------------------*/
static T_uezError LPC1756_SSP_TransferInOutBytes(
        void *aWorkspace,
        SPI_Request *aRequest)
{
    T_LPC1756_SSP_Workspace *aW = (T_LPC1756_SSP_Workspace *)aWorkspace;
    T_LPC1756_SSP_Registers *p = aW->iReg;
    TUInt32 sent;
    TUInt32 count;
    TUInt8 *p_dataMOSI = (TUInt8 *)aRequest->iDataMOSI;
    TUInt8 *p_dataMISO = (TUInt8 *)aRequest->iDataMISO;
    TUInt8 dummy[8];

    // This routine only works with transfer of 8 bits or lower
    if (aRequest->iBitsPerTransfer > 8)
        return UEZ_ERROR_INVALID_PARAMETER;

    sent = 0;
    count = aRequest->iNumTransfers;

    // Send data while there is data to send
    while (sent < count) {
        if (!aRequest->iDataMISO)
            p_dataMISO = dummy;

        // Always send in groups of 8 bytes if there are 8 bytes to send
        if ((sent + 8) <= count) {
            // Send 8
            if (!aRequest->iDataMOSI) {
                p->iDR = 0xFF;
                p->iDR = 0xFF;
                p->iDR = 0xFF;
                p->iDR = 0xFF;
                p->iDR = 0xFF;
                p->iDR = 0xFF;
                p->iDR = 0xFF;
                p->iDR = 0xFF;
            } else {
                p->iDR = *(p_dataMOSI++);
                p->iDR = *(p_dataMOSI++);
                p->iDR = *(p_dataMOSI++);
                p->iDR = *(p_dataMOSI++);
                p->iDR = *(p_dataMOSI++);
                p->iDR = *(p_dataMOSI++);
                p->iDR = *(p_dataMOSI++);
                p->iDR = *(p_dataMOSI++);
            }

            // Wait until SSP done
            while (((p->iSR & SSP_TFE) == 0) || (p->iSR & SSP_BSY)) {
                // TBD: For polling this is fine, but we may need to yield at some point?
            }

            // Receive 8
            *(p_dataMISO++) = p->iDR;
            *(p_dataMISO++) = p->iDR;
            *(p_dataMISO++) = p->iDR;
            *(p_dataMISO++) = p->iDR;
            *(p_dataMISO++) = p->iDR;
            *(p_dataMISO++) = p->iDR;
            *(p_dataMISO++) = p->iDR;
            *(p_dataMISO++) = p->iDR;

            sent += 8;
        } else {
            // There are now less than 8 bytes to send, send
            // one at a time.

            // Send 1
            if (!aRequest->iDataMOSI) {
                p->iDR = 0xFF;
            } else {
                p->iDR = *(p_dataMOSI++);
            }
            // Wait until SSP done
            while (((p->iSR & SSP_TFE) == 0) || (p->iSR & SSP_BSY)) {
                // TBD: For polling this is fine, but we may need to yield at some point?
            }

            // Receive 1
            *(p_dataMISO++) = p->iDR;

            sent++;
        }
    }

    return UEZ_ERROR_NONE;
}

static void ISSPOutput(T_LPC1756_SSP_Workspace *aW)
{
    T_LPC1756_SSP_Registers *p = aW->iReg;
    SPI_Request *r = aW->iRequest;
    TUInt32 num;
    TUInt8 *p_dataMOSI8;

    // Is there any room to send data?
    num = r->iNumTransfers - r->iNumTransferredOut;
    if (r->iDataMOSI) {
        // Output bytes from the array
        if (num >= 4) {
            p_dataMOSI8 = ((TUInt8 *)r->iDataMOSI) + r->iNumTransferredOut;
            p->iDR = p_dataMOSI8[0];
            p->iDR = p_dataMOSI8[1];
            p->iDR = p_dataMOSI8[2];
            p->iDR = p_dataMOSI8[3];
            r->iNumTransferredOut+=4;
        } else if (num) {
            // Output all we got left
            p_dataMOSI8 = ((TUInt8 *)r->iDataMOSI) + r->iNumTransferredOut;
            while (num--) {
                p->iDR = *(p_dataMOSI8++);
                r->iNumTransferredOut++;
            }
        } else {
            // No longer report interrupts for room to transfer,
            // we are out of bytes to transfer.
            p->iIMSC &= ~(SSP_TXIM);
        }
    } else {
        // Output 0xFF's
        if (num >= 4) {
            // Output 4 in a bunch
            p->iDR = 0xFF;
            p->iDR = 0xFF;
            p->iDR = 0xFF;
            p->iDR = 0xFF;
            r->iNumTransferredOut += 4;
        } else if (num) {
            // Output the remaining
            while (num--) {
                p->iDR = 0xFF;
                r->iNumTransferredOut++;
            }
        } else {
            // There is no more to output, stop doing interrupts
            // from the TXIM
            p->iIMSC &= ~(SSP_TXIM);
        }
    }
}

static T_uezError LPC1756_SSP_TransferNoBlock(
        void *aWorkspace,
        SPI_Request *aRequest,
        T_spiCompleteCallback aCallback,
        void *aCallbackWorkspace)
{
    T_LPC1756_SSP_Workspace *aW = (T_LPC1756_SSP_Workspace *)aWorkspace;
    T_LPC1756_SSP_Registers *p = aW->iReg;

    // This routine only works with transfer of 8 bits or lower
    if (aRequest->iBitsPerTransfer > 8)
        return UEZ_ERROR_INVALID_PARAMETER;

    aRequest->iNumTransferredOut = 0;
    aRequest->iNumTransferredIn = 0;

    // Setup the callback and the parameters
    aW->iCompleteCallback = aCallback;
    aW->iCompleteCallbackWorkspace = aCallbackWorkspace;
    aW->iRequest = aRequest;

    // Setup SSP for this configuration
    ISSPConfig(aW, aRequest);

    // Start SSP
    ISSPStart(aRequest);

    // Note we are in the middle of a transaction
    aW->iIsBusy = ETrue;

    // Allow receive half full, receive idle, and transmit half empty interrupts
    p->iIMSC = SSP_RTIM|SSP_RXIM|SSP_TXIM;

    // Prime the pump and output in an amount of data
    // On interrupting, we'll feed in the data
    ISSPOutput(aW);

    // Now allow processing of the interrupts (which probably just occurred)
    InterruptEnable(aW->iIRQChannel);

    return UEZ_ERROR_NONE;
}

static TBool LPC1756_SSP_IsBusy(void *aWorkspace)
{
    T_LPC1756_SSP_Workspace *aW = (T_LPC1756_SSP_Workspace *)aWorkspace;

    return aW->iIsBusy;
}




/*---------------------------------------------------------------------------*
 * HAL Interface table:
 *---------------------------------------------------------------------------*/
const HAL_SPI SSP_LPC1756_Port0_Interface = {
    {
    "NXP:LPC1756:SSP0",
    0x0100,
    LPC1756_SSP_SSP0_InitializeWorkspace,
    sizeof(T_LPC1756_SSP_Workspace),
    },

    LPC1756_SSP_TransferPolled,

    LPC1756_SSP_Start,
        LPC1756_SSP_TransferInOut,
        LPC1756_SSP_Stop,
        LPC1756_SSP_TransferInOutBytes,

        // uEZ v2.02
        LPC1756_SSP_TransferNoBlock,
        LPC1756_SSP_IsBusy,
};

const HAL_SPI SSP_LPC1756_Port1_Interface = {
    {
    "NXP:LPC1756:SSP1",
    0x0100,
    LPC1756_SSP_SSP1_InitializeWorkspace,
    sizeof(T_LPC1756_SSP_Workspace),
    },

    LPC1756_SSP_TransferPolled,


        LPC1756_SSP_Start,
        LPC1756_SSP_TransferInOut,
        LPC1756_SSP_Stop,
        LPC1756_SSP_TransferInOutBytes,

        // uEZ v2.02
        LPC1756_SSP_TransferNoBlock,
        LPC1756_SSP_IsBusy,
};

/*---------------------------------------------------------------------------*
 * Requirement routines:
 *---------------------------------------------------------------------------*/
void LPC1756_SSP0_Require(
        T_uezGPIOPortPin aPinSCK0,
        T_uezGPIOPortPin aPinMISO0,
        T_uezGPIOPortPin aPinMOSI0,
        T_uezGPIOPortPin aPinSSEL0)
{
    static const T_LPC1756_IOCON_ConfigList sck0[] = {
            {GPIO_P0_15, IOCON_D_DEFAULT(2)},
            {GPIO_P1_20, IOCON_D_DEFAULT(3)},
    };
    static const T_LPC1756_IOCON_ConfigList ssel0[] = {
            {GPIO_P0_16, IOCON_D_DEFAULT(2)},
            {GPIO_P1_21, IOCON_D_DEFAULT(3)},
    };
    static const T_LPC1756_IOCON_ConfigList miso0[] = {
            {GPIO_P0_17, IOCON_D_DEFAULT(2)},
            {GPIO_P1_23, IOCON_D_DEFAULT(3)},
    };
    static const T_LPC1756_IOCON_ConfigList mosi0[] = {
            {GPIO_P0_18, IOCON_D_DEFAULT(2)},
            {GPIO_P1_24, IOCON_D_DEFAULT(3)},
    };

    HAL_DEVICE_REQUIRE_ONCE();
    // Register SSP0
    HALInterfaceRegister("SSP0",
            (T_halInterface *)&SSP_LPC1756_Port0_Interface, 0, 0);
    LPC1756_IOCON_ConfigPinOrNone(aPinSCK0, sck0, ARRAY_COUNT(sck0));
    LPC1756_IOCON_ConfigPinOrNone(aPinSSEL0, ssel0, ARRAY_COUNT(ssel0));
    LPC1756_IOCON_ConfigPinOrNone(aPinMISO0, miso0, ARRAY_COUNT(miso0));
    LPC1756_IOCON_ConfigPinOrNone(aPinMOSI0, mosi0, ARRAY_COUNT(mosi0));
    LPC1756PowerOn(1<<21);

    // Setup interrupt, but do not enable
    InterruptRegister(SSP0_IRQn, ISSP0IRQ, INTERRUPT_PRIORITY_HIGH, "SSP0");
    InterruptDisable(SSP0_IRQn);
}

void LPC1756_SSP1_Require(
        T_uezGPIOPortPin aPinSCK1,
        T_uezGPIOPortPin aPinMISO1,
        T_uezGPIOPortPin aPinMOSI1,
        T_uezGPIOPortPin aPinSSEL1)
{
    static const T_LPC1756_IOCON_ConfigList sck1[] = {
            {GPIO_P0_7,  IOCON_D_DEFAULT(2)},
            {GPIO_P1_31, IOCON_D_DEFAULT(2)},
    };
    static const T_LPC1756_IOCON_ConfigList ssel1[] = {
            {GPIO_P0_6,  IOCON_D_DEFAULT(2)},
    };
    static const T_LPC1756_IOCON_ConfigList miso1[] = {
            {GPIO_P0_8,  IOCON_D_DEFAULT(2)},
    };
    static const T_LPC1756_IOCON_ConfigList mosi1[] = {
            {GPIO_P0_9,  IOCON_D_DEFAULT(2)},
    };

    HAL_DEVICE_REQUIRE_ONCE();
    // Register SSP1
    HALInterfaceRegister("SSP1",
            (T_halInterface *)&SSP_LPC1756_Port1_Interface, 0, 0);
    LPC1756_IOCON_ConfigPinOrNone(aPinSCK1, sck1, ARRAY_COUNT(sck1));
    LPC1756_IOCON_ConfigPinOrNone(aPinSSEL1, ssel1, ARRAY_COUNT(ssel1));
    LPC1756_IOCON_ConfigPinOrNone(aPinMISO1, miso1, ARRAY_COUNT(miso1));
    LPC1756_IOCON_ConfigPinOrNone(aPinMOSI1, mosi1, ARRAY_COUNT(mosi1));
    LPC1756PowerOn(1<<10);

    // Setup interrupt, but do not enable
    InterruptRegister(SSP1_IRQn, ISSP1IRQ, INTERRUPT_PRIORITY_HIGH, "SSP1");
    InterruptDisable(SSP1_IRQn);
}
/** @} */
/*-------------------------------------------------------------------------*
 * End of File:  SSP.c
 *-------------------------------------------------------------------------*/
