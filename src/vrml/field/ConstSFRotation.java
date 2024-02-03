package vrml.field;

import vrml.*;

public class ConstSFRotation extends ConstField {

	private SFVec3f	mVector = new SFVec3f(0.0f, 0.0f, 1.0f);
	private float	mAngle = 0.0f;

	public ConstSFRotation() {
		setType(fieldTypeConstSFRotation);
		setValue(0.0f, 0.0f, 1.0f, 0.0f);
	}

	public ConstSFRotation(SFRotation rotation) {
		setType(fieldTypeConstSFRotation);
		setValue(rotation);
	}

	public ConstSFRotation(ConstSFRotation rotation) {
		setType(fieldTypeConstSFRotation);
		setValue(rotation);
	}


	public ConstSFRotation(float x, float y, float z, float rot) {
		setType(fieldTypeConstSFRotation);
		setValue(x, y, z, rot);
	}

	public ConstSFRotation(float value[]) {
		setType(fieldTypeSFRotation);
		setValue(value);
	}

	////////////////////////////////////////////////
	//	set value
	////////////////////////////////////////////////

	public void setValue(float x, float y, float z, float rot) {
		mVector.setValue(x, y, z);
		mVector.normalize();
		mAngle = rot;
	}

	public void setValue(float value[]) {
		mVector.setValue(value);
		mVector.normalize();
		mAngle = value[3];
	}

	public void setValue(SFRotation rotation) {
		setValue(rotation.getX(), rotation.getY(), rotation.getZ(), rotation.getAngle());
	}

	public void setValue(ConstSFRotation rotation) {
		setValue(rotation.getX(), rotation.getY(), rotation.getZ(), rotation.getAngle());
	}

	////////////////////////////////////////////////
	//	get value
	////////////////////////////////////////////////

	public void getValue(float value[]) {
		mVector.getValue(value);
		value[3] = mAngle;
	}

	public float[] getValue() {
		float value[] = new float[4];
		getValue(value);
		return value;
	}

	public void getVector(float vector[]) {
		mVector.getValue(vector);
	}

	public float[] getVector() {
		float vector[] = new float[3];
		mVector.getValue(vector);
		return vector;
	}

	float getX() {
		return mVector.getX();
	}

	float getY() {
		return mVector.getY();
	}

	float getZ() {
		return mVector.getZ();
	}

	public float getAngle() {
		return mAngle;
	}

	////////////////////////////////////////////////
	//	add 
	////////////////////////////////////////////////

	public void add(SFRotation rot)
	{
		SFMatrix m1 = new SFMatrix();
		getSFMatrix(m1);

		SFMatrix m2 = new SFMatrix();
		rot.getSFMatrix(m2);
		
		m1.add(m2);

		SFRotation newRotation = new SFRotation();
		m1.getSFRotation(newRotation);

		setValue(newRotation);
	}

	public void add(float rotationValue[]) {
		SFRotation rotation = new SFRotation(rotationValue);
		add(rotation);
	}

	public void add(float x, float y, float z, float rot) {
		SFRotation rotation = new SFRotation(x, y, z, rot);
		add(rotation);
	}

	////////////////////////////////////////////////
	//	multi 
	////////////////////////////////////////////////

	public void multi(float vector[])
	{
		SFMatrix m = new SFMatrix();
		getSFMatrix(m);
		m.multi(vector);
	}

	public void multi(SFVec3f vector)
	{
		SFMatrix m = new SFMatrix();
		getSFMatrix(m);
		m.multi(vector);
	}

	////////////////////////////////////////////////
	//	convert
	////////////////////////////////////////////////

	public void getSFMatrix(SFMatrix matrix)
	{
		float vector[] = getVector();
		float rotation = getAngle();

		float k = (float)(1.0 - Math.cos(rotation));
		float s = (float)Math.sin(rotation);
		float c = (float)Math.cos(rotation);
		float ax = vector[0];
		float ay = vector[1];
		float az = vector[2];
		float ax2 = ax * ax;
		float ay2 = ay * ay;
		float az2 = az * az;

		float ma[][] = new float[4][4];
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++)
				ma[i][j] = 0.0f;
		}

		ma[0][0] = k*ax2 + c;
		ma[0][1] = k*ax*ay + s*az;
		ma[0][2] = k*ax*az - s*ay;
		ma[1][0] = k*ax*ay - s*az;
		ma[1][1] = k*ay2 + c;
		ma[1][2] = k*ay*az + s*ax;
		ma[2][0] = k*ax*az + s*ay;
		ma[2][1] = k*ay*az - s*ax;
		ma[2][2] = k*az2 + c;

		matrix.setValue(ma);
	}

	////////////////////////////////////////////////
	//	invert
	////////////////////////////////////////////////

	public void invert() {
		mAngle = -mAngle;
	}

	////////////////////////////////////////////////
	//	toString
	////////////////////////////////////////////////

	public String toString() {
		float vector[] = new float[3];
		getVector(vector);
		return vector[0] + " " + vector[1] + " " + vector[2] + " " + getAngle();
	}

	////////////////////////////////////////////////
	//	initialization
	////////////////////////////////////////////////

	public void initValue()
	{
		setValue(0.0f, 0.0f, 1.0f, 0.0f);
	}
}