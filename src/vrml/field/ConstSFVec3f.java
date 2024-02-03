package vrml.field;

import vrml.*;

public class ConstSFVec3f extends ConstField {

	private float mValue[] = new float[3]; 

	public ConstSFVec3f() {
		setType(fieldTypeConstSFVec3f);
		setValue(0.0f, 0.0f, 0.0f);
	}

	public ConstSFVec3f(SFVec3f vector) {
		setType(fieldTypeConstSFVec3f);
		setValue(vector);
	}

	public ConstSFVec3f(ConstSFVec3f vector) {
		setType(fieldTypeConstSFVec3f);
		setValue(vector);
	}

	public ConstSFVec3f(float x, float y, float z) {
		setType(fieldTypeConstSFVec3f);
		setValue(x, y, z);
	}

	public ConstSFVec3f(float value[]) {
		setType(fieldTypeConstSFVec3f);
		setValue(value);
	}

	////////////////////////////////////////////////
	//	get value
	////////////////////////////////////////////////

	public void getValue(float value[]) {
		value[0] = mValue[0];
		value[1] = mValue[1];
		value[2] = mValue[2];
	}

	public float[] getValue() {
		return mValue;
	}

	public float getX() {
		return mValue[0];
	}

	public float getY() {
		return mValue[1];
	}

	public float getZ() {
		return mValue[2];
	}

	////////////////////////////////////////////////
	//	set value
	////////////////////////////////////////////////

	public void setValue(float x, float y, float z) {
		mValue[0] = x;
		mValue[1] = y;
		mValue[2] = z;
	}

	public void setValue(float value[]) {
		mValue[0] = value[0];
		mValue[1] = value[1];
		mValue[2] = value[2];
	}

	public void setValue(SFVec3f vector) {
		setValue(vector.getX(), vector.getY(), vector.getZ());
	}

	public void setValue(ConstSFVec3f vector) {
		setValue(vector.getX(), vector.getY(), vector.getZ());
	}

	////////////////////////////////////////////////
	//	add value
	////////////////////////////////////////////////

	public void add(float x, float y, float z) {
		mValue[0] += x;
		mValue[1] += y;
		mValue[2] += z;
	}

	public void add(float value[]) {
		mValue[0] += value[0];
		mValue[1] += value[1];
		mValue[2] += value[2];
	}

	public void add(SFVec3f value) {
		add(value.getValue());
	}

	////////////////////////////////////////////////
	//	sub value
	////////////////////////////////////////////////

	public void sub(float x, float y, float z) {
		mValue[0] -= x;
		mValue[1] -= y;
		mValue[2] -= z;
	}

	public void sub(float value[]) {
		mValue[0] -= value[0];
		mValue[1] -= value[1];
		mValue[2] -= value[2];
	}

	public void sub(SFVec3f value) {
		sub(value.getValue());
	}

	////////////////////////////////////////////////
	//	scale
	////////////////////////////////////////////////

	public void scale(float scale) {
		mValue[0] *= scale;
		mValue[1] *= scale;
		mValue[2] *= scale;
	}

	////////////////////////////////////////////////
	//	invert
	////////////////////////////////////////////////

	public void invert() {
		mValue[0] = -mValue[0];
		mValue[1] = -mValue[1];
		mValue[2] = -mValue[2];
	}

	////////////////////////////////////////////////
	//	scalar
	////////////////////////////////////////////////

	public float getScalar()
	{
		return (float)Math.sqrt(mValue[0]*mValue[0]+mValue[1]*mValue[1]+mValue[2]*mValue[2]);
	}

	////////////////////////////////////////////////
	//	toString
	////////////////////////////////////////////////

	public String toString() {
		return mValue[0] + " " + mValue[1] + " " + mValue[2];
	}
}