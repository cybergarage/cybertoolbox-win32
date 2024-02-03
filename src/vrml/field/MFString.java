package vrml.field;

import java.io.PrintStream;
import vrml.*;

public class MFString extends MField {

	public MFString() {
		setType(fieldTypeMFString);
	}

	public MFString(MFString strings) {
		setType(fieldTypeMFString);
		copy(strings);
	}

	public MFString(ConstMFString strings) {
		setType(fieldTypeMFString);
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