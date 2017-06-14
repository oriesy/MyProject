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
//  Header: pxa320_clkmgr.h
//
//  Defines the clock/timer register layout and associated types and constants.
//
#ifndef __PXA320_CLKMGR_H
#define __PXA320_CLKMGR_H

#if __cplusplus
extern "C" {
#endif

//------------------------------------------------------------------------------
//
//  Type:  PXA320_CLKMGR_REG
//
//  Defines the clock/timer control register layout.
//

#include <xllp_clkmgr.h>

typedef XLLP_CLKMGR_T PXA320_CLKMGR_REG;
typedef XLLP_CLKMGR_T *PPXA320_CLKMGR_REG;

//------------------------------------------------------------------------------

#if __cplusplus
}
#endif

#endif 
