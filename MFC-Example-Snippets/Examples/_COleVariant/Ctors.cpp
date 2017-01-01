#include "pch-MFC-Example-Snippets.hpp"
#include "Ctors.hpp"
namespace Examples {

	/**
	 *  Local function to return the symbol for the given VARTYPE.
	 */
	static const wchar_t* vartype_symbol(VARTYPE vt)
	{
		switch (vt) {
		case VT_EMPTY:
			return L"VT_EMPTY";
		case VT_NULL:
			return L"VT_NULL";
		case VT_I2:
			return L"VT_I2";
		case VT_I4:
			return L"VT_I4";
		case VT_R4:
			return L"VT_R4";
		case VT_R8:
			return L"VT_R8";
		case VT_CY:
			return L"VT_CY";
		case VT_DATE:
			return L"VT_DATE";
		case VT_BSTR:
			return L"VT_BSTR";
		case VT_DISPATCH:
			return L"VT_DISPATCH";
		case VT_ERROR:
			return L"VT_ERROR";
		case VT_BOOL:
			return L"VT_BOOL";
		case VT_VARIANT:
			return L"VT_VARIANT";
		case VT_DECIMAL:
			return L"VT_DECIMAL";
		case VT_RECORD:
			return L"VT_RECORD";
		case VT_UNKNOWN:
			return L"VT_UNKNOWN";
		case VT_I1:
			return L"VT_I1";
		case VT_UI1:
			return L"VT_UI1";
		case VT_UI2:
			return L"VT_UI2";
		case VT_UI4:
			return L"VT_UI4";
		case VT_INT:
			return L"VT_INT";
		case VT_UINT:
			return L"VT_UINT";
		case VT_VOID:
			return L"VT_VOID";
		case VT_HRESULT:
			return L"VT_HRESULT";
		case VT_PTR:
			return L"VT_PTR";
		case VT_SAFEARRAY:
			return L"VT_SAFEARRAY";
		case VT_CARRAY:
			return L"VT_CARRAY";
		case VT_USERDEFINED:
			return L"VT_USERDEFINED";
		case VT_LPSTR:
			return L"VT_LPSTR";
		case VT_LPWSTR:
			return L"VT_LPWSTR";
		case VT_FILETIME:
			return L"VT_FILETIME";
		case VT_BLOB:
			return L"VT_BLOB";
		case VT_STREAM:
			return L"VT_STREAM";
		case VT_STORAGE:
			return L"VT_STORAGE";
		case VT_STREAMED_OBJECT:
			return L"VT_STREAMED_OBJECT";
		case VT_STORED_OBJECT:
			return L"VT_STORED_OBJECT";
		case VT_BLOB_OBJECT:
			return L"VT_BLOB_OBJECT";
		case VT_CF:
			return L"VT_CF";
		case VT_CLSID:
			return L"VT_CLSID";
		case VT_VECTOR:
			return L"VT_VECTOR";
		case VT_ARRAY:
			return L"VT_ARRAY";
		case VT_BYREF:
			return L"VT_BYREF";
		case VT_RESERVED:
			return L"VT_RESERVED";
		default:
			return L"Unknown VARTYPE";
		}
	}


	void _COleVariant::Ctors::run()
	{
		TEXT_OUT("Instantiating no-arg ctor...");
		COleVariant v0;
		VARTYPE v0_vt = v0.vt;
		TEXT_OUT("    VARTYPE is: " << vartype_symbol(v0_vt));

		TEXT_OUT_BLANKLINE;

		TEXT_OUT("Instantiating wchar_t* ctor...");
		COleVariant v1{ L"A short pithy wstring!" };
		TEXT_OUT("    VARTYPE is: " << vartype_symbol(v1.vt));
		TEXT_OUT("      Value is: " << v1.bstrVal);

		TEXT_OUT_BLANKLINE;

		TEXT_OUT("Instantiating CString ctor...");
		CString cs{ L"A quick and simple CString!" };
		COleVariant v2{ cs };
		TEXT_OUT("    VARTYPE is: " << vartype_symbol(v2.vt));
		TEXT_OUT("      Value is: " << v2.bstrVal);

		TEXT_OUT_BLANKLINE;

		TEXT_OUT("Instantiating signed short ctor...");
		const signed short ival = std::numeric_limits<signed short>::max();
		COleVariant v3{ ival };
		TEXT_OUT("    VARTYPE is: " << vartype_symbol(v3.vt));
		TEXT_OUT("      Value is: " << v3.iVal);

		TEXT_OUT_BLANKLINE;

		TEXT_OUT("Instantiating signed long ctor...");
		const signed long lval = std::numeric_limits<signed long>::max();
		COleVariant v4{ lval };
		TEXT_OUT("    VARTYPE is: " << vartype_symbol(v4.vt));
		TEXT_OUT("      Value is: " << v4.lVal);

		TEXT_OUT_BLANKLINE;

		TEXT_OUT("Instantiating Currency ctor...");
		constexpr long cents = 100; // Accuracy factor for cents in a CURRENCY value.
		COleCurrency curA(4, 5 * cents);
		COleVariant v5{ curA };
		TEXT_OUT("    VARTYPE is: " << vartype_symbol(v5.vt));
		TEXT_OUT("      Value is: " << COleCurrency{ v5.cyVal }.Format().GetString());

		TEXT_OUT_BLANKLINE;

		TEXT_OUT("Instantiating float ctor...");
		const float fltval = 7.89f;
		COleVariant v6{ fltval };
		TEXT_OUT("    VARTYPE is: " << vartype_symbol(v6.vt));
		TEXT_OUT("      Value is: " << v6.fltVal);

		TEXT_OUT_BLANKLINE;

		TEXT_OUT("Instantiating double ctor...");
		const double dblval = 9.86;
		COleVariant v7{ dblval };
		TEXT_OUT("    VARTYPE is: " << vartype_symbol(v7.vt));
		TEXT_OUT("      Value is: " << v7.dblVal);

		TEXT_OUT_BLANKLINE;

		TEXT_OUT("Instantiating date & time ctor...");
		COleDateTime dnt{ COleDateTime::GetCurrentTime() };
		COleVariant v8{ dnt };
		TEXT_OUT("    VARTYPE is: " << vartype_symbol(v8.vt));
		TEXT_OUT("      Value is: " << COleDateTime{ v8.date }.Format().GetString());

		TEXT_OUT_BLANKLINE;

		TEXT_OUT("Instantiating byte array ctor...");
		CByteArray ba; ba.SetSize(32);
		for (__int64 idx = 0; idx < ba.GetSize(); ++idx)
		{
			BYTE bb = static_cast<BYTE>('a' + idx);
			ba.SetAt(idx, bb);
		}
		ba.SetAt(26, 0);
		COleVariant v9{ ba };
		TEXT_OUT("    VARTYPE is: " << vartype_symbol(v9.vt & ~VT_TYPEMASK));
		TEXT_OUT("  Elements are: " << vartype_symbol(v9.vt & VT_TYPEMASK));
		SAFEARRAY *sa = v9.parray;
		TEXT_OUT("      Value is: " << reinterpret_cast<char*>(sa->pvData));

	}
}
