package vrml.field;

import vrml.*;

public class ConstSFInt32 extends ConstField {

	public int mValue; 

	public ConstSFInt32() {
		setType(fieldTypeConstSFInt32);
		setValue(0);
	}

	public ConstSFInt32(SFInt32 value) {
		setType(fieldTypeConstMFInt32);
		setValue(value);
	}

	public ConstSFInt32(ConstSFInt32 value) {
		setType(fieldTypeConstMFInt32);
		setValue(value);
	}

	public ConstSFInt32(int value) {
		setType(fieldTypeConstSFInt32);
		setValue(value);
	}

	public ConstSFInt32(String value) {
		setType(fieldTypeConstSFInt32);
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