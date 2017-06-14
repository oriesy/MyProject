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
/** FILENAME:	xllp_pm.h
**
** PURPOSE:	contain register definition for Service Power Manager and 
**		Boerne Power Manager registers.
**
******************************************************************************/

#ifndef __XLLP_PM_H
#define __XLLP_PM_H

#include "xllp_defs.h"

/* XLLP PM registers definition*/
typedef struct {
	XLLP_VUINT32_T pmcr;
	XLLP_VUINT32_T psr;
	XLLP_VUINT32_T pspr;
	XLLP_VUINT32_T pcfr;
	XLLP_VUINT32_T pwer;
	XLLP_VUINT32_T pwsr;
	XLLP_VUINT32_T pecr;
	XLLP_VUINT32_T reserved1[25];
	XLLP_VUINT32_T dcsr;
	XLLP_VUINT32_T jconr;
	XLLP_VUINT32_T reserved2[30];
	XLLP_VUINT32_T pvcr;
}XLLP_PM_SPMU_T, *P_XLLP_PM_SPMU_T;

typedef struct {
	XLLP_VUINT32_T ascr;
	XLLP_VUINT32_T arsr;
	XLLP_VUINT32_T ad3er;
	XLLP_VUINT32_T ad3sr;
	XLLP_VUINT32_T ad2d0er;
	XLLP_VUINT32_T ad2d0sr;
	XLLP_VUINT32_T ad2d1er;
	XLLP_VUINT32_T ad2d1sr;
	XLLP_VUINT32_T ad1d0er;
	XLLP_VUINT32_T ad1d0sr;
	XLLP_VUINT32_T reserved[2];
	XLLP_VUINT32_T ad3r;
	XLLP_VUINT32_T ad2r;
	XLLP_VUINT32_T ad1r;
}XLLP_PM_BPMU_T, *P_XLLP_PM_BPMU_T;

#define XLLP_ARSR_HWR   (0x1 << 0)
#define XLLP_ARSR_WDT   (0x1 << 1)
#define XLLP_ARSR_LPMR  (0x1 << 2)
#define XLLP_ARSR_GPR   (0x1 << 3)
//
// D1/D2
#define XLLP_ADxD0_EXTERN0  (0x1 << 0)
#define XLLP_ADxD0_EXTERN1  (0x1 << 1)
#define XLLP_ADxD0_GENERIC_0      (0x1 << 2)
#define XLLP_ADxD0_GENERIC_1      (0x1 << 3)
#define XLLP_ADxD0_GENERIC_2      (0x1 << 4)
#define XLLP_ADxD0_GENERIC_3      (0x1 << 5)
#define XLLP_ADxD0_GENERIC_4      (0x1 << 6)
#define XLLP_ADxD0_GENERIC_5      (0x1 << 7)
#define XLLP_ADxD0_GENERIC_6      (0x1 << 8)  // kp_mkin
#define XLLP_ADxD0_GENERIC_7      (0x1 << 9)
#define XLLP_ADxD0_GENERIC_8      (0x1 << 10)
#define XLLP_ADxD0_GENERIC_9      (0x1 << 11)
#define XLLP_ADxD0_GENERIC_10     (0x1 << 12)
#define XLLP_ADxD0_GENERIC_11     (0x1 << 13)
#define XLLP_ADxD0_GENERIC_12     (0x1 << 14)
#define XLLP_ADxD0_GENERIC_13     (0x1 << 15)
#define XLLP_ADxD0_OTG      (0x1 << 16)
#define XLLP_ADxD0_USIM0    (0x1 << 19)
#define XLLP_ADxD0_USIM1    (0x1 << 20)
#define XLLP_ADxD0_KP       (0x1 << 21)     //D2 to D0 Wakeup for direct Keypad
//#define XLLP_AD2D0_KP       (0x1 << 21)     //D2 to D0 Wakeup for direct Keypad : synonym for keypad driver until i can repair my corrupted view!
#define XLLP_ADxD0_EDMUX2   (0x1 << 22)
#define XLLP_ADxD0_EDMUX3   (0x1 << 23)
#define XLLP_ADxD0_MSL0     (0x1 << 24)
#define XLLP_ADxD0_USB2     (0x1 << 26)
#define XLLP_ADxD0_USBH     (0x1 << 28)
#define XLLP_ADxD0_TSI      (0x1 << 29)
#define XLLP_ADxD0_OST      (0x1 << 30)
#define XLLP_ADxD0_RTC      (0x1 << 31)





#define XLLP_PVCR_FVE	(0x1 << 31)
#define XLLP_PVCR_PVE	(0x1 << 30)
#define XLLP_PVCR_TVE	(0x1 << 29)

#define XLLP_ASCR_MTS(n)	((n) << 12)
#define XLLP_ASCR_MTS_MASK	(0x7 << 12)

#endif
