/*-------------------------------------------------------------------------*
 * File:  RX62N_UtilityFuncs.c
 *-------------------------------------------------------------------------*
 * Description:
 *      
 *-------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
 * uEZ(R) - Copyright (C) 2007-2012 Future Designs, Inc.
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
#include "RX62N_UtilityFuncs.h"

void RX62N_PinsLock(
        const T_uezGPIOPortPin *aPins,
        TUInt8 aCount)
{
    while (aCount--) {
        UEZGPIOLock(aPins[aCount]);
    }
}
 
 /*-------------------------------------------------------------------------*
 * End of File:  RX62N_UtilityFuncs.c
 *-------------------------------------------------------------------------*/