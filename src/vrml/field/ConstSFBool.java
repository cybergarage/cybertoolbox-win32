package vrml.field;

import vrml.*;

public class ConstSFBool extends ConstField {

	public boolean mValue; 

	public ConstSFBool() {
		setType(fieldTypeConstSFBool);
		setValue(true);
	}

	public ConstSFBool(SFBool value) {
		setType(fieldTypeConstSFBool);
		setValue(value);
	}

	public ConstSFBool(ConstSFBool value) {
		setType(fieldTypeConstSFBool);
		setValue(value);
	}

	public ConstSFBool(boolean value) {
		setType(fieldTypeConstSFBool);
		setValue(value);
	}

	public ConstSFBool(String value) {
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