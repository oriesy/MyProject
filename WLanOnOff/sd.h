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
//
// Copyright (c) 2002 BSQUARE Corporation.  All rights reserved.
// DO NOT REMOVE --- BEGIN EXTERNALLY DEVELOPED SOURCE CODE ID 40973--- DO NOT REMOVE
//
// Module Name:
//
//    sd.h   
//
// Abstract:
//
//    definitions for PXA320 Controller
//
// Notes:
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _SDH_DEFINED
#define _SDH_DEFINED

#include "SDCardDDK.h"
#include "SDHCD.h"
#include "ipm_api.h"
#include "xllp_pm.h"
#include "monahans.h"
#include <xllp_mmc.h>

#define SDH_TAG 'SDH'

#define MMC_RXFIFO_SIZE 32
#define MMC_TXFIFO_SIZE 32
#define MMC_RESFIFO_SIZE 8


#ifndef SD_API_STATUS_FAST_PATH_SUCCESS
// may have to define this value as public header file doesn't contain this
#define SD_API_STATUS_FAST_PATH_SUCCESS                ((SD_API_STATUS)0x00000002L)
#endif

#define NUM_BYTE_FOR_POLLING_MODE 0x800
#define MAXIMUM_SDCLOCK_FREQUENCY 25000000
    // MMC Controller register offsets
#define MMC_STRPCL 0x0000   // clock start/stop
#define MMC_STAT   0x0004   // MMC Status register
#define MMC_CLKRT  0x0008   // clock rate
#define MMC_SPI    0x000C   // SPI mode control
#define MMC_CMDAT  0x0010   // command/response/data sequence
#define MMC_RESTO  0x0014   // response timeout
#define MMC_RDTO   0x0018   // expected data read timeout
#define MMC_BLKLEN 0x001C   // data phase block length
#define MMC_NOB    0x0020   // number of blocks
#define MMC_PRTBUF 0x0024   // partial MMC TX Fifo
#define MMC_IMASK  0x0028   // interrupt mask
#define MMC_IREG   0x002C   // interrupt register
#define MMC_CMD    0x0030   // command
#define MMC_ARGH   0x0034   // MSW of command argument
#define MMC_ARGL   0x0038   // LSW of command argument
#define MMC_RES    0x003C   // response Fifo

#define MMC_BLKS_REM    0x004C  // Number of data block that are not transferred.

    // OS Timer register offsets
#define OST_COUNT_REG       0x0010   // OS Timer count register

    // bit definitions for MMC_STRPCL
#define MMC_STRPCL_START_CLOCK 0x02
#define MMC_STRPCL_STOP_CLOCK  0x01

    // bit definitions for MMC_IMASK
#define MMC_IMASK_DATA_TRAN_DONE_INT_MASKED   (1 << 0)
#define MMC_IMASK_PROG_DONE_INT_MASKED        (1 << 1)
#define MMC_IMASK_END_CMD_INT_MASKED          (1 << 2)
#define MMC_IMASK_STOP_CMD_INT_MASKED         (1 << 3)
#define MMC_IMASK_CLOCK_OFF_INT_MASKED        (1 << 4)
#define MMC_IMASK_RXFIFO_REQ_INT_MASKED       (1 << 5)
#define MMC_IMASK_TXFIFO_REQ_INT_MASKED       (1 << 6)
#define MMC_IMASK_TRANSMIT_TIMEOUT_INT_MASKED (1 << 7)
#define MMC_IMASK_DATA_ERROR_INT_MASKED       (1 << 8)
#define MMC_IMASK_RESPONSE_ERROR_INT_MASKED   (1 << 9)
#define MMC_IMASK_STALLED_READ_INT_MASKED     (1 << 10)
#define MMC_IMASK_SDIO_INT_MASKED             (1 << 11)
#define MMC_IMASK_SDIO_SUSPEND_ACK_INT_MASKED (1 << 12)
#define MMC_IMASK_ALL_INTERRUPTS_MASKED      (MMC_IMASK_DATA_TRAN_DONE_INT_MASKED   | \
                                              MMC_IMASK_PROG_DONE_INT_MASKED        | \
                                              MMC_IMASK_END_CMD_INT_MASKED          | \
                                              MMC_IMASK_STOP_CMD_INT_MASKED         | \
                                              MMC_IMASK_CLOCK_OFF_INT_MASKED        | \
                                              MMC_IMASK_RXFIFO_REQ_INT_MASKED       | \
                                              MMC_IMASK_TXFIFO_REQ_INT_MASKED)      | \
                                              MMC_IMASK_TRANSMIT_TIMEOUT_INT_MASKED | \
                                              MMC_IMASK_DATA_ERROR_INT_MASKED       | \
                                              MMC_IMASK_RESPONSE_ERROR_INT_MASKED   | \
                                              MMC_IMASK_STALLED_READ_INT_MASKED     | \
                                              MMC_IMASK_SDIO_INT_MASKED             | \
                                              MMC_IMASK_SDIO_SUSPEND_ACK_INT_MASKED
    // bit definitions for MMC_IREG
#define MMC_IREG_DATA_TRAN_DONE             (1 << 0)
#define MMC_IREG_PROG_DONE                  (1 << 1)
#define MMC_IREG_END_CMD                    (1 << 2)
#define MMC_IREG_STOP_CMD                   (1 << 3)
#define MMC_IREG_CLOCK_IS_OFF               (1 << 4)
#define MMC_IREG_RXFIFO_REQ                 (1 << 5)
#define MMC_IREG_TXFIFO_REQ                 (1 << 6)
#define MMC_IREG_TINT                       (1 << 7)
#define MMC_IREG_DAT_ERR                    (1 << 8)
#define MMC_IREG_RES_ERR                    (1 << 9)
#define MMC_IREG_RD_STALLED                 (1 << 10)
#define MMC_IREG_SDIO_INT                   (1 << 11)
#define MMC_IREG_SDIO_SUSPEND_ACK           (1 << 12)
#define MMC_IREG_INTERRUPTS                 0x1FFF

    // bit definitions for MMC_CMDAT
#define MMC_CMDAT_RESPONSE_NONE 0x00        // no response
#define MMC_CMDAT_RESPONSE_R1   0x01        // expected R1 response
#define MMC_CMDAT_RESPONSE_R2   0x02        // expected R2 response
#define MMC_CMDAT_RESPONSE_R3   0x03        // expected R3 response
#define MMC_CMDAT_DATA_EN       (1 << 2)    // data transfer to follow
#define MMC_CMDAT_DATA_WRITE    (1 << 3)    // data transfer is a write
#define MMC_CMDAT_STREAM        (1 << 4)    // data transfer is stream mode
#define MMC_CMDAT_EXPECT_BUSY   (1 << 5)    // the command uses busy signalling
#define MMC_CMDAT_INIT          (1 << 6)    // add init clocks
#define MMC_CMDAT_DMA_ENABLE    (1 << 7)    // enable DMA
#define MMC_CMDAT_SD_4DAT       (1 << 8)    // enable 4 bit data transfers
#define MMC_CMDAT_STOP_TRAN     (1 << 10)   // stop data transmission
#define MMC_CMDAT_SDIO_INT_EN   (1 << 11)   // enable controller to check for an SDIO interrupt from the card
#define MMC_CMDAT_SDIO_SUSPEND  (1 << 12)   // SDIO CMD 52, suspend current data transfer
#define MMC_CMDAT_SDIO_RESUME   (1 << 13)   // SDIO CMD 52, resume a suspended data transfer

    // bit definitions for MMC_STAT
#define MMC_STAT_READ_TIMEOUT          (1 << 0)
#define MMC_STAT_RESPONSE_TIMEOUT      (1 << 1)
#define MMC_STAT_WRITE_DATA_CRC_ERROR  (1 << 2)

#define MMC_STAT_READ_DATA_CRC_ERROR   (1 << 3)
#define MMC_STAT_SPI_READ_TOKEN_ERROR  (1 << 4)
#define MMC_STAT_RESPONSE_CRC_ERROR    (1 << 5)

#define MMC_STAT_CLOCK_ENABLED         (1 << 8)

#define MMC_STAT_FLASH_ERROR           (1 << 9)
#define MMC_STAT_SPI_WR_ERROR          (1 << 10)

#define MMC_STAT_DATA_TRANSFER_DONE    (1 << 11)
#define MMC_STAT_PROGRAM_DONE          (1 << 12)
#define MMC_STAT_END_CMD_RES           (1 << 13)

#define MMC_STAT_RD_STALLED            (1 << 14)
#define MMC_STAT_SDIO_INT              (1 << 15)
#define MMC_STAT_SDIO_SUSPEND_ACK      (1 << 16)

    // bit definition for MMC_PRTBUF
#define MMC_PRTBUF_BUFFER_PARTIAL_FULL (1 << 0)

#define MAX_NAMELEN         128

typedef enum {
    Idle = -1 ,
    CommandSend = 1,
    CommandComplete = 2,
    ResponseWait = 3,
    WriteDataTransfer = 4,
    WriteDataTransferDone = 5,
    ProgramWait = 6,
    WriteDataDone = 7,
    ReadDataTransfer = 8,
    ReadDataTransferDone = 9,
    ReadDataDone = 10,
} SDHSTATE;


  // PXA320 hardware specific context
typedef struct _SDH_HARDWARE_CONTEXT {
   volatile PXA320_GPIO_REG     *pGPIORegisters;     // GPIO registers
   volatile PXA320_MMC_REG      *pSDMMCRegisters;    // SD/MMC controller registers
   volatile PXA320_CLKMGR_REG   *pClkMgrRegisters;   // Clock Manager registers
   volatile PXA320_DMA_REG      *pDMARegisters;      // DMA control registers
   volatile PXA320_OST_REG      *pOSTRegisters;      // OST control registers   
   volatile unsigned int	 * pMFPRegisters; //MFP registers
   P_XLLP_PM_BPMU_T pBPMURegisters; //BPMU registers
   
   volatile HANDLE m_MfpRMDbHandle;
   XLLP_MMC_CONTEXT_T XllpMMCContext;
   
   
   PSDCARD_HC_CONTEXT   pHCContext;      // the host controller context

   DWORD                dwSDMMCIrq;       // SD/MMC Controller interrupt IRQ value
   DWORD                dwSysintrSDMMC;   // SD/MMC controller interrupt SYSINTR value
   HANDLE               hControllerInterruptEvent;     // controller interrupt event
   HANDLE               hControllerInterruptThread;    // controller interrupt thread
   int                  ControllerIstThreadPriority;   // controller IST thread priority
   DWORD                dwPollingModeSize;          // Fast path polling mode size.

   BOOL                 DriverShutdown;                // controller shutdown
   CRITICAL_SECTION     ControllerCriticalSection;     // controller critical section 
   BOOL                 SendInitClocks;                // flag to indicate that we need to send the init clock
   WCHAR                RegPath[256];                  // reg path  
   SDHSTATE             CurrentState;                  // current transfer state
   UCHAR                RcvBuffer[MMC_RXFIFO_SIZE];    // receive buffer
   UCHAR                XmitBuffer[MMC_TXFIFO_SIZE];   // xmit buffer
   BOOL                 fSDIOEnabled;                  // SDIO interrupts enabled
   BOOL                 fSDIOInterruptPending;         // indicates that and SDIO interupt has occured
   BOOL                 f4BitMode;                     // indicates that 4 bit data transfer mode is enabled
   BOOL                 fClockAlwaysOn;                // indicates that MMC clock should always remain ON
   BOOL                 fClockOnIfInterruptsEnabled;   // indicates that clock should remain on if SDIO interrupts are enabled
   BOOL                 DevicePresent;                 // device is present in the slot
   BOOL                 fFastPathEnabled;             // fastpath is enabled

   DWORD                dwWorkClkRate;
   BOOL                 fClkAdjusted;
   BOOL                 fSDCKENOn;
   BOOL                 fCMD;

   // WPM and IPM specific information
   CEDEVICE_POWER_STATE gPowerState;   // current power state
   TCHAR                szName[MAX_NAMELEN];    // device name, eg "SDH1:"
   CEDEVICE_POWER_STATE CurrentDx;              // current power level
   UCHAR                ucSupportedStatesMask;   // which of D0-D4 driver supports
   CLIENT_ID            ClientID;                // IPM ClientID
   HANDLE               hClockOn, hClockOff;    // Events to signify clock state change.
   HANDLE               hClockHysteresisThread;
   HANDLE               hevStop;
   HANDLE               hMinOpMutex;
   BOOL                  fMinOpEnabled;
   BOOL                  fClockOn;
   BOOL                  fSuspended;            // Set to TRUE when we enter the power handler to power down. Set to FALSE to when we enter the power handler to power up

   volatile PSD_BUS_REQUEST      pCurrentRequest; // Current Processing Request.
   volatile BOOL                 fCurrentRequestFastPath;
   volatile SD_API_STATUS        FastPathStatus;

   DWORD                dwSDClockFrequency;            // current SD clock frequency (Hz)
   DWORD                dwMaximumSDClockFrequency;     // maximum SD clock frequency (Hz)
   
   CRITICAL_SECTION     intrRegCriticalSection;        // imask register critical section

}SDH_HARDWARE_CONTEXT, *PSDH_HARDWARE_CONTEXT;


typedef enum
{
    NOTREADY,
    HYSTERESIS,
    READY

}IPMSHDCRDYSTATE;


#define SetCurrentState(pHC, d) \
{\
    ((pHC)->CurrentState = (d)); \
}

//local define for retail message
#define MY_RETAILMSG RETAILMSG
//#define MY_RETAILMSG //RETAILMSG
	
#define ACQUIRE_LOCK(pHC) EnterCriticalSection(&(pHC)->ControllerCriticalSection)
#define RELEASE_LOCK(pHC) LeaveCriticalSection(&(pHC)->ControllerCriticalSection)

    // prototypes for handlers
BOOLEAN SDHCancelIoHandler(PSDCARD_HC_CONTEXT pHCContext,DWORD Slot, PSD_BUS_REQUEST pRequest);
SD_API_STATUS SDHBusRequestHandler(PSDCARD_HC_CONTEXT pHCContext,DWORD Slot, PSD_BUS_REQUEST pRequest);
SD_API_STATUS SDHSlotOptionHandler(PSDCARD_HC_CONTEXT    pHCContext,
                                     DWORD                 SlotNumber, 
                                     SD_SLOT_OPTION_CODE   Option, 
                                     PVOID                 pData,
                                     ULONG                 OptionSize);

    // other prototypes
SD_API_STATUS SDDeinitialize(PSDCARD_HC_CONTEXT pHCContext);
SD_API_STATUS SDInitialize(PSDCARD_HC_CONTEXT pHCContext);

#define SDH_INTERRUPT_ZONE    SDCARD_ZONE_0
#define SDH_SEND_ZONE         SDCARD_ZONE_1
#define SDH_RESPONSE_ZONE     SDCARD_ZONE_2
#define SDH_RECEIVE_ZONE      SDCARD_ZONE_3
#define SDH_CLOCK_ZONE        SDCARD_ZONE_4
#define SDH_TRANSMIT_ZONE     SDCARD_ZONE_5
#define SDH_SDBUS_INTERACTION_ZONE     SDCARD_ZONE_7

#define SDH_INTERRUPT_ZONE_ON ZONE_ENABLE_0
#define SDH_SEND_ZONE_ON      ZONE_ENABLE_1
#define SDH_RESPONSE_ZONE_ON  ZONE_ENABLE_2
#define SDH_RECEIVE_ZONE_ON   ZONE_ENABLE_3
#define SDH_CLOCK_ZONE_ON     ZONE_ENABLE_4
#define SDH_TRANSMIT_ZONE_ON  ZONE_ENABLE_5
#define SDH_SDBUS_INTERACTION_ZONE_ON  ZONE_ENABLE_7

#define SDH_CARD_CONTROLLER_PRIORITY 100
#define SDH_DEFAULT_RESPONSE_TIMEOUT_CLOCKS 64
#define SDH_DEFAULT_DATA_TIMEOUT_CLOCKS 0xFFFF

#define SDH_RESPONSE_FIFO_DEPTH              8  // 
      
#define SDH_MAX_BLOCK_SIZE           1023
#define SDH_MIN_BLOCK_SIZE           32

void  ProcessCardInsertion(void *pContext);
void  ProcessCardRemoval(void *pContext);
BOOL  DriverShutdown(void *pContext);
BOOL LoadRegistrySettings( HKEY hKeyDevice, PSDH_HARDWARE_CONTEXT pController );

    // platform specific functions
BOOL  InitializeHardware(PSDH_HARDWARE_CONTEXT pHardwareContext );
void  UnInitializeHardware(PSDH_HARDWARE_CONTEXT pHardwareContext  );

BOOL LoadPlatformRegistrySettings( HKEY hKeyDevice );

void  MMCPowerControl(void *pContext, BOOL fPowerOn );

BOOL  IsCardWriteProtected(void *pContext);
BOOL  IsCardPresent(void *pContext);
BOOL  SetupCardDetectIST(void *pContext);
void  CleanupCardDetectIST();
void  SimulateCardInsertion();

#endif

// DO NOT REMOVE --- END EXTERNALLY DEVELOPED SOURCE CODE ID --- DO NOT REMOVE

