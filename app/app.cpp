// CICD_Example.cpp : Defines the entry point for the application.
//
#include <Windows.h>
#include <Psapi.h>
#include <wchar.h>
#include "app.h"
#include <stdio.h>
#include <iostream>


void PrintMemoryInfo(DWORD processID)
{
	HANDLE hProcess;
	PROCESS_MEMORY_COUNTERS pmc;
	// Print the process identifier.
	wprintf(L"\nProcess ID : %u\n", processID);
	// Print information about the memory usage of the process.
	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);
	if (hProcess == NULL)
	{
		wprintf(L"OpenProcess() failed!Error %d\n", GetLastError());
		return;
	}

	if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
	{
		
		wprintf(L"\tPageFaultCount: 0x%08X\n", pmc.PageFaultCount);
		wprintf(L"\tPeakWorkingSetSize: 0x%08X\n", pmc.PeakWorkingSetSize);
		wprintf(L"\tWorkingSetSize: 0x%08X\n", pmc.WorkingSetSize);
		wprintf(L"\tQuotaPeakPagedPoolUsage: 0x%08X\n", pmc.QuotaPeakPagedPoolUsage);
		wprintf(L"\tQuotaPagedPoolUsage: 0x%08X\n", pmc.QuotaPagedPoolUsage);
		wprintf(L"\tQuotaPeakNonPagedPoolUsage: 0x%08X\n", pmc.QuotaPeakNonPagedPoolUsage);
		wprintf(L"\tQuotaNonPagedPoolUsage: 0x%08X\n", pmc.QuotaNonPagedPoolUsage);
		wprintf(L"\tPagefileUsage: 0x%08X\n", pmc.PagefileUsage);
		wprintf(L"\tPeakPagefileUsage: 0x%08X\n", pmc.PeakPagefileUsage);
	}
	CloseHandle(hProcess);
}


int getcurrentRamUsage() {

	uint64_t currentUsedRAM(0);

	PROCESS_MEMORY_COUNTERS info;
	GetProcessMemoryInfo(GetCurrentProcess(), &info, sizeof(info));
	currentUsedRAM = info.WorkingSetSize;

	const int N(100000000);
	int *x = new int[N];
	for (int i = 0; i < N; i++)
	{
		x[i] = 1;
	}
	
	GetProcessMemoryInfo(GetCurrentProcess(), &info, sizeof(info));
	currentUsedRAM = info.WorkingSetSize - currentUsedRAM;

	return currentUsedRAM;
}


void LeakyFunction() {
	malloc(1024 * 1024 * 5); // leak 5Mb
}

using namespace std;


int main() {
//int wmain(int argc, WCHAR **argv){


	cout << "Hello World"; // prints Hello World
	cubic(20);
	int test[10];
	int a = test[12];

	// create memory leak for testing
	int * q = new int;
	int * p = new int;

	/*
	// Get the list of process identifiers.
	DWORD aProcesses[1024], cbNeeded, cProcesses;

	unsigned int i;

	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		return 1;
	}

	// Calculate how many process identifiers were returned.
	cProcesses = cbNeeded / sizeof(DWORD);

	// Print the memory usage for each process
	wprintf(L"Press any key for more...\n");

	for (i = 0; i < cProcesses; i++)
	{
		PrintMemoryInfo(aProcesses[i]);
		_getwch();
	} 
	*/
	//int ram = getcurrentRamUsage();
	//std::cout << "\nCurrent RAM used: " << ram / 1024 / 1024 << " MB\n";

	LeakyFunction();
	std::getchar();

	return 0;
}
