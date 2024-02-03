package vrml.field;

import java.io.PrintStream;
import vrml.*;

public class ConstMFString extends ConstMField {

	public ConstMFString() {
		setType(fieldTypeConstMFString);
	}

	public ConstMFString(MFString strings) {
		setType(fieldTypeConstMFString);
		copy(strings);
	}

	public ConstMFString(ConstMFString strings) {
		setType(fieldTypeConstMFString);
		copy(strings);
	}


	public void addValue(String value) {
		SFString sfvalue = new SFString(value);
		add(sfvalue);
	}

	public void addValue(SFString sfvalue) {
		add(sfvalue);
	}

	public void insertValue(int index, String value) {
		SFString sfvalue = new SFString(value);
		insert(sfvalue, index);
	}

	public String get1Value(int index) {
		SFString sfvalue = (SFString)getObject(index);
		return sfvalue.getValue();
	}

	public void set1Value(int index, String value) {
		SFString sfvalue = (SFString)getObject(index);
		sfvalue.setValue(value);
	}

	////////////////////////////////////////////////
	//	Output
	////////////////////////////////////////////////

	public void outputContext(PrintStream printStream, String indentString) {
		float value[] = new float[3];
		for (int n=0; n<getSize(); n++) {
			if (n < getSize()-1)
				printStream.println(indentString + "\"" + get1Value(n) + "\"" + ",");
			else	
				printStream.println(indentString + "\"" + get1Value(n) + "\"");
		}
	}

	////////////////////////////////////////////////
	//	toString
	////////////////////////////////////////////////

	public String toString() {
		return null;
	}
}