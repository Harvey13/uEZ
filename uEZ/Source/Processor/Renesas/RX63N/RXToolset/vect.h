/***********************************************************************/
/*                                                                     */
/*  FILE        :vect.h                                                */
/*  DATE        :Wed, Sep 19, 2012                                     */
/*  DESCRIPTION :Definition of Vector                                  */
/*  CPU TYPE    :RX63N                                                 */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.53).    */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
/************************************************************************
*
* Device     : RX/RX600/RX63N
*
* File Name  : vect.h
*
* Abstract   : Definition of Vector.
*
* History    : 0.10  (2011-02-21)  [Hardware Manual Revision : 0.01]
*            : 0.11  (2011-06-20)  [Hardware Manual Revision : 0.50]
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
* Copyright (C) 2010 (2011) Renesas Electronics Corporation.
* and Renesas Solutions Corp.
*
************************************************************************/

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
#pragma interrupt (Excep_FCUIF_FIFEERR(vect=21))
void Excep_FCUIF_FIFEERR(void);

// vector 22 reserved

// FCU_FRDYI
#pragma interrupt (Excep_FCUIF_FRDYI(vect=23))
void Excep_FCUIF_FRDYI(void);

// vector 24 reserved
// vector 25 reserved
// vector 26 reserved

// ICU SWINT
#pragma interrupt (Excep_ICU_SWINT(vect=27))
void Excep_ICU_SWINT(void);

// CMTU0_CMT0
#pragma interrupt (Excep_CMT0_CMI0(vect=28))
void Excep_CMT0_CMI0(void);

// CMTU1_CMT1
#pragma interrupt (Excep_CMT1_CMI1(vect=29))
void Excep_CMT1_CMI1(void);

// CMTU2_CMT2
#pragma interrupt (Excep_CMT2_CMI2(vect=30))
void Excep_CMT2_CMI2(void);

// CMTU3_CMT3
#pragma interrupt (Excep_CMT3_CMI3(vect=31))
void Excep_CMT3_CMI3(void);

// ETHER EINT
#pragma interrupt (Excep_ETHER_EINT(vect=32))
void Excep_ETHER_EINT(void);

// USB0 D0FIFO0
#pragma interrupt (Excep_USB0_D0FIFO0(vect=33))
void Excep_USB0_D0FIFO0(void);

// USB0 D1FIFO0
#pragma interrupt (Excep_USB0_D1FIFO0(vect=34))
void Excep_USB0_D1FIFO0(void);

// USB0 USBI0
#pragma interrupt (Excep_USB0_USBI0(vect=35))
void Excep_USB0_USBI0(void);

// USB1 D0FIFO1
#pragma interrupt (Excep_USB1_D0FIFO1(vect=36))
void Excep_USB1_D0FIFO1(void);

// USB1 D1FIFO1
#pragma interrupt (Excep_USB1_D1FIFO1(vect=37))
void Excep_USB1_D1FIFO1(void);

// USB1 USBI1
#pragma interrupt (Excep_USB1_USBI1(vect=38))
void Excep_USB1_USBI1(void);

// RSPI0 SPRI0
#pragma interrupt (Excep_RSPI0_SPRI0(vect=39))
void Excep_RSPI0_SPRI0(void);

// RSPI0 SPTI0
#pragma interrupt (Excep_RSPI0_SPTI0(vect=40))
void Excep_RSPI0_SPTI0(void);

// RSPI0 SPII0
#pragma interrupt (Excep_RSPI0_SPII0(vect=41))
void Excep_RSPI0_SPII0(void);

// RSPI1 SPRI1
#pragma interrupt (Excep_RSPI1_SPRI1(vect=42))
void Excep_RSPI1_SPRI1(void);

// RSPI1 SPTI1
#pragma interrupt (Excep_RSPI1_SPTI1(vect=43))
void Excep_RSPI1_SPTI1(void);

// RSPI1 SPII1
#pragma interrupt (Excep_RSPI1_SPII1(vect=44))
void Excep_RSPI1_SPII1(void);

// RSPI2 SPRI2
#pragma interrupt (Excep_RSPI2_SPRI2(vect=45))
void Excep_RSPI2_SPRI2(void);

// RSPI2 SPTI2
#pragma interrupt (Excep_RSPI2_SPTI2(vect=46))
void Excep_RSPI2_SPTI2(void);

// RSPI2 SPII2
#pragma interrupt (Excep_RSPI2_SPII2(vect=47))
void Excep_RSPI2_SPII2(void);

// CAN0 RXF0
#pragma interrupt (Excep_CAN0_RXF0(vect=48))
void Excep_CAN0_RXF0(void);

// CAN0 TXF0
#pragma interrupt (Excep_CAN0_TXF0(vect=49))
void Excep_CAN0_TXF0(void);

// CAN0 RXM0
#pragma interrupt (Excep_CAN0_RXM0(vect=50))
void Excep_CAN0_RXM0(void);

// CAN0 TXM0
#pragma interrupt (Excep_CAN0_TXM0(vect=51))
void Excep_CAN0_TXM0(void);

// CAN1 RXF1
#pragma interrupt (Excep_CAN1_RXF1(vect=52))
void Excep_CAN1_RXF1(void);

// CAN1 TXF1
#pragma interrupt (Excep_CAN1_TXF1(vect=53))
void Excep_CAN1_TXF1(void);

// CAN1 RXM1
#pragma interrupt (Excep_CAN1_RXM1(vect=54))
void Excep_CAN1_RXM1(void);

// CAN1 TXM1
#pragma interrupt (Excep_CAN1_TXM1(vect=55))
void Excep_CAN1_TXM1(void);

// vector 56 reserved
// vector 57 reserved
// vector 58 reserved
// vector 59 reserved
// vector 60 reserved
// vector 61 reserved

// RTC CUP
#pragma interrupt (Excep_RTC_CUP(vect=62))
void Excep_RTC_CUP(void);

// vector 63 reserved

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

// RTC SLEEP
#pragma interrupt (Excep_RTC_SLEEP(vect=93))
void Excep_RTC_SLEEP(void);

// vector 94 reserved
// vector 95 reserved
// vector 96 reserved
// vector 97 reserved

// ADA0 ADI0
#pragma interrupt (Excep_ADA0_ADI0(vect=98))
void Excep_ADA0_ADI0(void);

// vector 99 reserved
// vector 100 reserved
// vector 101 reserved

// S12AD0 S12ADI0
#pragma interrupt (Excep_S12AD0_S12ADI0(vect=102))
void Excep_S12AD0_S12ADI0(void);

// vector 103 reserved
// vector 104 reserved
// vector 105 reserved

// GROUP E0
#pragma interrupt (Excep_GROUP_E0(vect=106))
void Excep_GROUP_E0(void);

// GROUP E1
#pragma interrupt (Excep_GROUP_E1(vect=107))
void Excep_GROUP_E1(void);

// GROUP E2
#pragma interrupt (Excep_GROUP_E2(vect=108))
void Excep_GROUP_E2(void);

// GROUP E3
#pragma interrupt (Excep_GROUP_E3(vect=109))
void Excep_GROUP_E3(void);

// GROUP E4
#pragma interrupt (Excep_GROUP_E4(vect=110))
void Excep_GROUP_E4(void);

// GROUP E5
#pragma interrupt (Excep_GROUP_E5(vect=111))
void Excep_GROUP_E5(void);

// GROUP E6
#pragma interrupt (Excep_GROUP_E6(vect=112))
void Excep_GROUP_E6(void);

// vector 113 reserved

// GROUP L0
#pragma interrupt (Excep_GROUP_L0(vect=114))
void Excep_GROUP_L0(void);

// vector 115 reserved
// vector 116 reserved
// vector 117 reserved
// vector 118 reserved
// vector 119 reserved
// vector 120 reserved
// vector 121 reserved

// SCIX_SCIX0
#pragma interrupt (Excep_SCIX_SCIX0(vect=122))
void Excep_SCIX_SCIX0(void);

// SCIX_SCIX1
#pragma interrupt (Excep_SCIX_SCIX1(vect=123))
void Excep_SCIX_SCIX1(void);

// SCIX_SCIX2
#pragma interrupt (Excep_SCIX_SCIX2(vect=124))
void Excep_SCIX_SCIX2(void);

// SCIX_SCIX3
#pragma interrupt (Excep_SCIX_SCIX3(vect=125))
void Excep_SCIX_SCIX3(void);

// TPU0 TGIA0
#pragma interrupt (Excep_TPU0_TGIA0(vect=126))
void Excep_TPU0_TGIA0(void);

// TPU0 TGIB0
#pragma interrupt (Excep_TPU0_TGIB0(vect=127))
void Excep_TPU0_TGIB0(void);

// TPU0 TGIC0
#pragma interrupt (Excep_TPU0_TGIC0(vect=128))
void Excep_TPU0_TGIC0(void);

// TPU0 TGID0
#pragma interrupt (Excep_TPU0_TGID0(vect=129))
void Excep_TPU0_TGID0(void);

// TPU1 TGIA1
#pragma interrupt (Excep_TPU1_TGIA1(vect=130))
void Excep_TPU1_TGIA1(void);

// TPU1 TGIB1
#pragma interrupt (Excep_TPU1_TGIB1(vect=131))
void Excep_TPU1_TGIB1(void);

// TPU2 TGIA2
#pragma interrupt (Excep_TPU2_TGIA2(vect=132))
void Excep_TPU2_TGIA2(void);

// TPU2 TGIB2
#pragma interrupt (Excep_TPU2_TGIB2(vect=133))
void Excep_TPU2_TGIB2(void);

// TPU3 TGIA3
#pragma interrupt (Excep_TPU3_TGIA3(vect=134))
void Excep_TPU3_TGIA3(void);

// TPU3 TGIB3
#pragma interrupt (Excep_TPU3_TGIB3(vect=135))
void Excep_TPU3_TGIB3(void);

// TPU3 TGIC3
#pragma interrupt (Excep_TPU3_TGIC3(vect=136))
void Excep_TPU3_TGIC3(void);

// TPU3 TGID3
#pragma interrupt (Excep_TPU3_TGID3(vect=137))
void Excep_TPU3_TGID3(void);

// TPU4 TGIA4
#pragma interrupt (Excep_TPU4_TGIA4(vect=138))
void Excep_TPU4_TGIA4(void);

// TPU4 TGIB4
#pragma interrupt (Excep_TPU4_TGIB4(vect=139))
void Excep_TPU4_TGIB4(void);

// TPU5 TGIA15
#pragma interrupt (Excep_TPU5_TGIA5(vect=140))
void Excep_TPU5_TGIA5(void);

// TPU5 TGIB5
#pragma interrupt (Excep_TPU5_TGIB5(vect=141))
void Excep_TPU5_TGIB5(void);

// TPU6/MTU0 TGIA6/TGIA0
//#pragma interrupt (Excep_TPU6_TGIA6(vect=142))
//void Excep_TPU6_TGIA6(void);

// TPU6/MTU0 TGIB6/TGIB0
//#pragma interrupt (Excep_TPU6_TGIB6(vect=143))
//void Excep_TPU6_TGIB6(void);

// TPU6/MTU0 TGIC6/TGIC0
#pragma interrupt (Excep_TPU6_TGIC6(vect=144))
void Excep_TPU6_TGIC6(void);

// TPU6/MTU0 TGID6/TGID0
#pragma interrupt (Excep_TPU6_TGID6(vect=145))
void Excep_TPU6_TGID6(void);

// TPU6/MTU0 TGIE6/TGIE0
#pragma interrupt (Excep_TPU6_TGIE6(vect=146))
void Excep_TPU6_TGIE6(void);

// TPU6/MTU0 TGIF6/TGIF0
#pragma interrupt (Excep_TPU6_TGIF6(vect=147))
void Excep_TPU6_TGIF6(void);

// TPU7/MTU1 TGIA7/TGIA1
#pragma interrupt (Excep_TPU7_TGIA7(vect=148))
void Excep_TPU7_TGIA7(void);

// TPU7/MTU1 TGIB7/TGIB1
#pragma interrupt (Excep_TPU7_TGIB7(vect=149))
void Excep_TPU7_TGIB7(void);

// TPU8/MTU2 TGIA8/TGIA2
#pragma interrupt (Excep_TPU8_TGIA8(vect=150))
void Excep_TPU8_TGIA8(void);

// TPU8/MTU2 TGIB8/TGIB2
#pragma interrupt (Excep_TPU8_TGIB8(vect=151))
void Excep_TPU8_TGIB8(void);

// TPU9/MTU3 TGIA9/TGIA3
#pragma interrupt (Excep_TPU9_TGIA9(vect=152))
void Excep_TPU9_TGIA9(void);

// TPU9/MTU3 TGIB9/TGIB3
#pragma interrupt (Excep_TPU9_TGIB9(vect=153))
void Excep_TPU9_TGIB9(void);

// TPU9/MTU3 TGIC9/TGIC3
//#pragma interrupt (Excep_TPU9_TGIC9(vect=154))
//void Excep_TPU9_TGIC9(void);

// TPU9/MTU3 TGID9/TGID3
#pragma interrupt (Excep_TPU9_TGID9(vect=155))
void Excep_TPU9_TGID9(void);

// TPU10/MTU4 TGIA10/TGIA4
#pragma interrupt (Excep_TPU10_TGIA10(vect=156))
void Excep_TPU10_TGIA10(void);

// TPU10/MTU4 TGIB10/TGIB4
#pragma interrupt (Excep_TPU10_TGIB10(vect=157))
void Excep_TPU10_TGIB10(void);

// TPU10/MTU4 TGIC10/TGIC4
#pragma interrupt (Excep_TPU10_TGIC10(vect=158))
void Excep_TPU10_TGIC10(void);

// TPU10/MTU4 TGID10/TGID4
#pragma interrupt (Excep_TPU10_TGID10(vect=159))
void Excep_TPU10_TGID10(void);

// TPU10/MTU4 TGIV10/TGIV4
#pragma interrupt (Excep_TPU10_TGIV10(vect=160))
void Excep_TPU10_TGIV10(void);

// MTU5 TGIU5
#pragma interrupt (Excep_MTU5_TGIU5(vect=161))
void Excep_MTU5_TGIU5(void);

// MTU5 TGIV5
#pragma interrupt (Excep_MTU5_TGIV5(vect=162))
void Excep_MTU5_TGIV5(void);

// MTU5 TGIW5
#pragma interrupt (Excep_MTU5_TGIW5(vect=163))
void Excep_MTU5_TGIW5(void);

// TPU11 TGIA11
#pragma interrupt (Excep_TPU11_TGIA11(vect=164))
void Excep_TPU11_TGIA11(void);

// TPU11 TGIB11
#pragma interrupt (Excep_TPU11_TGIB11(vect=165))
void Excep_TPU11_TGIB11(void);

// POE2 OEI1
#pragma interrupt (Excep_POE2_OEI1(vect=166))
void Excep_POE2_OEI1(void);

// POE2 OEI2
#pragma interrupt (Excep_POE2_OEI2(vect=167))
void Excep_POE2_OEI2(void);

// vector 168 reserved
// vector 169 reserved

// TMR0_CMIA0
#pragma interrupt (Excep_TMR0_CMIA0(vect=170))
void Excep_TMR0_CMIA0(void);

// TMR0_CMIB0
#pragma interrupt (Excep_TMR0_CMIB0(vect=171))
void Excep_TMR0_CMIB0(void);

// TMR0_OVI0
#pragma interrupt (Excep_TMR0_OVI0(vect=172))
void Excep_TMR0_OVI0(void);

// TMR1_CMIA1
#pragma interrupt (Excep_TMR1_CMIA1(vect=173))
void Excep_TMR1_CMIA1(void);

// TMR1_CMIB1
#pragma interrupt (Excep_TMR1_CMIB1(vect=174))
void Excep_TMR1_CMIB1(void);

// TMR1_OVI1
#pragma interrupt (Excep_TMR1_OVI1(vect=175))
void Excep_TMR1_OVI1(void);

// TMR2_CMIA2
#pragma interrupt (Excep_TMR2_CMIA2(vect=176))
void Excep_TMR2_CMIA2(void);

// TMR2_CMIB2
#pragma interrupt (Excep_TMR2_CMIB2(vect=177))
void Excep_TMR2_CMIB2(void);

// TMR2_OVI2
#pragma interrupt (Excep_TMR2_OVI2(vect=178))
void Excep_TMR2_OVI2(void);

// TMR3_CMIA3
#pragma interrupt (Excep_TMR3_CMIA3(vect=179))
void Excep_TMR3_CMIA3(void);

// TMR3_CMIB3
#pragma interrupt (Excep_TMR3_CMIB3(vect=180))
void Excep_TMR3_CMIB3(void);

// TMR3_OVI3
#pragma interrupt (Excep_TMR3_OVI3(vect=181))
void Excep_TMR3_OVI3(void);

// RIIC0 EEI0
#pragma interrupt (Excep_RIIC0_EEI0(vect=182))
void Excep_RIIC0_EEI0(void);

// RIIC0 RXI0
#pragma interrupt (Excep_RIIC0_RXI0(vect=183))
void Excep_RIIC0_RXI0(void);

// RIIC0 TXI0
#pragma interrupt (Excep_RIIC0_TXI0(vect=184))
void Excep_RIIC0_TXI0(void);

// RIIC0 TEI0
#pragma interrupt (Excep_RIIC0_TEI0(vect=185))
void Excep_RIIC0_TEI0(void);

// RIIC1 EEI0
#pragma interrupt (Excep_RIIC1_EEI0(vect=186))
void Excep_RIIC1_EEI0(void);

// RIIC1 RXI0
#pragma interrupt (Excep_RIIC1_RXI0(vect=187))
void Excep_RIIC1_RXI0(void);

// RIIC1 TXI0
#pragma interrupt (Excep_RIIC1_TXI0(vect=188))
void Excep_RIIC1_TXI0(void);

// RIIC1 TEI0
#pragma interrupt (Excep_RIIC1_TEI0(vect=189))
void Excep_RIIC1_TEI0(void);

// RIIC2 EEI0
#pragma interrupt (Excep_RIIC2_EEI0(vect=190))
void Excep_RIIC2_EEI0(void);

// RIIC2 RXI0
#pragma interrupt (Excep_RIIC2_RXI0(vect=191))
void Excep_RIIC2_RXI0(void);

// RIIC2 TXI0
#pragma interrupt (Excep_RIIC2_TXI0(vect=192))
void Excep_RIIC2_TXI0(void);

// RIIC2 TEI0
#pragma interrupt (Excep_RIIC2_TEI0(vect=193))
void Excep_RIIC2_TEI0(void);

// RIIC3 EEI0
#pragma interrupt (Excep_RIIC3_EEI0(vect=194))
void Excep_RIIC3_EEI0(void);

// RIIC3 RXI0
#pragma interrupt (Excep_RIIC3_RXI0(vect=195))
void Excep_RIIC3_RXI0(void);

// RIIC3 TXI0
#pragma interrupt (Excep_RIIC3_TXI0(vect=196))
void Excep_RIIC3_TXI0(void);

// RIIC3 TEI0
#pragma interrupt (Excep_RIIC3_TEI0(vect=197))
void Excep_RIIC3_TEI0(void);

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

// SCI0_RXI0
#pragma interrupt (Excep_SCI0_RXI0(vect=214))
void Excep_SCI0_RXI0(void);

// SCI0_TXI0
#pragma interrupt (Excep_SCI0_TXI0(vect=215))
void Excep_SCI0_TXI0(void);

// SCI0_TEI0
#pragma interrupt (Excep_SCI0_TEI0(vect=216))
void Excep_SCI0_TEI0(void);

// SCI1_RXI1
#pragma interrupt (Excep_SCI1_RXI1(vect=217))
void Excep_SCI1_RXI1(void);

// SCI1_TXI1
#pragma interrupt (Excep_SCI1_TXI1(vect=218))
void Excep_SCI1_TXI1(void);

// SCI1_TEI1
#pragma interrupt (Excep_SCI1_TEI1(vect=219))
void Excep_SCI1_TEI1(void);

// SCI2_RXI2
#pragma interrupt (Excep_SCI2_RXI2(vect=220))
void Excep_SCI2_RXI2(void);

// SCI2_TXI2
#pragma interrupt (Excep_SCI2_TXI2(vect=221))
void Excep_SCI2_TXI2(void);

// SCI2_TEI2
#pragma interrupt (Excep_SCI2_TEI2(vect=222))
void Excep_SCI2_TEI2(void);

// SCI3_RXI3
#pragma interrupt (Excep_SCI3_RXI3(vect=223))
void Excep_SCI3_RXI3(void);

// SCI3_TXI3
#pragma interrupt (Excep_SCI3_TXI3(vect=224))
void Excep_SCI3_TXI3(void);

// SCI3_TEI3
#pragma interrupt (Excep_SCI3_TEI3(vect=225))
void Excep_SCI3_TEI3(void);

// SCI4_RXI4
#pragma interrupt (Excep_SCI4_RXI4(vect=226))
void Excep_SCI4_RXI4(void);

// SCI4_TXI4
#pragma interrupt (Excep_SCI4_TXI4(vect=227))
void Excep_SCI4_TXI4(void);

// SCI4_TEI4
#pragma interrupt (Excep_SCI4_TEI4(vect=228))
void Excep_SCI4_TEI4(void);

// SCI5_RXI5
#pragma interrupt (Excep_SCI5_RXI5(vect=229))
void Excep_SCI5_RXI5(void);

// SCI5_TXI5
#pragma interrupt (Excep_SCI5_TXI5(vect=230))
void Excep_SCI5_TXI5(void);

// SCI5_TEI5
#pragma interrupt (Excep_SCI5_TEI5(vect=231))
void Excep_SCI5_TEI5(void);

// SCI6_RXI6
#pragma interrupt (Excep_SCI6_RXI6(vect=232))
void Excep_SCI6_RXI6(void);

// SCI6_TXI6
#pragma interrupt (Excep_SCI6_TXI6(vect=233))
void Excep_SCI6_TXI6(void);

// SCI6_TEI6
#pragma interrupt (Excep_SCI6_TEI6(vect=234))
void Excep_SCI6_TEI6(void);

// SCI7_RXI7
#pragma interrupt (Excep_SCI7_RXI7(vect=235))
void Excep_SCI7_RXI7(void);

// SCI7_TXI7
#pragma interrupt (Excep_SCI7_TXI7(vect=236))
void Excep_SCI7_TXI7(void);

// SCI7_TEI7
#pragma interrupt (Excep_SCI7_TEI7(vect=237))
void Excep_SCI7_TEI7(void);

// SCI8_RXI8
#pragma interrupt (Excep_SCI8_RXI8(vect=238))
void Excep_SCI8_RXI8(void);

// SCI8_TXI8
#pragma interrupt (Excep_SCI8_TXI8(vect=239))
void Excep_SCI8_TXI8(void);

// SCI8_TEI8
#pragma interrupt (Excep_SCI8_TEI8(vect=240))
void Excep_SCI8_TEI8(void);

// SCI9_RXI9
#pragma interrupt (Excep_SCI9_RXI9(vect=241))
void Excep_SCI9_RXI9(void);

// SCI9_TXI9
#pragma interrupt (Excep_SCI9_TXI9(vect=242))
void Excep_SCI9_TXI9(void);

// SCI9_TEI9
#pragma interrupt (Excep_SCI9_TEI9(vect=243))
void Excep_SCI9_TEI9(void);

// SCI10_RXI10
#pragma interrupt (Excep_SCI10_RXI10(vect=244))
void Excep_SCI10_RXI10(void);

// SCI10_TXI10
#pragma interrupt (Excep_SCI10_TXI10(vect=245))
void Excep_SCI10_TXI10(void);

// SCI10_TEI10
#pragma interrupt (Excep_SCI10_TEI10(vect=246))
void Excep_SCI10_TEI10(void);

// SCI11_RXI11
#pragma interrupt (Excep_SCI11_RXI11(vect=247))
void Excep_SCI11_RXI11(void);

// SCI11_TXI11
#pragma interrupt (Excep_SCI11_TXI11(vect=248))
void Excep_SCI11_TXI11(void);

// SCI11_TEI11
#pragma interrupt (Excep_SCI11_TEI11(vect=249))
void Excep_SCI11_TEI11(void);

// SCI12_RXI12
#pragma interrupt (Excep_SCI12_RXI12(vect=250))
void Excep_SCI12_RXI12(void);

// SCI12_TXI12
#pragma interrupt (Excep_SCI12_TXI12(vect=251))
void Excep_SCI12_TXI12(void);

// SCI12_TEI12
#pragma interrupt (Excep_SCI12_TEI12(vect=252))
void Excep_SCI12_TEI12(void);

// IEBUS IEBINT
#pragma interrupt (Excep_IEBUS_IEBINT(vect=253))
void Excep_IEBUS_IEBINT(void);

// vector 254 reserved
// vector 255 reserved

//;<<VECTOR DATA START (POWER ON RESET)>>
//;Power On Reset PC
extern void PowerON_Reset_PC(void);                                                                                                                
//;<<VECTOR DATA END (POWER ON RESET)>>

