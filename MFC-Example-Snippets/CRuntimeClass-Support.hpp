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

#define DECLARE_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE	\
    public:                                             \
    static CRuntimeClass* __stdcall _GetBaseClass();    \
    static CRuntimeClass* GetThisClass();               \
    static CObject* __stdcall CreateObject();           \
    CRuntimeClass* GetRuntimeClass() const override;



#define IMPLEMENT_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE(fqcn)			\
    CObject* __stdcall fqcn::CreateObject()                             \
    {                                                                   \
        return new fqcn;                                                \
    }                                                                   \
                                                                        \
    CRuntimeClass* __stdcall fqcn::_GetBaseClass()                      \
    {                                                                   \
        return RUNTIME_CLASS(CObject);                                  \
    }                                                                   \
                                                                        \
    static AFX_CLASSINIT __afx_class_init__{ fqcn::GetThisClass() };    \
                                                                        \
    CRuntimeClass* fqcn::GetThisClass()                                 \
    {                                                                   \
        static CRuntimeClass runtime_class                              \
            = { #fqcn,                                                  \
                sizeof(fqcn),                                           \
                0xFFFF,                                                 \
                &fqcn::CreateObject,                                    \
                &fqcn::_GetBaseClass,                                   \
                nullptr,                                                \
                &__afx_class_init__ };                                  \
        return &runtime_class;                                          \
    }                                                                   \
                                                                        \
    CRuntimeClass* fqcn::GetRuntimeClass() const                        \
    {                                                                   \
        return fqcn::GetThisClass();                                    \
    }
