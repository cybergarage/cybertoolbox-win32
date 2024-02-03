package vrml.node;

import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class Box extends Node {

	private String	sizeFieldName		= "size";
	
	public Box() {

		setHeaderFlag(false);
		setType(boxTypeName);

		// size exposed field
		SFVec3f size = new SFVec3f(2.0f, 2.0f, 2.0f);
		size.setName(sizeFieldName);
		addExposedField(size);
	}

	////////////////////////////////////////////////
	//	size
	////////////////////////////////////////////////

	public void setSize(float value[]) {
		SFVec3f size = (SFVec3f)getExposedField(sizeFieldName);
		size.setValue(value);
	}
	public void setSize(float x, float y, float z) {
		SFVec3f size = (SFVec3f)getExposedField(sizeFieldName);
		size.setValue(x, y, z);
	}
	public void getSize(float value[]) {
		SFVec3f size = (SFVec3f)getExposedField(sizeFieldName);
		size.getValue(value);
	}
	public float getX() {
		return ((SFVec3f)getExposedField(sizeFieldName)).getX();
	}
	public float getY() {
		return ((SFVec3f)getExposedField(sizeFieldName)).getY();
	}
	public float getZ() {
		return ((SFVec3f)getExposedField(sizeFieldName)).getZ();
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public Box next() {
		return (Box)next(getType());
	}

	public Box nextTraversal() {
		return (Box)nextTraversalByType(getType());
	}

	////////////////////////////////////////////////
	//	abstract functions
	////////////////////////////////////////////////
	
	public void initialize() {
	}

	public void update() {
	}

	////////////////////////////////////////////////
	//	Infomation
	////////////////////////////////////////////////

	public void outputContext(PrintStream printStream, String indentString) {
		float value[] = new float[3];
		getSize(value);	printStream.println(indentString + "\t" + "size " + value[X] + " "+ value[Y] + " " + value[Z] );
	}
}
