package vrml.node;

import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class Shape extends Node {

	public Shape() {
		setHeaderFlag(false);
		setType(shapeTypeName);
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public Shape next() {
		return (Shape)next(getType());
	}

	public Shape nextTraversal() {
		return (Shape)nextTraversalByType(getType());
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

		Appearance appearance = getAppearances();
		if (appearance != null) {
			printStream.println(indentString + "\t" + "appearance Appearance {");
			appearance.outputContext(printStream, indentString + "\t");
			printStream.println(indentString + "\t" + "}");
		}
		
		BaseNode node = getGeometryNode();
		if (node != null) {
			printStream.println(indentString + "\t" + "geometry " + node.getType() + " {");
			node.outputContext(printStream, indentString + "\t");
			printStream.println(indentString + "\t" + "}");
		}
	}
}