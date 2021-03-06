// WindowsBSOD.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include "stdafx.h"
#include <Windows.h>
#include <winternl.h>
#include <iostream>

#pragma comment(lib, "ntdll.lib") // This library is older than 50% of my viewers ^^

using namespace std;

extern "C" NTSTATUS NTAPI RtlAdjustPrivilege(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrThread, PBOOLEAN StatusPointer);
extern "C" NTSTATUS NTAPI NtRaiseHardError(LONG ErrorStatus, ULONG Unless1, ULONG Unless2, PULONG_PTR Unless3, ULONG ValidResponseOption, PULONG ResponsePointer);

int main() {
	BOOLEAN PrivilegeState = FALSE;
	ULONG ErrorResponse = 0;
	RtlAdjustPrivilege(19, TRUE, FALSE, &PrivilegeState);
	printf("Crashing...");
	NtRaiseHardError(STATUS_IN_PAGE_ERROR, 0, 0, NULL, 6, &ErrorResponse); // There are many Crash reasons
	printf("Crash failed!"); // The program would exit before this.
	return 0;
}