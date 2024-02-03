/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	Icon.cpp
*
******************************************************************/

#include <stdio.h>
#include "Icon.h"

#ifdef WIN32
typedef struct
{
    BYTE        bWidth;          // Width, in pixels, of the image
    BYTE        bHeight;         // Height, in pixels, of the image
    BYTE        bColorCount;     // Number of colors in image (0 if >=8bpp)
    BYTE        bReserved;       // Reserved ( must be 0)
    WORD        wPlanes;         // Color Planes
    WORD        wBitCount;       // Bits per pixel
    DWORD       dwBytesInRes;    // How many bytes in this resource?
    DWORD       dwImageOffset;   // Where in the file is this image?
} ICONDIRENTRY, *LPICONDIRENTRY;
  
typedef struct
{
    WORD           idReserved;   // Reserved (must be 0)
    WORD           idType;       // Resource Type (1 for icons)
    WORD           idCount;      // How many images?
    ICONDIRENTRY   idEntries[1]; // An entry for each image (idCount of 'em)
} ICONDIR, *LPICONDIR;
  
typedef struct
{
   BITMAPINFOHEADER	icHeader;      // DIB header
   RGBQUAD			icColors[1];   // Color table
   BYTE				icXOR[1];      // DIB bits for XOR mask
   BYTE				icAND[1];      // DIB bits for AND mask
} ICONIMAGE, *LPICONIMAGE;
#endif

GrIcon LoadIconFromFile(char *iconFilename)
{
	GrIcon	icon = new CGrIcon;

	if (!iconFilename || !strlen(iconFilename))
		return NULL;

	FILE	*fp;
	if (!(fp = fopen(iconFilename, "rb")))
		return NULL;

#ifdef WIN32
	// We need an ICONDIR to hold the data
	//ICONDIR *pIconDir = (ICONDIR *)malloc( sizeof( ICONDIR ) );
	//ICONDIR *pIconDir = (ICONDIR *)malloc( ( sizeof( WORD ) * 3 ) + ( sizeof( ICONDIRENTRY ) * pIconDir->idCount ) );
	ICONDIR *pIconDir = (ICONDIR *)malloc( ( sizeof( WORD ) * 3 ) + ( sizeof( ICONDIRENTRY ) * 2 ) );
	ICONIMAGE *pIconImage;
	// Read the Reserved word

	fread(&(pIconDir->idReserved), 1, sizeof( WORD ), fp);
	// Read the Type word - make sure it is 1 for icons
	fread(&(pIconDir->idType), 1, sizeof( WORD ), fp);	
	// Read the count - how many images in this file?
	fread(&(pIconDir->idCount), 1, sizeof( WORD ), fp);

	// Reallocate IconDir so that idEntries has enough room for idCount elements
	//pIconDir = (ICONDIR *)realloc( pIconDir, ( sizeof( WORD ) * 3 ) + ( sizeof( ICONDIRENTRY ) * pIconDir->idCount ) );
	pIconDir->idCount = 1;

	// Read the ICONDIRENTRY elements
	fread(pIconDir->idEntries, 1, pIconDir->idCount * sizeof(ICONDIRENTRY), fp);

	int i = 0;

	// Allocate memory to hold the image
	pIconImage = (ICONIMAGE *)malloc( pIconDir->idEntries[i].dwBytesInRes );
	// Seek to the location in the file that has the image	
	fseek(fp, pIconDir->idEntries[i].dwImageOffset, SEEK_SET); 
	// Read the image data
	fread(pIconImage, 1, pIconDir->idEntries[i].dwBytesInRes,fp);
	icon->mhIcon = CreateIconFromResourceEx((unsigned char *)pIconImage, pIconDir->idEntries[i].dwBytesInRes, TRUE, 0x00030000, 
										           pIconImage->icHeader.biWidth, pIconImage->icHeader.biHeight/2, 0 );
    if( icon->mhIcon == NULL )
    {
		// We would break on NT if we try with a 16bpp image
        if(pIconImage->icHeader.biBitCount != 16)
			icon->mhIcon = CreateIconFromResource((unsigned char *)pIconImage, pIconDir->idEntries[i].dwBytesInRes, TRUE, 0x00030000 );
	}

	// Copy file image
	icon->mFileImageSize = sizeof(WORD)*3 + sizeof(ICONDIRENTRY) + pIconDir->idEntries[i].dwBytesInRes; // 766 byte
	icon->mFileImage = new char[icon->mFileImageSize];
	memcpy(&icon->mFileImage[0], pIconDir, sizeof(WORD)*3); 
	memcpy(&icon->mFileImage[sizeof(WORD)*3], pIconDir->idEntries, sizeof(ICONDIRENTRY)); 
	memcpy(&icon->mFileImage[sizeof(WORD)*3 + sizeof(ICONDIRENTRY)], pIconImage, pIconDir->idEntries[i].dwBytesInRes); 

	// Clean up the ICONDIR memory
	free( pIconImage );
	free(pIconDir);
#endif
	fclose(fp);

	return icon;
}

void SaveIconIntoFile(GrIcon icon, char *iconFilename)
{
	if (!iconFilename || !strlen(iconFilename))
		return;

	FILE *fp = fopen(iconFilename, "wb");
	if (!fp)
		return;
	fwrite(icon->GetFileImage(), icon->GetFileImageSize(), 1, fp);
	fclose(fp);
}
