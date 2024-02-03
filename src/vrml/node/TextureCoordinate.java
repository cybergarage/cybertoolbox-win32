package vrml.node;

import java.util.Vector;
import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class TextureCoordinate extends Node {
	
	private String	pointFieldName = "point";

	public TextureCoordinate() {
		setHeaderFlag(false);
		setType(textureCoordinateTypeName);

		// point exposed field
		MFVec2f mfpoint = new MFVec2f();
		mfpoint.setName(pointFieldName);
		addExposedField(mfpoint);
	}

	////////////////////////////////////////////////
	//	point 
	////////////////////////////////////////////////

	public void addPoint(float point[]) {
		MFVec2f mfpoint = (MFVec2f)getExposedField(pointFieldName);
		mfpoint.addValue(point);
	}

	public int getNPoints() {
		MFVec2f mfpoint = (MFVec2f)getExposedField(pointFieldName);
		return mfpoint.getSize();
	}

	public void getPoint(int index, float point[]) {
		MFVec2f mfpoint = (MFVec2f)getExposedField(pointFieldName);
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
		float point[] = new float[2];
		printStream.println(indentString + "\tpoint [");
		for (int n=0; n<getNPoints(); n++) {
			getPoint(n, point);
			if (n < getNPoints()-1)
				printStream.println(indentString + "\t\t" + point[X] + " " + point[Y] +  ",");
			else	
				printStream.println(indentString + "\t\t" + point[X] + " " + point[Y]);
		}
		printStream.println(indentString + "\t]");
	}
	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public TextureCoordinate next() {
		return (TextureCoordinate)next(getType());
	}

	public TextureCoordinate nextTraversal() {
		return (TextureCoordinate)nextTraversalByType(getType());
	}

}