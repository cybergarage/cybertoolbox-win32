package vrml.field;

import vrml.*;

public class SFTime extends Field {

	public double mValue; 
	
	public SFTime() {
		setType(fieldTypeSFTime);
		setValue(-1);
	}

	public SFTime(SFTime time) {
		setType(fieldTypeSFTime);
		setValue(time);
	}

	public SFTime(ConstSFTime time) {
		setType(fieldTypeSFTime);
		setValue(time);
	}

	public SFTime(double value) {
		setType(fieldTypeSFTime);
		setValue(value);
	}

	public SFTime(String value) {
		setType(fieldTypeSFTime);
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