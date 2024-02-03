package vrml.field;

import java.io.PrintStream;
import vrml.*;

public class MFFloat extends MField {

	public MFFloat() {
		setType(fieldTypeMFFloat);
	}

	public MFFloat(MFFloat values) {
		setType(fieldTypeMFFloat);
		copy(values);
	}

	public MFFloat(ConstMFFloat values) {
		setType(fieldTypeMFFloat);
		copy(values);
	}

	public void addValue(float value) {
		SFFloat sfvalue = new SFFloat(value);
		add(sfvalue);
	}

	public void addValue(SFFloat sfvalue) {
		add(sfvalue);
	}

	public void insertValue(int index, float value) {
		SFFloat sfvalue = new SFFloat(value);
		insert(sfvalue, index);
	}

	public float get1Value(int index) {
		SFFloat sfvalue = (SFFloat)getObject(index);
		return sfvalue.getValue();
	}

	public void set1Value(int index, float value) {
		SFFloat sfvalue = (SFFloat)getObject(index);
		sfvalue.setValue(value);
	}

	////////////////////////////////////////////////
	//	Output
	////////////////////////////////////////////////

	public void outputContext(PrintStream printStream, String indentString) {
		for (int n=0; n<getSize(); n++) {
			if (n < getSize()-1)
				printStream.println(indentString + get1Value(n) + ",");
			else	
				printStream.println(indentString + get1Value(n));
		}
	}

	////////////////////////////////////////////////
	//	toString
	////////////////////////////////////////////////

	public String toString() {
		return null;
	}
}