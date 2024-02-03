package vrml.node;

import java.util.Vector;
import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class Coordinate extends Node {

	private String	pointFieldName = "point";

	public Coordinate() {
		setHeaderFlag(false);
		setType(coordinateTypeName);

		// point exposed field
		MFVec3f mfpoint = new MFVec3f();
		mfpoint.setName(pointFieldName);
		addExposedField(mfpoint);
	}

	////////////////////////////////////////////////
	//	point 
	////////////////////////////////////////////////

	public void addPoint(float point[]) {
		MFVec3f mfpoint = (MFVec3f)getExposedField(pointFieldName);
		mfpoint.addValue(point);
	}

	public int getNPoints() {
		MFVec3f mfpoint = (MFVec3f)getExposedField(pointFieldName);
		return mfpoint.getSize();
	}

	public void getPoint(int index, float point[]) {
		MFVec3f mfpoint = (MFVec3f)getExposedField(pointFieldName);
		mfpoint.get1Value(index, point);
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
		float point[] = new float[3];
		printStream.println(indentString + "\tpoint [");
		for (int n=0; n<getNPoints(); n++) {
			getPoint(n, point);
			if (n < getNPoints()-1)
				printStream.println(indentString + "\t\t" + point[X] + " " + point[Y] + " " + point[Z] + ",");
			else	
				printStream.println(indentString + "\t\t" + point[X] + " " + point[Y] + " " + point[Z]);
		}
		printStream.println(indentString + "\t]");
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public Coordinate next() {
		return (Coordinate)next(getType());
	}

	public Coordinate nextTraversal() {
		return (Coordinate)nextTraversalByType(getType());
	}

}