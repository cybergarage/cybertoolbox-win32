package vrml.field;

import vrml.*;

public class SFFloat extends Field {

	public float mValue; 

	public SFFloat() {
		setType(fieldTypeSFFloat);
		setValue(0.0f);
	}

	public SFFloat(SFFloat value) {
		setType(fieldTypeSFFloat);
		setValue(value);
	}

	public SFFloat(ConstSFFloat value) {
		setType(fieldTypeSFFloat);
		setValue(value);
	}

	public SFFloat(float value) {
		setType(fieldTypeSFFloat);
		setValue(value);
	}

	public SFFloat(String value) {
		setType(fieldTypeSFFloat);
		setValue(value);
	}

	public void setValue(float value) {
		mValue = value;
	}

	public void setValue(SFFloat fvalue) {
		mValue = fvalue.getValue();
	}

	public void setValue(ConstSFFloat fvalue) {
		mValue = fvalue.getValue();
	}

	public void setValue(String value) {
		Float fvalue = new Float(value);
		setValue(fvalue.floatValue());
	}

	public float getValue() {
		return mValue;
	}

	////////////////////////////////////////////////
	//	toString
	////////////////////////////////////////////////

	public String toString() {
		Float value = new Float(mValue);
		return value.toString();
	}
}