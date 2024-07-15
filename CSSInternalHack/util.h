#pragma once
#include "pch.h"
#include <Windows.h>
template <typename FuncType> 
FuncType CallFunc(void* Class, int index)
{
	void **vtable = *(reinterpret_cast<void***>(Class));
	void *func = vtable[index];
	return (FuncType)(func);
}
typedef void* (*CreateInterfaceFn)(const char* name, int* return_code);
template <typename T> inline T find_interface(const char* module, const char* interface_name) {
	// get a handle to the module
	if (const auto handle = GetModuleHandleA(module)) {
		// get the exported function from the handle
		if (const auto interface_func = reinterpret_cast<CreateInterfaceFn>(GetProcAddress(handle, "CreateInterface"))) {
			return reinterpret_cast<T>(interface_func(interface_name, nullptr));
		}
	}
	return T();
}
template <typename T> inline T find_vfunc(void* vmt, int index) {
	return (*static_cast<T**>(vmt))[index];
}
void* CreateInterface(LPCWSTR moduleName, const char* version)
{
	HMODULE module = GetModuleHandle(moduleName);
	if (module == NULL)
	{
		MessageBox(0, L"Null module", L"A", 0);
		return NULL;
	}
	typedef void* (*CreateInterfaceFn)(const char* name, int* returnCode);
	CreateInterfaceFn createInterface = (CreateInterfaceFn)GetProcAddress(module, "CreateInterface");
	if (createInterface == NULL)
	{
		MessageBox(0, L"Null interface", L"A", 0);
		return NULL;
	}
	void* interfacePtr = createInterface(version, NULL);
	if (interfacePtr == NULL)
	{
		MessageBox(0, L"Null interface pointer", L"A", 0);
		return NULL;
	}
	return interfacePtr;
}