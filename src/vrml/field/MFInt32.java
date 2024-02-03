package vrml.field;

import java.io.PrintStream;
import vrml.*;

public class MFInt32 extends MField {

	public MFInt32() {
		setType(fieldTypeMFInt32);
	}

	public MFInt32(MFInt32 values) {
		setType(fieldTypeMFInt32);
		copy(values);
	}

	public MFInt32(ConstMFInt32 values) {
		setType(fieldTypeMFInt32);
		copy(values);
	}

	public void addValue(int value) {
		SFInt32 sfvalue = new SFInt32(value);
		add(sfvalue);
	}

	public void addValue(SFInt32 sfvalue) {
		add(sfvalue);
	}

	public void insertValue(int index, int value) {
		SFInt32 sfvalue = new SFInt32(value);
		insert(sfvalue, index);
	}

	public int get1Value(int index) {
		SFInt32 sfvalue = (SFInt32)getObject(index);
		return sfvalue.getValue();
	}

	public void set1Value(int index, int value) {
		SFInt32 sfvalue = (SFInt32)getObject(index);
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