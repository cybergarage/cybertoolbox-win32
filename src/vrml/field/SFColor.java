package vrml.field;

import vrml.*;

public class SFColor extends Field {

	private float mValue[] = new float[3]; 

	public SFColor() {
		setType(fieldTypeSFColor);
		setValue(1.0f, 1.0f, 1.0f);
	}

	public SFColor(SFColor color) {
		setType(fieldTypeSFColor);
		setValue(color);
	}

	public SFColor(ConstSFColor color) {
		setType(fieldTypeSFColor);
		setValue(color);
	}

	public SFColor(float r, float g, float b) {
		setType(fieldTypeSFColor);
		setValue(r, g, b);
	}

	public SFColor(float value[]) {
		setType(fieldTypeSFColor);
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

	public float getRed() {
		return mValue[0];
	}

	public float getGreen() {
		return mValue[1];
	}

	public float getBlue() {
		return mValue[2];
	}

	////////////////////////////////////////////////
	//	set value
	////////////////////////////////////////////////

	public void setValue(float r, float g, float b) {
		mValue[0] = r;
		mValue[1] = g;
		mValue[2] = b;
	}

	public void setValue(float value[]) {
		mValue[0] = value[0];
		mValue[1] = value[1];
		mValue[2] = value[2];
	}

	public void setValue(SFColor color) {
		setValue(color.getRed(), color.getGreen(), color.getBlue());
	}

	public void setValue(ConstSFColor color) {
		setValue(color.getRed(), color.getGreen(), color.getBlue());
	}

	////////////////////////////////////////////////
	//	add value
	////////////////////////////////////////////////

	public void add(float x, float y, float z) {
		mValue[0] += x;
		mValue[1] += y;
		mValue[2] += z;
		mValue[0] /= 2.0f;
		mValue[1] /= 2.0f;
		mValue[2] /= 2.0f;
	}

	public void add(float value[]) {
		add(value[0], value[1], value[2]);
	}

	public void add(SFColor value) {
		add(value.getValue());
	}

	////////////////////////////////////////////////
	//	sub value
	////////////////////////////////////////////////

	public void sub(float x, float y, float z) {
		mValue[0] -= x;
		mValue[1] -= y;
		mValue[2] -= z;
		mValue[0] /= 2.0f;
		mValue[1] /= 2.0f;
		mValue[2] /= 2.0f;
	}

	public void sub(float value[]) {
		sub(value[0], value[1], value[2]);
	}

	public void sub(SFColor value) {
		sub(value.getValue());
	}

	////////////////////////////////////////////////
	//	toString
	////////////////////////////////////////////////

	public String toString() {
		return mValue[0] + " " + mValue[1] + " " + mValue[2];
	}

	////////////////////////////////////////////////
	//	scale
	////////////////////////////////////////////////

	public void scale(float scale) {
		mValue[0] *= scale;
		mValue[1] *= scale;
		mValue[2] *= scale;
	}

}