#pragma once
#include "targetver.h"
#include <afx.h>
#include <afxwin.h>
#include <afxext.h>
#include <atlbase.h>
#include <atlstr.h>
#include <afxdisp.h>
#undef min
#undef max

#define DECLARE_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE    \
    public:                                             \
    static CRuntimeClass* __stdcall _GetBaseClass();    \
    static CRuntimeClass* GetThisClass();               \
    static CObject* __stdcall CreateObject();           \
    CRuntimeClass* GetRuntimeClass() const override;    \
    static const wchar_t* fqcn();



#define IMPLEMENT_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE(FQCN)            \
    CObject* __stdcall FQCN::CreateObject()                             \
    {                                                                   \
        return new FQCN;                                                \
    }                                                                   \
                                                                        \
                                                                        \
    CRuntimeClass* __stdcall FQCN::_GetBaseClass()                      \
    {                                                                   \
        return RUNTIME_CLASS(CObject);                                  \
    }                                                                   \
                                                                        \
                                                                        \
    static AFX_CLASSINIT __afx_class_init__{ FQCN::GetThisClass() };    \
                                                                        \
                                                                        \
    CRuntimeClass* FQCN::GetThisClass()                                 \
    {                                                                   \
        static CRuntimeClass runtime_class                              \
            = { #FQCN,                                                  \
                sizeof(FQCN),                                           \
                0xFFFF,                                                 \
                &FQCN::CreateObject,                                    \
                &FQCN::_GetBaseClass,                                   \
                nullptr,                                                \
                &__afx_class_init__ };                                  \
        return &runtime_class;                                          \
    }                                                                   \
                                                                        \
                                                                        \
    CRuntimeClass* FQCN::GetRuntimeClass() const                        \
    {                                                                   \
        return FQCN::GetThisClass();                                    \
    }                                                                   \
                                                                        \
                                                                        \
    const wchar_t* FQCN::fqcn() {                                       \
        static CComBSTR fqcn{ GetThisClass()->m_lpszClassName };        \
        return fqcn;                                                    \
    }
