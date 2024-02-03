package vrml.node;

import java.io.PrintStream;
import java.util.Date;
import vrml.*;
import vrml.field.*;

public class Background extends Node {
	
	private String	groundColorFieldName	= "groundColor";
	private String	skyColorFieldName		= "skyColor";
	private String	groundAngleFieldName	= "groundAngle";
	private String	skyAngleFieldName		= "skyAngle";
	private String	frontUrlFieldName		= "frontUrl";
	private String	backUrlFieldName		= "backUrl";
	private String	leftUrlFieldName		= "leftUrl";
	private String	rightUrlFieldName		= "rightUrl";
	private String	topUrlFieldName			= "topUrl";
	private String	bottomUrlFieldName		= "bottomUrl";
	private String	bindEventIn				= "bind";
	private String	isBoundEventOut			= "isBound";

	public Background() {
		setHeaderFlag(false);
		setType(backgroundTypeName);

		// groundColor exposed field
		MFColor groundColor = new MFColor();
		addExposedField(groundColorFieldName, groundColor);

		// skyColor exposed field
		MFColor skyColor = new MFColor();
		addExposedField(skyColorFieldName, skyColor);

		// groundAngle exposed field
		MFFloat groundAngle = new MFFloat();
		addExposedField(groundAngleFieldName, groundAngle);

		// skyAngle exposed field
		MFFloat skyAngle = new MFFloat();
		addExposedField(skyAngleFieldName, skyAngle);

		// url exposed field
		MFString frontUrl = new MFString();
		addExposedField(frontUrlFieldName, frontUrl);

		// url exposed field
		MFString backUrl = new MFString();
		addExposedField(backUrlFieldName, backUrl);

		// url exposed field
		MFString leftUrl = new MFString();
		addExposedField(leftUrlFieldName, leftUrl);

		// url exposed field
		MFString rightUrl = new MFString();
		addExposedField(rightUrlFieldName, rightUrl);

		// url exposed field
		MFString topUrl = new MFString();
		addExposedField(topUrlFieldName, topUrl);

		// url exposed field
		MFString bottomUrl = new MFString();
		addExposedField(bottomUrlFieldName, bottomUrl);


		// bind event int
		SFBool bind = new SFBool(false);
		addEventIn(bindEventIn, bind);

		// isBound event out
		ConstSFBool isBound = new ConstSFBool(false);
		addEventOut(isBoundEventOut, isBound);
	}

	////////////////////////////////////////////////
	// groundColor
	////////////////////////////////////////////////

	public void addGroundColor(float value[]) {
		MFColor groundColor = (MFColor)getExposedField(groundColorFieldName);
		groundColor.addValue(value);
	}
	public int getNGroundColors() {
		MFColor groundColor = (MFColor)getExposedField(groundColorFieldName);
		return groundColor.getSize();
	}
	public void getGroundColor(int index, float value[]) {
		MFColor groundColor = (MFColor)getExposedField(groundColorFieldName);
		groundColor.get1Value(index, value);
	}

	////////////////////////////////////////////////
	// skyColor
	////////////////////////////////////////////////

	public void addSkyColor(float value[]) {
		MFColor skyColor = (MFColor)getExposedField(skyColorFieldName);
		skyColor.addValue(value);
	}
	public int getNSkyColors() {
		MFColor skyColor = (MFColor)getExposedField(skyColorFieldName);
		return skyColor.getSize();
	}
	public void getSkyColor(int index, float value[]) {
		MFColor skyColor = (MFColor)getExposedField(skyColorFieldName);
		skyColor.get1Value(index, value);
	}

	////////////////////////////////////////////////
	// groundAngle
	////////////////////////////////////////////////

	public void addGroundAngle(float value) {
		MFFloat groundAngle = (MFFloat)getExposedField(groundAngleFieldName);
		groundAngle.addValue(value);
	}
	public int getNGroundAngles() {
		MFFloat groundAngle = (MFFloat)getExposedField(groundAngleFieldName);
		return groundAngle.getSize();
	}
	public float getGroundAngle(int index) {
		MFFloat groundAngle = (MFFloat)getExposedField(groundAngleFieldName);
		return groundAngle.get1Value(index);
	}

	////////////////////////////////////////////////
	// skyAngle
	////////////////////////////////////////////////

	public void addSkyAngle(float value) {
		MFFloat skyAngle = (MFFloat)getExposedField(skyAngleFieldName);
		skyAngle.addValue(value);
	}
	public int getNSkyAngles() {
		MFFloat skyAngle = (MFFloat)getExposedField(skyAngleFieldName);
		return skyAngle.getSize();
	}
	public float getSkyAngle(int index) {
		MFFloat skyAngle = (MFFloat)getExposedField(skyAngleFieldName);
		return skyAngle.get1Value(index);
	}

	////////////////////////////////////////////////
	// frontUrl
	////////////////////////////////////////////////

	public void addFrontUrl(String value) {
		MFString frontUrl = (MFString)getExposedField(frontUrlFieldName);
		frontUrl.addValue(value);
	}
	public int getNFrontUrls() {
		MFString frontUrl = (MFString)getExposedField(frontUrlFieldName);
		return frontUrl.getSize();
	}
	public String getFrontUrl(int index) {
		MFString frontUrl = (MFString)getExposedField(frontUrlFieldName);
		return frontUrl.get1Value(index);
	}

	////////////////////////////////////////////////
	// backUrl
	////////////////////////////////////////////////

	public void addBackUrl(String value) {
		MFString backUrl = (MFString)getExposedField(backUrlFieldName);
		backUrl.addValue(value);
	}
	public int getNBackUrls() {
		MFString backUrl = (MFString)getExposedField(backUrlFieldName);
		return backUrl.getSize();
	}
	public String getBackUrl(int index) {
		MFString backUrl = (MFString)getExposedField(backUrlFieldName);
		return backUrl.get1Value(index);
	}

	////////////////////////////////////////////////
	// leftUrl
	////////////////////////////////////////////////

	public void addLeftUrl(String value) {
		MFString leftUrl = (MFString)getExposedField(leftUrlFieldName);
		leftUrl.addValue(value);
	}
	public int getNLeftUrls() {
		MFString leftUrl = (MFString)getExposedField(leftUrlFieldName);
		return leftUrl.getSize();
	}
	public String getLeftUrl(int index) {
		MFString leftUrl = (MFString)getExposedField(leftUrlFieldName);
		return leftUrl.get1Value(index);
	}

	////////////////////////////////////////////////
	// rightUrl
	////////////////////////////////////////////////

	public void addRightUrl(String value) {
		MFString rightUrl = (MFString)getExposedField(rightUrlFieldName);
		rightUrl.addValue(value);
	}
	public int getNRightUrls() {
		MFString rightUrl = (MFString)getExposedField(rightUrlFieldName);
		return rightUrl.getSize();
	}
	public String getRightUrl(int index) {
		MFString rightUrl = (MFString)getExposedField(rightUrlFieldName);
		return rightUrl.get1Value(index);
	}

	////////////////////////////////////////////////
	// topUrl
	////////////////////////////////////////////////

	public void addTopUrl(String value) {
		MFString topUrl = (MFString)getExposedField(topUrlFieldName);
		topUrl.addValue(value);
	}
	public int getNTopUrls() {
		MFString topUrl = (MFString)getExposedField(topUrlFieldName);
		return topUrl.getSize();
	}
	public String getTopUrl(int index) {
		MFString topUrl = (MFString)getExposedField(topUrlFieldName);
		return topUrl.get1Value(index);
	}

	////////////////////////////////////////////////
	// bottomUrl
	////////////////////////////////////////////////

	public void addBottomUrl(String value) {
		MFString bottomUrl = (MFString)getExposedField(bottomUrlFieldName);
		bottomUrl.addValue(value);
	}
	public int getNBottomUrls() {
		MFString bottomUrl = (MFString)getExposedField(bottomUrlFieldName);
		return bottomUrl.getSize();
	}
	public String getBottomUrl(int index) {
		MFString bottomUrl = (MFString)getExposedField(bottomUrlFieldName);
		return bottomUrl.get1Value(index);
	}

	////////////////////////////////////////////////
	//	bind
	////////////////////////////////////////////////

	public void setBind(boolean value) {
		SFBool bind = (SFBool)getEventIn(bindEventIn);
		bind.setValue(value);
	}
	public boolean getBind() {
		SFBool bind = (SFBool)getEventIn(bindEventIn);
		return bind.getValue();
	}

	////////////////////////////////////////////////
	//	isBound
	////////////////////////////////////////////////

	public void setIsBound(boolean value) {
		ConstSFBool isBound = (ConstSFBool)getEventOut(isBoundEventOut);
		isBound.setValue(value);
	}
	public boolean getIsBound() {
		ConstSFBool isBound = (ConstSFBool)getEventOut(isBoundEventOut);
		return isBound.getValue();
	}

	public boolean isBound() {
		return getIsBound();
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public Background next() {
		return (Background)next(getType());
	}

	public Background nextTraversal() {
		return (Background)nextTraversalByType(getType());
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

		MFColor groundColor = (MFColor)getExposedField(groundColorFieldName);
		printStream.println(indentString + "\t" + "groundColor [");
		groundColor.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");

		MFColor skyColor = (MFColor)getExposedField(skyColorFieldName);
		printStream.println(indentString + "\t" + "skyColor [");
		skyColor.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");


		MFFloat groundAngle = (MFFloat)getExposedField(groundAngleFieldName);
		printStream.println(indentString + "\t" + "groundAngle [");
		groundAngle.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");

		MFFloat skyAngle = (MFFloat)getExposedField(skyAngleFieldName);
		printStream.println(indentString + "\t" + "skyAngle [");
		skyAngle.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");


		MFString frontUrl = (MFString)getExposedField(frontUrlFieldName);
		printStream.println(indentString + "\t" + "frontUrl [");
		frontUrl.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");

		MFString backUrl = (MFString)getExposedField(backUrlFieldName);
		printStream.println(indentString + "\t" + "backUrl [");
		backUrl.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");

		MFString leftUrl = (MFString)getExposedField(leftUrlFieldName);
		printStream.println(indentString + "\t" + "leftUrl [");
		leftUrl.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");

		MFString rightUrl = (MFString)getExposedField(rightUrlFieldName);
		printStream.println(indentString + "\t" + "rightUrl [");
		rightUrl.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");

		MFString topUrl = (MFString)getExposedField(topUrlFieldName);
		printStream.println(indentString + "\t" + "topUrl [");
		topUrl.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");

		MFString bottomUrl = (MFString)getExposedField(bottomUrlFieldName);
		printStream.println(indentString + "\t" + "bottomUrl [");
		bottomUrl.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");
	}
}
