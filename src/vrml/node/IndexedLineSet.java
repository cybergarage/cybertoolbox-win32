package vrml.node;

import java.util.*;
import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class IndexedLineSet extends Node {
	
	//// Field ////////////////
	private String	colorPerVertexFieldName		= "colorPerVertex";
	private String	coordIndexFieldName			= "coordIndex";
	private String	colorIndexFieldName			= "colorIndex";

	//// EventIn ////////////////
	private String	coordIndexEventInName		= "coordIndex";
	private String	colorIndexEventInName		= "colorIndex";

	public IndexedLineSet() {
		setHeaderFlag(false);
		setType(indexedLineSetTypeName);

		///////////////////////////
		// Field 
		///////////////////////////

		// colorPerVertex  field
		SFBool colorPerVertex = new SFBool(true);
		colorPerVertex.setName(colorPerVertexFieldName);
		addField(colorPerVertex);

		// coordIndex  field
		MFInt32 coordIndex = new MFInt32();
		coordIndex.setName(coordIndexFieldName);
		addField(coordIndex);

		// colorIndex  field
		MFInt32 colorIndex = new MFInt32();
		colorIndex.setName(colorIndexFieldName);
		addField(colorIndex);

		///////////////////////////
		// EventIn
		///////////////////////////

		// coordIndex  EventIn
		coordIndex = new MFInt32();
		coordIndex.setName(coordIndexEventInName);
		addEventIn(coordIndex);

		// colorIndex  EventIn
		colorIndex = new MFInt32();
		colorIndex.setName(colorIndexEventInName);
		addEventIn(colorIndex);
	}
	
	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public IndexedLineSet next() {
		return (IndexedLineSet)next(getType());
	}

	public IndexedLineSet nextTraversal() {
		return (IndexedLineSet)nextTraversalByType(getType());
	}

	////////////////////////////////////////////////
	//	ColorPerVertex
	////////////////////////////////////////////////
	
	public void setColorPerVertex(boolean value) {
		SFBool colorPerVertex = (SFBool)getField(colorPerVertexFieldName);
		colorPerVertex.setValue(value);
	}

	public boolean getColorPerVertex() {
		SFBool colorPerVertex = (SFBool)getField(colorPerVertexFieldName);
		return colorPerVertex.getValue();
	}

	////////////////////////////////////////////////
	// CoordIndex
	////////////////////////////////////////////////

	public void addCoordIndex(int value) {
		MFInt32 coordIndex = (MFInt32)getField(coordIndexFieldName);
		coordIndex.addValue(value);
	}
	public int getNCoordIndexes() {
		MFInt32 coordIndex = (MFInt32)getField(coordIndexFieldName);
		return coordIndex.getSize();
	}
	public int getCoordIndex(int index) {
		MFInt32 coordIndex = (MFInt32)getField(coordIndexFieldName);
		return coordIndex.get1Value(index);
	}
	
	////////////////////////////////////////////////
	// ColorIndex
	////////////////////////////////////////////////

	public void addColorIndex(int value) {
		MFInt32 colorIndex = (MFInt32)getField(colorIndexFieldName);
		colorIndex.addValue(value);
	}
	public int getNColorIndexes() {
		MFInt32 colorIndex = (MFInt32)getField(colorIndexFieldName);
		return colorIndex.getSize();
	}
	public int getColorIndex(int index) {
		MFInt32 colorIndex = (MFInt32)getField(colorIndexFieldName);
		return colorIndex.get1Value(index);
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
		SFBool colorPerVertex = (SFBool)getField(colorPerVertexFieldName);

		printStream.println(indentString + "\t" + "colorPerVertex " + colorPerVertex);

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

		MFInt32 coordIndex = (MFInt32)getField(coordIndexFieldName);
		printStream.println(indentString + "\t" + "coordIndex [");
		coordIndex.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");
		
		MFInt32 colorIndex = (MFInt32)getField(colorIndexFieldName);
		printStream.println(indentString + "\t" + "colorIndex [");
		colorIndex.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");
	}
}