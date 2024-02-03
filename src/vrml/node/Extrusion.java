package vrml.node;

import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class Extrusion extends Node {

	//// Field ////////////////
	private String	beginCapFieldName			= "beginCap";
	private String	endCapFieldName				= "endCap";
	private String	ccwFieldName				= "ccw";
	private String	convexFieldName				= "convex";
	private String	creaseAngleFieldName		= "creaseAngle";
	private String	solidFieldName				= "solid";
	private String	orientationFieldName		= "orientation";
	private String	scaleFieldName				= "scale";
	private String	crossSectionFieldName		= "crossSection";
	private String	spineFieldName				= "spine";

	//// EventIn ////////////////
	private String	crossSectionEventInName		= "crossSection";
	private String	orientationEventInName		= "orientation";
	private String	scaleEventInName			= "scale";
	private String	spineEventInName			= "spine";
	
	public Extrusion() {

		setHeaderFlag(false);
		setType(extrusionTypeName);

		///////////////////////////
		// Field 
		///////////////////////////
		
		// beginCap field
		SFBool beginCap = new SFBool(true);
		addField(beginCapFieldName, beginCap);

		// endCap field
		SFBool endCap = new SFBool(true);
		addField(endCapFieldName, endCap);

		// ccw field
		SFBool ccw = new SFBool(true);
		ccw.setName(ccwFieldName);
		addField(ccw);

		// convex field
		SFBool convex = new SFBool(true);
		convex.setName(convexFieldName);
		addField(convex);

		// creaseAngle field
		SFFloat creaseAngle = new SFFloat(0.0f);
		creaseAngle.setName(creaseAngleFieldName);
		addField(creaseAngle);

		// solid field
		SFBool solid = new SFBool(true);
		solid.setName(solidFieldName);
		addField(solid);

		// orientation field
		MFRotation orientation = new MFRotation();
		orientation.setName(orientationFieldName);
		addField(orientation);

		// scale field
		MFVec2f scale = new MFVec2f();
		scale.setName(scaleFieldName);
		addField(scale);

		// crossSection field
		MFVec2f crossSection = new MFVec2f();
		addField(crossSectionFieldName, crossSection);

		// spine field
		MFVec3f spine = new MFVec3f();
		addField(spineFieldName, spine);

		///////////////////////////
		// EventIn
		///////////////////////////

		// orientation EventIn
		orientation = new MFRotation();
		orientation.setName(orientationEventInName);
		addEventIn(orientation);

		// scale EventIn
		scale = new MFVec2f();
		scale.setName(scaleEventInName);
		addEventIn(scale);

		// crossSection EventIn
		crossSection = new MFVec2f();
		addEventIn(crossSectionEventInName, crossSection);

		// spine EventIn
		spine = new MFVec3f();
		addEventIn(spineEventInName, spine);
	}

	////////////////////////////////////////////////
	//	BeginCap
	////////////////////////////////////////////////
	
	public void setBeginCap(boolean value) {
		SFBool beginCap = (SFBool)getField(beginCapFieldName);
		beginCap.setValue(value);
	}

	public boolean getBeginCap() {
		SFBool beginCap = (SFBool)getField(beginCapFieldName);
		return beginCap.getValue();
	}

	////////////////////////////////////////////////
	//	EndCap
	////////////////////////////////////////////////
	
	public void setEndCap(boolean value) {
		SFBool endCap = (SFBool)getField(endCapFieldName);
		endCap.setValue(value);
	}

	public boolean getEndCap() {
		SFBool endCap = (SFBool)getField(endCapFieldName);
		return endCap.getValue();
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
	// orientation
	////////////////////////////////////////////////

	public void addOrientation(float value[]) {
		MFRotation orientation = (MFRotation)getField(orientationFieldName);
		orientation.addValue(value);
	}
	public int getNOrientations() {
		MFRotation orientation = (MFRotation)getField(orientationFieldName);
		return orientation.getSize();
	}
	public void getOrientation(int index, float value[]) {
		MFRotation orientation = (MFRotation)getField(orientationFieldName);
		orientation.get1Value(index, value);
	}

	////////////////////////////////////////////////
	// scale
	////////////////////////////////////////////////

	public void addScale(float value[]) {
		MFVec2f scale = (MFVec2f)getField(scaleFieldName);
		scale.addValue(value);
	}
	public int getNScales() {
		MFVec2f scale = (MFVec2f)getField(scaleFieldName);
		return scale.getSize();
	}
	public void getScale(int index, float value[]) {
		MFVec2f scale = (MFVec2f)getField(scaleFieldName);
		scale.get1Value(index, value);
	}

	////////////////////////////////////////////////
	// crossSection
	////////////////////////////////////////////////

	public void addCrossSection(float value[]) {
		MFVec2f crossSection = (MFVec2f)getField(crossSectionFieldName);
		crossSection.addValue(value);
	}
	public int getNCrossSections() {
		MFVec2f crossSection = (MFVec2f)getField(crossSectionFieldName);
		return crossSection.getSize();
	}
	public void getCrossSection(int index, float value[]) {
		MFVec2f crossSection = (MFVec2f)getField(crossSectionFieldName);
		crossSection.get1Value(index, value);
	}

	////////////////////////////////////////////////
	// spine
	////////////////////////////////////////////////

	public void addSpine(float value[]) {
		MFVec3f spine = (MFVec3f)getField(spineFieldName);
		spine.addValue(value);
	}
	public int getNSpines() {
		MFVec3f spine = (MFVec3f)getField(spineFieldName);
		return spine.getSize();
	}
	public void getSpine(int index, float value[]) {
		MFVec3f spine = (MFVec3f)getField(spineFieldName);
		spine.get1Value(index, value);
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public Extrusion next() {
		return (Extrusion)next(getType());
	}

	public Extrusion nextTraversal() {
		return (Extrusion)nextTraversalByType(getType());
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

		SFBool beginCap = (SFBool)getField(beginCapFieldName);
		SFBool endCap = (SFBool)getField(endCapFieldName);
		SFBool ccw = (SFBool)getField(ccwFieldName);
		SFBool convex = (SFBool)getField(convexFieldName);
		SFBool solid = (SFBool)getField(solidFieldName);

		printStream.println(indentString + "\t" + "beginCap " + beginCap);
		printStream.println(indentString + "\t" + "endCap " + endCap);
		printStream.println(indentString + "\t" + "solid " + solid);
		printStream.println(indentString + "\t" + "ccw " + ccw);
		printStream.println(indentString + "\t" + "convex " + convex);
		printStream.println(indentString + "\t" + "creaseAngle " + getCreaseAngle());

		MFVec2f crossSection = (MFVec2f)getField(crossSectionFieldName);
		printStream.println(indentString + "\t" + "crossSection [");
		crossSection.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");

		MFRotation orientation = (MFRotation)getField(orientationFieldName);
		printStream.println(indentString + "\t" + "orientation [");
		orientation.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");

		MFVec2f scale = (MFVec2f)getField(scaleFieldName);
		printStream.println(indentString + "\t" + "scale [");
		scale.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");

		MFVec3f spine = (MFVec3f)getField(spineFieldName);
		printStream.println(indentString + "\t" + "spine [");
		spine.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");
	}
}
