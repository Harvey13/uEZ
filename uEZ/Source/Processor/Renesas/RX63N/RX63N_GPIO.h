/*-------------------------------------------------------------------------*
 * File:  RX63N_GPIO.h
 *-------------------------------------------------------------------------*
 * Description:
 *     
 *-------------------------------------------------------------------------*/
#ifndef RX63N_GPIO_H_
#define RX63N_GPIO_H_

/*--------------------------------------------------------------------------
 * uEZ(tm) - Copyright (C) 2007-2011 Future Designs, Inc.
 *--------------------------------------------------------------------------
 * This file is part of the uEZ(tm) distribution.
 *
 * uEZ(tm) is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * uEZ(tm) is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with uEZ(tm); if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * A special exception to the GPL can be applied should you wish to
 * distribute a combined work that includes uEZ(tm), without being obliged
 * to provide the source code for any proprietary components.  See the
 * licensing section of http://www.teamfdi.com/uez for full details of how
 * and when the exception can be applied.
 *
 *    *===============================================================*
 *    |  Future Designs, Inc. can port uEZ(tm) to your own hardware!  |
 *    |             We can get you up and running fast!               |
 *    |      See http://www.teamfdi.com/uez for more details.         |
 *    *===============================================================*
 *
 *-------------------------------------------------------------------------*/
#include <HAL/GPIO.h>

/*-------------------------------------------------------------------------*
 * Globals:
 *-------------------------------------------------------------------------*/
extern const HAL_GPIOPort GPIO_RX63N_Port0_Interface;
extern const HAL_GPIOPort GPIO_RX63N_Port1_Interface;
extern const HAL_GPIOPort GPIO_RX63N_Port2_Interface;
extern const HAL_GPIOPort GPIO_RX63N_Port3_Interface;
extern const HAL_GPIOPort GPIO_RX63N_Port4_Interface;
extern const HAL_GPIOPort GPIO_RX63N_Port5_Interface;
extern const HAL_GPIOPort GPIO_RX63N_Port6_Interface;
extern const HAL_GPIOPort GPIO_RX63N_Port7_Interface;
extern const HAL_GPIOPort GPIO_RX63N_Port8_Interface;
extern const HAL_GPIOPort GPIO_RX63N_Port9_Interface;
extern const HAL_GPIOPort GPIO_RX63N_PortA_Interface;
extern const HAL_GPIOPort GPIO_RX63N_PortB_Interface;
extern const HAL_GPIOPort GPIO_RX63N_PortC_Interface;
extern const HAL_GPIOPort GPIO_RX63N_PortD_Interface;
extern const HAL_GPIOPort GPIO_RX63N_PortE_Interface;
extern const HAL_GPIOPort GPIO_RX63N_PortF_Interface;
extern const HAL_GPIOPort GPIO_RX63N_PortG_Interface;
extern const HAL_GPIOPort GPIO_RX63N_PortJ_Interface;

/*-------------------------------------------------------------------------*
 * Types:
 *-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*
 * Prototypes:
 *-------------------------------------------------------------------------*/
//  176-Pin: 17 ports (0 to 9 and A to G)
//  145-Pin: 15 ports (0 to 9 and A to E)
// 	100-Pin: 11 ports (0 to 5, A to E)
// 	85-Pin:  10 ports (0 to 5, A to D)
void RX63N_GPIO_P0_Require(void);
void RX63N_GPIO_P1_Require(void);
void RX63N_GPIO_P2_Require(void);
void RX63N_GPIO_P3_Require(void);
void RX63N_GPIO_P4_Require(void);
void RX63N_GPIO_P5_Require(void);
void RX63N_GPIO_P6_Require(void);
void RX63N_GPIO_P8_Require(void);
void RX63N_GPIO_P9_Require(void);
void RX63N_GPIO_PA_Require(void);
void RX63N_GPIO_PB_Require(void);
void RX63N_GPIO_PC_Require(void);
void RX63N_GPIO_PD_Require(void);
void RX63N_GPIO_PE_Require(void);
void RX63N_GPIO_PF_Require(void);
void RX63N_GPIO_PG_Require(void);
void RX63N_GPIO_PJ_Require(void);

#endif // RX63N_GPIO_H_
/*-------------------------------------------------------------------------*
 * End of File:  RX63N_GPIO.h
 *-------------------------------------------------------------------------*/
