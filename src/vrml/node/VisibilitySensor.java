package vrml.node;

import java.io.PrintStream;
import java.util.Date;
import vrml.*;
import vrml.field.*;

public class VisibilitySensor extends Node {
	
	private String	enabledFieldName		= "enabled";
	private String	centerFieldName			= "center";
	private String	sizeFieldName			= "size";

	private String	enterTimeEventOutName	= "enterTime";
	private String	exitTimeEventOutName	= "exitTime";

	public VisibilitySensor() {
		setHeaderFlag(false);
		setType(visibilitySensorTypeName);

		// enabled exposed field
		SFBool enabled = new SFBool(true);
		addExposedField(enabledFieldName, enabled);

		// center exposed field
		SFVec3f center = new SFVec3f(0.0f, 0.0f, 0.0f);
		addExposedField(centerFieldName, center);

		// size exposed field
		SFVec3f size = new SFVec3f(0.0f, 0.0f, 0.0f);
		addExposedField(sizeFieldName, size);

		
		// isActive eventOut field
		ConstSFBool isActive = new ConstSFBool(false);
		addEventOut(isActiveFieldName, isActive);

		// enterTime eventOut field
		ConstSFTime enterTime = new ConstSFTime(0.0f);
		addEventOut(enterTimeEventOutName, enterTime);

		// exitTime eventOut field
		ConstSFTime exitTime = new ConstSFTime(0.0f);
		addEventOut(exitTimeEventOutName, exitTime);
	}

	////////////////////////////////////////////////
	//	Enabled
	////////////////////////////////////////////////
	
	public void setEnabled(boolean value) {
		SFBool bEnabled = (SFBool)getExposedField(enabledFieldName);
		bEnabled.setValue(value);
	}
	public boolean getEnabled() {
		SFBool bEnabled = (SFBool)getExposedField(enabledFieldName);
		return bEnabled.getValue();
	}
	public boolean isEnabled() {
		return getEnabled();
	}

	////////////////////////////////////////////////
	//	Center
	////////////////////////////////////////////////
	
	public void setCenter(float value[]) {
		SFVec3f sfvec3f = (SFVec3f)getExposedField(centerFieldName);
		sfvec3f.setValue(value);
	}
	public void setCenter(float x, float y, float z) {
		SFVec3f sfvec3f = (SFVec3f)getExposedField(centerFieldName);
		sfvec3f.setValue(x, y, z);
	}
	public void getCenter(float value[]) {
		SFVec3f sfvec3f = (SFVec3f)getExposedField(centerFieldName);
		sfvec3f.getValue();
	}

	////////////////////////////////////////////////
	//	Size
	////////////////////////////////////////////////
	
	public void setSize(float value[]) {
		SFVec3f sfvec3f = (SFVec3f)getExposedField(sizeFieldName);
		sfvec3f.setValue(value);
	}
	public void setSize(float x, float y, float z) {
		SFVec3f sfvec3f = (SFVec3f)getExposedField(sizeFieldName);
		sfvec3f.setValue(x, y, z);
	}
	public void getSize(float value[]) {
		SFVec3f sfvec3f = (SFVec3f)getExposedField(sizeFieldName);
		sfvec3f.getValue();
	}

	////////////////////////////////////////////////
	//	isActive
	////////////////////////////////////////////////
	
	public void setIsActive(boolean value) {
		SFBool sfbool = (SFBool)getExposedField(isActiveFieldName);
		sfbool.setValue(value);
	}
	public boolean getIsActive() {
		SFBool sfbool = (SFBool)getExposedField(isActiveFieldName);
		return sfbool.getValue();
	}
	public boolean isActive() {
		return getIsActive();
	}

	////////////////////////////////////////////////
	//	EnterTime
	////////////////////////////////////////////////
	
	public void setEnterTime(double value) {
		ConstSFTime time = (ConstSFTime)getEventOut(enterTimeEventOutName);
		time.setValue(value);
	}
	public double getEnterTime() {
		ConstSFTime time = (ConstSFTime)getEventOut(enterTimeEventOutName);
		return time.getValue();
	}

	////////////////////////////////////////////////
	//	ExitTime
	////////////////////////////////////////////////
	
	public void setExitTime(double value) {
		ConstSFTime time = (ConstSFTime)getEventOut(exitTimeEventOutName);
		time.setValue(value);
	}
	public double getExitTime() {
		ConstSFTime time = (ConstSFTime)getEventOut(exitTimeEventOutName);
		return time.getValue();
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public VisibilitySensor next() {
		return (VisibilitySensor)next(getType());
	}

	public VisibilitySensor nextTraversal() {
		return (VisibilitySensor)nextTraversalByType(getType());
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
		SFBool enabled = (SFBool)getExposedField(enabledFieldName);
		SFVec3f center = (SFVec3f)getExposedField(centerFieldName);
		SFVec3f size = (SFVec3f)getExposedField(sizeFieldName);

		printStream.println(indentString + "\t" + "enabled " + enabled );
		printStream.println(indentString + "\t" + "center " + center );
		printStream.println(indentString + "\t" + "size " + size );
	}
}
