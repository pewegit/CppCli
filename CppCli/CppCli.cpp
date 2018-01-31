// CppCli.cpp: Hauptprojektdatei.

#include "stdafx.h"

#include <windows.h> // SYSTEMTIME

using namespace System;

void test_cliSyntax(void);
void test_systemTime(void);
void test_heapApi(void);

int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"Hello World");

	test_cliSyntax();

	test_systemTime();

	test_heapApi();
	
    return 0;
}

void test_cliSyntax(void)
{
	array<String^> ^arr = gcnew array<String^>(10);
	int i = 0;

	for each(String^% s in arr) {
		s = i++.ToString();
		Console::WriteLine(s);
	}

	Console::WriteLine("Array-Value: {0}", arr[5]);
}

void test_systemTime(void)
{
	SYSTEMTIME st, lt;

	GetSystemTime(&st); // UTC-based (does not consider DST = daylight saving time)
	GetLocalTime(&lt); // considers summer or winter time

	String^ strTimeStamp = lt.wYear.ToString("0000") + "-" + lt.wMonth.ToString("00") + "-" + lt.wDay.ToString("00")
		+ " " + lt.wHour.ToString("00") + ":" + lt.wMinute.ToString("00") + ":" + lt.wSecond.ToString("00") + "." + lt.wMilliseconds.ToString("000");
	Console::WriteLine(strTimeStamp);
	Console::WriteLine("Time-Stamp [{0}:{1,-2}:{2,2}:{3,2}:{4,2}:{5,2}.{6,3}]", lt.wYear, lt.wMonth, lt.wDay, lt.wHour, lt.wMinute, lt.wSecond, lt.wMilliseconds);
}

void test_heapApi(void)
{
	// Heap API check
	typedef struct
	{
		int status;
		int handle;
		double value1;
		double value2;
		double value3;
	} T_myType;
	HANDLE hHeap = HeapCreate(HEAP_NO_SERIALIZE, 1000, 1000000);

	//double *p = (double *)HeapAlloc(hHeap, HEAP_NO_SERIALIZE, 100);
	//p[1000] = -17.42; // throws access violation

	T_myType *p = (T_myType *)HeapAlloc(hHeap, HEAP_NO_SERIALIZE, 10000000); // too large
	p += 0x12345678;
	p[17].value3 = -17.42; // throws access violation
	
	BOOL retVal = HeapDestroy(hHeap);
}