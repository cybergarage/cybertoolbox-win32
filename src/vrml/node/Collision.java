package vrml.node;

import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class Collision extends GroupingNode {

	private String	collideFieldName		= "collide";
	private String	collideTimeEventOut		= "collideTime";
	
	public Collision() {
		super();

		setHeaderFlag(false);
		setType(collisionTypeName);

		// collide exposed field
		SFBool collide = new SFBool(true);
		addExposedField(collideFieldName, collide);

		// collide event out
		ConstSFTime collideTime = new ConstSFTime(-1.0);
		addEventOut(collideTimeEventOut, collideTime);
	}

	////////////////////////////////////////////////
	//	collide
	////////////////////////////////////////////////

	public void setCollide(boolean value) {
		SFBool collide = (SFBool)getExposedField(collideFieldName);
		collide.setValue(value);
	}

	public boolean getCollide() {
		SFBool collide = (SFBool)getExposedField(collideFieldName);
		return collide.getValue();
	}

	////////////////////////////////////////////////
	//	collideTime
	////////////////////////////////////////////////

	public void setcollideTime(double value) {
		ConstSFTime collideTime = (ConstSFTime)getEventOut(collideTimeEventOut);
		collideTime.setValue(value);
	}

	public double getcollideTime() {
		ConstSFTime collideTime = (ConstSFTime)getEventOut(collideTimeEventOut);
		return collideTime.getValue();
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public Collision next() {
		return (Collision)next(getType());
	}

	public Collision nextTraversal() {
		return (Collision)nextTraversalByType(getType());
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
		SFBool collide = (SFBool)getExposedField(collideFieldName);
		printStream.println(indentString + "\t" + "collide " + collide);
	}
}
