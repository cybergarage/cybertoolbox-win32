package vrml.field;

import java.io.PrintStream;
import vrml.*;

public class ConstMFFloat extends ConstMField {

	public ConstMFFloat() {
		setType(fieldTypeConstMFFloat);
	}

	public ConstMFFloat(MFFloat values) {
		setType(fieldTypeConstMFFloat);
		copy(values);
	}

	public ConstMFFloat(ConstMFFloat values) {
		setType(fieldTypeConstMFFloat);
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
		float value[] = new float[3];
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