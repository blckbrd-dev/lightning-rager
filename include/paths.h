#include <climits>
#include <cstdlib>

#pragma once
namespace vmonitor {
#ifdef WINDOWS
	#include <windows.h>
	TCHAR full_path[MAX_PATH];
	GetFullPathName(_T("bin/"), MAX_PATH, full_path, NULL);
#else
	char* full_path = realpath("bin/", NULL);
#endif
}
