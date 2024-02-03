package vrml.field;

import vrml.*;

public class ConstSFTime extends ConstField {

	public double mValue; 

	public ConstSFTime() {
		setType(fieldTypeConstSFTime);
		setValue(-1.0);
	}

	public ConstSFTime(SFTime time) {
		setType(fieldTypeConstSFTime);
		setValue(time);
	}

	public ConstSFTime(ConstSFTime time) {
		setType(fieldTypeConstSFTime);
		setValue(time);
	}

	public ConstSFTime(double value) {
		setType(fieldTypeConstSFTime);
		setValue(value);
	}

	public ConstSFTime(String value) {
		setType(fieldTypeConstSFTime);
		setValue(value);
	}

	public void setValue(double value) {
		mValue = value;
	}

	public void setValue(SFTime value) {
		mValue = value.getValue();
	}

	public void setValue(ConstSFTime value) {
		mValue = value.getValue();
	}

	public void setValue(String value) {
		Double dvalue = new Double(value);
		setValue(dvalue.doubleValue());
	}

	public double getValue() {
		return mValue;
	}

	////////////////////////////////////////////////
	//	toString
	////////////////////////////////////////////////

	public String toString() {
		Double value = new Double(mValue);
		return value.toString();
	}
}