package vrml.field;

import vrml.*;

public class SFString extends Field {

	public String mValue = null; 

	public SFString() {
		setType(fieldTypeSFString);
	}

	public SFString(SFString string) {
		setType(fieldTypeSFString);
		setValue(string);
	}

	public SFString(ConstSFString string) {
		setType(fieldTypeSFString);
		setValue(string);
	}

	public SFString(String value) {
		setType(fieldTypeSFString);
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
		return "\"" + mValue + "\"";
	}
}