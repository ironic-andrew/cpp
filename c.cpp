#include <windows.h>
#include <iostream>
#include <wbemidl.h>
#pragma comment(lib, "wbemuuid.lib")

void GetWMIInfo(const wchar_t* wqlQuery, const wchar_t* propertyName) {
    HRESULT hres;

    hres = CoInitializeEx(0, COINIT_MULTITHREADED);
    if (FAILED(hres)) {
        std::wcout << L"❌ CoInitializeEx failed" << std::endl;
        return;
    }

    hres = CoInitializeSecurity(
        NULL, -1, NULL, NULL,
        RPC_C_AUTHN_LEVEL_DEFAULT,
        RPC_C_IMP_LEVEL_IMPERSONATE,
        NULL, EOAC_NONE, NULL
    );

    if (FAILED(hres) && hres != RPC_E_TOO_LATE) {
        std::wcout << L"❌ CoInitializeSecurity failed" << std::endl;
        CoUninitialize();
        return;
    }

    IWbemLocator* pLocator = nullptr;
    hres = CoCreateInstance(
        CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER,
        IID_IWbemLocator, (LPVOID*)&pLocator
    );

    if (FAILED(hres)) {
        std::wcout << L"❌ CoCreateInstance failed" << std::endl;
        CoUninitialize();
        return;
    }

    IWbemServices* pServices = nullptr;
    hres = pLocator->ConnectServer(
        SysAllocString(L"ROOT\\CIMV2"),
        NULL, NULL, 0, 0, 0, 0, &pServices
    );

    if (FAILED(hres)) {
        std::wcout << L"❌ ConnectServer failed" << std::endl;
        pLocator->Release();
        CoUninitialize();
        return;
    }

    hres = CoSetProxyBlanket(
        pServices,
        RPC_C_AUTHN_WINNT,
        RPC_C_AUTHZ_NONE,
        NULL,
        RPC_C_AUTHN_LEVEL_CALL,
        RPC_C_IMP_LEVEL_IMPERSONATE,
        NULL,
        EOAC_NONE
    );

    if (FAILED(hres)) {
        std::wcout << L"❌ CoSetProxyBlanket failed" << std::endl;
        pServices->Release();
        pLocator->Release();
        CoUninitialize();
        return;
    }

    IEnumWbemClassObject* pEnumerator = nullptr;
    hres = pServices->ExecQuery(
        SysAllocString(L"WQL"),
        SysAllocString(wqlQuery),
        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
        NULL,
        &pEnumerator
    );

    if (FAILED(hres)) {
        std::wcout << L"❌ ExecQuery failed" << std::endl;
        pServices->Release();
        pLocator->Release();
        CoUninitialize();
        return;
    }

    IWbemClassObject* pObj = nullptr;
    ULONG uReturn = 0;

    while (pEnumerator) {
        HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1, &pObj, &uReturn);
        if (!uReturn) break;

        VARIANT vtProp;
        VariantInit(&vtProp);

        hr = pObj->Get(propertyName, 0, &vtProp, 0, 0);
        if (SUCCEEDED(hr) && vtProp.vt == VT_BSTR)
            std::wcout << propertyName << L": " << vtProp.bstrVal << std::endl;
        else
            std::wcout << L"(немає значення)" << std::endl;

        VariantClear(&vtProp);
        pObj->Release();
    }

    pServices->Release();
    pLocator->Release();
    pEnumerator->Release();
    CoUninitialize();
}

int main() {
    std::wcout << L"--- CPU ---" << std::endl;
    GetWMIInfo(L"SELECT Name FROM Win32_Processor", L"Name");
    std::wcout << L"\n--- GPU ---" << std::endl;
    GetWMIInfo(L"SELECT Name FROM Win32_VideoController", L"Name");
}
