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

/******************************************************************************
**
** INTEL CONFIDENTIAL
** Copyright 2000-2005 Intel Corporation All Rights Reserved.
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
**
**
**  FILENAME: ipm_api.h
**
**  PURPOSE: Header file for IPM API
**
******************************************************************************/

#pragma once

#include "ipm_defs.h"

#ifdef __cplusplus
extern "C"{
#endif 

    //Please refer to IPM LLD for detailed description of this API
    IPM_STATUS_T IPM_Service_Register(LPCTSTR szClientName,CLIENT_ID* pClientID, PIPM_REGISTER_HANDLE_EXCHANGE pExchange, HANDLE hCallerProcess, DWORD dwTimeout);
    IPM_STATUS_T IPM_Register(LPCTSTR szClientName,CLIENT_ID* pClientID,DWORD dwTimeout);
    //A-Sync version of registration 
    IPM_STATUS_T IPM_RegisterEx(LPCTSTR szClientName,IPM_CLIENT_TYPE clientType,IPM_CALLBACK_FUNC pCallback,DWORD dwTimeout);


    IPM_STATUS_T IPM_DeRegister(CLIENT_ID clientID,DWORD dwTimeout);

    IPM_STATUS_T IPM_SetFreqChangeBlock(CLIENT_ID clientID,DWORD dwTimeout);
    IPM_STATUS_T IPM_ReleaseFreqChangeBlock(CLIENT_ID clientID,DWORD dwTimeout);

    IPM_STATUS_T IPM_SetMinOp(CLIENT_ID clientID,IPM_PRODUCT_OP op,DWORD dwTimeout);
    IPM_STATUS_T IPM_ReleaseMinOp(CLIENT_ID clientID,DWORD dwTimeout);


    IPM_STATUS_T IPM_NotifyReadyForProcState(CLIENT_ID clientID,DWORD dwProcState,DWORD dwTimeout);

    BOOL         IPM_IsRunning();


#ifdef __cplusplus
}
#endif 



