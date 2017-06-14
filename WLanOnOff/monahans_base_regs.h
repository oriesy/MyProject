//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
//
// Use of this sample source code is subject to the terms of the Microsoft
// license agreement under which you licensed this sample source code. If
// you did not accept the terms of the license agreement, you are not
// authorized to use this sample source code. For the terms of the license,
// please see the license agreement between you and Microsoft or, if applicable,
// see the LICENSE.RTF on your install media or the root of your tools installation.
// THE SAMPLE SOURCE CODE IS PROVIDED "AS IS", WITH NO WARRANTIES OR INDEMNITIES.
//
//
// (C) Copyright 2006 Marvell International Ltd.
// All Rights Reserved
//
//------------------------------------------------------------------------------
//
//  File:  monahans_base_regs.h
//
//  Intel Monahans register and physical address definitions.
//
#ifndef _monahans_base_regs_h_
#define _monahans_base_regs_h_

////////////////////////////////////////////////////
/* DEVICE BASE ADDRESSES GROUPED BY FUNCTIONALITY */
////////////////////////////////////////////////////

//
// Internal Memory - Storage (768 KB)
//
#define MONAHANS_BASE_REG_PA_IMSTORAGE  0x5C000000

//
// Internal Memory - Control (12 B)
//
#define MONAHANS_BASE_REG_PA_IMCONTROL  0x58000000

//
// Camera Peripheral
//
#define MONAHANS_BASE_REG_PA_CAMERA     0x50000000

//
// USB 1.0 Host
//
#define MONAHANS_BASE_REG_PA_USBH       0x4C000000

//
// USB 2.0 Host
//
#define MONAHANS_BASE_REG_PA_USB2H			    0x54100000
    
//
//  Dynamic MEMC (DMC)
//;
#define MONAHANS_BASE_REG_PA_DMEMC              0x48100000

//
//  Static MEMC (SMC)
//
#define MONAHANS_BASE_REG_PA_SMEMC              0x4A000000

//
//  Data Flash Controller (DFC)
//
#define MONAHANS_BASE_REG_PA_DFC                0x43100000

//
// LCDC
//
#define MONAHANS_BASE_REG_PA_LCD        0x44000000

//
// 2D Graphics
//
#define MONAHANS_BASE_REG_PA_2D			0x54000000

//
// Peripheral registers base 
//
#define MONAHANS_BASE_REG_PA_PERIPH     0x40000000

//
// Mini LCD
//
#define MONAHANS_BASE_REG_PA_MLCD		0x46000000

//
// Px 1 and 2 Arbiters
//
#define MONAHANS_BASE_REG_PA_PXARB	    0x4600FE00

//
// ASSP PMU.  Can be mapped to core PMU events 0x80-0x87
//
#define MONAHANS_BASE_REG_PA_ASSPPMU	0x4600FF00

//
// Caddo Module
//
#define MONAHANS_BASE_REG_PA_CADDO		0x43000000

//
// PCMCIA Slot
//
#define MONAHANS_BASE_REG_PA_PCMCIA_IO       0x20000000
#define MONAHANS_BASE_REG_PA_PCMCIA_ATTR     0x28000000
#define MONAHANS_BASE_REG_PA_PCMCIA_CMN      0x2C000000

//
// TrueIDE Hard driver (VLIO)
//
#define MONAHANS_BASE_REG_PA_HD_CTL			0x14080000
#define MONAHANS_BASE_REG_PA_HD_TASKFILE	0x14100000
#define MONAHANS_BASE_REG_PA_HD_DMA		0x14180000
#define MONAHANS_BASE_REG_PA_HD_SWITCH		0x14200004





/////////////////////////////////////////////////////////////////////////////////////////
/* PERIPHERAL OFFSETS */
/////////////////////////////////////////////////////////////////////////////////////////

#define DMAC_OFFSET                     0x0             // DMA CONTROLLER
#define FFUART_OFFSET                   0x00100000      // Full-Feature UART
#define BTUART_OFFSET                   0x00200000      // BlueTooth UART
#define I2C_OFFSET                      0x00300000      // I2C
#define AC97_OFFSET                     0x00500000      // AC97
#define UDC_OFFSET                      0x00600000      // UDC (usb client)
#define SIRUART_OFFSET                  0x00700000      // SIR UART
#define RTC_OFFSET                      0x00900000      // real time clock
#define OST_OFFSET                      0x00A00000      // OS Timer
#define PWM0_2_OFFSET                   0x00B00000      // PWM 0 (pulse-width mod)
#define PWM1_3_OFFSET                   0x00C00000      // PWM 1 (pulse-width mod)
#define INTC_OFFSET                     0x00D00000      // Interrupt controller
#define GPIO_OFFSET                     0x00E00000      // GPIO
#define MFP_OFFSET                      0x00E10000
#define PWR_OFFSET                      0x00F00000      // Power Manager and Reset Control
#define BPMU_OFFSET                     0x00F40000      // BPMU (Slave PMU)
#define SPMU_OFFSET                     0x00F50000      // SPMU (Services PMU)
#define SSP1_OFFSET                     0x01000000      // SSP 1
#define MMC_OFFSET                      0x01100000      // MMC
#define MONAHANS_CLKMGR_OFFSET          0x01340000      // Clock Manager
#define OSCC_OFFSET               0x01350000      // Oscillator Configuration Register  (OSCC)   
#define BB_OFFSET                       0x01400000      // Baseband Interface
#define KEYPAD_OFFSET                   0x01500000      // Keypad Interface
#define USIM_OFFSET                     0x01600000      // USIM
#define SSP2_OFFSET                     0x01700000      // SSP 2
#define SSP3_OFFSET                     0x01900000      // SSP 3
#define SSP4_OFFSET			            0x01A00000	    // SSP 4
#define ONEWIRE_OFFSET			        0x01B00000	    // 1-wire
#define TSI_OFFSET			            0x01C00000	    // Touch Screen Interface/ADC
#define CIR_OFFSET			            0x01D00000	    // Consumer IR
#define MMC2_OFFSET			            0x02000000	    // MMC 2
#define USIM2_OFFSET			        0x02100000	    // USIM 2

/////////////////////////////////////////////////////////////////////////////////////////
/* DEVICE-SPECIFIC ADDRESS DEFINITIONS */
/////////////////////////////////////////////////////////////////////////////////////////

#define MONAHANS_BASE_REG_PA_DMAC       (MONAHANS_BASE_REG_PA_PERIPH + DMAC_OFFSET)
#define MONAHANS_BASE_REG_PA_FFUART     (MONAHANS_BASE_REG_PA_PERIPH + FFUART_OFFSET)
#define MONAHANS_BASE_REG_PA_BTUART     (MONAHANS_BASE_REG_PA_PERIPH + BTUART_OFFSET)
#define MONAHANS_BASE_REG_PA_I2C        (MONAHANS_BASE_REG_PA_PERIPH + I2C_OFFSET)
#define MONAHANS_BASE_REG_PA_AC97       (MONAHANS_BASE_REG_PA_PERIPH + AC97_OFFSET)
#define MONAHANS_BASE_REG_PA_UDC        (MONAHANS_BASE_REG_PA_PERIPH + UDC_OFFSET)
#define MONAHANS_BASE_REG_PA_SIRUART    (MONAHANS_BASE_REG_PA_PERIPH + SIRUART_OFFSET)
#define MONAHANS_BASE_REG_PA_RTC        (MONAHANS_BASE_REG_PA_PERIPH + RTC_OFFSET)
#define MONAHANS_BASE_REG_PA_OST        (MONAHANS_BASE_REG_PA_PERIPH + OST_OFFSET)
#define MONAHANS_BASE_REG_PA_PWM0_2     (MONAHANS_BASE_REG_PA_PERIPH + PWM0_2_OFFSET)
#define MONAHANS_BASE_REG_PA_PWM1_3     (MONAHANS_BASE_REG_PA_PERIPH + PWM1_3_OFFSET)
#define MONAHANS_BASE_REG_PA_INTC       (MONAHANS_BASE_REG_PA_PERIPH + INTC_OFFSET)
#define MONAHANS_BASE_REG_PA_GPIO       (MONAHANS_BASE_REG_PA_PERIPH + GPIO_OFFSET)
#define MONAHANS_BASE_REG_PA_PWR        (MONAHANS_BASE_REG_PA_PERIPH + PWR_OFFSET)
#define MONAHANS_BASE_REG_PA_SSP1       (MONAHANS_BASE_REG_PA_PERIPH + SSP1_OFFSET)
#define MONAHANS_BASE_REG_PA_MMC        (MONAHANS_BASE_REG_PA_PERIPH + MMC_OFFSET)
#define MONAHANS_BASE_REG_PA_CLKMGR     (MONAHANS_BASE_REG_PA_PERIPH + MONAHANS_CLKMGR_OFFSET)
#define MONAHANS_BASE_REG_PA_OSCC       (MONAHANS_BASE_REG_PA_PERIPH + OSCC_OFFSET)
#define MONAHANS_BASE_REG_PA_BB         (MONAHANS_BASE_REG_PA_PERIPH + BB_OFFSET)
#define MONAHANS_BASE_REG_PA_KEYPAD     (MONAHANS_BASE_REG_PA_PERIPH + KEYPAD_OFFSET)
#define MONAHANS_BASE_REG_PA_USIM       (MONAHANS_BASE_REG_PA_PERIPH + USIM_OFFSET)
#define MONAHANS_BASE_REG_PA_SSP2       (MONAHANS_BASE_REG_PA_PERIPH + SSP2_OFFSET)
#define MONAHANS_BASE_REG_PA_SSP3       (MONAHANS_BASE_REG_PA_PERIPH + SSP3_OFFSET)
#define MONAHANS_BASE_REG_PA_SSP4       (MONAHANS_BASE_REG_PA_PERIPH + SSP4_OFFSET)
#define MONAHANS_BASE_REG_PA_ONEWIRE    (MONAHANS_BASE_REG_PA_PERIPH + ONEWIRE_OFFSET)
#define MONAHANS_BASE_REG_PA_TSI        (MONAHANS_BASE_REG_PA_PERIPH + TSI_OFFSET)
#define MONAHANS_BASE_REG_PA_CIR        (MONAHANS_BASE_REG_PA_PERIPH + CIR_OFFSET)
#define MONAHANS_BASE_REG_PA_MMC2       (MONAHANS_BASE_REG_PA_PERIPH + MMC2_OFFSET)
#define MONAHANS_BASE_REG_PA_USIM2      (MONAHANS_BASE_REG_PA_PERIPH + USIM2_OFFSET)
#define MONAHANS_BASE_REG_PA_BPMU       (MONAHANS_BASE_REG_PA_PERIPH + BPMU_OFFSET)
#define MONAHANS_BASE_REG_PA_SPMU       (MONAHANS_BASE_REG_PA_PERIPH + SPMU_OFFSET)
#define MONAHANS_BASE_REG_PA_MFP        (MONAHANS_BASE_REG_PA_PERIPH + MFP_OFFSET)


#endif  // _MONAHANS_base_regs_h_.

