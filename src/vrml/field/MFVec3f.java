package vrml.field;

import java.io.PrintStream;
import vrml.*;

public class MFVec3f extends MField {

	public MFVec3f() {
		setType(fieldTypeMFVec3f);
	}

	public MFVec3f(MFVec3f vectors) {
		setType(fieldTypeMFVec3f);
		copy(vectors);
	}

	public MFVec3f(ConstMFVec3f vectors) {
		setType(fieldTypeMFVec3f);
		copy(vectors);
	}

	public void addValue(float x, float y, float z) {
		SFVec3f vector = new SFVec3f(x, y, z);
		add(vector);
	}

	public void addValue(float value[]) {
		SFVec3f vector = new SFVec3f(value);
		add(vector);
	}

	public void addValue(SFVec3f vector) {
		add(vector);
	}

	public void insertValue(int index, float x, float y, float z) {
		SFVec3f vector = new SFVec3f(x, y, z);
		insert(vector, index);
	}

	public void insertValue(int index, float value[]) {
		SFVec3f vector = new SFVec3f(value);
		insert(vector, index);
	}

	public void insertValue(int index, SFVec3f vector) {
		insert(vector, index);
	}

	public void get1Value(int index, float value[]) {
		SFVec3f vector = (SFVec3f)getObject(index);
		vector.getValue(value);
	}

	public void set1Value(int index, float value[]) {
		SFVec3f vector = (SFVec3f)getObject(index);
		vector.setValue(value);
	}

	public void set1Value(int index, float x, float y, float z) {
		SFVec3f vector = (SFVec3f)getObject(index);
		vector.setValue(x, y, z);
	}

	////////////////////////////////////////////////
	//	Output
	////////////////////////////////////////////////

	public void outputContext(PrintStream printStream, String indentString) {
		float value[] = new float[3];
		for (int n=0; n<getSize(); n++) {
			get1Value(n, value);
			if (n < getSize()-1)
				printStream.println(indentString + value[X] + " " + value[Y] + " " + value[Z] + ",");
			else	
				printStream.println(indentString + value[X] + " " + value[Y] + " " + value[Z]);
		}
	}

	////////////////////////////////////////////////
	//	toString
	////////////////////////////////////////////////

	public String toString() {
		return null;
	}

}