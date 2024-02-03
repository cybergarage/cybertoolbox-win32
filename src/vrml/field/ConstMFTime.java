package vrml.field;

import java.io.PrintStream;
import vrml.*;

public class ConstMFTime extends ConstMField {

	public ConstMFTime() {
		setType(fieldTypeConstMFTime);
	}

	public ConstMFTime(MFTime times) {
		setType(fieldTypeConstMFTime);
		copy(times);
	}

	public ConstMFTime(ConstMFTime times) {
		setType(fieldTypeConstMFTime);
		copy(times);
	}

	public void addValue(double value) {
		SFTime sfvalue = new SFTime(value);
		add(sfvalue);
	}

	public void addValue(SFTime sfvalue) {
		add(sfvalue);
	}

	public void insertValue(int index, double value) {
		SFTime sfvalue = new SFTime(value);
		insert(sfvalue, index);
	}

	public double get1Value(int index) {
		SFTime sfvalue = (SFTime)getObject(index);
		return sfvalue.getValue();
	}

	public void set1Value(int index, double value) {
		SFTime sfvalue = (SFTime)getObject(index);
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