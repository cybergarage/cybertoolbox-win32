package vrml.node;

import java.util.Vector;
import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class Color extends Node {

	private String	colorFieldName = "color";

	public Color() {
		setHeaderFlag(false);
		setType(colorTypeName);

		// color exposed field
		MFColor mfcolor = new MFColor();
		mfcolor.setName(colorFieldName);
		addExposedField(mfcolor);
	}

	////////////////////////////////////////////////
	//	color
	////////////////////////////////////////////////
	
	public void addColor(float color[]) {
		MFColor mfcolor = (MFColor)getExposedField(colorFieldName);
		mfcolor.addValue(color);
	}
	public int getNColors() {
		MFColor mfcolor = (MFColor)getExposedField(colorFieldName);
		return mfcolor.getSize();
	}
	public void getColor(int index, float color[]) {
		MFColor mfcolor = (MFColor)getExposedField(colorFieldName);
		mfcolor.get1Value(index, color);
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
		float color[] = new float[3];
		printStream.println(indentString + "\tcolor [");
		for (int n=0; n<getNColors(); n++) {
			getColor(n, color);
			if (n < getNColors()-1)
				printStream.println(indentString + "\t\t" + color[X] + " " + color[Y] + " " + color[Z] + ",");
			else	
				printStream.println(indentString + "\t\t" + color[X] + " " + color[Y] + " " + color[Z]);
		}
		printStream.println(indentString + "\t]");
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public Color next() {
		return (Color)next(getType());
	}

	public Color nextTraversal() {
		return (Color)nextTraversalByType(getType());
	}

}