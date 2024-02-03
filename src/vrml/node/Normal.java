package vrml.node;

import java.util.Vector;
import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class Normal extends Node {

	private String	vectorFieldName = "vector";

	public Normal () {
		setHeaderFlag(false);
		setType(normalTypeName);

		// vector exposed field
		MFVec3f vector = new MFVec3f();
		vector.setName(vectorFieldName);
		addExposedField(vector);
	}

	////////////////////////////////////////////////
	//	vector
	////////////////////////////////////////////////
	
	public void addVector(float value[]) {
		MFVec3f vector = (MFVec3f)getExposedField(vectorFieldName);
		vector.addValue(value);
	}
	public int getNVectors() {
		MFVec3f vector = (MFVec3f)getExposedField(vectorFieldName);
		return vector.getSize();
	}
	public void getVector(int index, float value[]) {
		MFVec3f vector = (MFVec3f)getExposedField(vectorFieldName);
		vector.get1Value(index, value);
	}

	////////////////////////////////////////////////
	//	abstract functions
	////////////////////////////////////////////////
	
	public void initialize() {
	}

	public void update() {
	}

	////////////////////////////////////////////////
	//	Output
	////////////////////////////////////////////////

	public void outputContext(PrintStream printStream, String indentString) {
		float vector[] = new float[3];
		printStream.println(indentString + "\tvector [");
		for (int n=0; n<getNVectors(); n++) {
			getVector(n, vector);
			if (n < getNVectors()-1)
				printStream.println(indentString + "\t\t" + vector[X] + " " + vector[Y] + " " + vector[Z] + ",");
			else	
				printStream.println(indentString + "\t\t" + vector[X] + " " + vector[Y] + " " + vector[Z]);
		}
		printStream.println(indentString + "\t]");
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public Normal next() {
		return (Normal)next(getType());
	}

	public Normal nextTraversal() {
		return (Normal)nextTraversalByType(getType());
	}

}