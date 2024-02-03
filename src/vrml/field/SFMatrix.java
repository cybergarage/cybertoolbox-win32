package vrml.field;

import vrml.*;

public class SFMatrix extends Field {

	private float mValue[][] = new float[4][4]; 

	public SFMatrix() {
		init();
	}

	public SFMatrix(float value[][]) {
		setValue(value);
	}

	public SFMatrix(SFMatrix value) {
		setValue(value);
	}

	////////////////////////////////////////////////
	//	set value 
	////////////////////////////////////////////////

	public void setValue(float value[][]) {
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++)
				mValue[i][j] = value[i][j];
		}
	}

	public void setValue(SFMatrix matrix) {
		float	value[][] = new float[4][4];
		matrix.getValue(value);
		setValue(value);
	}

	////////////////////////////////////////////////
	//	set as scaling value 
	////////////////////////////////////////////////

	public void setValueAsScaling(float value[]) {
		init();
		setValueAsScaling(value[0], value[1], value[2]);
	}

	public void setValueAsScaling(float x, float y, float z) {
		init();
		mValue[0][0] = x;
		mValue[1][1] = y;
		mValue[2][2] = z;
	}

	////////////////////////////////////////////////
	//	set as translation value 
	////////////////////////////////////////////////

	public void setValueAsTranslation(SFVec3f vector) {
		setValueAsTranslation(vector.getX(), vector.getY(), vector.getZ());
	}

	public void setValueAsTranslation(float value[]) {
		setValueAsTranslation(value[0], value[1], value[2]);
	}

	public void setValueAsTranslation(float x, float y, float z) {
		init();
		mValue[3][0] = x;
		mValue[3][1] = y;
		mValue[3][2] = z;
	}

	////////////////////////////////////////////////
	//	set as rotation value 
	////////////////////////////////////////////////

	public void setValueAsRotation(SFRotation rotation) {
		setValueAsRotation(rotation.getX(), rotation.getY(), rotation.getZ(), rotation.getAngle());
	}

	public void setValueAsRotation(float value[]) {
		setValueAsRotation(value[0], value[1], value[2], value[3]);
	}

	public void setValueAsRotation(float x, float y, float z, float rot) {
		SFRotation rotation = new SFRotation(x, y, z, rot);
		SFMatrix matrix = new SFMatrix();
		rotation.getSFMatrix(matrix);
		float value[][] = new float[4][4];
		matrix.getValue(value); 
		setValue(value);
	}

	////////////////////////////////////////////////
	//	get value
	////////////////////////////////////////////////

	public float[][] getValue() {
		return mValue;
	}

	public void getValue(float value[][]) {
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++)
				value[i][j] = mValue[i][j];
		}
	}

	////////////////////////////////////////////////
	//	get value only translation
	////////////////////////////////////////////////

	public float[] getValueOnlyTranslation() {
		float value[] = new float[3];
		getValueOnlyTranslation(value);
		return value;
	}

	public void getValueOnlyTranslation(float value[]) {
		value[0] = mValue[3][0];
		value[1] = mValue[3][1];
		value[2] = mValue[3][2];
	}

	////////////////////////////////////////////////
	//	add 
	////////////////////////////////////////////////

	public void add(SFMatrix matrix)
	{
		float ma1[][] = new float[4][4];
		float ma2[][] = new float[4][4];
		float maOut[][] = new float[4][4]; 

		getValue(ma1); 
		matrix.getValue(ma2); 
		
		for (int i = 0; i<4; i++) {
			for (int j = 0; j<4; j++) {
				maOut[j][i] = 0.0f;
				for (int k = 0; k<4; k++)
					maOut[j][i] += ma1[k][i]*ma2[j][k];
			}
		}
		
		setValue(maOut);
	}

	////////////////////////////////////////////////
	//	multi 
	////////////////////////////////////////////////

	public void multi(float vector[])
	{
		float vectorIn[] = new float[4];

		vectorIn[0] = vector[0];
		vectorIn[1] = vector[1];
		vectorIn[2] = vector[2];
		vectorIn[3] = 1.0f;

		float vectorOut[] = new float[4];

		float ma[][] = getValue(); 
		for (int n = 0; n<4; n++)
			vectorOut[n] = ma[0][n]*vectorIn[0] + ma[1][n]*vectorIn[1] + ma[2][n]*vectorIn[2] + ma[3][n]*vectorIn[3];

		vector[0] = vectorOut[0];
		vector[1] = vectorOut[1];
		vector[2] = vectorOut[2];
	}

	public void multi(SFVec3f vector)
	{
		float value[] = new float[3];
		vector.getValue(value);
		multi(value);
		vector.setValue(value);
	}

	////////////////////////////////////////////////
	//	convert
	////////////////////////////////////////////////

	public void getSFRotation(SFRotation rotation)
	{
		float x, y, z, w;

		float m[][] = new float[4][4];
		getValue(m);

		float w2 = 1.0f/4.0f*(1.0f + m[0][0] + m[1][1] + m[2][2]);
		if (0.0f < w2) {
			w = (float)Math.sqrt(w2);
			x = (m[1][2] - m[2][1])/(4.0f*w);
			y = (m[2][0] - m[0][2])/(4.0f*w);
			z = (m[0][1] - m[1][0])/(4.0f*w);
		}
		else {
			w = 0.0f;
			float x2 = -1.0f/(2.0f*(m[1][1] + m[2][2]));
			if (0.0f < x2) {
				x = (float)Math.sqrt(x2);
				y = m[0][1] / (2.0f*x);
				z = m[0][2] / (2.0f*x);
			}
			else {
				x = 0.0f;
				float y2 = 1.0f / (2.0f*(1.0f - m[2][2]));
				if (0.0f < y2) {
					y = (float)Math.sqrt(y2);
					z = m[1][2] / (2.0f*y);
				}
				else {
					y = 0.0f;
					z = 1.0f;
				}
			}
		}

		float angle = (float)Math.acos(2.0f*w*w - 1.0f);
		float value[] = new float[4];
		if (angle != 0.0f) {
			value[0] = x / (float)Math.sin(angle);
			value[1] = y / (float)Math.sin(angle);
			value[2] = z / (float)Math.sin(angle);
			value[3] = angle;
		}
		else {
			value[0] = 0.0f;
			value[1] = 0.0f;
			value[2] = 1.0f;
			value[3] = 0.0f;
		}

		rotation.setValue(value);
	}

	////////////////////////////////////////////////
	//	toString
	////////////////////////////////////////////////

	public String toString() {
		return	mValue[0][0] + " " + mValue[0][1] + " " + mValue[0][2] + " " + mValue[0][3] + "\n" +
				mValue[1][0] + " " + mValue[1][1] + " " + mValue[1][2] + " " + mValue[1][3] + "\n" +
				mValue[2][0] + " " + mValue[2][1] + " " + mValue[2][2] + " " + mValue[2][3] + "\n" +
				mValue[3][0] + " " + mValue[3][1] + " " + mValue[3][2] + " " + mValue[3][3];
	}

	////////////////////////////////////////////////
	//	other
	////////////////////////////////////////////////

	public void init()
	{
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++)
				mValue[i][j] = 0.0f;
		}

		for (int n=0; n<4; n++)
			mValue[n][n] = 1.0f;
	}
}