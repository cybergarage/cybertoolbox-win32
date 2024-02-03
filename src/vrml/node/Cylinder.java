package vrml.node;

import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class Cylinder extends Node {

	private String	radiusFieldName		= "radius";
	private String	heightFieldName		= "height";
	private String	topFieldName		= "top";
	private String	sideFieldName		= "side";
	private String	bottomFieldName		= "bottom";
	
	public Cylinder() {

		setHeaderFlag(false);
		setType(cylinderTypeName);

		// radius field
		SFFloat radius = new SFFloat(1.0f);
		addExposedField(radiusFieldName, radius);

		// height field
		SFFloat height = new SFFloat(1.0f);
		addExposedField(heightFieldName, height);

		// top field
		SFBool top = new SFBool(true);
		addExposedField(topFieldName, top);

		// side field
		SFBool side = new SFBool(true);
		addExposedField(sideFieldName, side);

		// bottom field
		SFBool bottom = new SFBool(true);
		addExposedField(bottomFieldName, bottom);
	}

	////////////////////////////////////////////////
	//	radius
	////////////////////////////////////////////////

	public void setRadius(float value) {
		SFFloat radius = (SFFloat)getExposedField(radiusFieldName);
		radius.setValue(value);
	}
	public float getRadius() {
		SFFloat radius = (SFFloat)getExposedField(radiusFieldName);
		return radius.getValue();
	}

	////////////////////////////////////////////////
	//	height
	////////////////////////////////////////////////

	public void setHeight(float value) {
		SFFloat height = (SFFloat)getExposedField(heightFieldName);
		height.setValue(value);
	}
	public float getHeight() {
		SFFloat height = (SFFloat)getExposedField(heightFieldName);
		return height.getValue();
	}

	////////////////////////////////////////////////
	//	top
	////////////////////////////////////////////////

	public void setTop(boolean value) {
		SFBool top = (SFBool)getExposedField(topFieldName);
		top.setValue(value);
	}
	public boolean getTop() {
		SFBool top = (SFBool)getExposedField(topFieldName);
		return top.getValue();
	}

	////////////////////////////////////////////////
	//	side
	////////////////////////////////////////////////

	public void setSide(boolean value) {
		SFBool side = (SFBool)getExposedField(sideFieldName);
		side.setValue(value);
	}
	public boolean getSide() {
		SFBool side = (SFBool)getExposedField(sideFieldName);
		return side.getValue();
	}

	////////////////////////////////////////////////
	//	bottom
	////////////////////////////////////////////////

	public void setBottom(boolean value) {
		SFBool bottom = (SFBool)getExposedField(bottomFieldName);
		bottom.setValue(value);
	}
	public boolean getBottom() {
		SFBool bottom = (SFBool)getExposedField(bottomFieldName);
		return bottom.getValue();
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public Cylinder next() {
		return (Cylinder)next(getType());
	}

	public Cylinder nextTraversal() {
		return (Cylinder)nextTraversalByType(getType());
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
		SFBool top = (SFBool)getExposedField(topFieldName);
		SFBool side = (SFBool)getExposedField(sideFieldName);
		SFBool bottom = (SFBool)getExposedField(bottomFieldName);

		printStream.println(indentString + "\t" + "radius " + getRadius());
		printStream.println(indentString + "\t" + "height " + getHeight());
		printStream.println(indentString + "\t" + "side " + side);
		printStream.println(indentString + "\t" + "top " + top);
		printStream.println(indentString + "\t" + "bottom " + bottom);
	}
}
