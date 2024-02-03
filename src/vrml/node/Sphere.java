package vrml.node;

import java.io.PrintStream;
import java.util.Date;
import vrml.*;
import vrml.field.*;

public class Sphere extends Node {
	
	//// Field ////////////////
	private String	radiusFieldName	= "radius";

	public Sphere() {
		setHeaderFlag(false);
		setType(sphereTypeName);

		///////////////////////////
		// Exposed Field 
		///////////////////////////

		// radius exposed field
		SFFloat radius = new SFFloat(1);
		addExposedField(radiusFieldName, radius);
	}

	////////////////////////////////////////////////
	//	Radius
	////////////////////////////////////////////////
	
	public void setRadius(float value) {
		SFFloat sffloat = (SFFloat)getExposedField(radiusFieldName);
		sffloat.setValue(value);
	}
	public float getRadius() {
		SFFloat sffloat = (SFFloat)getExposedField(radiusFieldName);
		return sffloat.getValue();
	} 

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public Sphere next() {
		return (Sphere)next(getType());
	}

	public Sphere nextTraversal() {
		return (Sphere)nextTraversalByType(getType());
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
		printStream.println(indentString + "\t" + "radius " + getRadius() );
	}
}
