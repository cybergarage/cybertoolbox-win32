package vrml.field;

import java.io.PrintStream;
import vrml.*;

public class MFRotation extends MField {

	public MFRotation() {
		setType(fieldTypeMFRotation);
	}

	public MFRotation(MFRotation rotations) {
		setType(fieldTypeMFRotation);
		copy(rotations);
	}

	public MFRotation(ConstMFRotation rotations) {
		setType(fieldTypeMFRotation);
		copy(rotations);
	}

	public void addValue(float x, float y, float z, float rot) {
		SFRotation rotation = new SFRotation(x, y, z, rot);
		add(rotation);
	}

	public void addValue(float value[]) {
		SFRotation rotation = new SFRotation(value);
		add(rotation);
	}

	public void addValue(SFRotation rotation) {
		add(rotation);
	}

	public void insertValue(int index, float x, float y, float z, float rot) {
		SFRotation rotation = new SFRotation(x, y, z, rot);
		insert(rotation, index);
	}

	public void insertValue(int index, float value[]) {
		SFRotation rotation = new SFRotation(value);
		insert(rotation, index);
	}

	public void insertValue(int index, SFRotation rotation) {
		insert(rotation, index);
	}

	public void get1Value(int index, float value[]) {
		SFRotation rotation = (SFRotation)getObject(index);
		rotation.getValue(value);
	}

	public void set1Value(int index, float value[]) {
		SFRotation rotation = (SFRotation)getObject(index);
		rotation.setValue(value);
	}

	public void set1Value(int index, float x, float y, float z, float angle) {
		SFRotation rotation = (SFRotation)getObject(index);
		rotation.setValue(x, y, z, angle);
	}

	////////////////////////////////////////////////
	//	Output
	////////////////////////////////////////////////

	public void outputContext(PrintStream printStream, String indentString) {
		float value[] = new float[4];
		for (int n=0; n<getSize(); n++) {
			get1Value(n, value);
			if (n < getSize()-1)
				printStream.println(indentString + value[X] + " " + value[Y] + " " + value[Z] + " " + value[3] + ",");
			else	
				printStream.println(indentString + value[X] + " " + value[Y] + " " + value[Z] + " " + value[3]);
		}
	}

	////////////////////////////////////////////////
	//	toString
	////////////////////////////////////////////////

	public String toString() {
		return null;
	}
}