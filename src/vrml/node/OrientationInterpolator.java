package vrml.node;

import java.util.Vector;
import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class OrientationInterpolator extends Node {

	private String	keyFieldName		= "key";
	private String	keyValueFieldName	= "keyValue";

	public OrientationInterpolator() {
		setHeaderFlag(false);
		setType(orientationInterpolatorTypeName);

		// key exposed field
		MFFloat key = new MFFloat();
		addExposedField(keyFieldName, key);

		// keyValue exposed field
		MFRotation keyValue = new MFRotation();
		addExposedField(keyValueFieldName, keyValue);

		// set_fraction eventIn field
		SFFloat setFraction = new SFFloat(0.0f);
		addEventIn(fractionFieldName, setFraction);

		// value_changed eventOut field
		ConstSFRotation valueChanged = new ConstSFRotation(0.0f, 0.0f, 1.0f, 0.0f);
		addEventOut(valueFieldName, valueChanged);
	}

	////////////////////////////////////////////////
	//	key
	////////////////////////////////////////////////
	
	public void addKey(float value) {
		MFFloat key = (MFFloat)getExposedField(keyFieldName);
		key.addValue(value);
	}
	public int getNKeys() {
		MFFloat key = (MFFloat)getExposedField(keyFieldName);
		return key.getSize();
	}
	public float getKey(int index) {
		MFFloat key = (MFFloat)getExposedField(keyFieldName);
		return key.get1Value(index);
	}
	public Field getKeyField() {
		return getExposedField(keyFieldName);
	}

	////////////////////////////////////////////////
	//	keyValue
	////////////////////////////////////////////////
	
	public void addKeyValue(float rotation[]) {
		MFRotation keyValue = (MFRotation)getExposedField(keyValueFieldName);
		keyValue.addValue(rotation);
	}

	public int getNKeyValues() {
		MFRotation keyValue = (MFRotation)getExposedField(keyValueFieldName);
		return keyValue.getSize();
	}
	
	public void getKeyValue(int index, float rotation[]) {
		MFRotation keyValue = (MFRotation)getExposedField(keyValueFieldName);
		keyValue.get1Value(index, rotation);
	}

	public Field getKeyValueField() {
		return getExposedField(keyValueFieldName);
	}

	////////////////////////////////////////////////
	//	fraction
	////////////////////////////////////////////////
	
	public void setFraction(float value) {
		SFFloat fraction = (SFFloat)getEventIn(fractionFieldName);
		fraction.setValue(value);
	}

	public float getFraction() {
		SFFloat fraction = (SFFloat)getEventIn(fractionFieldName);
		return fraction.getValue();
	}

	public Field getFractionField() {
		return getEventIn(fractionFieldName);
	}

	////////////////////////////////////////////////
	//	value
	////////////////////////////////////////////////
	
	public void setValue(float rotation[]) {
		ConstSFRotation value = (ConstSFRotation)getEventOut(valueFieldName);
		value.setValue(rotation);
	}

	public void getValue(float rotation[]) {
		ConstSFRotation value = (ConstSFRotation)getEventOut(valueFieldName);
		value.getValue(rotation);
	}

	public Field getValueField() {
		return getEventOut(valueFieldName);
	}

	////////////////////////////////////////////////
	//	abstract functions
	////////////////////////////////////////////////
	
	public void initialize() {
	}

	public void update() {

		float fraction = getFraction();
		int index = -1;
		for (int n=0; n<(getNKeys()-1); n++) {
			if (getKey(n) <= fraction && fraction <= getKey(n+1)) {
				index = n;
				break;
			}
		}
		if (index == -1)
			return;

		float scale = (fraction - getKey(index)) / (getKey(index+1) - getKey(index));

		float rotation1[] = new float[4];
		float rotation2[] = new float[4];
		float rotationOut[] = new float[4];

		getKeyValue(index, rotation1);
		getKeyValue(index+1, rotation2);
		for (int n=0; n<4; n++)
			rotationOut[n] = rotation1[n] + (rotation2[n] - rotation1[n])*scale;

		setValue(rotationOut);
		sendEvent(getValueField());
	}

	////////////////////////////////////////////////
	//	Output
	////////////////////////////////////////////////

	public void outputContext(PrintStream printStream, String indentString) {

		printStream.println(indentString + "\tkey [");
		for (int n=0; n<getNKeys(); n++) {
			if (n < getNKeys()-1)
				printStream.println(indentString + "\t\t" + getKey(n));
			else	
				printStream.println(indentString + "\t\t" + getKey(n));
		}
		printStream.println(indentString + "\t]");
	
		float rotation[] = new float[4];
		printStream.println(indentString + "\tkeyValue [");
		for (int n=0; n<getNKeyValues(); n++) {
			getKeyValue(n, rotation);
			if (n < getNKeyValues()-1)
				printStream.println(indentString + "\t\t" + rotation[X] + " " + rotation[Y] + " " + rotation[Z] + " " + rotation[3] + ",");
			else	
				printStream.println(indentString + "\t\t" + rotation[X] + " " + rotation[Y] + " " + rotation[Z] + " " + rotation[3]);
		}
		printStream.println(indentString + "\t]");
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public OrientationInterpolator next() {
		return (OrientationInterpolator)next(getType());
	}

	public OrientationInterpolator nextTraversal() {
		return (OrientationInterpolator)nextTraversalByType(getType());
	}

}