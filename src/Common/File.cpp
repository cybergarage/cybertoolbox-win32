/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	File.cpp
*
******************************************************************/
#include <stdio.h>
#include "common.h"
#include "File.h"
#include "StringFn.h"

void FileStripFileName(char *fname)
{
	int nFname = strlen(fname);
	for (int n=0; n<nFname; n++) {
		if (fname[(nFname-1)-n] == FILE_PATH_DELIM)
			break;
	}
	fname[nFname-n] = '\0';
}

void FileStripExtention(char *fname)
{
	int nFname = strlen(fname);
	for (int n=0; n<nFname; n++) {
		if (fname[(nFname-1)-n] == '.')
			break;
	}
	fname[(nFname-1)-n] = '\0';
}

void FileStripPathName(char *fname)
{
	int nFname = strlen(fname);
	for (int n=0; n<nFname; n++) {
		if (fname[(nFname-1)-n] == FILE_PATH_DELIM)
			break;
	}
	
	char *buffer = new char[nFname+1];
	strcpy(buffer, fname);
	strcpy(fname, &buffer[((nFname-1)-n)+1]);
	delete buffer;
}

void FileChangePathName(char *fname, char *newPathName)
{
	char *onlyFilename = new char[strlen(fname)+1];
	strcpy(onlyFilename, fname);
	FileStripPathName(onlyFilename);

	strcpy(fname, newPathName);
	strcat(fname, onlyFilename);

	delete onlyFilename;
}

bool FileCopy(char *srcFname, char *dstFname)
{
	if(!StringCompare(srcFname, dstFname))
		return TRUE;
	return CopyFile(srcFname, dstFname, FALSE) ? true : false;
}

bool FileExists(char *filename)
{
	FILE *fp = fopen(filename, "r");
	
	if (fp == NULL)
		return false;

	fclose(fp);
	return true;
}

bool FileGetFullPathName(char *filename, char *fullpathFilename, int bufferLen)
{
	char *filenamePos;

	return (0 < GetFullPathName(filename, bufferLen , fullpathFilename, &filenamePos)) ? true : false;
}

char *FileGetCurrentDirectory(char *dirname, int bufferLen)
{
	GetCurrentDirectory(bufferLen, dirname);
	return dirname;
}
