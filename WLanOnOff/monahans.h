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
//  Header: monahans.h
//
//  This header file defines the Intel Monahans processor.
//
//  The Monahans is a System on Chip (SoC) part consisting of an ARMv5TE compliant core. 
//  This header file is comprised of component header files that define the 
//  register layout of each component.
//  
//------------------------------------------------------------------------------
#ifndef _MONAHANS_H_
#define _MONAHANS_H_

#if __cplusplus
extern "C" {
#endif

//------------------------------------------------------------------------------

// Base Definitions
//
#define MFPRMDB_SHARED_FILENAME TEXT("MFPRMDB_SHARED_FILE")

#include "monahans_base_regs.h"

// SoC Components
//
#include "monahans_ac97.h"
#include "monahans_clkmgr.h"
#include "monahans_dma.h"
#include "monahans_gpio.h"
#include "monahans_intr.h"
#include "monahans_keypad.h"
#include "monahans_mmc.h"
#include "monahans_ost.h"
#include "monahans_rtc.h"
#include "monahans_uart.h"
#include "monahans_rtc.h"

//------------------------------------------------------------------------------

#if __cplusplus
}
#endif



#endif 
