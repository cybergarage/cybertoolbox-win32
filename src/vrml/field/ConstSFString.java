package vrml.field;

import vrml.*;

public class ConstSFString extends ConstField {

	public String mValue = null; 

	public ConstSFString() {
		setType(fieldTypeConstSFString);
	}

	public ConstSFString(SFString string) {
		setType(fieldTypeConstSFString);
		setValue(string);
	}

	public ConstSFString(ConstSFString string) {
		setType(fieldTypeConstSFString);
		setValue(string);
	}

	public ConstSFString(String value) {
		setType(fieldTypeConstSFString);
		setValue(value);
	}

	public void setValue(String value) {
		mValue = value;
	}

	public void setValue(SFString value) {
		setValue(value.getValue());
	}

	public void setValue(ConstSFString value) {
		setValue(value.getValue());
	}

	public String getValue() {
		return mValue;
	}

	////////////////////////////////////////////////
	//	toString
	////////////////////////////////////////////////

	public String toString() {
		return mValue;
	}
}