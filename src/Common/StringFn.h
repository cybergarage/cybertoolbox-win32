/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	StringFn.h
*
******************************************************************/
#ifndef _STRINGFN_H_
#define _STRINGFN_H_

#define	strlen	StringLength
#define	strcmp	StringCompare
#define	strncpy	StringNCopy

int		StringLength(char *string);
void	StringToUpper(char *string);
int		StringCompare(char *string1, char *string2);
int		StringCompareIgnoreCase(char *string1, char *string2);
int		StringNCompare(char *string1, char *string2, int n);
int		StringNCompareIgnoreCase(char *string1, char *string2, int n);

int		StringIndexOf(char *string, char ch, int fromIndex);
int		StringIndexOf(char *string, char ch);
int		StringLastIndexOf(char *string, char ch, int fromIndex);
int		StringLastIndexOf(char *string, char ch);

char	*StringNCopy(char *string1, char *string2, int length);

int		StringReplaceChar(char *string, char targetChar, char repleseChar);

const char *GetDirectoryName(const char *path);

#endif
