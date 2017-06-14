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
#include <windows.h>

// should use ZONES in future
#define BSP_IPMLOGMSG

#define SZ_SHELL_API_READY TEXT("SYSTEM/ShellAPIReady")

#define MAX_IPM_CLIENTS 32 //currently IPM can handle 32 clients.
//Max client dll name, usually is will contain 5 chars, such as "FMD1:"
#define SZ_CLIENT_NAME_MAX_CHAR 64
//Define global event that signals the IPM is running
#define SZ_IPM_RUNNING TEXT("IPM_RUNNING")



enum IPM_IO_CONTROL
{
    IOCTL_IPM_REGISTER,
};

#define IPM_FILE_NAME L"IPM1:"

//CLIENT_ID Type would be used by IPM to identify the requesting driver 
typedef DWORD CLIENT_ID;

#define INVALID_CLIENT_ID 		(-1) // Add to handle error case in driver

//This templete usede to filter non valid id passed to IPM 
#define VALID_CLIENT_ID_TEMPLETE 0xfafb

/* IPM status codes. */
typedef enum
{
    IPM_STATUS_SUCCESS = 0,
        IPM_STATUS_FAILURE,
        IPM_STATUS_INVALID_PARAM,
        IPM_STATUS_READ_TIME_OUT,
        IPM_STATUS_READ_ERROR,
        IPM_STATUS_WRITE_TIME_OUT,
        IPM_STATUS_WRITE_ERROR,
        IPM_STATUS_NO_RESOURCES,
        IPM_STATUS_NO_RESPONSE,
        IPM_STATUS_INVALID_QUEUE_HANDLE,
        IPM_STATUS_INVALID_CLIENT_ID,
        IPM_STATUS_QUEUE_FAILURE,
        IPM_STATUS_WRONG_MESSAGING_VERSION,
        IPM_STATUS_INSUFFICIENT_BUFFER,
        IPM_STATUS_MONITOR_FAILURE,
        IPM_STATUS_NO_MORE_CLIENTS_ALLOWED,
        IPM_STATUS_NOT_RUNNING,
        IPM_STATUS_IPM_DISABLED,				// BSP_NOIPM=1 case
        IPM_STATUS_INCORRECT_CLIENT_TYPE,
        IPM_STATUS_CLIENT_ALREADY_EXIST,
        IPM_STATUS_UNKNOWN_SYSTEM_STATE,
        IPM_STATUS_OP_NOT_SUPPORTED,
        IPM_STATUS_OP_ALREADY_REGISTERED


}IPM_STATUS_T;

//
// Define how many MS IPM should wait after being woke up from a keypress
// 
#define IPM_KEYPADWAIT_MS   5

/*
Define Processor States
Make Sure enum below matches the defines 
We use enums for readiness arrays
*/
#define IPM_PROCESSOR_D0_RDY			0x01
#define IPM_PROCESSOR_RING_OSC_RDY		0x02
#define IPM_PROCESSOR_D1_RDY			0x04
#define IPM_PROCESSOR_D2_RDY			0x08
#define IPM_PROCESSOR_STATES_COUNT			4 //this count the possible states
#define IPM_PROCESSOR_ALL_RDY			IPM_PROCESSOR_D0_RDY|IPM_PROCESSOR_D1_RDY|IPM_PROCESSOR_D2_RDY|IPM_PROCESSOR_RING_OSC_RDY

typedef enum
{
    IPM_CLIENT_NOTIFY_TYPE=0,
        IPM_CLIENT_QUERY_TYPE,
        IPM_CLIENT_TYPE_COUNT

}IPM_CLIENT_TYPE;

typedef struct
{
    HANDLE hSrcProc;       // IPM Process ID 
    HANDLE hClientToIPMQ;           // IPM incoming Queue
    HANDLE hIPMToClientAckQ;     // Ack Queue set up to IPM, IPM side context.
}IPM_REGISTER_HANDLE_EXCHANGE, *PIPM_REGISTER_HANDLE_EXCHANGE;


//define requests that IPM handles
typedef enum
{
    //registration MSG types
    IPM_REQUEST_REGISTER=0,
        IPM_REQUEST_REGISTER_EX,
        IPM_REQUEST_DE_REGISTER,
        //Block Freq Change Request
        IPM_REQUEST_SET_FREQ_CHANGE_BLOCK,
        IPM_REQUEST_RELEASE_FREQ_CHANGE_BLOCK,
        //Set Min Op
        IPM_REQUEST_SET_MIN_OP,
        IPM_REQUEST_RELEASE_MIN_OP,
        //Processor State Ready notification
        IPM_NOTIFY_PROC_STATE_READY,
        //Processor State change notification request
        IPM_REQUEST_PROC_STATE_NOTIFICATION,
        IPM_BROADCAST_PROC_STATE_CHANGED,
        //Ack message type
        IPM_ACK_REGISTRATION,
        IPM_ACK_SET_FREQ_CHANGE_BLOCK,
        IPM_ACK_SET_MIN_OP,

        IPM_EVENT_PROFILER

}IPM_OPERATION_TYPE;

//define Q messages structure
#define IPM_MSG_VERSION_MAJOR 1
#define IPM_MSG_VERSION_MINOR 1

/*--------------IPM Message Version History 
Version 1.0 - (11/1/05), define all basic msg types. 
Version 1.1 - (2/21/07), pass acknowledgement queue to support unnamed queues
*/

//////////// Registration Request MSG Struct
typedef struct
{
    IPM_OPERATION_TYPE	dwRequest;
    WORD				wMsgVersion;
    TCHAR				szRegisterName[SZ_CLIENT_NAME_MAX_CHAR];
    IPM_CLIENT_TYPE		clientType;
    HANDLE hIPMToClientACKQ_Write;
} IPM_REQUEST_REGISTER_MSG,*PIPM_REQUEST_REGISTER_MSG;

//////////// IPM ACK MSG Struct
typedef struct
{
    IPM_OPERATION_TYPE	dwRequestAknowledged;
    IPM_STATUS_T		nErrorCode;
    CLIENT_ID			nApprovedClientID;
} IPM_ACK_MSG,*PIPM_ACK_MSG;

//////////// IPM Request MSG Struct
typedef struct
{
    IPM_OPERATION_TYPE	dwRequest;
    CLIENT_ID			nRequestingClientID;
    DWORD				dwRequestData;
    HANDLE hIPMToClientACKQ_Write;
} IPM_REQUEST_MSG,*PIPM_REQUEST_MSG;


typedef struct
{
    IPM_OPERATION_TYPE	dwCode;
    DWORD				dwData;
    IPM_STATUS_T		ErrorCode;
} IPM_CALLBACK_MSG,*PIPM_CALLBACK_MSG;
typedef BOOL (*IPM_CALLBACK_FUNC)(
PIPM_CALLBACK_MSG pCallbackMsg);
//Incomming msg should be defines as the largest msg, currently this is registration msg
#define CLIENT_QUEUE_INCOMMING_MSG IPM_REQUEST_REGISTER_MSG


typedef enum
{
    IPM_OP_D0CS = 0,
        IPM_OP_104MHZ,
        IPM_OP_208MHZ,
        IPM_OP_416MHZ,
        IPM_OP_624MHZ,
        IPM_OP_806MHZ,
        IPM_OP_AUTOCLK,
        IPM_OP_COUNT

} IPM_PRODUCT_OP;

//Description of the POR Operation points, index must match IPM_PRODUCT_OP enum
static PTCHAR g_szOPDescription[IPM_OP_COUNT] =
{
    _T ("Ring OSC"),
    _T ("104 MHZ"),
    _T ("208 MHZ"),
    _T ("416 MHZ"),
    _T ("624 MHZ"),
    _T ("806 MHZ"),
    _T ("Auto Clock")
};


typedef enum
{
    WPM_OFF=0,
        WPM_ON,
        WPM_SUSPENDED,
        WPM_RESUMING,
        WPM_UNATTENDED,
        WPM_USER_IDLE,
        WPM_BACKLIGHT_OFF,
        WPM_SCREEN_OFF,
        WPM_STATES_UNKNOWN,
        WPM_STATES_COUNT


}WPM_SYSTEM_POWER_STATES;

// Used for idle replacements of D1/D2
typedef struct __IPMD1D2Struct
{
    UINT32 ReloStartAdx;
    UINT32 DMCBaseAdx;
    UINT32 ReloSPAdx;
    UINT32 CP14Val;
} IPMD1D2Struct;


  #define SYSTEM_MAX_OP IPM_OP_806MHZ
  #define SYSTEM_MIN_OP IPM_OP_104MHZ
  #define IPM_FCS_BLOCK_SAFE_OP IPM_OP_806MHZ


#define IPM_NO_MIN_OP IPM_OP_D0CS // set this one to lowest op, meaning no limit at all
#define IPM_OPERATING_POINTS_COUNT      IPM_OP_COUNT       // accomodate more if needed
