/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	StringFn.cpp
*
******************************************************************/
#include <string>
#include <string.h>
#include <ctype.h>

using namespace std;

int StringLength(char *string)
{
	if (!string)
		return 0;
	return strlen(string);
}

void StringToUpper(char *string)
{
	if (!string)
		return;
	for (int n=0; n<StringLength(string); n++)
		string[n] = toupper(string[n]);
}

int StringCompare(char *string1, char *string2)
{
	if (!string1 || !string2)
		return -1;
	return 	strcmp(string1, string2);
}

int StringNCompare(char *string1, char *string2, int n)
{
	if (!string1 || !string2)
		return -1;
	return 	strncmp(string1, string2, n);
}

int StringCompareIgnoreCase(char *string1, char *string2)
{
	if (!string1 || !string2)
		return -1;

	char *String1 = new char[StringLength(string1)+1];
	char *String2 = new char[StringLength(string2)+1];

	strcpy(String1, string1);
	strcpy(String2, string2);

	StringToUpper(String1);
	StringToUpper(String2);
	
	int ret = strcmp(String1, String2);

	delete String1;
	delete String2;

	return ret;
}

int StringNCompareIgnoreCase(char *string1, char *string2, int n)
{
	if (!string1 || !string2)
		return -1;

	char *String1 = new char[StringLength(string1)+1];
	char *String2 = new char[StringLength(string2)+1];

	strcpy(String1, string1);
	strcpy(String2, string2);

	StringToUpper(String1);
	StringToUpper(String2);
	
	int ret = strncmp(String1, String2, n);

	delete String1;
	delete String2;

	return ret;
}

int StringIndexOf(char *string, char ch, int fromIndex)
{
	if (!string || fromIndex < 0 || (StringLength(string)-1) < fromIndex)
		return -1;

	for (int n=fromIndex; n<StringLength(string); n++) {
		if (string[n] == ch)
			return n;
	}

	return 	-1;
}

int StringIndexOf(char *string, char ch)
{
	return StringIndexOf(string, ch, 0);
}

int StringLastIndexOf(char *string, char ch, int fromIndex)
{
	if (!string || fromIndex < 0 || (StringLength(string)-1) < fromIndex)
		return -1;

	for (int n=fromIndex; 0<=n; n--) {
		if (string[n] == ch)
			return n;
	}

	return 	-1;
}

int StringLastIndexOf(char *string, char ch)
{
	if (!string)
		return -1;
	return StringLastIndexOf(string, ch, StringLength(string)-1);
}

char *StringNCopy(char *string1, char *string2, int length)
{
	if (!string1 || !string2 || length <= 0)
		return NULL;
	char *ret = strncpy(string1, string2, length);
	string1[length] = '\0';
	return ret;
}

int StringReplaceChar(char *string, char targetChar, char repleseChar)
{
	int nReplased = 0;
	for (int n=0; n<StringLength(string); n++) {
		if (string[n] == targetChar) {
			string[n] = repleseChar;
			nReplased++;
		}
	}
	return nReplased;
}

const char *GetDirectoryName(const char *path)
{
	string pathStr = path;
	int lastSlashIndex = pathStr.find_last_of('\\');
	static string dirStr;
	dirStr = pathStr.substr(0, lastSlashIndex);
	return dirStr.c_str();
}
