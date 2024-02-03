package vrml.node;

import java.util.Vector;
import java.lang.String;
import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class NavigationInfo extends Node {
	
	//// Exposed Field ////////////////
	private String	visibilityLimitExposedFieldName	= "visibilityLimit";
	private String	avatarSizeExposedFieldName		= "avatarSize";
	private String	typeExposedFieldName			= "type";
	private String	headlightExposedFieldName		= "headlight";
	private String	speedExposedFieldName			= "speed";

	//// EventIn ////////////////
	private String	bindEventInName					= "bind";

	//// EventOut ////////////////
	private String	isBoundEventOutName				= "isBound";

	public NavigationInfo() {
		setHeaderFlag(false);
		setType(navigationInfoTypeName);

		///////////////////////////
		// Exposed Field 
		///////////////////////////

		// visibilityLimit exposed field
		SFFloat visibilityLimit = new SFFloat(0);
		addExposedField(visibilityLimitExposedFieldName, visibilityLimit);

		// avatarSize exposed field
		MFFloat avatarSize = new MFFloat();
		addExposedField(avatarSizeExposedFieldName, avatarSize);

		// type exposed field
		MFString type = new MFString();
		addExposedField(typeExposedFieldName, type);

		// headlight exposed field
		SFBool headlight = new SFBool(false);
		addExposedField(headlightExposedFieldName, headlight);

		// speed exposed field
		SFFloat speed = new SFFloat(1);
		addExposedField(speedExposedFieldName, speed);

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
	// Type
	////////////////////////////////////////////////

	public void addType(String value) {
		MFString type = (MFString)getExposedField(typeExposedFieldName);
		type.addValue(value);
	}
	public int getNTypes() {
		MFString type = (MFString)getExposedField(typeExposedFieldName);
		return type.getSize();
	}
	public String getType(int index) {
		MFString type = (MFString)getExposedField(typeExposedFieldName);
		return type.get1Value(index);
	}

	////////////////////////////////////////////////
	// avatarSize
	////////////////////////////////////////////////

	public void addAvatarSize(float value) {
		MFFloat avatarSize = (MFFloat)getExposedField(avatarSizeExposedFieldName);
		avatarSize.addValue(value);
	}
	public int getNAvatarSizes() {
		MFFloat avatarSize = (MFFloat)getExposedField(avatarSizeExposedFieldName);
		return avatarSize.getSize();
	}
	public float getAvatarSize(int index) {
		MFFloat avatarSize = (MFFloat)getExposedField(avatarSizeExposedFieldName);
		return avatarSize.get1Value(index);
	}

	////////////////////////////////////////////////
	//	Headlight
	////////////////////////////////////////////////
	
	public void setHeadlight(boolean value) {
		SFBool headlight = (SFBool)getExposedField(headlightExposedFieldName);
		headlight.setValue(value);
	}
	public boolean getHeadlight() {
		SFBool headlight = (SFBool)getExposedField(headlightExposedFieldName);
		return headlight.getValue();
	}

	////////////////////////////////////////////////
	//	VisibilityLimit
	////////////////////////////////////////////////

	public void setVisibilityLimit(float value) {
		SFFloat visibilityLimit = (SFFloat)getExposedField(visibilityLimitExposedFieldName);
		visibilityLimit.setValue(value);
	}
	public float getVisibilityLimit() {
		SFFloat visibilityLimit = (SFFloat)getExposedField(visibilityLimitExposedFieldName);
		return visibilityLimit.getValue();
	}

	////////////////////////////////////////////////
	//	Speed
	////////////////////////////////////////////////
	
	public void setSpeed(float value) {
		SFFloat time = (SFFloat)getExposedField(speedExposedFieldName);
		time.setValue(value);
	}
	public float getSpeed() {
		SFFloat time = (SFFloat)getExposedField(speedExposedFieldName);
		return time.getValue();
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
		ConstSFBool isBound = (ConstSFBool)getEventOut(isBoundEventOutName);
		isBound.setValue(value);
	}
	public boolean getIsBound() {
		ConstSFBool isBound = (ConstSFBool)getEventOut(isBoundEventOutName);
		return isBound.getValue();
	}

	public boolean isBound() {
		return getIsBound();
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public NavigationInfo next() {
		return (NavigationInfo)next(getType());
	}

	public NavigationInfo nextTraversal() {
		return (NavigationInfo)nextTraversalByType(getType());
	}

	////////////////////////////////////////////////
	//	abstract functions
	////////////////////////////////////////////////
	
	public void initialize() {
	}

	public void update() {
	}

	////////////////////////////////////////////////
	//	infomation
	////////////////////////////////////////////////

	public void outputContext(PrintStream printStream, String indentString) {
		SFBool headlight = (SFBool)getExposedField(headlightExposedFieldName);

		printStream.println(indentString + "\t" + "visibilityLimit " + getVisibilityLimit());
		printStream.println(indentString + "\t" + "headlight " + headlight );
		printStream.println(indentString + "\t" + "speed " + getSpeed() );

		MFString type = (MFString)getExposedField(typeExposedFieldName);
		printStream.println(indentString + "\t" + "type [");
		type.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");

		MFFloat avatarSize = (MFFloat)getExposedField(avatarSizeExposedFieldName);
		printStream.println(indentString + "\t" + "avatarSize [");
		avatarSize.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");
	}
}
