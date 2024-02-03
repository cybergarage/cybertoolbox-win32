/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	File.cpp
*
******************************************************************/
#ifndef _FILE_H_
#define _FILE_H_

#define FILE_MAX_PATHLEN	512
#define FILE_MAX_FILENAME	(512 + FILE_MAX_PATHLEN)

#if MACINTOSH
#define FILE_PATH_DELIM		':'
#define FILE_PWD_DELIM		':'
#elif WIN32
#define FILE_PATH_DELIM		'\\'
#define FILE_PWD_PATH_DELIM	'.\\'
#define FILE_PWD_DELIM		'.'
#endif

void	FileStripFileName(char *filename);
void	FileStripExtention(char *filename);
void	FileStripPathName(char *filename);
void	FileChangePathName(char *filename, char *newPathName);
bool	FileCopy(char *srcFilename, char *dstFilename);
bool	FileExists(char *filename);
bool	FileGetFullPathName(char *filename, char *fullpathFilaname, int bufferLen);
char	*FileGetCurrentDirectory(char *dirname, int bufferLen);

#endif
