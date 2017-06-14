// WLanOnOffDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WLanOnOff.h"
#include "WLanOnOffDlg.h"

#include "SDHCD.h"
#include "sd.h"

#include <xllp_ExtRTC.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWLanOnOffDlg dialog

CWLanOnOffDlg::CWLanOnOffDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWLanOnOffDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWLanOnOffDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWLanOnOffDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWLanOnOffDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWLanOnOffDlg, CDialog)
	//{{AFX_MSG_MAP(CWLanOnOffDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWLanOnOffDlg message handlers

BOOL CWLanOnOffDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}



void CWLanOnOffDlg::OnButton1() 
{

	PSDCARD_HC_CONTEXT      pHostContext; 
	SD_API_STATUS           status;         // SD status
	PSDH_HARDWARE_CONTEXT	pHCDevice;

	status = SDHCDAllocateContext(SDH_SLOTS, &pHostContext);
	if (!SD_API_SUCCESS(status))
    {
        RETAILMSG(1,(TEXT("SDH: Failed to allocate context : 0x%08X \n"), status));
        return ;
    }

	 pHCDevice = (PSDH_HARDWARE_CONTEXT)malloc(sizeof(SDH_HARDWARE_CONTEXT));

    if (pHCDevice == NULL)
    {
        RETAILMSG(1, (TEXT("SDH: Failed to allocate extension\n")));
        return ;
    }

	memset(pHCDevice, 0, sizeof(SDH_HARDWARE_CONTEXT));

	 pHostContext->pHCSpecificContext = pHCDevice;

	  pController->pHCContext = pHostContext;

	      SDHCDSetHCName(pHostContext, TEXT("Zylonite"));

    // set init handler
    SDHCDSetControllerInitHandler(pHostContext, SDInitialize);
    // set deinit handler
    SDHCDSetControllerDeinitHandler(pHostContext, SDDeinitialize);
    // set the bus request handler
    SDHCDSetBusRequestHandler(pHostContext, SDHBusRequestHandler);
    // set the cancel I/O handler
    SDHCDSetCancelIOHandler(pHostContext, SDHCancelIoHandler);
    // set the slot option handler
    SDHCDSetSlotOptionHandler(pHostContext, SDHSlotOptionHandler);

    // now register the host controller
    status = SDHCDRegisterHostController(pHostContext);

	   if (!SD_API_SUCCESS(status))
    {
        if (pHCDevice)
        {
            free(pHCDevice);
        }
        SDHCDDeleteContext(pHostContext);
        RETAILMSG(1, (TEXT("SDH: Failed to register host controller: %0x08X \n"), status));
        return ;
    }

	 MMCPowerControl(pHCDevice, FALSE);	// TODO: Add your control notification handler code here

}

