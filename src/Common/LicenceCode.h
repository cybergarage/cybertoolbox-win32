/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	LicenceCode.h
*
******************************************************************/

#ifndef _LICENCECODE_H_
#define _LICENCECODE_H_

char *GenerateRawSoftwareProductID(void);
char *GenerateSoftwareProductID(void);
bool CheckSoftwareProductID(char *id);
char *CodeSoftwareProductID(char *id);
char *DecodeSoftwareProductID(char *id);
char *GenerateLicenceCode(char *id);
bool CheckLicenceCode(char *licenceCode);

int	GetYearFromSoftwareProductID(char *id);
int GetMonthFromSoftwareProductID(char *id);
int GetDayFromSoftwareProductID(char *id);
int GetCodePageFromSoftwareProductID(char *id); 
int GetWindowsMajorVersionFromSoftwareProductID(char *id); 
int GetWindowsMinorVersionFromSoftwareProductID(char *id); 
int GetOSVersionFromSoftwareProductID(char *id); 
int GetSystemProcessorLevelFromSoftwareProductID(char *id); 
int GetSystemProcessorRevisionFromSoftwareProductID(char *id); 
int GetSystemNumberOfProcessorsFromSoftwareProductID(char *id);

  #endif