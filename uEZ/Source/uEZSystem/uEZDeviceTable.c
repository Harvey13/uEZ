/*-------------------------------------------------------------------------*
 * File:  uEZDeviceTable.c
 *-------------------------------------------------------------------------*
 * Description:
 *      uEZ Device Table used to track all devices in the system.
 *
 * Implementation Notes:
 *      Each device is an entry in the handle table.  The handle stores
 *      three data items: workspace, device interface, and name.
 *      The workspace holds the specific implementation data for the
 *      device. The device interface is the structure for that device.
 *      The name is a static string that gives the device a unique
 *      identifier (for finding later).
 *      NOTE: It is assumed that a user of a device understands the
 *      interface associated with that device.
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
 *    @addtogroup uEZDeviceTable
 *  @{
 *  @brief     uEZ Device Table Interface
 *  @see http://www.teamfdi.com/uez/
 *  @see http://www.teamfdi.com/uez/files/uEZLicense.txt
 *
 *    The uEZ Device Table interface.
 *
 * @par Example code:
 * Example task to find device
 * @par
 * @code
 *  #include <uEZ.h>
 *  #include <uEZDevice.h>
 *
 *   TUInt32 SPIfind(T_uezTask aMyTask, void *aParams)
 *   {
 *       T_uezDevice SPI;
 *       if (UEZDeviceTableFind("SPI0", &SPI) == UEZ_ERROR_NONE) {
 *           // found device handle and stored in SPI
 *       }
 *       return 0;
 *   }
 * @endcode
 */
#include <string.h>
#include <Config.h>
#include <uEZ.h>
#include <Source/uEZSystem/uEZHandles.h>
#include <uEZMemory.h>
#include <uEZDevice.h>

static TUInt32 G_deviceWorkspaceAllocated=0;

/*---------------------------------------------------------------------------*
 * Routine:  UEZDeviceTableRegister
 *---------------------------------------------------------------------------*/
/**
 *  Register a device with the given interface and handle.  Creates
 *      a workspace for the device.
 *
 * @param [in] *aName  		  Unique identifier for device
 *
 * @param [in] *aInterface 	  Interface to the device
 *
 * @param [in] *aDeviceHandle Pointer to recently created device's handle.
 *
 * @param [in] **aWorkspace   Pointer to pointer to recently created workspace.
 *
 * @return    T_uezError     Error code
 * @par Example Code:
 * @code
 *  #include <uEZ.h>
 *  #include <uEZDevice.h>
 *  #include <Generic_SPI.h>
 *
 *   T_uezDeviceWorkspace *p_ssp0;
 *   // Initialize the SPI bus 0 device
 *   // and link to the SPI0 HAL driver
 *   UEZDeviceTableRegister(
 *           "SPI0",
 *           (T_uezDeviceInterface *)&SPIBus_Generic_Interface,
 *           0,
 *           &p_ssp0);
 * @endcode
 */
/*---------------------------------------------------------------------------*/
T_uezError UEZDeviceTableRegister(
                const char * const aName,
                T_uezDeviceInterface *aInterface,
                T_uezDevice *aDeviceHandle,
                T_uezDeviceWorkspace **aWorkspace)
{
    T_uezError error;
    T_uezDeviceWorkspace *workspace;
    T_uezDevice dev;

    error = uEZHandleAlloc(&dev);
    if (error)
        return error;

    // Got a handle.
    // Create the workspace
    workspace = (T_uezDeviceWorkspace *)UEZMemAllocPermanent(aInterface->iWorkspaceSize);
    if (workspace == 0)  {
        // Did not get the workspace, delete the handle
        // and report out of memory
        uEZHandleFree(dev);
        return UEZ_ERROR_OUT_OF_MEMORY;
    }
    // Reset the workspace to a junk state
    memset(workspace, 0xCC, aInterface->iWorkspaceSize);
    G_deviceWorkspaceAllocated += aInterface->iWorkspaceSize;

    // Got a handle and workspace.
    // Let's initialize the workspace
    workspace->iInterface = (void *)aInterface;
    error = aInterface->InitializeWorkspace((void *)workspace);
    if (error)  {
        // If we got an error, delete the handle and workspace
        UEZMemFree((void *)workspace);
        uEZHandleFree(dev);
        return error;
    }

    // Record information about this driver in the table
    uEZHandleSet(
        dev,
        UEZ_HANDLE_DEVICE,
        (TUInt32)workspace,
        (TUInt32)aInterface,
        (TUInt32)aName);

    if (aWorkspace)
        *aWorkspace = workspace;
    if (aDeviceHandle)
        *aDeviceHandle = dev;

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZDeviceTableGetWorkspace
 *---------------------------------------------------------------------------*/
/**
 *  Register a device with the given interface and handle.  Creates
 *  a workspace for the device.
 *
 *  @param [in]    aDevice          Device with workspace to get
 *
 *  @param [in]    **aWorkspace 	Pointer to pointer to returned
 *                                  workspace.
 *  @return        T_uezError     	Error code
 *  @par Example Code:
 *  @code
 *  #include <uEZ.h>
 *  #include <uEZDevice.h>
 *
 *   T_uezDevice SPI;
 *   if (UEZDeviceTableFind("SPI0", &SPI) == UEZ_ERROR_NONE) {
 *       // found device handle and stored in SPI
 *   }
 *  @endcode
 */
/*---------------------------------------------------------------------------*/
T_uezError UEZDeviceTableGetWorkspace(
            T_uezDevice aDevice,
            T_uezDeviceWorkspace **aWorkspace)
{
    TUInt32 type = UEZ_HANDLE_FREE;

    uEZHandleGet(aDevice, &type, (TUInt32 *)aWorkspace, 0, 0);
    if ((type & UEZ_HANDLE_TYPE_MASK) != UEZ_HANDLE_DEVICE) {
        *aWorkspace = 0;
        return UEZ_ERROR_HANDLE_INVALID;
    }
    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZDeviceTableFind
 *---------------------------------------------------------------------------*/
/**
 *  Search device table for existing device and return device handle.
 *
 *  @param [in]    *aName 			Pointer to device name to find.
 *
 *  @param [in]    *aDevice 		Pointer to device to return
 *
 *  @return        T_uezError   	Error code
 *  @par Example Code:
 *  @code
 *  #include <uEZ.h>
 *  #include <uEZDevice.h>
 *
 *   T_uezDevice SPI;
 *   if (UEZDeviceTableFind("SPI0", &SPI) == UEZ_ERROR_NONE) {
 *       // found device handle and stored in SPI
 *   }
 * @endcode
 */
/*---------------------------------------------------------------------------*/
T_uezError UEZDeviceTableFind(const char * const aName, T_uezDevice *aDevice)
{
    T_uezError error;
    TUInt32 index = UEZ_HANDLE_FIND_START;
    char *handleName;

    // Search until we hit the end
    *aDevice = UEZ_NULL_HANDLE;
    do {
        error = uEZHandleFindOfType(UEZ_HANDLE_DEVICE, aDevice, &index);
        if (error == UEZ_ERROR_NONE)  {
            // We found a match of type.
            // Does the name match?
            uEZHandleGet(*aDevice, 0, 0, 0, (TUInt32 *)&handleName);
            if (strcmp(handleName, aName) == 0)
                return UEZ_ERROR_NONE;
        }
    } while (error == UEZ_ERROR_NONE);

#ifndef NDEBUG
    UEZFailureMsg("Device not found!");
#endif

    return UEZ_ERROR_NOT_FOUND;
}
/** @} */
/*-------------------------------------------------------------------------*
 * End of File:  uEZDeviceTable.c
 *-------------------------------------------------------------------------*/
