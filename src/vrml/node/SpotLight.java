package vrml.node;

import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class SpotLight extends Node {
	
	private String	onFieldName					= "on";
	private String	intensityFieldName			= "intensity";
	private String	ambientIntensityFieldName	= "ambientIntensity";
	private String	locationFieldName			= "location";
	private String	directionFieldName			= "direction";
	private String	colorFieldName				= "color";
	private String	radiusFieldName				= "radius";
	private String	attenuationFieldName		= "attenuation";
	private String	beamWidthFieldName			= "beamWidth";
	private String	cutOffAngleFieldName		= "cutOffAngle";

	public SpotLight() {
		setHeaderFlag(false);
		setType(spotLightTypeName);

		// on exposed field
		SFBool bon = new SFBool(true);
		bon.setName(onFieldName);
		addExposedField(bon);

		// intensity exposed field
		SFFloat intensity = new SFFloat(1.0f);
		intensity.setName(intensityFieldName);
		addExposedField(intensity);

		// ambient intensity exposed field
		SFFloat ambientIntensity = new SFFloat(0.0f);
		ambientIntensity.setName(ambientIntensityFieldName);
		addExposedField(ambientIntensity);

		// location exposed field
		SFVec3f location = new SFVec3f(0.0f, 0.0f, 0.0f);
		location.setName(locationFieldName);
		addExposedField(location);

		// direction exposed field
		SFVec3f direction = new SFVec3f(0.0f, 0.0f, -1.0f);
		direction.setName(directionFieldName);
		addExposedField(direction);

		// color exposed field
		SFColor color = new SFColor(1.0f, 1.0f, 1.0f);
		color.setName(colorFieldName);
		addExposedField(color);

		// radius exposed field
		SFFloat radius = new SFFloat(100.0f);
		radius.setName(radiusFieldName);
		addExposedField(radius);

		// attenuation exposed field
		SFVec3f attenuation = new SFVec3f(1.0f, 0.0f, 0.0f);
		attenuation.setName(attenuationFieldName);
		addExposedField(attenuation);

		// beamWidth exposed field
		SFFloat beamWidth = new SFFloat(1.570796f);
		beamWidth.setName(beamWidthFieldName);
		addExposedField(beamWidth);

		// cutOffAngle exposed field
		SFFloat cutOffAngle = new SFFloat(0.785398f);
		cutOffAngle.setName(cutOffAngleFieldName);
		addExposedField(cutOffAngle);
	}

	////////////////////////////////////////////////
	//	On
	////////////////////////////////////////////////
	
	public void setOn(boolean on) {
		SFBool bon = (SFBool)getExposedField(onFieldName);
		bon.setValue(on);
	}
	public boolean isOn() {
		SFBool bon = (SFBool)getExposedField(onFieldName);
		return bon.getValue();
	}

	////////////////////////////////////////////////
	//	Intensity
	////////////////////////////////////////////////
	
	public void setIntensity(float value) {
		SFFloat intensity = (SFFloat)getExposedField(intensityFieldName);
		intensity.setValue(value);
	}
	public float getIntensity() {
		SFFloat intensity = (SFFloat)getExposedField(intensityFieldName);
		return intensity.getValue();
	}

	////////////////////////////////////////////////
	//	AmbientIntensity
	////////////////////////////////////////////////
	
	public void setAmbientIntensity(float value) {
		SFFloat intensity = (SFFloat)getExposedField(ambientIntensityFieldName);
		intensity.setValue(value);
	}
	public float getAmbientIntensity() {
		SFFloat intensity = (SFFloat)getExposedField(ambientIntensityFieldName);
		return intensity.getValue();
	}

	////////////////////////////////////////////////
	//	Location
	////////////////////////////////////////////////

	public void setLocation(float value[]) {
		SFVec3f location = (SFVec3f)getExposedField(locationFieldName);
		location.setValue(value);
	}
	public void setLocation(float x, float y, float z) {
		SFVec3f location = (SFVec3f)getExposedField(locationFieldName);
		location.setValue(x, y, z);
	}
	public void getLocation(float value[]) {
		SFVec3f location = (SFVec3f)getExposedField(locationFieldName);
		location.getValue(value);
	}

	////////////////////////////////////////////////
	//	Direction
	////////////////////////////////////////////////

	public void setDirection(float value[]) {
		SFVec3f direction = (SFVec3f)getExposedField(directionFieldName);
		direction.setValue(value);
	}
	public void setDirection(float x, float y, float z) {
		SFVec3f direction = (SFVec3f)getExposedField(directionFieldName);
		direction.setValue(x, y, z);
	}
	public void getDirection(float value[]) {
		SFVec3f direction = (SFVec3f)getExposedField(directionFieldName);
		direction.getValue(value);
	}

	////////////////////////////////////////////////
	//	Color
	////////////////////////////////////////////////

	public void setColor(float value[]) {
		SFColor color = (SFColor)getExposedField(colorFieldName);
		color.setValue(value);
	}
	public void setColor(float r, float g, float b) {
		SFColor color = (SFColor)getExposedField(colorFieldName);
		color.setValue(r, g, b);
	}
	public void getColor(float value[]) {
		SFColor color = (SFColor)getExposedField(colorFieldName);
		color.getValue(value);
	}

	////////////////////////////////////////////////
	//	Radius
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
	//	Attenuation
	////////////////////////////////////////////////

	public void setAttenuation(float value[]) {
		SFVec3f attenuation = (SFVec3f)getExposedField(attenuationFieldName);
		attenuation.setValue(value);
	}
	public void setAttenuation(float x, float y, float z) {
		SFVec3f attenuation = (SFVec3f)getExposedField(attenuationFieldName);
		attenuation.setValue(x, y, z);
	}
	public void getAttenuation(float value[]) {
		SFVec3f attenuation = (SFVec3f)getExposedField(attenuationFieldName);
		attenuation.getValue(value);
	}

	////////////////////////////////////////////////
	//	BeamWidth
	////////////////////////////////////////////////
	
	public void setBeamWidth(float value) {
		SFFloat bwidth = (SFFloat)getExposedField(beamWidthFieldName);
		bwidth.setValue(value);
	}
	public float getBeamWidth() {
		SFFloat bwidth = (SFFloat)getExposedField(beamWidthFieldName);
		return bwidth.getValue();
	}


	////////////////////////////////////////////////
	//	CutOffAngle
	////////////////////////////////////////////////
	
	public void setCutOffAngle(float value) {
		SFFloat angle = (SFFloat)getExposedField(cutOffAngleFieldName);
		angle.setValue(value);
	}
	public float getCutOffAngle() {
		SFFloat angle = (SFFloat)getExposedField(cutOffAngleFieldName);
		return angle.getValue();
	}

	////////////////////////////////////////////////
	//	Diffuse Color
	////////////////////////////////////////////////

	void getDiffuseColor(float value[]) {
		getColor(value);
		float	intensity = getIntensity();
		value[0] *= intensity;
		value[1] *= intensity;
		value[2] *= intensity;
	}

	////////////////////////////////////////////////
	//	Ambient Color
	////////////////////////////////////////////////

	void getAmbientColor(float value[]) {
		getColor(value);
		float	intensity = getIntensity();
		float	ambientIntensity = getAmbientIntensity();
		value[0] *= intensity * ambientIntensity;
		value[1] *= intensity * ambientIntensity;
		value[2] *= intensity * ambientIntensity;
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public SpotLight next() {
		return (SpotLight)next(getType());
	}

	public SpotLight nextTraversal() {
		return (SpotLight)nextTraversalByType(getType());
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
		SFBool bon = (SFBool)getExposedField(onFieldName);
		float vec[] = new float[3];
		float rot[] = new float[4];

		printStream.println(indentString + "\t" + "on " + bon );
		printStream.println(indentString + "\t" + "intensity " + getIntensity() );
		printStream.println(indentString + "\t" + "ambientIntensity " + getAmbientIntensity() );
		getColor(vec);			printStream.println(indentString + "\t" + "color " + vec[X] + " "+ vec[Y] + " " + vec[Z] );
		getDirection(vec);		printStream.println(indentString + "\t" + "direction " + vec[X] + " "+ vec[Y] + " " + vec[Z] );
		getLocation(vec);		printStream.println(indentString + "\t" + "location " + vec[X] + " "+ vec[Y] + " " + vec[Z] );
		printStream.println(indentString + "\t" + "beamWidth " + getBeamWidth() );
		printStream.println(indentString + "\t" + "cutOffAngle " + getCutOffAngle() );
		printStream.println(indentString + "\t" + "radius " + getRadius() );
		getAttenuation(vec);	printStream.println(indentString + "\t" + "attenuation " + vec[X] + " "+ vec[Y] + " " + vec[Z] );
	}
}
