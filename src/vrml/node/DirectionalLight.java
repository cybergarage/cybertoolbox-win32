package vrml.node;

import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class DirectionalLight extends Node {
	
	private String	onFieldName					= "on";
	private String	intensityFieldName			= "intensity";
	private String	ambientIntensityFieldName	= "ambientIntensity";
	private String	directionFieldName			= "direction";
	private String	colorFieldName				= "color";

	public DirectionalLight() {
		setHeaderFlag(false);
		setType(directionalLightTypeName);

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

		// direction exposed field
		SFVec3f direction = new SFVec3f(0.0f, 0.0f, -1.0f);
		direction.setName(directionFieldName);
		addExposedField(direction);

		// color exposed field
		SFColor color = new SFColor(1.0f, 1.0f, 1.0f);
		color.setName(colorFieldName);
		addExposedField(color);
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

	public DirectionalLight next() {
		return (DirectionalLight)next(getType());
	}

	public DirectionalLight nextTraversal() {
		return (DirectionalLight)nextTraversalByType(getType());
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
		float rot[] = new float[4];

		SFBool bon = (SFBool)getExposedField(onFieldName);
		printStream.println(indentString + "\t" + "on " + bon );

		printStream.println(indentString + "\t" + "intensity " + getIntensity() );
		printStream.println(indentString + "\t" + "ambientIntensity " + getAmbientIntensity() );
		getColor(vec);			printStream.println(indentString + "\t" + "color " + vec[X] + " "+ vec[Y] + " " + vec[Z] );
		getDirection(vec);		printStream.println(indentString + "\t" + "direction " + vec[X] + " "+ vec[Y] + " " + vec[Z] );
	}
}
