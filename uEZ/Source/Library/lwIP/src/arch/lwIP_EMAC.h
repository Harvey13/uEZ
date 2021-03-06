/*
	FreeRTOS.org V4.7.2 - Copyright (C) 2003-2008 Richard Barry.

	This file is part of the FreeRTOS.org distribution.

	FreeRTOS.org is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	FreeRTOS.org is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with FreeRTOS.org; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

	A special exception to the GPL can be applied should you wish to distribute
	a combined work that includes FreeRTOS.org, without being obliged to provide
	the source code for any proprietary components.  See the licensing section
	of http://www.FreeRTOS.org for full details of how and when the exception
	can be applied.

	***************************************************************************

	Please ensure to read the configuration and relevant port sections of the 
	online documentation.

	+++ http://www.FreeRTOS.org +++
	Documentation, latest information, license and contact details.  

	+++ http://www.SafeRTOS.com +++
	A version that is certified for use in safety critical systems.

	+++ http://www.OpenRTOS.com +++
	Commercial support, development, porting, licensing and training services.

	***************************************************************************
*/



#ifndef LWIP_EMAC_H
#define LWIP_EMAC_H


/*Define the PHY type*/
#define NATIONAL_PHY     0
#define MICREL_PHY 	 1

/*
 * Initialise the EMAC driver.  If successful a semaphore is returned that
 * is used by the EMAC ISR to indicate that Rx packets have been received.
 * If the initialisation fails then NULL is returned.
 */
T_uezSemaphore xEMACInit( void );

/*
 * Send ulLength bytes from pcFrom.  This copies the buffer to one of the
 * EMAC Tx buffers, then indicates to the EMAC that the buffer is ready.
 * If lEndOfFrame is true then the data being copied is the end of the frame
 * and the frame can be transmitted. 
 */
portLONG lEMACSend( portCHAR *pcFrom, unsigned portLONG ulLength, portLONG lEndOfFrame );

/*
 * Frames can be read from the EMAC in multiple sections.
 * Read ulSectionLength bytes from the EMAC receive buffers to pcTo.  
 * ulTotalFrameLength is the size of the entire frame.  Generally vEMACRead
 * will be repetedly called until the sum of all the ulSectionLenths totals
 * the value of ulTotalFrameLength.
 */
void vEMACRead( portCHAR *pcTo, unsigned portLONG ulSectionLength, unsigned portLONG ulTotalFrameLength );

/*
 * The EMAC driver and interrupt service routines are defined in different 
 * files as the driver is compiled to THUMB, and the ISR to ARM.  This function
 * simply passes the semaphore used to communicate between the two.
 */
void vPassEMACSemaphore( T_uezSemaphore xCreatedSemaphore );

/* 
 * Called by the Tx interrupt, this function traverses the buffers used to
 * hold the frame that has just completed transmission and marks each as
 * free again.
 */
void vClearEMACTxBuffer( void );

/*
 * Suspend on a semaphore waiting either for the semaphore to be obtained 
 * or a timeout.  The semaphore is used by the EMAC ISR to indicate that
 * data has been received and is ready for processing.
 */
void vEMACWaitForInput( void );

/*
 * Return the length of the next frame in the receive buffers.
 */
unsigned portLONG ulEMACInputLength( void );

#endif
