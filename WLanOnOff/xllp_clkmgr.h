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
/* 
** INTEL CONFIDENTIAL
** Copyright 2000-2006 Intel Corporation All Rights Reserved.
**
** The source code contained or described herein and all documents
** related to the source code (Material) are owned by Intel Corporation
** or its suppliers or licensors.  Title to the Material remains with
** Intel Corporation or its suppliers and licensors. The Material contains
** trade secrets and proprietary and confidential information of Intel
** or its suppliers and licensors. The Material is protected by worldwide
** copyright and trade secret laws and treaty provisions. No part of the
** Material may be used, copied, reproduced, modified, published, uploaded,
** posted, transmitted, distributed, or disclosed in any way without Intel’s
** prior express written permission.
**
** No license under any patent, copyright, trade secret or other intellectual
** property right is granted to or conferred upon you by disclosure or
** delivery of the Materials, either expressly, by implication, inducement,
** estoppel or otherwise. Any license under such intellectual property rights
** must be express and approved by Intel in writing.
*/
#ifndef __XLLP_CLKMGR_H__
#define __XLLP_CLKMGR_H__

/**
**  FILENAME:   xllp_clkmgr.h
**
**  PURPOSE:    contains all XLLP CLKMGR typedefs and bit definitions..
**              Valid for processor codenamed PXA320, stepping B0
**
******************************************************************************/

#include "xllp_defs.h"

//
// Current to PXA320 EAS 3.0
//


/// Clock Manager (CLKMGR) Register Bank
typedef struct
{
    XLLP_VUINT32_T    accr;         	///< Application Subsystem Clock Configure register
    XLLP_VUINT32_T    acsr;         	///< Application Subsystem Clock Status register
    XLLP_VUINT32_T    aicsr;         	///< Application Subsystem interrupt Control/Status register
    XLLP_VUINT32_T    d0cken_a;        	///< D0 Mode Clock Enable register A
	XLLP_VUINT32_T	  d0cken_b;			///< D0 Mode Clock Enable register B
	XLLP_VUINT32_T	  ac97_div;			///< AC97 clock divisor value register

 } XLLP_CLKMGR_T, *P_XLLP_CLKMGR_T;  


/// Clock Enable Register (CLKEN) Enum
typedef enum
{
	XLLP_CLK_LCD = 1, 		///< LCD Clock Enable
	XLLP_CLK_USBH,			///< USB host clock enable
	XLLP_CLK_CAMERA,		///< Camera interface clock enable
	XLLP_CLK_NAND,			///< NAND Flash Controller Clock Enable
	XLLP_CLK_USB2=6,		///< USB 2.0 client clock enable.
	XLLP_CLK_GRAPHICS,		///< Graphics controller clock enable
	XLLP_CLK_DMC,			///< Dynamic Memory Controller clock enable
	XLLP_CLK_SMC,			///< Static Memory Controller clock enable
	XLLP_CLK_ISC,			///< Internal SRAM Controller clock enable
	XLLP_CLK_BOOT,			///< Boot rom clock enable
	XLLP_CLK_MMC0,			///< MMC0 Clock enable
	XLLP_CLK_MMC1,			///< MMC1 clock enable
	XLLP_CLK_KEYPAD,			///< Keypand Controller Clock Enable
	XLLP_CLK_CIR,			///< Consumer IR Clock Enable
	XLLP_CLK_USIM0=17,		///< USIM[0] Clock Enable
	XLLP_CLK_USIM1,			///< USIM[1] Clock Enable
	XLLP_CLK_TPM,			///< TPM clock enable
	XLLP_CLK_UDC,			///< UDC clock enable
	XLLP_CLK_BTUART,		///< BTUART clock enable
	XLLP_CLK_FFUART,		///< FFUART clock enable
	XLLP_CLK_STUART,		///< STUART clock enable
	XLLP_CLK_AC97,			///< AC97 clock enable
	XLLP_CLK_TOUCH,			///< Touch screen Interface Clock Enable
	XLLP_CLK_SSP1,			///< SSP1 clock enable
	XLLP_CLK_SSP2,			///< SSP2 clock enable
	XLLP_CLK_SSP3,			///< SSP3 clock enable
	XLLP_CLK_SSP4,			///< SSP4 clock enable
	XLLP_CLK_MSL0,			///< MSL0 clock enable

	XLLP_CLK_PWM0=32,		///< PWM[0] clock enable
	XLLP_CLK_PWM1,			///< PWM[1] clock enable
	XLLP_CLK_I2C=32+4,		///< I2C clock enable
	XLLP_CLK_INTC=32+6,		///< Interrupt controller clock enable
	XLLP_CLK_GPIO,			///< GPIO clock enable
	XLLP_CLK_1WIRE,			///< 1-wire clock enable
	XLLP_CLK_MINI_IM=32+16,	///< Mini-IM
	XLLP_CLK_MINI_LCD		///< Mini LCD

} XLLP_CLK_MODULE;



//
// Application Subsystem clock configuration register(ACCR) Bits
//


#define XLLP_ACCR_XPDIS			(0x1u << 31)	
#define XLLP_ACCR_SPDIS			(0x1u << 30)	
#define XLLP_ACCR_13MEND1		(0x1u << 27)
#define XLLP_ACCR_D0CS			(0x1u << 26)
#define XLLP_ACCR_13MEND2		(0x1u << 21)
#define XLLP_ACCR_PCCE			(0x1u << 11)


//Application Subsystem Clock Status Register (ACSR)
#define XLLP_ACSR_XPDIS_S		(0x1u << 31)
#define XLLP_ACSR_SPDIS_S		(0x1u << 30)
#define XLLP_ACSR_XPLCK			(0x1u << 29)
#define XLLP_ACSR_SPLCK			(0x1u << 28)
#define XLLP_ACSR_RO_S			(0x1u << 26)


//Application Subsystem Interrupt Control/Status Register(AICSR)
#define XLLP_AICSR_PCIS			(0x1u << 5)
#define XLLP_AICSR_PCIE			(0x1u << 4)
#define XLLP_AICSR_TCIS			(0x1u << 3)
#define XLLP_AICSR_TCIE			(0x1u << 2)
#define XLLP_AICSR_FCIS			(0x1u << 1)
#define XLLP_AICSR_FCIE			(0x1u << 0)

// Oscillator Configuration Register  (OSCC)  
#define XLLP_OSCC_PEN           (0x1u<<11)      // CLK_POUT
#define XLLP_OSCC_TENS0         (0x1u<<8)       // CLK_TOUT S0 Enable Register


#ifdef __cplusplus
extern "C"
{
#endif

/**
	This routine reads the designated CLKCFG register via CoProcessor 14 

@return				CLKCFG register value
*/
extern unsigned int XllpReadClkCfg(void);
/**
	This routine Writes the designated CLKCFG register via CoProcessor 14 

@param	  aValue	Value to write to CLKCFG register
			
*/
extern void XllpWriteClkCfg( unsigned int aValue);

extern XLLP_BOOL_T XllpClockEnable(P_XLLP_CLKMGR_T  pReg, XLLP_CLK_MODULE module, XLLP_BOOL_T enable);
extern XLLP_STATUS_T XllpClockSave(P_XLLP_CLKMGR_T  pVirtualAddress, P_XLLP_CLKMGR_T pSaveBuff);
extern XLLP_STATUS_T XllpClockRestore(P_XLLP_CLKMGR_T  pVirtualAddress, P_XLLP_CLKMGR_T pSaveBuff);

#ifdef __cplusplus
}

#endif


#endif