package vrml.node;

import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class Billboard extends GroupingNode {

	private String	axisOfRotationFieldName		= "axisOfRotation";
	
	public Billboard() {
		super();

		setHeaderFlag(false);
		setType(billboardTypeName);

		// axisOfRotation exposed field
		SFVec3f axisOfRotation = new SFVec3f(0.0f, 1.0f, 0.0f);
		addExposedField(axisOfRotationFieldName, axisOfRotation);
	}

	////////////////////////////////////////////////
	//	axisOfRotation
	////////////////////////////////////////////////

	public void setAxisOfRotation(float value[]) {
		SFVec3f axisOfRotation = (SFVec3f)getExposedField(axisOfRotationFieldName);
		axisOfRotation.setValue(value);
	}

	public void setAxisOfRotation(float x, float y, float z) {
		SFVec3f axisOfRotation = (SFVec3f)getExposedField(axisOfRotationFieldName);
		axisOfRotation.setValue(x, y, z);
	}

	public void getAxisOfRotation(float value[]) {
		SFVec3f axisOfRotation = (SFVec3f)getExposedField(axisOfRotationFieldName);
		axisOfRotation.getValue(value);
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public Billboard next() {
		return (Billboard)next(getType());
	}

	public Billboard nextTraversal() {
		return (Billboard)nextTraversalByType(getType());
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
		SFVec3f axisOfRotation = (SFVec3f)getExposedField(axisOfRotationFieldName);
		printStream.println(indentString + "\t" + "axisOfRotation " + axisOfRotation);
	}
}
