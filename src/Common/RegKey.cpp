#include <stdio.h>
#include <afxwin.h>
#include "RegKey.h"

////////////////////////////////////////////////////////////
//	Save
////////////////////////////////////////////////////////////

BOOL RegKeyWriteValue(char *section, char *key, long value)
{
	char	valueKey[128];
	HKEY	hKey;
	DWORD	dwDispostion;
	sprintf(valueKey, "%s\\%s", REGKEY_ROOT_NAME, section);
	int res = RegCreateKeyEx(HKEY_LOCAL_MACHINE, valueKey, 0, "", REG_OPTION_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dwDispostion);
	if (res == ERROR_SUCCESS) 
		return (BOOL)RegSetValueEx(hKey, key, NULL, REG_DWORD, (unsigned char *)value, sizeof(long));
	else
		return FALSE;
}

BOOL RegKeyWriteValue(char *section, char *key, char *value)
{
	char	valueKey[128];
	HKEY	hKey;
	DWORD	dwDispostion;
	sprintf(valueKey, "%s\\%s", REGKEY_ROOT_NAME, section);
	int res = RegCreateKeyEx(HKEY_LOCAL_MACHINE, valueKey, 0, "", REG_OPTION_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dwDispostion);
	if (res == ERROR_SUCCESS) 
		return (BOOL)RegSetValueEx(hKey, key, NULL, REG_SZ, (unsigned char *)value, strlen(value));
	else
		return FALSE;
}

BOOL RegKeyWriteValue(char *section, char *key, int value1, int value2)
{
	char	value[128];
	sprintf(value, "%d %d", value1, value2);
	return RegKeyWriteValue(section, key, value);
}

BOOL RegKeyWriteValue(char *section, char *key, int value1, int value2, int value3, int value4)
{
	char	value[128];
	sprintf(value, "%d %d %d %d", value1, value2, value3, value4);
	return RegKeyWriteValue(section, key, value);
}

////////////////////////////////////////////////////////////
//	Read
////////////////////////////////////////////////////////////

BOOL RegKeyGetValue(char *section, char *key, long *value)
{
	char	valueKey[128];
	DWORD	type, dataSize;
	HKEY	hKey;
	DWORD	dwDispostion;
	value[0] = '\0';
	sprintf(valueKey, "%s\\%s", REGKEY_ROOT_NAME, section);
	int res = RegCreateKeyEx(HKEY_LOCAL_MACHINE, valueKey, 0, "", REG_OPTION_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dwDispostion);
	if (res == ERROR_SUCCESS) {
		dataSize = sizeof(long);
		int err = RegQueryValueEx(hKey, key, NULL, &type, (unsigned char *)value, &dataSize);
		if (err == ERROR_SUCCESS)
			return TRUE;
		else
			return FALSE;
	}
	return FALSE;
}

BOOL RegKeyGetValue(char *section, char *key, char *value)
{
	char	valueKey[128];
	DWORD	type, dataSize;
	HKEY	hKey;
	DWORD	dwDispostion;
	value[0] = '\0';
	sprintf(valueKey, "%s\\%s", REGKEY_ROOT_NAME, section);
	int res = RegCreateKeyEx(HKEY_LOCAL_MACHINE, valueKey, 0, "", REG_OPTION_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dwDispostion);
	if (res == ERROR_SUCCESS) {
		dataSize = 128;
		int err = RegQueryValueEx(hKey, key, NULL, &type, (unsigned char *)value, &dataSize);
		if (err == ERROR_SUCCESS)
			return TRUE;
		else
			return FALSE;
	}
	return FALSE;
}

BOOL RegKeyGetValue(char *section, char *key, int *value1, int *value2)
{
	char	value[128];
	if (RegKeyGetValue(section, key, value)) {
		sscanf(value, "%d %d", value1, value2);
		return TRUE;
	}
	return FALSE;
}

BOOL RegKeyGetValue(char *section, char *key, int *value1, int *value2, int *value3, int *value4)
{
	char	value[128];
	if (RegKeyGetValue(section, key, value)) {
		sscanf(value, "%d %d %d %d", value1, value2, value3, value4);
		return TRUE;
	}
	return FALSE;
}

