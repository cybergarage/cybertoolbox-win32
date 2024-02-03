package vrml.field;

import vrml.*;

public class ConstSFFloat extends ConstField {

	public float mValue; 

	public ConstSFFloat() {
		setType(fieldTypeConstSFFloat);
		setValue(0.0f);
	}

	public ConstSFFloat(SFFloat value) {
		setType(fieldTypeConstSFFloat);
		setValue(value);
	}

	public ConstSFFloat(ConstSFFloat value) {
		setType(fieldTypeConstSFFloat);
		setValue(value);
	}

	public ConstSFFloat(float value) {
		setType(fieldTypeConstSFFloat);
		setValue(value);
	}

	public ConstSFFloat(String value) {
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