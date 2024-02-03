package vrml.node;

import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class ElevationGrid extends Node {

	private String	xDimensionFieldName			= "xDimension";
	private String	zDimensionFieldName			= "zDimension";
	private String	xSpacingFieldName			= "xSpacing";
	private String	zSpacingFieldName			= "zSpacing";
	private String	colorPerVertexFieldName		= "colorPerVertex";
	private String	normalPerVertexFieldName	= "normalPerVertex";
	private String	heightFieldName				= "height";
	private String	ccwFieldName				= "ccw";
	private String	solidFieldName				= "solid";
	private String	creaseAngleFieldName		= "creaseAngle";
	
	public ElevationGrid() {

		setHeaderFlag(false);
		setType(elevationGridTypeName);

		// xSpacing field
		SFFloat xSpacing = new SFFloat(0.0f);
		addField(xSpacingFieldName, xSpacing);

		// zSpacing field
		SFFloat zSpacing = new SFFloat(0.0f);
		addField(zSpacingFieldName, zSpacing);

		// xDimension field
		SFInt32 xDimension = new SFInt32(0);
		addField(xDimensionFieldName, xDimension);

		// zDimension field
		SFInt32 zDimension = new SFInt32(0);
		addField(zDimensionFieldName, zDimension);

		// colorPerVertex exposed field
		SFBool colorPerVertex = new SFBool(true);
		colorPerVertex.setName(colorPerVertexFieldName);
		addField(colorPerVertex);

		// normalPerVertex exposed field
		SFBool normalPerVertex = new SFBool(true);
		normalPerVertex.setName(normalPerVertexFieldName);
		addField(normalPerVertex);

		// ccw exposed field
		SFBool ccw = new SFBool(true);
		ccw.setName(ccwFieldName);
		addField(ccw);

		// solid exposed field
		SFBool solid = new SFBool(true);
		solid.setName(solidFieldName);
		addField(solid);

		// creaseAngle exposed field
		SFFloat creaseAngle = new SFFloat(0.0f);
		creaseAngle.setName(creaseAngleFieldName);
		addField(creaseAngle);

		// height exposed field
		MFFloat height = new MFFloat();
		addField(heightFieldName, height);

		// height eventIn
		MFFloat setHeight = new MFFloat();
		addEventIn(heightFieldName, setHeight);
	}

	////////////////////////////////////////////////
	//	xSpacing
	////////////////////////////////////////////////

	public void setXSpacing(float value) {
		SFFloat space = (SFFloat)getField(xSpacingFieldName);
		space.setValue(value);
	}
	public float getXSpacing() {
		SFFloat space = (SFFloat)getField(xSpacingFieldName);
		return space.getValue();
	}

	////////////////////////////////////////////////
	//	zSpacing
	////////////////////////////////////////////////

	public void setZSpacing(float value) {
		SFFloat space = (SFFloat)getField(zSpacingFieldName);
		space.setValue(value);
	}
	public float getZSpacing() {
		SFFloat space = (SFFloat)getField(zSpacingFieldName);
		return space.getValue();
	}

	////////////////////////////////////////////////
	//	xDimension
	////////////////////////////////////////////////

	public void setXDimension(int value) {
		SFInt32 dimension = (SFInt32)getField(xDimensionFieldName);
		dimension.setValue(value);
	}
	public int getXDimension() {
		SFInt32 dimension = (SFInt32)getField(xDimensionFieldName);
		return dimension.getValue();
	}

	////////////////////////////////////////////////
	//	zDimension
	////////////////////////////////////////////////

	public void setZDimension(int value) {
		SFInt32 dimension = (SFInt32)getField(zDimensionFieldName);
		dimension.setValue(value);
	}
	public int getZDimension() {
		SFInt32 dimension = (SFInt32)getField(zDimensionFieldName);
		return dimension.getValue();
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
	//	List
	////////////////////////////////////////////////

	public ElevationGrid next() {
		return (ElevationGrid)next(getType());
	}

	public ElevationGrid nextTraversal() {
		return (ElevationGrid)nextTraversalByType(getType());
	}

	////////////////////////////////////////////////
	// height
	////////////////////////////////////////////////

	public void addHeight(float value) {
		MFFloat height = (MFFloat)getField(heightFieldName);
		height.addValue(value);
	}
	public int getNHeights() {
		MFFloat height = (MFFloat)getField(heightFieldName);
		return height.getSize();
	}
	public float getHeight(int index) {
		MFFloat height = (MFFloat)getField(heightFieldName);
		return height.get1Value(index);
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
		SFBool ccw = (SFBool)getField(ccwFieldName);
		SFBool solid = (SFBool)getField(solidFieldName);
		SFBool colorPerVertex = (SFBool)getField(colorPerVertexFieldName);
		SFBool normalPerVertex = (SFBool)getField(normalPerVertexFieldName);

		printStream.println(indentString + "\t" + "xDimension " + getXDimension());
		printStream.println(indentString + "\t" + "xSpacing " + getXSpacing());
		printStream.println(indentString + "\t" + "zDimension " + getZDimension());
		printStream.println(indentString + "\t" + "zSpacing " + getZSpacing());

		MFFloat height = (MFFloat)getField(heightFieldName);
		printStream.println(indentString + "\t" + "height [");
		height.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");

		printStream.println(indentString + "\t" + "colorPerVertex " + colorPerVertex);
		printStream.println(indentString + "\t" + "normalPerVertex " + normalPerVertex);
		printStream.println(indentString + "\t" + "ccw " + ccw);
		printStream.println(indentString + "\t" + "solid " + solid);
		printStream.println(indentString + "\t" + "creaseAngle " + getCreaseAngle());
		
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

		TextureCoordinate texCoord = getTextureCoordinates();
		if (texCoord != null) {
			printStream.println(indentString + "\t" + "texCoord TextureCoordinate {");
			texCoord.outputContext(printStream, indentString + "\t");
			printStream.println(indentString + "\t" + "}");
		}

	}
}
