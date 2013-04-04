/*-------------------------------------------------------------------------*
 * File:  EXC7200TouchScreen.h
 *-------------------------------------------------------------------------*
 * Description:
 *      Device implementation of the Four Wire Touchscreen interface.
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

#include <uEZ.h>
#include <Device/Touchscreen.h>
#include <UEZGPIO.h>
#define NUM_CALIBRATE_POINTS_NEEDED     3

/*---------------------------------------------------------------------------*
 * Types:
 *---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*
 * Globals:
 *---------------------------------------------------------------------------*/
 extern const DEVICE_TOUCHSCREEN Touchscreen_EXC7200_Interface;
T_uezError Touchscreen_EXC7200_Create(const char *aName,
                                        const char *aI2CBus,
                                        T_uezGPIOPortPin aInteruptPin,
                                        T_uezGPIOPortPin aResetPin);
/*---------------------------------------------------------------------------*
 * Prototypes:
 *---------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------*
 * End of File:  EXC7200TouchScreen.h
 *-------------------------------------------------------------------------*/
