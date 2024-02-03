package vrml.node;

import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class Fog extends Node {

	//// Exposed Field ////////////////
	private String	colorExposedFieldName			= "color";
	private String	fogTypeExposedFieldName			= "fogType";
	private String	visibilityRangeExposedFieldName	= "visibilityRange";

	//// EventIn ////////////////
	private String	bindEventInName					= "bind";

	//// EventOut ////////////////
	private String	isBoundEventOutName				= "isBound";
	
	public Fog() {

		setHeaderFlag(false);
		setType(fogTypeName);

		///////////////////////////
		// Exposed Field 
		///////////////////////////
		
		// color exposed field
		SFColor color = new SFColor(1, 1, 1);
		addExposedField(colorExposedFieldName, color);

		// fogType exposed field
		SFString fogType = new SFString("LINEAR");
		addExposedField(fogTypeExposedFieldName, fogType);

		// visibilityRange exposed field
		SFFloat visibilityRange = new SFFloat(0);
		addExposedField(visibilityRangeExposedFieldName, visibilityRange);

		///////////////////////////
		// EventIn
		///////////////////////////

		// bind EventIn
		SFBool bind = new SFBool();
		addEventIn(bindEventInName, bind);

		///////////////////////////
		// EventOut
		///////////////////////////

		// isBound EventIn
		ConstSFBool isBound = new ConstSFBool();
		addEventOut(isBoundEventOutName, isBound);
	}

	////////////////////////////////////////////////
	//	Color
	////////////////////////////////////////////////

	public void setColor(float value[]) {
		SFColor color = (SFColor)getExposedField(colorExposedFieldName);
		color.setValue(value);
	}
	public void setColor(float r, float g, float b) {
		SFColor color = (SFColor)getExposedField(colorExposedFieldName);
		color.setValue(r, g, b);
	}
	public void getColor(float value[]) {
		SFColor color = (SFColor)getExposedField(colorExposedFieldName);
		color.getValue(value);
	}

	////////////////////////////////////////////////
	//	FogType
	////////////////////////////////////////////////

	public void setFogType(String value) {
		SFString fogType = (SFString)getExposedField(fogTypeExposedFieldName);
		fogType.setValue(value);
	}
	public String getFogType() {
		SFString fogType = (SFString)getExposedField(fogTypeExposedFieldName);
		return fogType.getValue();
	}

	////////////////////////////////////////////////
	//	VisibilityRange
	////////////////////////////////////////////////

	public void setVisibilityRange(float value) {
		SFFloat visibilityRange = (SFFloat)getExposedField(visibilityRangeExposedFieldName);
		visibilityRange.setValue(value);
	}
	public float getVisibilityRange() {
		SFFloat visibilityRange = (SFFloat)getExposedField(visibilityRangeExposedFieldName);
		return visibilityRange.getValue();
	}

	////////////////////////////////////////////////
	//	bind
	////////////////////////////////////////////////

	public void setBind(boolean value) {
		SFBool bind = (SFBool)getEventIn(bindEventInName);
		bind.setValue(value);
	}
	public boolean getBind() {
		SFBool bind = (SFBool)getEventIn(bindEventInName);
		return bind.getValue();
	}

	////////////////////////////////////////////////
	//	isBound
	////////////////////////////////////////////////

	public void setIsBound(boolean value) {
		ConstSFBool isBound = (ConstSFBool)getEventIn(isBoundEventOutName);
		isBound.setValue(value);
	}
	public boolean getIsBound() {
		ConstSFBool isBound = (ConstSFBool)getEventIn(isBoundEventOutName);
		return isBound.getValue();
	}

	public boolean isBound() {
		return getIsBound();
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public Fog next() {
		return (Fog)next(getType());
	}

	public Fog nextTraversal() {
		return (Fog)nextTraversalByType(getType());
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

		SFColor color = (SFColor)getExposedField(colorExposedFieldName);
		SFString fogType = (SFString)getExposedField(fogTypeExposedFieldName);

		printStream.println(indentString + "\t" + "color " + color);
		printStream.println(indentString + "\t" + "fogType " + fogType);
		printStream.println(indentString + "\t" + "visibilityRange " + getVisibilityRange());

	}
}
