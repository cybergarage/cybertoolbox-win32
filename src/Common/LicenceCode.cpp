/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	LicenceCode.cpp
*
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <mbctype.h>
#include <afx.h>
#include "LicenceCode.h"

////////////////////////////////////////
//	Software Product ID Infomation
////////////////////////////////////////

static int GetWindowsMajorVersion(void)
{
	return _winmajor;
}

static int GetWindowsMinorVersion(void)
{
	return _winminor;
}

static int GetOSVersion(void)
{
	return _osver;
}

static char *GetLocale(void) 
{
	return setlocale( LC_ALL, NULL );
}

static int GetCodePage(void)
{
	return _getmbcp();
}

static int GetYear(void)
{
	return CTime::GetCurrentTime().GetYear();
}

static int GetMonth(void)
{
	return CTime::GetCurrentTime().GetMonth();
}

static int GetDay(void)
{
	return CTime::GetCurrentTime().GetDay();
}

static int GetSystemMemorySize(void)
{
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo); 
	return sysinfo.dwPageSize;
}

static int GetSystemProcessorLevel(void)
{
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo); 
	return sysinfo.wProcessorLevel;
}

static int GetSystemProcessorRevision(void)
{
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo); 
	return sysinfo.wProcessorRevision & 0xFFFF;
}

static int GetSystemNumberOfProcessors(void)
{
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo); 
	return sysinfo.dwNumberOfProcessors;
}

////////////////////////////////////////
//	Software Product ID Infomation
////////////////////////////////////////

#define CTB_STRING						"CTB"
#define	CTB_STRING_LENGTH				strlen(CTB_STRING)
#define CTB_VERSION_STRING				"220"
#define CTB_VERSION_LENGTH				strlen(CTB_VERSION_STRING)
#define	CTB_SOFTWARE_PRODUCT_ID_HEADER	(CTB_STRING CTB_VERSION_STRING)
#define CTB_LICENCECODE_STRING			CTB_SOFTWARE_PRODUCT_ID_HEADER
#define CTB_LICENCECODE_LENGTH			strlen(CTB_LICENCECODE_STRING)

#define CTB_LECENCECODE_KEYMAX			50
#define CTB_LECENCECODE_KEYMASK			21

static char gSoftwareProductID[128];
static char gCodeSoftwareProductID[128];
static char gDecodeSoftwareProductID[128];
static char gLicenceCode[128];

char *GenerateRawSoftwareProductID(void)
{
	sprintf(gSoftwareProductID, "%s-%04d %02d %02d-%04d-%02d %02d %05d-%03d %05d %01d %01d", 
		CTB_SOFTWARE_PRODUCT_ID_HEADER,
		GetYear(), 
		GetMonth(),
		GetDay(), 
		GetCodePage(), 
		GetWindowsMajorVersion(), 
		GetWindowsMinorVersion(), 
		GetOSVersion(), 
		GetSystemProcessorLevel(), 
		GetSystemProcessorRevision(), 
		GetSystemNumberOfProcessors(),
		0); 

	return gSoftwareProductID;
}

char *GenerateSoftwareProductID(void)
{
	int key = GetTickCount() & 0x7;
	if (key == 0)
		key = 9;

	sprintf(gSoftwareProductID, "%s-%04d%02d%02d-%04d-%02d%02d%05d-%03d%05d%01d%01d", 
		CTB_SOFTWARE_PRODUCT_ID_HEADER,
		GetYear(), 
		GetMonth(),
		GetDay(), 
		GetCodePage(), 
		GetWindowsMajorVersion(), 
		GetWindowsMinorVersion(), 
		GetOSVersion(), 
		GetSystemProcessorLevel(), 
		GetSystemProcessorRevision(), 
		GetSystemNumberOfProcessors(),
		key); 

	CodeSoftwareProductID(gSoftwareProductID);

	return gCodeSoftwareProductID;
}

bool CheckSoftwareProductID(char* id)
{
	if (id == NULL)
		return false;

	char *licenceCodeString = CTB_LICENCECODE_STRING;
	int licenceCodeStringLen = strlen(CTB_LICENCECODE_STRING);
	for (int n=0; n<licenceCodeStringLen; n++) {
		if (licenceCodeString[n] != id[n])
			return false;
	}

	return true;
}	

int GetSoftwareProductIDKey(char *id)
{
	int len = strlen(id);
	return (int)(id[len-1] - '0');
}

char *CodeSoftwareProductID(char *id)
{
	int key = GetSoftwareProductIDKey(id);

	strcpy(gCodeSoftwareProductID, id);

	int idLen = strlen(id);
	int headerLen = strlen(CTB_SOFTWARE_PRODUCT_ID_HEADER);
	for (int n=headerLen; n<idLen-1; n++) {
		char c = gCodeSoftwareProductID[n];
		if ('0' <= c && c <= '9') {
			int num = c - '0';
			num += key;
			num %= 10;
			gCodeSoftwareProductID[n] = num + '0';
		}
	}

	return gCodeSoftwareProductID;
}

char *DecodeSoftwareProductID(char *id)
{
	int key = GetSoftwareProductIDKey(id);

	strcpy(gDecodeSoftwareProductID, id);

	int idLen = strlen(id);
	int headerLen = strlen(CTB_SOFTWARE_PRODUCT_ID_HEADER);
	for (int n=headerLen; n<idLen-1; n++) {
		char c = gDecodeSoftwareProductID[n];
		if ('0' <= c && c <= '9') {
			int num = c - '0';
			num += 10;
			num -= key;
			num %= 10;
			gDecodeSoftwareProductID[n] = num + '0';
		}
	}

	return gDecodeSoftwareProductID;
}

////////////////////////////////////////
//	SoftwareProductID infomation	
////////////////////////////////////////

//sprintf(gSoftwareProductID, "%s-%04d%02d%02d-%04d-%02d%02d%05d-%02d%04d%01d%01d", 
int	GetValueFromSoftwareProductID(char *id, int index, int len)
{
	char *data = DecodeSoftwareProductID(id);

	static char value[32];

	strncpy(value, data + index, len);
	value[len] = '\n';

	return atoi(value);
}

int	GetYearFromSoftwareProductID(char *id)
{
	return GetValueFromSoftwareProductID(id, 7, 4);
}

int GetMonthFromSoftwareProductID(char *id)
{
	return GetValueFromSoftwareProductID(id, 7 + 4, 2);
}

int GetDayFromSoftwareProductID(char *id) 
{
	return GetValueFromSoftwareProductID(id, 7 + 4 + 2, 2);
}

int GetCodePageFromSoftwareProductID(char *id) 
{
	return GetValueFromSoftwareProductID(id, 7 + 4 + 2 + + 2 + 1, 4);
}

int GetWindowsMajorVersionFromSoftwareProductID(char *id) 
{
	return GetValueFromSoftwareProductID(id, 7 + 4 + 2 + + 2 + 1 + 4 + 1, 2);
}

int GetWindowsMinorVersionFromSoftwareProductID(char *id) 
{
	return GetValueFromSoftwareProductID(id, 7 + 4 + 2 + + 2 + 1 + 4 + 1 + 2, 2);
}

int GetOSVersionFromSoftwareProductID(char *id) 
{
	return GetValueFromSoftwareProductID(id, 7 + 4 + 2 + + 2 + 1 + 4 + 1 + 2 + 2, 5);
}

int GetSystemProcessorLevelFromSoftwareProductID(char *id) 
{
	return GetValueFromSoftwareProductID(id, 7 + 4 + 2 + + 2 + 1 + 4 + 1 + 2 + 2 + 5 + 1, 3);
}

int GetSystemProcessorRevisionFromSoftwareProductID(char *id) 
{
	return GetValueFromSoftwareProductID(id, 7 + 4 + 2 + + 2 + 1 + 4 + 1 + 2 + 2 + 5 + 1 + 3, 5);
}

int GetSystemNumberOfProcessorsFromSoftwareProductID(char *id)
{
	return GetValueFromSoftwareProductID(id, 7 + 4 + 2 + + 2 + 1 + 4 + 1 + 2 + 2 + 5 + 1 + 2 + 5, 1);
}

////////////////////////////////////////
//	Licence code	
////////////////////////////////////////

int GetLicenceKey(char *id)
{
	int len = strlen(id);
	int key;
	key = (int)(id[len-2] - '0') * 10;
	key += (int)(id[len-1] - '0');
	return key;
}

char *GenerateLicenceCode(char *id)
{
	int key = GetLicenceKey(id) % CTB_LECENCECODE_KEYMAX;
	
	char *licenceCodeString = CTB_LICENCECODE_STRING;

	int licenceCodeStringLen = strlen(CTB_LICENCECODE_STRING);
	for (int n=0; n<licenceCodeStringLen; n++) {
		int c = (int)licenceCodeString[n];
		c -= '0';
		c += key;
		gLicenceCode[n*2+0] = (char)((c / 10) + '0');
		gLicenceCode[n*2+1] = (char)((c % 10) + '0');
	}
	gLicenceCode[licenceCodeStringLen*2] = '\0';

	char keyString[8];
	sprintf(keyString, "%02d", key + CTB_LECENCECODE_KEYMASK);
	strcat(gLicenceCode, keyString);

	return gLicenceCode;
}	

bool CheckLicenceCode(char *licenceCode)
{
	int key = GetLicenceKey(licenceCode) - CTB_LECENCECODE_KEYMASK;
	
	char *licenceCodeString = CTB_STRING;
	int licenceCodeStringLen = strlen(CTB_STRING);
	for (int n=0; n<licenceCodeStringLen; n++) {
		char c;
		c = (licenceCode[n*2+0] - '0') * 10;
		c += (licenceCode[n*2+1] - '0');
		c -= key;
		c += '0';
		if (licenceCodeString[n] != c)
			return false;
	}

	return true;
}	

