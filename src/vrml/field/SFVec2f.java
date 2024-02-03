package vrml.field;

import vrml.*;

public class SFVec2f extends Field {

	private float mValue[] = new float[2]; 

	public SFVec2f() {
		setType(fieldTypeSFVec2f);
		setValue(0.0f, 0.0f);
	}

	public SFVec2f(SFVec2f vector) {
		setType(fieldTypeSFVec2f);
		setValue(vector);
	}

	public SFVec2f(ConstSFVec2f vector) {
		setType(fieldTypeSFVec2f);
		setValue(vector);
	}

	public SFVec2f(float x, float y) {
		setType(fieldTypeSFVec2f);
		setValue(x, y);
	}

	public SFVec2f(float value[]) {
		setType(fieldTypeSFVec2f);
		setValue(value);
	}

	////////////////////////////////////////////////
	//	get value
	////////////////////////////////////////////////

	public void getValue(float value[]) {
		value[0] = mValue[0];
		value[1] = mValue[1];
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

	////////////////////////////////////////////////
	//	set value
	////////////////////////////////////////////////

	public void setValue(float x, float y) {
		mValue[0] = x;
		mValue[1] = y;
	}

	public void setValue(float value[]) {
		mValue[0] = value[0];
		mValue[1] = value[1];
	}

	public void setValue(SFVec2f vector) {
		setValue(vector.getX(), vector.getY());
	}

	public void setValue(ConstSFVec2f vector) {
		setValue(vector.getX(), vector.getY());
	}

	////////////////////////////////////////////////
	//	add value
	////////////////////////////////////////////////

	public void add(float x, float y) {
		mValue[0] += x;
		mValue[1] += y;
	}

	public void add(float value[]) {
		mValue[0] += value[0];
		mValue[1] += value[1];
	}

	public void add(SFVec2f value) {
		add(value.getValue());
	}

	////////////////////////////////////////////////
	//	sub value
	////////////////////////////////////////////////

	public void sub(float x, float y) {
		mValue[0] -= x;
		mValue[1] -= y;
	}

	public void sub(float value[]) {
		mValue[0] -= value[0];
		mValue[1] -= value[1];
	}

	public void sub(SFVec2f value) {
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
	}

	////////////////////////////////////////////////
	//	scale
	////////////////////////////////////////////////

	public float getScalar()
	{
		return (float)Math.sqrt(mValue[0]*mValue[0]+mValue[1]*mValue[1]);
	}

	////////////////////////////////////////////////
	//	normalize
	////////////////////////////////////////////////

	public void normalize()
	{
		float scale = getScalar();
		mValue[0] /= scale;
		mValue[1] /= scale;
	}

	////////////////////////////////////////////////
	//	toString
	////////////////////////////////////////////////

	public String toString() {
		return mValue[0] + " " + mValue[1];
	}

}