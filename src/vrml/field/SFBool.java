package vrml.field;

import vrml.*;

public class SFBool extends Field {

	public boolean mValue; 

	public SFBool() {
		setType(fieldTypeSFBool);
		setValue(true);
	}

	public SFBool(SFBool value) {
		setType(fieldTypeSFBool);
		setValue(value);
	}

	public SFBool(ConstSFBool value) {
		setType(fieldTypeSFBool);
		setValue(value);
	}

	public SFBool(boolean value) {
		setType(fieldTypeSFBool);
		setValue(value);
	}

	public SFBool(String value) {
		setType(fieldTypeSFBool);
		setValue(value);
	}

	public void setValue(boolean value) {
		mValue = value;
	}

	public void setValue(SFBool value) {
		mValue = value.getValue();
	}

	public void setValue(ConstSFBool value) {
		mValue = value.getValue();
	}

	public void setValue(String value) {
		if (value.compareTo("TRUE") == 0)
			setValue(true);
		else
			setValue(false);
	}

	public boolean getValue() {
		return mValue;
	}

	////////////////////////////////////////////////
	//	toString
	////////////////////////////////////////////////

	public String toString() {
		if (mValue)
			return "TRUE";
		else
			return "FALSE";
	}
}