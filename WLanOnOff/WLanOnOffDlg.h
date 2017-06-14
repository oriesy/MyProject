// WLanOnOffDlg.h : header file
//

#if !defined(AFX_WLANONOFFDLG_H__66400B0D_82FB_44F8_A3CD_716C33139889__INCLUDED_)
#define AFX_WLANONOFFDLG_H__66400B0D_82FB_44F8_A3CD_716C33139889__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CWLanOnOffDlg dialog

class CWLanOnOffDlg : public CDialog
{
// Construction
public:
	CWLanOnOffDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWLanOnOffDlg)
	enum { IDD = IDD_WLANONOFF_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWLanOnOffDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWLanOnOffDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WLANONOFFDLG_H__66400B0D_82FB_44F8_A3CD_716C33139889__INCLUDED_)
