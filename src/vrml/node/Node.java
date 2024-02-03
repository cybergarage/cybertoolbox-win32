package vrml.node;

import java.util.Vector;
import java.io.*;
import vrml.linkedlist.*;
import vrml.*;

public abstract class Node extends BaseNode { 

	////////////////////////////////////////////////
	//	Field
	////////////////////////////////////////////////

	private Vector	mField = new Vector();

	// Get an exposed field by name. 
	//   Throws an InvalidExposedFieldException if fieldName isn't a valid
	//   exposed field name for a node of this type.
	public  Field getField(String fieldName) {
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

	// Get an EventOut by name. Return value is read-only.
	//   Throws an InvalidEventOutException if eventOutName isn't a valid
	//   event out name for a node of this type.
	public final ConstField getEventOut(String fieldName) {
		for (int n=0; n<getNEventOut(); n++) {
			ConstField field = getEventOut(n);
			if (fieldName.compareTo(field.getName()) == 0)
				return field;
			if (fieldName.endsWith(eventOutStripString)) {
				if (fieldName.startsWith(field.getName()))
					return field;
			}
		}
		return null;
	}

	public int getNEventOut() {
		return mEventOutField.size();
	}

	public void addEventOut(ConstField field) {
		mEventOutField.addElement(field);
	}

	public void addEventOut(String name, ConstField field) {
		field.setName(name);
		mEventOutField.addElement(field);
	}

	public ConstField getEventOut(int index) {
		return (ConstField)mEventOutField.elementAt(index);
	}

	////////////////////////////////////////////////
	//	toString
	////////////////////////////////////////////////

	// This overrides a method in Object
/*
	public String toString() {
		return null;
	}
*/

	////////////////////////////////////////////////
	//	Overload for BaseNode
	////////////////////////////////////////////////
/*
	public Node getParentNode() {
		return (Node)super.getParentNode();
	}

	public Node nextOrder () {
		return (Node)super.nextOrder();
	}

	public Node nextOrderByType(String type) {
		return (Node)super.nextOrderByType(type);
	}

	public Node nextOrderByName(String name) {
		return (Node)super.nextOrderByName(name);
	}

	public Node next() {
		return (Node)super.next();
	}

	public Node next(String type) {
		return (Node)super.next(type);
	}

	public Node getChildNodes() {
		return (Node)super.getChildNodes();
	}

	public Node getChildNodes(String type) {
		return (Node)super.getChildNodes(type);
	}
*/
	////////////////////////////////////////////////
	//	abstract functions
	////////////////////////////////////////////////

	abstract public void update();
	abstract public void initialize();

}