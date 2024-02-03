package vrml.field;

import vrml.*;

public class SFInt32 extends Field {

	public int mValue; 

	public SFInt32() {
		setType(fieldTypeSFInt32);
		setValue(0);
	}

	public SFInt32(SFInt32 value) {
		setType(fieldTypeSFInt32);
		setValue(value);
	}

	public SFInt32(ConstSFInt32 value) {
		setType(fieldTypeSFInt32);
		setValue(value);
	}

	public SFInt32(int value) {
		setType(fieldTypeSFInt32);
		setValue(value);
	}

	public SFInt32(String value) {
		setType(fieldTypeSFInt32);
		setValue(value);
	}

	public void setValue(int value) {
		mValue = value;
	}

	public void setValue(SFInt32 value) {
		mValue = value.getValue();
	}

	public void setValue(ConstSFInt32 value) {
		mValue = value.getValue();
	}

	public void setValue(String value) {
		Integer ivalue = new Integer(value);
		setValue(ivalue.intValue());
	}

	public int getValue() {
		return mValue;
	}

	////////////////////////////////////////////////
	//	toString
	////////////////////////////////////////////////

	public String toString() {
		Integer value = new Integer(mValue);
		return value.toString();
	}
}