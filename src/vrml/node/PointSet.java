package vrml.node;

import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class PointSet extends Node {

	private String	whichChoiceFieldName	= "whichChoice";
	
	public PointSet() {
		setHeaderFlag(false);
		setType(pointSetTypeName);
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public PointSet next() {
		return (PointSet)next(getType());
	}

	public PointSet nextTraversal() {
		return (PointSet)nextTraversalByType(getType());
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
		Color color = getColors();
		if (color != null) {
			printStream.println(indentString + "\t" + "color Color {");
			color.outputContext(printStream, indentString + "\t");
			printStream.println(indentString + "\t" + "}");
		}

		Coordinate coord = getCoordinates();
		if (coord != null) {
			printStream.println(indentString + "\t" + "coord Coordinate {");
			coord.outputContext(printStream, indentString + "\t");
			printStream.println(indentString + "\t" + "}");
		}
	}
}
