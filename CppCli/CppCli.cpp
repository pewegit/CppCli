// CppCli.cpp: Hauptprojektdatei.

#include "stdafx.h"

#include <windows.h> // SYSTEMTIME

using namespace System;

int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"Hello World");

	array<String^> ^arr = gcnew array<String^>(10);
	int i = 0;

	for each(String^% s in arr) {
		s = i++.ToString();
		Console::WriteLine(s);
	}

	Console::WriteLine("Array-Value: {0}", arr[5]);

	SYSTEMTIME st, lt;

	GetSystemTime(&st);
	GetLocalTime(&lt); // considers summer or winter time

	String^ strTimeStamp = lt.wYear.ToString("0000") + "-" + lt.wMonth.ToString("00") + "-" + lt.wDay.ToString("00")
		+ " " + lt.wHour.ToString("00") + ":" + lt.wMinute.ToString("00") + ":" + lt.wSecond.ToString("00") + "." + lt.wMilliseconds.ToString("000");
	Console::WriteLine(strTimeStamp);
	Console::WriteLine("Time-Stamp [{0}:{1,-2}:{2,2}:{3,2}:{4,2}:{5,2}.{6,3}]", lt.wYear, lt.wMonth, lt.wDay, lt.wHour, lt.wMinute, lt.wSecond, lt.wMilliseconds);


    return 0;
}
