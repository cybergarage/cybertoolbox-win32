package vrml.node;

import java.util.*;
import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class IndexedFaceSet extends Node {
	
	//// Field ////////////////
	private String	ccwFieldName				= "ccw";
	private String	colorPerVertexFieldName		= "colorPerVertex";
	private String	normalPerVertexFieldName	= "normalPerVertex";
	private String	solidFieldName				= "solid";
	private String	convexFieldName				= "convex";
	private String	creaseAngleFieldName		= "creaseAngle";
	private String	coordIndexFieldName			= "coordIndex";
	private String	texCoordIndexFieldName		= "texCoordIndex";
	private String	colorIndexFieldName			= "colorIndex";
	private String	normalIndexFieldName		= "normalIndex";

	//// EventIn ////////////////
	private String	coordIndexEventInName			= "coordIndex";
	private String	texCoordIndexEventInName		= "texCoordIndex";
	private String	colorIndexEventInName			= "colorIndex";
	private String	normalIndexEventInName		= "normalIndex";

	public IndexedFaceSet() {
		setHeaderFlag(false);
		setType(indexedFaceSetTypeName);

		///////////////////////////
		// Field 
		///////////////////////////

		// ccw  field
		SFBool ccw = new SFBool(true);
		ccw.setName(ccwFieldName);
		addField(ccw);

		// colorPerVertex  field
		SFBool colorPerVertex = new SFBool(true);
		colorPerVertex.setName(colorPerVertexFieldName);
		addField(colorPerVertex);

		// normalPerVertex  field
		SFBool normalPerVertex = new SFBool(true);
		normalPerVertex.setName(normalPerVertexFieldName);
		addField(normalPerVertex);

		// solid  field
		SFBool solid = new SFBool(true);
		solid.setName(solidFieldName);
		addField(solid);

		// convex  field
		SFBool convex = new SFBool(true);
		convex.setName(convexFieldName);
		addField(convex);

		// creaseAngle  field
		SFFloat creaseAngle = new SFFloat(0.0f);
		creaseAngle.setName(creaseAngleFieldName);
		addField(creaseAngle);

		// coordIndex  field
		MFInt32 coordIndex = new MFInt32();
		coordIndex.setName(coordIndexFieldName);
		addField(coordIndex);

		// texCoordIndex  field
		MFInt32 texCoordIndex = new MFInt32();
		texCoordIndex.setName(texCoordIndexFieldName);
		addField(texCoordIndex);

		// colorIndex  field
		MFInt32 colorIndex = new MFInt32();
		colorIndex.setName(colorIndexFieldName);
		addField(colorIndex);

		// normalIndex  field
		MFInt32 normalIndex = new MFInt32();
		normalIndex.setName(normalIndexFieldName);
		addField(normalIndex);

		///////////////////////////
		// EventIn
		///////////////////////////

		// coordIndex  EventIn
		coordIndex = new MFInt32();
		coordIndex.setName(coordIndexEventInName);
		addEventIn(coordIndex);

		// texCoordIndex  EventIn
		texCoordIndex = new MFInt32();
		texCoordIndex.setName(texCoordIndexEventInName);
		addEventIn(texCoordIndex);

		// colorIndex  EventIn
		colorIndex = new MFInt32();
		colorIndex.setName(colorIndexEventInName);
		addEventIn(colorIndex);

		// normalIndex  EventIn
		normalIndex = new MFInt32();
		normalIndex.setName(normalIndexEventInName);
		addEventIn(normalIndex);
	}
	
	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public IndexedFaceSet next() {
		return (IndexedFaceSet)next(getType());
	}

	public IndexedFaceSet nextTraversal() {
		return (IndexedFaceSet)nextTraversalByType(getType());
	}

	////////////////////////////////////////////////
	//	CCW
	////////////////////////////////////////////////
	
	public void setCCW(boolean value) {
		SFBool ccw = (SFBool)getField(ccwFieldName);
		ccw.setValue(value);
	}

	public boolean getCCW() {
		SFBool ccw = (SFBool)getField(ccwFieldName);
		return ccw.getValue();
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
	//	NormalPerVertex
	////////////////////////////////////////////////
	
	public void setNormalPerVertex(boolean value) {
		SFBool normalPerVertex = (SFBool)getField(normalPerVertexFieldName);
		normalPerVertex.setValue(value);
	}

	public boolean getNormalPerVertex() {
		SFBool normalPerVertex = (SFBool)getField(normalPerVertexFieldName);
		return normalPerVertex.getValue();
	}

	////////////////////////////////////////////////
	//	Solid
	////////////////////////////////////////////////
	
	public void setSolid(boolean value) {
		SFBool solid = (SFBool)getField(solidFieldName);
		solid.setValue(value);
	}

	public boolean getSolid() {
		SFBool solid = (SFBool)getField(solidFieldName);
		return solid.getValue();
	}

	////////////////////////////////////////////////
	//	Convex
	////////////////////////////////////////////////
	
	public void setConvex(boolean value) {
		SFBool convex = (SFBool)getField(convexFieldName);
		convex.setValue(value);
	}

	public boolean getConvex() {
		SFBool convex = (SFBool)getField(convexFieldName);
		return convex.getValue();
	}

	////////////////////////////////////////////////
	//	CreaseAngle
	////////////////////////////////////////////////
	
	public void setCreaseAngle(float value) {
		SFFloat creaseAngle = (SFFloat)getField(creaseAngleFieldName);
		creaseAngle.setValue(value);
	}

	public float getCreaseAngle() {
		SFFloat creaseAngle = (SFFloat)getField(creaseAngleFieldName);
		return creaseAngle.getValue();
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
	// TexCoordIndex
	////////////////////////////////////////////////

	public void addTexCoordIndex(int value) {
		MFInt32 coordIndex = (MFInt32)getField(texCoordIndexFieldName);
		coordIndex.addValue(value);
	}
	public int getNTexCoordIndexes() {
		MFInt32 coordIndex = (MFInt32)getField(texCoordIndexFieldName);
		return coordIndex.getSize();
	}
	public int getTexCoordIndex(int index) {
		MFInt32 coordIndex = (MFInt32)getField(texCoordIndexFieldName);
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
	// NormalIndex
	////////////////////////////////////////////////

	public void addNormalIndex(int value) {
		MFInt32 normalIndex = (MFInt32)getField(normalIndexFieldName);
		normalIndex.addValue(value);
	}
	public int getNNormalIndexes() {
		MFInt32 normalIndex = (MFInt32)getField(normalIndexFieldName);
		return normalIndex.getSize();
	}
	public int getNormalIndex(int index) {
		MFInt32 normalIndex = (MFInt32)getField(normalIndexFieldName);
		return normalIndex.get1Value(index);
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
		SFBool convex = (SFBool)getField(convexFieldName);
		SFBool solid = (SFBool)getField(solidFieldName);
		SFBool normalPerVertex = (SFBool)getField(normalPerVertexFieldName);
		SFBool colorPerVertex = (SFBool)getField(colorPerVertexFieldName);
		SFBool ccw = (SFBool)getField(ccwFieldName);

		printStream.println(indentString + "\t" + "ccw " + ccw);
		printStream.println(indentString + "\t" + "colorPerVertex " + colorPerVertex);
		printStream.println(indentString + "\t" + "normalPerVertex " + normalPerVertex);
		printStream.println(indentString + "\t" + "convex " + convex);
		printStream.println(indentString + "\t" + "creaseAngle " + getCreaseAngle());
		printStream.println(indentString + "\t" + "solid " + solid);

		Normal normal = getNormals();
		if (normal != null) {
			printStream.println(indentString + "\t" + "normal Normal {");
			normal.outputContext(printStream, indentString + "\t");
			printStream.println(indentString + "\t" + "}");
		}

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

		TextureCoordinate texCoord = getTextureCoordinates();
		if (texCoord != null) {
			printStream.println(indentString + "\t" + "texCoord TextureCoordinate {");
			texCoord.outputContext(printStream, indentString + "\t");
			printStream.println(indentString + "\t" + "}");
		}

		MFInt32 coordIndex = (MFInt32)getField(coordIndexFieldName);
		printStream.println(indentString + "\t" + "coordIndex [");
		coordIndex.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");
		
		MFInt32 texCoordIndex = (MFInt32)getField(texCoordIndexFieldName);
		printStream.println(indentString + "\t" + "texCoordIndex [");
		texCoordIndex.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");
		
		MFInt32 colorIndex = (MFInt32)getField(colorIndexFieldName);
		printStream.println(indentString + "\t" + "colorIndex [");
		colorIndex.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");
		
		MFInt32 normalIndex = (MFInt32)getField(normalIndexFieldName);
		printStream.println(indentString + "\t" + "normalIndex [");
		normalIndex.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");
	}
}