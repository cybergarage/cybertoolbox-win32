/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	ModuleFilename.cpp
*
******************************************************************/

#include <stdio.h>
#include "ModuleFilename.h"

static Vector<CModuleFilename> *mModuleFilenameVector;

void AddModuleFilename(char *filename)
{
	CModuleFilename *moduleFilename = new CModuleFilename(filename);
	mModuleFilenameVector->addElement(moduleFilename);
}

void ModuleFilenameInitialize(void)
{
	mModuleFilenameVector = new Vector<CModuleFilename>();

	AddModuleFilename("BooleanEqual.mod");
	AddModuleFilename("BooleanNotEqual.mod");
	AddModuleFilename("BooleanGreater.mod");
	AddModuleFilename("BooleanLess.mod");
	AddModuleFilename("BooleanEqualGreater.mod");
	AddModuleFilename("BooleanEqualLess.mod");
	AddModuleFilename("BooleanNot.mod");
	//AddModuleFilename("BooleanIf.mod");

	AddModuleFilename("FilterScale.mod");
	AddModuleFilename("FilterCeil.mod");
	AddModuleFilename("FilterFloor.mod");
	AddModuleFilename("FilterHigh.mod");
	AddModuleFilename("FilterLow.mod");
	AddModuleFilename("FilterRange.mod");

	AddModuleFilename("LightSetOn.mod");
	AddModuleFilename("LightSetColor.mod");
	AddModuleFilename("LightSetIntensity.mod");
	AddModuleFilename("LightSetLocation.mod");
	AddModuleFilename("LightSetDirection.mod");
	AddModuleFilename("LightSetRadius.mod");
	AddModuleFilename("LightGetOn.mod");
	AddModuleFilename("LightGetColor.mod");
	AddModuleFilename("LightGetIntensity.mod");
	AddModuleFilename("LightGetLocation.mod");
	AddModuleFilename("LightGetDirection.mod");
	AddModuleFilename("LightGetRadius.mod");

	AddModuleFilename("MaterialSetAmbientIntensity.mod");
	AddModuleFilename("MaterialSetDiffuseColor.mod");
	AddModuleFilename("MaterialSetEmissiveColor.mod");
	AddModuleFilename("MaterialSetShininess.mod");
	AddModuleFilename("MaterialSetTransparency.mod");
	AddModuleFilename("MaterialGetAmbientIntensity.mod");
	AddModuleFilename("MaterialGetDiffuseColor.mod");
	AddModuleFilename("MaterialGetEmissiveColor.mod");
	AddModuleFilename("MaterialGetShininess.mod");
	AddModuleFilename("MaterialGetTransparency.mod");

	AddModuleFilename("MathIncrement.mod");
	AddModuleFilename("MathDecrement.mod");
	AddModuleFilename("MathAbs.mod");
	AddModuleFilename("MathNegative.mod");
	AddModuleFilename("MathPow.mod");
	AddModuleFilename("MathSqrt.mod");
	AddModuleFilename("MathMin.mod");
	AddModuleFilename("MathMax.mod");
	AddModuleFilename("MathLog.mod");
	AddModuleFilename("MathExp.mod");
	AddModuleFilename("MathSin.mod");
	AddModuleFilename("MathCos.mod");
	AddModuleFilename("MathTan.mod");
	AddModuleFilename("MathASin.mod");
	AddModuleFilename("MathACos.mod");
	AddModuleFilename("MathATan.mod");
	AddModuleFilename("MathDegree2Radian.mod");
	AddModuleFilename("MathRadian2Degree.mod");

	AddModuleFilename("MiscGetTime.mod");
	AddModuleFilename("MiscRandom.mod");
	AddModuleFilename("MiscBeep.mod");
	AddModuleFilename("MiscPlaySound.mod");
	AddModuleFilename("MiscJavaConsole.mod");
	//AddModuleFilename("MiscObjectCollision.mod");

	AddModuleFilename("NumericAdd2Values.mod");
	AddModuleFilename("NumericSub2Values.mod");
	AddModuleFilename("NumericMulti2Values.mod");
	AddModuleFilename("NumericDiv2Values.mod");
	AddModuleFilename("NumericMod2Values.mod");
	AddModuleFilename("NumericAnd2Values.mod");
	AddModuleFilename("NumericOr2Values.mod");
	AddModuleFilename("NumericXor2Values.mod");

	AddModuleFilename("ObjectSetLocation.mod");
	AddModuleFilename("ObjectSetRotation.mod");
	AddModuleFilename("ObjectSetScale.mod");
	AddModuleFilename("ObjectSetCenter.mod");
	AddModuleFilename("ObjectGetLocation.mod");
	AddModuleFilename("ObjectGetRotation.mod");
	AddModuleFilename("ObjectGetScale.mod");
	AddModuleFilename("ObjectGetCenter.mod");

	AddModuleFilename("StringValue.mod");
	AddModuleFilename("StringPosition.mod");
	AddModuleFilename("StringDirection.mod");
	AddModuleFilename("StringRotation.mod");
	AddModuleFilename("StringBool.mod");
	AddModuleFilename("StringColor.mod");
	AddModuleFilename("StringPI.mod");
	AddModuleFilename("StringE.mod");
	AddModuleFilename("StringDivide2Values.mod");
	AddModuleFilename("StringDivide3Values.mod");
	AddModuleFilename("StringDivide4Values.mod");
	AddModuleFilename("StringMerge2Values.mod");
	AddModuleFilename("StringMerge3Values.mod");
	AddModuleFilename("StringMerge4Values.mod");
	AddModuleFilename("StringSelector.mod");
	AddModuleFilename("StringSetValue.mod");
	AddModuleFilename("StringSetArrayValue.mod");
	AddModuleFilename("StringGetValue.mod");
	AddModuleFilename("StringGetArrayValue.mod");

	AddModuleFilename("SystemArea.mod");
	AddModuleFilename("SystemClock.mod");
	AddModuleFilename("SystemDrag.mod");
	AddModuleFilename("SystemFrame.mod");
	AddModuleFilename("SystemPickup.mod");

	AddModuleFilename("ViewSetPosition.mod");
	AddModuleFilename("ViewSetOrientation.mod");
	AddModuleFilename("ViewSetFOV.mod");
	AddModuleFilename("ViewGetPosition.mod");
	AddModuleFilename("ViewGetOrientation.mod");
	AddModuleFilename("ViewGetFOV.mod");

	AddModuleFilename("GeometryInverse.mod");
	AddModuleFilename("GeometryNormalize.mod");
	AddModuleFilename("GeometryGetDistance.mod");
	AddModuleFilename("GeometryGetAngle.mod");
	AddModuleFilename("GeometryGetDot.mod");
	AddModuleFilename("GeometryGetLength.mod");
	AddModuleFilename("GeometryGetCross.mod");
	AddModuleFilename("GeometryGetVector.mod");
	AddModuleFilename("GeometryRotate.mod");

	AddModuleFilename("InterpScalar.mod");
	AddModuleFilename("InterpPosition.mod");
	AddModuleFilename("InterpNormal.mod");
	AddModuleFilename("InterpOrientation.mod");
	AddModuleFilename("InterpColor.mod");

	AddModuleFilename("NodeSetSwitch.mod");
	AddModuleFilename("NodeSetText.mod");
	AddModuleFilename("NodeSetSkyColor.mod");
	//AddModuleFilename("NodeSetImageTexture.mod");
	//AddModuleFilename("NodeSetAudioClip.mod");
}

void ModuleFilenameDelete(void)
{
	delete mModuleFilenameVector;
}

int GetNModuleFilenames(void)
{
	return mModuleFilenameVector->size();
}

char *GetModuleFilename(int n)
{
	CModuleFilename *moduleFilename = mModuleFilenameVector->elementAt(n);
	if (moduleFilename == NULL)
		return NULL;
	return moduleFilename->getFilename();
}
