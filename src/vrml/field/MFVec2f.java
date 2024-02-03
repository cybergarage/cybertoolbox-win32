package vrml.field;

import java.io.PrintStream;
import vrml.*;

public class MFVec2f extends MField {

	public MFVec2f() {
		setType(fieldTypeMFVec2f);
	}

	public MFVec2f(MFVec2f vectors) {
		setType(fieldTypeMFVec2f);
		copy(vectors);
	}

	public MFVec2f(ConstMFVec2f vectors) {
		setType(fieldTypeMFVec2f);
		copy(vectors);
	}

	public void addValue(float x, float y) {
		SFVec2f vector = new SFVec2f(x, y);
		add(vector);
	}

	public void addValue(float value[]) {
		SFVec2f vector = new SFVec2f(value);
		add(vector);
	}

	public void addValue(SFVec2f vector) {
		add(vector);
	}

	public void insertValue(int index, float x, float y) {
		SFVec2f vector = new SFVec2f(x, y);
		insert(vector, index);
	}

	public void insertValue(int index, float value[]) {
		SFVec2f vector = new SFVec2f(value);
		insert(vector, index);
	}

	public void insertValue(int index, SFVec2f vector) {
		insert(vector, index);
	}

	public void get1Value(int index, float value[]) {
		SFVec2f vector = (SFVec2f)getObject(index);
		vector.getValue(value);
	}

	public void set1Value(int index, float value[]) {
		SFVec2f vector = (SFVec2f)getObject(index);
		vector.setValue(value);
	}

	public void set1Value(int index, float x, float y) {
		SFVec2f vector = (SFVec2f)getObject(index);
		vector.setValue(x, y);
	}

	////////////////////////////////////////////////
	//	Output
	////////////////////////////////////////////////

	public void outputContext(PrintStream printStream, String indentString) {
		float value[] = new float[2];
		for (int n=0; n<getSize(); n++) {
			get1Value(n, value);
			if (n < getSize()-1)
				printStream.println(indentString + value[X] + " " + value[Y] + ",");
			else	
				printStream.println(indentString + value[X] + " " + value[Y]);
		}
	}

	////////////////////////////////////////////////
	//	toString
	////////////////////////////////////////////////

	public String toString() {
		return null;
	}
}