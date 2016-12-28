

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0620 */
/* at Tue Jan 19 14:14:07 2038
 */
/* Compiler settings for MFCExampleCode.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0620 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __MFCExampleCode_h_h__
#define __MFCExampleCode_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMFCExampleCode_FWD_DEFINED__
#define __IMFCExampleCode_FWD_DEFINED__
typedef interface IMFCExampleCode IMFCExampleCode;

#endif 	/* __IMFCExampleCode_FWD_DEFINED__ */


#ifndef __MFCExampleCode_FWD_DEFINED__
#define __MFCExampleCode_FWD_DEFINED__

#ifdef __cplusplus
typedef class MFCExampleCode MFCExampleCode;
#else
typedef struct MFCExampleCode MFCExampleCode;
#endif /* __cplusplus */

#endif 	/* __MFCExampleCode_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __MFCExampleCode_LIBRARY_DEFINED__
#define __MFCExampleCode_LIBRARY_DEFINED__

/* library MFCExampleCode */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_MFCExampleCode;

#ifndef __IMFCExampleCode_DISPINTERFACE_DEFINED__
#define __IMFCExampleCode_DISPINTERFACE_DEFINED__

/* dispinterface IMFCExampleCode */
/* [uuid] */ 


EXTERN_C const IID DIID_IMFCExampleCode;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("FFD422F2-4B62-4D59-B35A-8CACEE5806CB")
    IMFCExampleCode : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IMFCExampleCodeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMFCExampleCode * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMFCExampleCode * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMFCExampleCode * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMFCExampleCode * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMFCExampleCode * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMFCExampleCode * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMFCExampleCode * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IMFCExampleCodeVtbl;

    interface IMFCExampleCode
    {
        CONST_VTBL struct IMFCExampleCodeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMFCExampleCode_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMFCExampleCode_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMFCExampleCode_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMFCExampleCode_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMFCExampleCode_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMFCExampleCode_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMFCExampleCode_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IMFCExampleCode_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MFCExampleCode;

#ifdef __cplusplus

class DECLSPEC_UUID("E858A01C-0C76-41E6-A375-C1626C6E0F8C")
MFCExampleCode;
#endif
#endif /* __MFCExampleCode_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


