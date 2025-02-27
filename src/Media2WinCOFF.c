#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#include <Windows.h>
#include <winnt.h>
#include <synchapi.h>

#include <fileapi.h>
#include <handleapi.h>

#include <stdio.h>

int wmain(int argc, const wchar_t *argv[]){

	HANDLE hFile;

	hFile = CreateFileW(
		argv[1],
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_DELETE,
		NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_ENCRYPTED,
		NULL
	);

	if (hFile == INVALID_HANDLE_VALUE) {
		printf_s("Failed to open/create file!\n");
		return -1;
	}

	printf_s("File success to open/create file!\n\0");
	CloseHandle(hFile);

	// Sleep(3000);
	DWORD fAttr = GetFileAttributesW(L"Helloworld\0");
	
	printf_s("File attributes are: %ld", fAttr);

	return 0;
}