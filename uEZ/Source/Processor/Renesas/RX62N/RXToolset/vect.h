/***********************************************************************/
/*                                                                     */
/*  FILE        :vect.h                                                */
/*  DATE        :Thu, Sep 23, 2010                                     */
/*  DESCRIPTION :Definition of Vector                                  */
/*  CPU TYPE    :RX62N                                                 */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.51).    */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
/************************************************************************
*
* Device     : RX/RX600/RX62N
*
* File Name  : vect.h
*
* Abstract   : Definition of Vector.
*
* History    : 1.00  (2010-03-05)  [Hardware Manual Revision : 0.50]
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
* Copyright (C) 2009 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
*
************************************************************************/
#ifndef VECT_H
#define VECT_H


// Exception(Supervisor Instruction)
#pragma interrupt (Excep_SuperVisorInst)
void Excep_SuperVisorInst(void);

// Exception(Undefined Instruction)
#pragma interrupt (Excep_UndefinedInst)
void Excep_UndefinedInst(void);

// Exception(Floating Point)
#pragma interrupt (Excep_FloatingPoint)
void Excep_FloatingPoint(void);

// NMI
#pragma interrupt (NonMaskableInterrupt)
void NonMaskableInterrupt(void);

// Dummy
#pragma interrupt (Dummy)
void Dummy(void);

// BRK
#pragma interrupt (Excep_BRK(vect=0))
void Excep_BRK(void);

// vector  1 reserved
// vector  2 reserved
// vector  3 reserved
// vector  4 reserved
// vector  5 reserved
// vector  6 reserved
// vector  7 reserved
// vector  8 reserved
// vector  9 reserved
// vector 10 reserved
// vector 11 reserved
// vector 12 reserved
// vector 13 reserved
// vector 14 reserved
// vector 15 reserved

// BUSERR
#pragma interrupt (Excep_BUSERR(vect=16))
void Excep_BUSERR(void);

// vector 17 reserved
// vector 18 reserved
// vector 19 reserved
// vector 20 reserved

// FCU_FCUERR
#pragma interrupt (Excep_FCU_FCUERR(vect=21))
void Excep_FCU_FCUERR(void);

// vector 22 reserved

// FCU_FRDYI
#pragma interrupt (Excep_FCU_FRDYI(vect=23))
void Excep_FCU_FRDYI(void);

// vector 24 reserved
// vector 25 reserved
// vector 26 reserved

// ICU SWINT
//#pragma interrupt (Excep_ICU_SWINT(vect=27))
//void Excep_ICU_SWINT(void);

// CMTU0_CMT0
//#pragma interrupt (Excep_CMTU0_CMT0(vect=28))
//void Excep_CMTU0_CMT0(void);

// CMTU0_CMT1
#pragma interrupt (Excep_CMTU0_CMT1(vect=29))
void Excep_CMTU0_CMT1(void);

// CMTU1_CMT2
#pragma interrupt (Excep_CMTU1_CMT2(vect=30))
void Excep_CMTU1_CMT2(void);

// CMTU1_CMT3
#pragma interrupt (Excep_CMTU1_CMT3(vect=31))
void Excep_CMTU1_CMT3(void);

// ETHER EINT
#pragma interrupt (Excep_ETHER_EINT(vect=32))
void Excep_ETHER_EINT(void);

// vector 33 reserved
// vector 34 reserved
// vector 35 reserved

// USB0 D0FIFO0
#pragma interrupt (Excep_USB0_D0FIFO0(vect=36))
void Excep_USB0_D0FIFO0(void);

// USB0 D1FIFO0
#pragma interrupt (Excep_USB0_D1FIFO0(vect=37))
void Excep_USB0_D1FIFO0(void);

// USB0 USBI0
#pragma interrupt (Excep_USB0_USBI0(vect=38))
void Excep_USB0_USBI0(void);

// vector 39 reserved

// USB1 D0FIFO1
#pragma interrupt (Excep_USB1_D0FIFO1(vect=40))
void Excep_USB1_D0FIFO1(void);

// USB1 D1FIFO1
#pragma interrupt (Excep_USB1_D1FIFO1(vect=41))
void Excep_USB1_D1FIFO1(void);

// USB1 USBI1
#pragma interrupt (Excep_USB1_USBI1(vect=42))
void Excep_USB1_USBI1(void);

// vector 43 reserved

// RSPI0 SPEI0
#pragma interrupt (Excep_RSPI0_SPEI0(vect=44))
void Excep_RSPI0_SPEI0(void);

// RSPI0 SPRI0
#pragma interrupt (Excep_RSPI0_SPRI0(vect=45))
void Excep_RSPI0_SPRI0(void);

// RSPI0 SPTI0
#pragma interrupt (Excep_RSPI0_SPTI0(vect=46))
void Excep_RSPI0_SPTI0(void);

// RSPI0 SPII0
#pragma interrupt (Excep_RSPI0_SPII0(vect=47))
void Excep_RSPI0_SPII0(void);

// RSPI1 SPEI1
#pragma interrupt (Excep_RSPI1_SPEI1(vect=48))
void Excep_RSPI1_SPEI1(void);

// RSPI1 SPRI1
#pragma interrupt (Excep_RSPI1_SPRI1(vect=49))
void Excep_RSPI1_SPRI1(void);

// RSPI1 SPTI1
#pragma interrupt (Excep_RSPI1_SPTI1(vect=50))
void Excep_RSPI1_SPTI1(void);

// RSPI1 SPII1
#pragma interrupt (Excep_RSPI1_SPII1(vect=51))
void Excep_RSPI1_SPII1(void);

// vector 52 reserved
// vector 53 reserved
// vector 54 reserved
// vector 55 reserved

// CAN0 ERS0
#pragma interrupt (Excep_CAN0_ERS0(vect=56))
void Excep_CAN0_ERS0(void);

// CAN0 RXF0
#pragma interrupt (Excep_CAN0_RXF0(vect=57))
void Excep_CAN0_RXF0(void);

// CAN0 TXF0
#pragma interrupt (Excep_CAN0_TXF0(vect=58))
void Excep_CAN0_TXF0(void);

// CAN0 RXM0
#pragma interrupt (Excep_CAN0_RXM0(vect=59))
void Excep_CAN0_RXM0(void);

// CAN0 TXM0
#pragma interrupt (Excep_CAN0_TXM0(vect=60))
void Excep_CAN0_TXM0(void);

// vector 61 reserved

// RTC PRD
#pragma interrupt (Excep_RTC_PRD(vect=62))
void Excep_RTC_PRD(void);

// RTC CUP
#pragma interrupt (Excep_RTC_CUP(vect=63))
void Excep_RTC_CUP(void);

// IRQ0
#pragma interrupt (Excep_IRQ0(vect=64))
void Excep_IRQ0(void);

// IRQ1
#pragma interrupt (Excep_IRQ1(vect=65))
void Excep_IRQ1(void);

// IRQ2
#pragma interrupt (Excep_IRQ2(vect=66))
void Excep_IRQ2(void);

// IRQ3
#pragma interrupt (Excep_IRQ3(vect=67))
void Excep_IRQ3(void);

// IRQ4
#pragma interrupt (Excep_IRQ4(vect=68))
void Excep_IRQ4(void);

// IRQ5
#pragma interrupt (Excep_IRQ5(vect=69))
void Excep_IRQ5(void);

// IRQ6
#pragma interrupt (Excep_IRQ6(vect=70))
void Excep_IRQ6(void);

// IRQ7
#pragma interrupt (Excep_IRQ7(vect=71))
void Excep_IRQ7(void);

// IRQ8
#pragma interrupt (Excep_IRQ8(vect=72))
void Excep_IRQ8(void);

// IRQ9
#pragma interrupt (Excep_IRQ9(vect=73))
void Excep_IRQ9(void);

// IRQ10
#pragma interrupt (Excep_IRQ10(vect=74))
void Excep_IRQ10(void);

// IRQ11
#pragma interrupt (Excep_IRQ11(vect=75))
void Excep_IRQ11(void);

// IRQ12
#pragma interrupt (Excep_IRQ12(vect=76))
void Excep_IRQ12(void);

// IRQ13
#pragma interrupt (Excep_IRQ13(vect=77))
void Excep_IRQ13(void);

// IRQ14
#pragma interrupt (Excep_IRQ14(vect=78))
void Excep_IRQ14(void);

// IRQ15
#pragma interrupt (Excep_IRQ15(vect=79))
void Excep_IRQ15(void);

// vector 80 reserved
// vector 81 reserved
// vector 82 reserved
// vector 83 reserved
// vector 84 reserved
// vector 85 reserved
// vector 86 reserved
// vector 87 reserved
// vector 88 reserved
// vector 89 reserved

// USB RESUME USBR0
#pragma interrupt (Excep_USB_USBR0(vect=90))
void Excep_USB_USBR0(void);

// USB RESUME USBR1
#pragma interrupt (Excep_USB_USBR1(vect=91))
void Excep_USB_USBR1(void);

// RTC ALM
#pragma interrupt (Excep_RTC_ALM(vect=92))
void Excep_RTC_ALM(void);

// vector 93 reserved
// vector 94 reserved
// vector 95 reserved

// WDT_WOVI
#pragma interrupt (Excep_WDT_WOVI(vect=96))
void Excep_WDT_WOVI(void);

// vector 97 reserved

// AD0_ADI0
#pragma interrupt (Excep_AD0_ADI0(vect=98))
void Excep_AD0_ADI0(void);

// AD1_ADI1
#pragma interrupt (Excep_AD1_ADI1(vect=99))
void Excep_AD1_ADI1(void);

// vector 100 reserved
// vector 101 reserved

// S12AD ADI12
#pragma interrupt (Excep_S12AD_ADI12(vect=102))
void Excep_S12AD_ADI12(void);

// vector 103 reserved
// vector 104 reserved
// vector 105 reserved
// vector 106 reserved
// vector 107 reserved
// vector 108 reserved
// vector 109 reserved
// vector 110 reserved
// vector 111 reserved
// vector 112 reserved
// vector 113 reserved

// MTU0 TGIA0
#pragma interrupt (Excep_MTU0_TGIA0(vect=114))
void Excep_MTU0_TGIA0(void);

// MTU0 TGIB0
#pragma interrupt (Excep_MTU0_TGIB0(vect=115))
void Excep_MTU0_TGIB0(void);

// MTU0 TGIC0
#pragma interrupt (Excep_MTU0_TGIC0(vect=116))
void Excep_MTU0_TGIC0(void);

// MTU0 TGID0
#pragma interrupt (Excep_MTU0_TGID0(vect=117))
void Excep_MTU0_TGID0(void);

// MTU0 TCIV0
#pragma interrupt (Excep_MTU0_TCIV0(vect=118))
void Excep_MTU0_TCIV0(void);

// MTU0 TGIE0
#pragma interrupt (Excep_MTU0_TGIE0(vect=119))
void Excep_MTU0_TGIE0(void);

// MTU0 TGIF0
#pragma interrupt (Excep_MTU0_TGIF0(vect=120))
void Excep_MTU0_TGIF0(void);

// MTU1 TGIA1
#pragma interrupt (Excep_MTU1_TGIA1(vect=121))
void Excep_MTU1_TGIA1(void);

// MTU1 TGIB1
#pragma interrupt (Excep_MTU1_TGIB1(vect=122))
void Excep_MTU1_TGIB1(void);

// MTU1 TCIV1
#pragma interrupt (Excep_MTU1_TCIV1(vect=123))
void Excep_MTU1_TCIV1(void);

// MTU1 TCIU1
#pragma interrupt (Excep_MTU1_TCIU1(vect=124))
void Excep_MTU1_TCIU1(void);

// MTU2 TGIA2
#pragma interrupt (Excep_MTU2_TGIA2(vect=125))
void Excep_MTU2_TGIA2(void);

// MTU2 TGIB2
#pragma interrupt (Excep_MTU2_TGIB2(vect=126))
void Excep_MTU2_TGIA2(void);

// MTU2 TCIV2
#pragma interrupt (Excep_MTU2_TCIV2(vect=127))
void Excep_MTU2_TCIV2(void);

// MTU2 TCIU2
#pragma interrupt (Excep_MTU2_TCIU2(vect=128))
void Excep_MTU2_TCIU2(void);

// MTU3 TGIA3
#pragma interrupt (Excep_MTU3_TGIA3(vect=129))
void Excep_MTU3_TGIA3(void);

// MTU3 TGIB3
#pragma interrupt (Excep_MTU3_TGIB3(vect=130))
void Excep_MTU3_TGIB3(void);

// MTU3 TGIC3
#pragma interrupt (Excep_MTU3_TGIC3(vect=131))
void Excep_MTU3_TGIC3(void);

// MTU3 TGID3
#pragma interrupt (Excep_MTU3_TGID3(vect=132))
void Excep_MTU3_TGID3(void);

// MTU3 TCIV3
#pragma interrupt (Excep_MTU3_TCIV3(vect=133))
void Excep_MTU3_TCIV3(void);


// MTU4 TGIA4
#pragma interrupt (Excep_MTU4_TGIA4(vect=134))
void Excep_MTU4_TGIA4(void);

// MTU4 TGIB4
#pragma interrupt (Excep_MTU4_TGIB4(vect=135))
void Excep_MTU4_TGIB4(void);

// MTU4 TGIC4
#pragma interrupt (Excep_MTU4_TGIC4(vect=136))
void Excep_MTU4_TGIC4(void);

// MTU4 TGID4
#pragma interrupt (Excep_MTU4_TGID4(vect=137))
void Excep_MTU4_TGID4(void);

// MTU4 TCIV4
#pragma interrupt (Excep_MTU4_TCIV4(vect=138))
void Excep_MTU4_TCIV4(void);

// MTU5 TCIU5
#pragma interrupt (Excep_MTU5_TCIU5(vect=139))
void Excep_MTU5_TCIU5(void);

// MTU5 TCIV5
#pragma interrupt (Excep_MTU5_TCIV5(vect=140))
void Excep_MTU5_TCIV5(void);

// MTU5 TCIW5
#pragma interrupt (Excep_MTU5_TCIW5(vect=141))
void Excep_MTU5_TCIW5(void);

// MTU6 TGIA6
#pragma interrupt (Excep_MTU6_TGIA6(vect=142))
void Excep_MTU6_TGIA6(void);

// MTU6 TGIB6
#pragma interrupt (Excep_MTU6_TGIB6(vect=143))
void Excep_MTU6_TGIB6(void);

// MTU6 TGIC6
#pragma interrupt (Excep_MTU6_TGIC6(vect=144))
void Excep_MTU6_TGIC6(void);

// MTU6 TGID6
#pragma interrupt (Excep_MTU6_TGID6(vect=145))
void Excep_MTU6_TGID6(void);

// MTU6 TCIV6
#pragma interrupt (Excep_MTU6_TCIV6(vect=146))
void Excep_MTU6_TCIV6(void);

// MTU6 TGIE6
#pragma interrupt (Excep_MTU6_TGIE6(vect=147))
void Excep_MTU6_TGIE6(void);

// MTU6 TGIF6
#pragma interrupt (Excep_MTU6_TGIF6(vect=148))
void Excep_MTU6_TGIF6(void);

// MTU7 TGIA7
#pragma interrupt (Excep_MTU7_TGIA7(vect=149))
void Excep_MTU7_TGIA7(void);

// MTU7 TGIB7
#pragma interrupt (Excep_MTU7_TGIB7(vect=150))
void Excep_MTU7_TGIA7(void);

// MTU7 TCIV7
#pragma interrupt (Excep_MTU7_TCIV7(vect=151))
void Excep_MTU7_TCIV7(void);

// MTU7 TCIU7
#pragma interrupt (Excep_MTU7_TCIU7(vect=152))
void Excep_MTU7_TCIU7(void);

// MTU8 TGIA8
#pragma interrupt (Excep_MTU8_TGIA8(vect=153))
void Excep_MTU8_TGIA8(void);

// MTU8 TGIB8
#pragma interrupt (Excep_MTU8_TGIB8(vect=154))
void Excep_MTU8_TGIA8(void);

// MTU8 TCIV8
#pragma interrupt (Excep_MTU8_TCIV8(vect=155))
void Excep_MTU8_TCIV8(void);

// MTU8 TCIU8
#pragma interrupt (Excep_MTU8_TCIU8(vect=156))
void Excep_MTU8_TCIU8(void);

// MTU9 TGIA9
#pragma interrupt (Excep_MTU9_TGIA9(vect=157))
void Excep_MTU9_TGIA9(void);

// MTU9 TGIB9
#pragma interrupt (Excep_MTU9_TGIB9(vect=158))
void Excep_MTU9_TGIB9(void);

// MTU9 TGIC9
#pragma interrupt (Excep_MTU9_TGIC9(vect=159))
void Excep_MTU9_TGIC9(void);

// MTU9 TGID9
#pragma interrupt (Excep_MTU9_TGID9(vect=160))
void Excep_MTU9_TGID9(void);

// MTU9 TCIV9
#pragma interrupt (Excep_MTU9_TCIV9(vect=161))
void Excep_MTU9_TCIV9(void);

// MTU10 TGIA10
#pragma interrupt (Excep_MTU10_TGIA10(vect=162))
void Excep_MTU10_TGIA10(void);

// MTU10 TGIB10
#pragma interrupt (Excep_MTU10_TGIB10(vect=163))
void Excep_MTU10_TGIB10(void);

// MTU10 TGIC10
#pragma interrupt (Excep_MTU10_TGIC10(vect=164))
void Excep_MTU10_TGIC10(void);

// MTU10 TGID10
#pragma interrupt (Excep_MTU10_TGID10(vect=165))
void Excep_MTU10_TGID10(void);

// MTU10 TCIV10
#pragma interrupt (Excep_MTU10_TCIV10(vect=166))
void Excep_MTU10_TCIV10(void);

// MTU11 TCIU11
#pragma interrupt (Excep_MTU11_TCIU11(vect=167))
void Excep_MTU11_TCIU11(void);

// MTU11 TCIV11
#pragma interrupt (Excep_MTU11_TCIV11(vect=168))
void Excep_MTU11_TCIV11(void);

// MTU11 TCIW11
#pragma interrupt (Excep_MTU11_TCIW11(vect=169))
void Excep_MTU11_TCIW11(void);

// POE OEI1
#pragma interrupt (Excep_POE_OEI1(vect=170))
void Excep_POE_OEI1(void);

// POE OEI1
#pragma interrupt (Excep_POE_OEI2(vect=171))
void Excep_POE_OEI2(void);

// POE OEI1
#pragma interrupt (Excep_POE_OEI3(vect=172))
void Excep_POE_OEI3(void);

// POE OEI1
#pragma interrupt (Excep_POE_OEI4(vect=173))
void Excep_POE_OEI4(void);

// TMR0_CMI0A
#pragma interrupt (Excep_TMR0_CMI0A(vect=174))
void Excep_TMR0_CMI0A(void);

// TMR0_CMI0B
#pragma interrupt (Excep_TMR0_CMI0B(vect=175))
void Excep_TMR0_CMI0B(void);

// TMR0_OV0I
#pragma interrupt (Excep_TMR0_OV0I(vect=176))
void Excep_TMR0_OV0I(void);

// TMR1_CMI1A
#pragma interrupt (Excep_TMR1_CMI1A(vect=177))
void Excep_TMR1_CMI1A(void);

// TMR1_CMI1B
#pragma interrupt (Excep_TMR1_CMI1B(vect=178))
void Excep_TMR1_CMI1B(void);

// TMR1_OV1I
#pragma interrupt (Excep_TMR1_OV1I(vect=179))
void Excep_TMR1_OV1I(void);

// TMR2_CMI2A
#pragma interrupt (Excep_TMR2_CMI2A(vect=180))
void Excep_TMR2_CMI2A(void);

// TMR2_CMI2B
#pragma interrupt (Excep_TMR2_CMI2B(vect=181))
void Excep_TMR2_CMI2B(void);

// TMR2_OV2I
#pragma interrupt (Excep_TMR2_OV2I(vect=182))
void Excep_TMR2_OV2I(void);

// TMR3_CMI3A
#pragma interrupt (Excep_TMR3_CMI3A(vect=183))
void Excep_TMR3_CMI3A(void);

// TMR3_CMI3B
#pragma interrupt (Excep_TMR3_CMI3B(vect=184))
void Excep_TMR3_CMI3B(void);

// TMR3_OV3I
#pragma interrupt (Excep_TMR3_OV3I(vect=185))
void Excep_TMR3_OV3I(void);

// vector 186 reserved
// vector 187 reserved
// vector 188 reserved
// vector 189 reserved
// vector 190 reserved
// vector 191 reserved
// vector 192 reserved
// vector 193 reserved
// vector 194 reserved
// vector 195 reserved
// vector 196 reserved
// vector 197 reserved

// DMACA DMAC0
#pragma interrupt (Excep_DMACA_DMAC0(vect=198))
void Excep_DMACA_DMAC0(void);

// DMAC DMAC1
#pragma interrupt (Excep_DMACA_DMAC1(vect=199))
void Excep_DMACA_DMAC1(void);

// DMAC DMAC2
#pragma interrupt (Excep_DMACA_DMAC2(vect=200))
void Excep_DMACA_DMAC2(void);

// DMAC DMAC3
#pragma interrupt (Excep_DMACA_DMAC3(vect=201))
void Excep_DMACA_DMAC3(void);

// EXDMAC DMAC0
#pragma interrupt (Excep_EXDMAC_DMAC0(vect=202))
void Excep_EXDMAC_DMAC0(void);

// EXDMAC DMAC1
#pragma interrupt (Excep_EXDMAC_DMAC1(vect=203))
void Excep_EXDMAC_DMAC1(void);

// vector 203 reserved
// vector 204 reserved
// vector 205 reserved
// vector 206 reserved
// vector 207 reserved
// vector 208 reserved
// vector 209 reserved
// vector 210 reserved
// vector 211 reserved
// vector 212 reserved
// vector 213 reserved

// SCI0_ERI0
#pragma interrupt (Excep_SCI0_ERI0(vect=214))
void Excep_SCI0_ERI0(void);

// SCI0_RXI0
#pragma interrupt (Excep_SCI0_RXI0(vect=215))
void Excep_SCI0_RXI0(void);

// SCI0_TXI0
#pragma interrupt (Excep_SCI0_TXI0(vect=216))
void Excep_SCI0_TXI0(void);

// SCI0_TEI0
#pragma interrupt (Excep_SCI0_TEI0(vect=217))
void Excep_SCI0_TEI0(void);

// SCI1_ERI1
#pragma interrupt (Excep_SCI1_ERI1(vect=218))
void Excep_SCI1_ERI1(void);

// SCI1_RXI1
#pragma interrupt (Excep_SCI1_RXI1(vect=219))
void Excep_SCI1_RXI1(void);

// SCI1_TXI1
#pragma interrupt (Excep_SCI1_TXI1(vect=220))
void Excep_SCI1_TXI1(void);

// SCI1_TEI1
#pragma interrupt (Excep_SCI1_TEI1(vect=221))
void Excep_SCI1_TEI1(void);

// SCI2_ERI2
#pragma interrupt (Excep_SCI2_ERI2(vect=222))
void Excep_SCI2_ERI2(void);

// SCI2_RXI2
#pragma interrupt (Excep_SCI2_RXI2(vect=223))
void Excep_SCI2_RXI2(void);

// SCI2_TXI2
#pragma interrupt (Excep_SCI2_TXI2(vect=224))
void Excep_SCI2_TXI2(void);

// SCI2_TEI2
#pragma interrupt (Excep_SCI2_TEI2(vect=225))
void Excep_SCI2_TEI2(void);

// SCI3_ERI3
#pragma interrupt (Excep_SCI3_ERI3(vect=226))
void Excep_SCI3_ERI3(void);

// SCI3_RXI3
#pragma interrupt (Excep_SCI3_RXI3(vect=227))
void Excep_SCI3_RXI3(void);

// SCI3_TXI3
#pragma interrupt (Excep_SCI3_TXI3(vect=228))
void Excep_SCI3_TXI3(void);

// SCI3_TEI3
#pragma interrupt (Excep_SCI3_TEI3(vect=229))
void Excep_SCI3_TEI3(void);

// vector 230 reserved
// vector 231 reserved
// vector 232 reserved
// vector 233 reserved

// SCI5_ERI5
#pragma interrupt (Excep_SCI5_ERI5(vect=234))
void Excep_SCI5_ERI5(void);

// SCI5_RXI5
#pragma interrupt (Excep_SCI5_RXI5(vect=235))
void Excep_SCI5_RXI5(void);

// SCI5_TXI5
#pragma interrupt (Excep_SCI5_TXI5(vect=236))
void Excep_SCI5_TXI5(void);

// SCI5_TEI5
#pragma interrupt (Excep_SCI5_TEI5(vect=237))
void Excep_SCI5_TEI5(void);

// SCI6_ERI6
#pragma interrupt (Excep_SCI6_ERI6(vect=238))
void Excep_SCI6_ERI6(void);

// SCI6_RXI6
#pragma interrupt (Excep_SCI6_RXI6(vect=239))
void Excep_SCI6_RXI6(void);

// SCI6_TXI6
#pragma interrupt (Excep_SCI6_TXI6(vect=240))
void Excep_SCI6_TXI6(void);

// SCI6_TEI6
#pragma interrupt (Excep_SCI6_TEI6(vect=241))
void Excep_SCI6_TEI6(void);

// vector 242 reserved
// vector 243 reserved
// vector 244 reserved
// vector 245 reserved

// RIIC0_EEI0
#pragma interrupt (Excep_RIIC0_EEI0(vect=246))
void Excep_RIIC0_EEI0(void);

// RIIC0_RXI0
#pragma interrupt (Excep_RIIC0_RXI0(vect=247))
void Excep_RIIC0_RXI0(void);

// RIIC0_TXI0
#pragma interrupt (Excep_RIIC0_TXI0(vect=248))
void Excep_RIIC0_TXI0(void);

// RIIC0_TEI0
#pragma interrupt (Excep_RIIC0_TEI0(vect=249))
void Excep_RIIC0_TEI0(void);

// RIIC1_EEI1
#pragma interrupt (Excep_RIIC1_EEI1(vect=250))
void Excep_RIIC1_EEI1(void);

// RIIC1_RXI1
#pragma interrupt (Excep_RIIC1_RXI1(vect=251))
void Excep_RIIC1_RXI1(void);

// RIIC1_TXI1
#pragma interrupt (Excep_RIIC1_TXI1(vect=252))
void Excep_RIIC1_TXI1(void);

// RIIC1_TEI1
#pragma interrupt (Excep_RIIC1_TEI1(vect=253))
void Excep_RIIC1_TEI1(void);

// vector 254 reserved
// vector 255 reserved

//;<<VECTOR DATA START (POWER ON RESET)>>
//;Power On Reset PC
extern void PowerON_Reset_PC(void);                                                                                                                
//;<<VECTOR DATA END (POWER ON RESET)>>


#endif // VECT_H