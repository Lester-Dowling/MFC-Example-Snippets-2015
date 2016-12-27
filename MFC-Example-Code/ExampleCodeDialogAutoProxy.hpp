
// ExampleCodeDialogAutoProxy.hpp: header file
//

#pragma once

class ExampleCodeDialog;


// ExampleCodeDialogAutoProxy command target

class ExampleCodeDialogAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(ExampleCodeDialogAutoProxy)

	ExampleCodeDialogAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	ExampleCodeDialog* m_pDialog;

// Operations
public:

// Overrides
	public:
	virtual void OnFinalRelease();

// Implementation
protected:
	virtual ~ExampleCodeDialogAutoProxy();

	// Generated message map functions

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(ExampleCodeDialogAutoProxy)

	// Generated OLE dispatch map functions

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

