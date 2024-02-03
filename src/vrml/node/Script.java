package vrml.node;

import java.io.PrintStream;
import java.util.Vector;
import java.util.Date;
import vrml.*;
import vrml.field.*;

public class Script extends BaseNode { 
 
	private String	urlExposedFieldName		= "url";
	private String	directOutputFieldName	= "directOutput";
	private String	mustEvaluateFieldName	= "mustEvaluate";
	private Script	mBehaviorScript			= null;

	public Script() {
		setHeaderFlag(false);
		setType(scriptTypeName);

		// directOutput exposed field
		SFBool directOutput = new SFBool(false);
		addField(directOutputFieldName, directOutput);

		// directOutput exposed field
		SFBool mustEvaluate = new SFBool(false);
		addField(mustEvaluateFieldName, mustEvaluate);

		// url exposed field
		MFString url = new MFString();
		addExposedField(urlExposedFieldName, url);
	}

	////////////////////////////////////////////////
	// DirectOutput
	////////////////////////////////////////////////

	public void setDirectOutput(boolean value) {
		SFBool directOutput = (SFBool)getField(directOutputFieldName);
		directOutput.setValue(value);
	}
	public boolean getDirectOutput() {
		SFBool directOutput = (SFBool)getField(directOutputFieldName);
		return directOutput.getValue();
	}

	////////////////////////////////////////////////
	// MustEvaluate
	////////////////////////////////////////////////

	public void setMustEvaluate(boolean value) {
		SFBool mustEvaluate = (SFBool)getField(mustEvaluateFieldName);
		mustEvaluate.setValue(value);
	}
	public boolean getMustEvaluate() {
		SFBool mustEvaluate = (SFBool)getField(mustEvaluateFieldName);
		return mustEvaluate.getValue();
	}

	////////////////////////////////////////////////
	// Url
	////////////////////////////////////////////////

	public void addUrl(String value) {
		MFString url = (MFString)getExposedField(urlExposedFieldName);
		url.addValue(value);
	}
	public int getNUrls() {
		MFString url = (MFString)getExposedField(urlExposedFieldName);
		return url.getSize();
	}
	public String getUrl(int index) {
		MFString url = (MFString)getExposedField(urlExposedFieldName);
		return url.get1Value(index);
	}

	////////////////////////////////////////////////
	// Add Field
	////////////////////////////////////////////////

	public Field createFieldFromString(String fieldType) {

		if (fieldType.compareTo("SFBool") == 0)
			return new SFBool(true);
		else if (fieldType.compareTo("SFColor") == 0)
			return new SFColor(0.0f, 0.0f, 0.0f);
		else if (fieldType.compareTo("SFFloat") == 0)
			return new SFFloat(0.0f);
		else if (fieldType.compareTo("SFInt32") == 0)
			return new SFInt32(0);
		else if (fieldType.compareTo("SFRotation") == 0)
			return new SFRotation(0.0f, 0.0f, 1.0f, 0.0f);
		else if (fieldType.compareTo("SFString") == 0)
			return new SFString("");
		else if (fieldType.compareTo("SFTime") == 0)
			return new SFTime(0.0);
		else if (fieldType.compareTo("SFVec2f") == 0)
			return new SFVec2f(0.0f, 0.0f);
		else if (fieldType.compareTo("SFVec3f") == 0)
			return new SFVec3f(0.0f, 0.0f, 0.0f);

		if (fieldType.compareTo("ConstSFBool") == 0)
			return new ConstSFBool(true);
		else if (fieldType.compareTo("ConstSFColor") == 0)
			return new ConstSFColor(0.0f, 0.0f, 0.0f);
		else if (fieldType.compareTo("ConstSFFloat") == 0)
			return new ConstSFFloat(0.0f);
		else if (fieldType.compareTo("ConstSFInt32") == 0)
			return new ConstSFInt32(0);
		else if (fieldType.compareTo("ConstSFRotation") == 0)
			return new ConstSFRotation(0.0f, 0.0f, 1.0f, 0.0f);
		else if (fieldType.compareTo("ConstSFString") == 0)
			return new ConstSFString("");
		else if (fieldType.compareTo("ConstSFTime") == 0)
			return new ConstSFTime(0.0);
		else if (fieldType.compareTo("ConstSFVec2f") == 0)
			return new ConstSFVec2f(0.0f, 0.0f);
		else if (fieldType.compareTo("ConstSFVec3f") == 0)
			return new ConstSFVec3f(0.0f, 0.0f, 0.0f);

		if (fieldType.compareTo("MFColor") == 0)
			return new MFColor();
		else if (fieldType.compareTo("MFFloat") == 0)
			return new MFFloat();
		else if (fieldType.compareTo("MFInt32") == 0)
			return new MFInt32();
		else if (fieldType.compareTo("MFRotation") == 0)
			return new MFRotation();
		else if (fieldType.compareTo("MFString") == 0)
			return new MFString();
		else if (fieldType.compareTo("MFTime") == 0)
			return new MFTime();
		else if (fieldType.compareTo("MFVec2f") == 0)
			return new MFVec2f();
		else if (fieldType.compareTo("MFVec3f") == 0)
			return new MFVec3f();

		if (fieldType.compareTo("ConstMFColor") == 0)
			return new ConstMFColor();
		else if (fieldType.compareTo("ConstMFFloat") == 0)
			return new ConstMFFloat();
		else if (fieldType.compareTo("ConstMFInt32") == 0)
			return new ConstMFInt32();
		else if (fieldType.compareTo("ConstMFRotation") == 0)
			return new ConstMFRotation();
		else if (fieldType.compareTo("ConstMFString") == 0)
			return new ConstMFString();
		else if (fieldType.compareTo("ConstMFTime") == 0)
			return new ConstMFTime();
		else if (fieldType.compareTo("ConstMFVec2f") == 0)
			return new ConstMFVec2f();
		else if (fieldType.compareTo("ConstMFVec3f") == 0)
			return new ConstMFVec3f();

		return null;
	}

	public void addEventOut(String fieldType, String name) {
		Field field = createFieldFromString(fieldType);

		if (field != null) {
			addEventOut(name, field);
		}
	}

	public void addEventIn(String fieldType, String name) {
		Field field = createFieldFromString(fieldType);
		if (field != null) {
			addEventIn(name, field);
		}
	}

	public void addField(String fieldType, String name, String value) {
		Field field = createFieldFromString(fieldType);

		if (field != null) {
			if (fieldType.compareTo("SFBool") == 0)
				((SFBool)field).setValue(value);
/*
			else if (fieldType.compareTo("SFColor") == 0)
				return new SFColor(0.0f, 0.0f, 0.0f);
*/
			else if (fieldType.compareTo("SFFloat") == 0)
				((SFFloat)field).setValue(value);
			else if (fieldType.compareTo("SFInt32") == 0)
				((SFInt32)field).setValue(value);
/*
			else if (fieldType.compareTo("SFRotation") == 0)
				return new SFRotation(0.0f, 0.0f, 1.0f, 0.0f);
*/
			else if (fieldType.compareTo("SFString") == 0)
				((SFString)field).setValue(value);
			else if (fieldType.compareTo("SFTime") == 0)
				((SFTime)field).setValue(value);
/*
			else if (fieldType.compareTo("SFVec2f") == 0)
				return new SFVec2f(0.0f, 0.0f);
*/
			else if (fieldType.compareTo("SFVec3f") == 0)
				((SFVec3f)field).setValue(value);

			addField(name, field);
		}
	}

	////////////////////////////////////////////////
	//	Field
	////////////////////////////////////////////////

	private Vector	mField = new Vector();

	public Field getField(String fieldName) {
		for (int n=0; n<getNFields(); n++) {
			Field field = getField(n);
			if (fieldName.compareTo(field.getName()) == 0)
				return field;
		}
		return null;
	}

	public int getNFields() {
		return mField.size();
	}

	public void addField(Field field) {
		mField.addElement(field);
	}

	public void addField(String name, Field field) {
		field.setName(name);
		mField.addElement(field);
	}

	public Field getField(int index) {
		return (Field)mField.elementAt(index);
	}

	////////////////////////////////////////////////
	//	ExposedField
	////////////////////////////////////////////////

	private Vector	mExposedField = new Vector();

	// Get an exposed field by name. 
	//   Throws an InvalidExposedFieldException if fieldName isn't a valid
	//   exposed field name for a node of this type.
	public final Field getExposedField(String fieldName) {
		for (int n=0; n<getNExposedFields(); n++) {
			Field field = getExposedField(n);
			if (fieldName.compareTo(field.getName()) == 0)
				return field;
			if (fieldName.startsWith(eventInStripString)) {
				if (fieldName.endsWith(field.getName()))
					return field;
			}
			if (fieldName.endsWith(eventOutStripString)) {
				if (fieldName.startsWith(field.getName()))
					return field;
			}
		}
		return null;
	}

	public int getNExposedFields() {
		return mExposedField.size();
	}

	public void addExposedField(Field field) {
		mExposedField.addElement(field);
	}

	public void addExposedField(String name, Field field) {
		field.setName(name);
		mExposedField.addElement(field);
	}

	public Field getExposedField(int index) {
		return (Field)mExposedField.elementAt(index);
	}

	////////////////////////////////////////////////
	//	EventIn
	////////////////////////////////////////////////

	private Vector	mEventInField = new Vector();

	// Get an EventIn by name. Return value is write-only.
	//   Throws an InvalidEventInException if eventInName isn't a valid
	//   event in name for a node of this type.
	public final Field getEventIn(String fieldName) {

		for (int n=0; n<getNEventIn(); n++) {
			Field field = getEventIn(n);
			if (fieldName.compareTo(field.getName()) == 0)
				return field;
			if (fieldName.startsWith(eventInStripString)) {
				if (fieldName.endsWith(field.getName()))
					return field;
			}
		}

		return null;
	}

	public int getNEventIn() {
		return mEventInField.size();
	}

	public void addEventIn(Field field) {
		mEventInField.addElement(field);
	}

	public void addEventIn(String name, Field field) {
		field.setName(name);
		mEventInField.addElement(field);
	}

	public Field getEventIn(int index) {
		return (Field)mEventInField.elementAt(index);
	}

	////////////////////////////////////////////////
	//	EventOut
	////////////////////////////////////////////////

	private Vector	mEventOutField = new Vector();

	public final Field getEventOut(String fieldName) {
		for (int n=0; n<getNEventOut(); n++) {
			Field field = getEventOut(n);
			if (fieldName.compareTo(field.getName()) == 0)
				return field;
			if (fieldName.regionMatches(fieldName.length() - eventOutStripString.length(), eventOutStripString, 0, eventOutStripString.length())) {
				if (fieldName.regionMatches(0, field.getName(), 0, fieldName.length() - eventOutStripString.length()))
					return field;
			}
		}
		return null;
	}

	public int getNEventOut() {
		return mEventOutField.size();
	}

	public void addEventOut(Field field) {
		mEventOutField.addElement(field);
	}

	public void addEventOut(String name, Field field) {
		field.setName(name);
		mEventOutField.addElement(field);
	}

	public Field getEventOut(int index) {
		return (Field)mEventOutField.elementAt(index);
	}


	////////////////////////////////////////////////
	//	processEvent
	////////////////////////////////////////////////

	// processEvents() is called automatically when the script receives 
	//   some set of events. It should not be called directly except by its subclass.
	//   count indicates the number of events delivered.
	public void processEvents(int count, Event events[]) {
	}

	// processEvent() is called automatically when the script receives 
	// an event. 
	public void processEvent(Event event) {
	}

	// eventsProcessed() is called after every invocation of processEvents().
	public void eventsProcessed() {
	}

	// shutdown() is called when this Script node is deleted.
	public void shutdown() {
	}

	////////////////////////////////////////////////
	//	Script
	////////////////////////////////////////////////

	public boolean hasScript() {
		if (mBehaviorScript != null)
			return true;
		else
			return false;
	}

	public Script getScriptObject() {
		return mBehaviorScript;
	}

	// This method is called before any event is generated
	public void initialize() {
		if (1 <= getNUrls()) {
			ScriptClassLoader lc = new ScriptClassLoader();
			String classFileName = getUrl(0);
			Class c = null;
			try {
				c = lc.loadClass(classFileName, true);
				mBehaviorScript = (Script)c.newInstance();
				if (mBehaviorScript!= null)
					mBehaviorScript.initialize();
			}
			catch (ClassNotFoundException e) {
				System.out.println("Script : Couldn't load the file (" + c + " : " + mBehaviorScript + ") !!");
				System.out.println(e);
			}
			catch (InstantiationException e) {
				System.out.println("Script : Couldn't create the class (" + c + " : " + mBehaviorScript + ") !!");
				System.out.println(e);
			}
			catch (IllegalAccessException e) {
				System.out.println("Script : Couldn't create the class (" +  c + " : " + mBehaviorScript + ") !!");
				System.out.println(e);
			}
		}

	}

	public void processEvent(Field eventField) {
		// Create a const field value for event
		ConstField	cfield = null;
		switch (eventField.getType()) {
		// Field
		case fieldTypeSFBool		: cfield = new ConstSFBool((SFBool)eventField);		break;
		case fieldTypeSFColor		: cfield = new ConstSFColor((SFColor)eventField);	break;
		case fieldTypeSFFloat		: cfield = new ConstSFFloat((SFFloat)eventField);	break;
		case fieldTypeSFInt32		: cfield = new ConstSFInt32((SFInt32)eventField);	break;
		case fieldTypeSFRotation	: cfield = new ConstSFRotation((SFRotation)eventField);	break;
		case fieldTypeSFString		: cfield = new ConstSFString((SFString)eventField);	break;
		case fieldTypeSFTime		: cfield = new ConstSFTime((SFTime)eventField);		break;
	  	case fieldTypeSFVec2f		: cfield = new ConstSFVec2f((SFVec2f)eventField);	break;
	  	case fieldTypeSFVec3f		: cfield = new ConstSFVec3f((SFVec3f)eventField);	break;
	  	case fieldTypeSFNode		: cfield = new ConstSFNode((SFNode)eventField);		break;
		case fieldTypeMFColor		: cfield = new ConstMFColor((MFColor)eventField);	break;
		case fieldTypeMFFloat		: cfield = new ConstMFFloat((MFFloat)eventField);	break;
		case fieldTypeMFInt32		: cfield = new ConstMFInt32((MFInt32)eventField);	break;
		case fieldTypeMFRotation	: cfield = new ConstMFRotation((MFRotation)eventField);	break;
		case fieldTypeMFString		: cfield = new ConstMFString((MFString)eventField);	break;
		case fieldTypeMFTime		: cfield = new ConstMFTime((MFTime)eventField);		break;
	  	case fieldTypeMFVec2f		: cfield = new ConstMFVec2f((MFVec2f)eventField);	break;
	  	case fieldTypeMFVec3f		: cfield = new ConstMFVec3f((MFVec3f)eventField);	break;
	  	case fieldTypeMFNode		: cfield = new ConstMFNode((MFNode)eventField);		break;
		// ConstField
		case fieldTypeConstSFBool		: cfield = new ConstSFBool((ConstSFBool)eventField);	break;
		case fieldTypeConstSFColor		: cfield = new ConstSFColor((ConstSFColor)eventField);	break;
		case fieldTypeConstSFFloat		: cfield = new ConstSFFloat((ConstSFFloat)eventField);	break;
		case fieldTypeConstSFInt32		: cfield = new ConstSFInt32((ConstSFInt32)eventField);	break;
		case fieldTypeConstSFRotation	: cfield = new ConstSFRotation((ConstSFRotation)eventField);break;
		case fieldTypeConstSFString		: cfield = new ConstSFString((ConstSFString)eventField);break;
		case fieldTypeConstSFTime		: cfield = new ConstSFTime((ConstSFTime)eventField);	break;
	  	case fieldTypeConstSFVec2f		: cfield = new ConstSFVec2f((ConstSFVec2f)eventField);	break;
	  	case fieldTypeConstSFVec3f		: cfield = new ConstSFVec3f((ConstSFVec3f)eventField);	break;
	  	case fieldTypeConstSFNode		: cfield = new ConstSFNode((ConstSFNode)eventField);	break;
		case fieldTypeConstMFColor		: cfield = new ConstMFColor((ConstMFColor)eventField);	break;
		case fieldTypeConstMFFloat		: cfield = new ConstMFFloat((ConstMFFloat)eventField);	break;
		case fieldTypeConstMFInt32		: cfield = new ConstMFInt32((ConstMFInt32)eventField);	break;
		case fieldTypeConstMFRotation	: cfield = new ConstMFRotation((ConstMFRotation)eventField);break;
		case fieldTypeConstMFString		: cfield = new ConstMFString((ConstMFString)eventField);break;
		case fieldTypeConstMFTime		: cfield = new ConstMFTime((ConstMFTime)eventField);	break;
	  	case fieldTypeConstMFVec2f		: cfield = new ConstMFVec2f((ConstMFVec2f)eventField);	break;
	  	case fieldTypeConstMFVec3f		: cfield = new ConstMFVec3f((ConstMFVec3f)eventField);	break;
	  	case fieldTypeConstMFNode		: cfield = new ConstMFNode((ConstMFNode)eventField);	break;
		default:
			System.out.println("Unknown field type : " + eventField.getName() + " "+ eventField);
		}

		// Get current time for event
		Date	date = new Date();
		double time = (double)date.getTime() / 1000.0;

		// Create a event for processEvent function
		cfield.setName(eventField.getName());
		Event event = new Event(eventField.getName(), time, cfield);

		// Call processEvent functions
		processEvent(event);
	}

	public void finalize() {
		if (hasScript()) {
			Script scriptObject = getScriptObject();
			scriptObject.shutdown();
		}
	}

	////////////////////////////////////////////////
	//	update
	////////////////////////////////////////////////

	public void update() {
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////
/*
	public Script next() {
		return (Script)next(getType());
	}

	public Script nextTraversal() {
		return (Script)nextTraversalByType(getType());
	}
*/
	////////////////////////////////////////////////
	//	output
	////////////////////////////////////////////////

	public void outputContext(PrintStream printStream, String indentString) {
		SFBool directOutput = (SFBool)getField(directOutputFieldName);
		SFBool mustEvaluate = (SFBool)getField(mustEvaluateFieldName);

		printStream.println(indentString + "\t" + "directOutput " + directOutput);
		printStream.println(indentString + "\t" + "mustEvaluate " + mustEvaluate);

		MFString url = (MFString)getExposedField(urlExposedFieldName);
		printStream.println(indentString + "\t" + "url [");
		url.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");

		for (int n=0; n<getNEventIn(); n++) {
			Field field = getEventIn(n);
			printStream.println(indentString + "\t" + "eventIn " + field.getTypeName() + " " + field.getName());
		}

		for (int n=0; n<getNFields(); n++) {
			Field field = getField(n);
			String fieldName = field.getName();
			if (fieldName.compareTo(directOutputFieldName) != 0 && fieldName.compareTo(mustEvaluateFieldName) != 0) 
				printStream.println(indentString + "\t" + "field " + field.getTypeName() + " " + field.getName() + " " + field.toString());
		}

		for (int n=0; n<getNEventOut(); n++) {
			Field field = getEventOut(n);
			printStream.println(indentString + "\t" + "eventOut " + field.getTypeName() + " " + field.getName());
		}
	}
}