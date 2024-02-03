package vrml.node;

import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class PointLight extends Node {

	private String	onFieldName					= "on";
	private String	intensityFieldName			= "intensity";
	private String	ambientIntensityFieldName	= "ambientIntensity";
	private String	locationFieldName			= "location";
	private String	colorFieldName				= "color";
	private String	radiusFieldName				= "radius";
	private String	attenuationFieldName		= "attenuation";
	
	public PointLight() {
		setHeaderFlag(false);
		setType(pointLightTypeName);

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

	public PointLight next() {
		return (PointLight)next(getType());
	}

	public PointLight nextTraversal() {
		return (PointLight)nextTraversalByType(getType());
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
		float vec[] = new float[3];

		SFBool bon = (SFBool)getExposedField(onFieldName);
		printStream.println(indentString + "\t" + "on " + bon );

		printStream.println(indentString + "\t" + "intensity " + getIntensity() );
		printStream.println(indentString + "\t" + "ambientIntensity " + getAmbientIntensity() );
		getColor(vec);			printStream.println(indentString + "\t" + "color " + vec[X] + " "+ vec[Y] + " " + vec[Z] );
		getLocation(vec);		printStream.println(indentString + "\t" + "location " + vec[X] + " "+ vec[Y] + " " + vec[Z] );
		printStream.println(indentString + "\t" + "radius " + getRadius() );
		getAttenuation(vec);	printStream.println(indentString + "\t" + "attenuation " + vec[X] + " "+ vec[Y] + " " + vec[Z] );
	}
}
