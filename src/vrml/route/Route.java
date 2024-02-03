package vrml.route;

import java.io.PrintStream;
import vrml.linkedlist.*;
import vrml.parser.*;
import vrml.node.*;
import vrml.field.*;
import vrml.*;

public class Route extends LinkedListNode implements Constants {
	BaseNode	mEventOutNode = null;
	BaseNode	mEventInNode = null;
	Field		mEventOutField = null;
	Field		mEventInField = null;

	public Route(BaseNode eventOutNode, Field eventOutField, BaseNode eventInNode, Field eventInField) {
		setHeaderFlag(false);
		setEventOutNode(eventOutNode);
		setEventInNode(eventInNode);
		setEventOutField(eventOutField);
		setEventInField(eventInField);
	}
	public void			setEventOutNode(BaseNode node)		{ mEventOutNode = node; }
	public void			setEventInNode(BaseNode node)		{ mEventInNode = node; }
	public BaseNode		getEventOutNode()					{ return mEventOutNode; }
	public BaseNode		getEventInNode()					{ return mEventInNode; }
	public void			setEventOutField(Field field)		{ mEventOutField = field; }
	public Field		getEventOutField()					{ return mEventOutField; }
	public void			setEventInField(Field field)		{ mEventInField = field; }
	public Field		getEventInField()					{ return mEventInField; }

	////////////////////////////////////////////////
	//	next node list
	////////////////////////////////////////////////

	public Route next () {
		return (Route)getNextNode();
	}

	////////////////////////////////////////////////
	//	update
	////////////////////////////////////////////////

	public void update() {
		Field	eventOutField	= getEventOutField();
		Field	eventInField	= getEventInField();

		if (eventOutField == null || eventInField == null)
			return;

		int eventOutFieldType	= eventOutField.getType();
		int eventInFieldType	= eventInField.getType();	

		switch (eventOutFieldType) {

		////////////////////////////////////////////////
		//	SField
		////////////////////////////////////////////////

		case fieldTypeSFBool :
			{
				SFBool boolOut = (SFBool)eventOutField;
				boolean value = boolOut.getValue();
				switch (eventInFieldType) {
				case fieldTypeSFBool :
					{
						SFBool boolIn = (SFBool)eventInField;
						boolIn.setValue(value);
					}
					break;
				case fieldTypeConstSFBool :
					{
						ConstSFBool boolIn = (ConstSFBool)eventInField;
						boolIn.setValue(value);
					}
					break;
				}
			}
			break;
		case fieldTypeConstSFBool :
			{
				ConstSFBool boolOut = (ConstSFBool)eventOutField;
				boolean value = boolOut.getValue();
				switch (eventInFieldType) {
				case fieldTypeSFBool :
					{
						SFBool boolIn = (SFBool)eventInField;
						boolIn.setValue(value);
					}
					break;
				case fieldTypeConstSFBool :
					{
						ConstSFBool boolIn = (ConstSFBool)eventInField;
						boolIn.setValue(value);
					}
					break;
				}
			}
			break;
		case fieldTypeSFFloat :
			{
				SFFloat fieldOut = (SFFloat)eventOutField;
				float value = fieldOut.getValue();
				switch (eventInFieldType) {
				case fieldTypeSFFloat :
					{
						SFFloat fieldIn = (SFFloat)eventInField;
						fieldIn.setValue(value);
					}
					break;
				case fieldTypeConstSFFloat :
					{
						ConstSFFloat fieldIn = (ConstSFFloat)eventInField;
						fieldIn.setValue(value);
					}
					break;
				}
			}
			break;
		case fieldTypeConstSFFloat :
			{
				ConstSFFloat fieldOut = (ConstSFFloat)eventOutField;
				float value = fieldOut.getValue();
				switch (eventInFieldType) {
				case fieldTypeSFFloat :
					{
						SFFloat fieldIn = (SFFloat)eventInField;
						fieldIn.setValue(value);
					}
					break;
				case fieldTypeConstSFFloat :
					{
						ConstSFFloat fieldIn = (ConstSFFloat)eventInField;
						fieldIn.setValue(value);
					}
					break;
				}
			}
			break;
		case fieldTypeSFInt32 :
			{
				SFInt32 fieldOut = (SFInt32)eventOutField;
				int value = fieldOut.getValue();
				switch (eventInFieldType) {
				case fieldTypeSFInt32 :
					{
						SFInt32 fieldIn = (SFInt32)eventInField;
						fieldIn.setValue(value);
					}
					break;
				case fieldTypeConstSFInt32 :
					{
						ConstSFInt32 fieldIn = (ConstSFInt32)eventInField;
						fieldIn.setValue(value);
					}
					break;
				}
			}
			break;
		case fieldTypeConstSFInt32 :
			{
				ConstSFInt32 fieldOut = (ConstSFInt32)eventOutField;
				int value = fieldOut.getValue();
				switch (eventInFieldType) {
				case fieldTypeSFInt32 :
					{
						SFInt32 fieldIn = (SFInt32)eventInField;
						fieldIn.setValue(value);
					}
					break;
				case fieldTypeConstSFInt32 :
					{
						ConstSFInt32 fieldIn = (ConstSFInt32)eventInField;
						fieldIn.setValue(value);
					}
					break;
				}
			}
			break;
		case fieldTypeSFTime :
			{
				SFTime fieldOut = (SFTime)eventOutField;
				double value = fieldOut.getValue();
				switch (eventInFieldType) {
				case fieldTypeSFTime :
					{
						SFTime fieldIn = (SFTime)eventInField;
						fieldIn.setValue(value);
					}
					break;
				case fieldTypeConstSFTime :
					{
						ConstSFTime fieldIn = (ConstSFTime)eventInField;
						fieldIn.setValue(value);
					}
					break;
				}
			}
			break;
		case fieldTypeConstSFTime :
			{
				ConstSFTime fieldOut = (ConstSFTime)eventOutField;
				double value = fieldOut.getValue();
				switch (eventInFieldType) {
				case fieldTypeSFTime :
					{
						SFTime fieldIn = (SFTime)eventInField;
						fieldIn.setValue(value);
					}
					break;
				case fieldTypeConstSFTime :
					{
						ConstSFTime fieldIn = (ConstSFTime)eventInField;
						fieldIn.setValue(value);
					}
					break;
				}
			}
			break;
		case fieldTypeSFString :
			{
				SFString fieldOut = (SFString)eventOutField;
				String value = fieldOut.getValue();
				switch (eventInFieldType) {
				case fieldTypeSFString :
					{
						SFString fieldIn = (SFString)eventInField;
						fieldIn.setValue(value);
					}
					break;
				case fieldTypeConstSFString :
					{
						ConstSFString fieldIn = (ConstSFString)eventInField;
						fieldIn.setValue(value);
					}
					break;
				}
			}
			break;
		case fieldTypeConstSFString :
			{
				ConstSFString fieldOut = (ConstSFString)eventOutField;
				String value = fieldOut.getValue();
				switch (eventInFieldType) {
				case fieldTypeSFString :
					{
						SFString fieldIn = (SFString)eventInField;
						fieldIn.setValue(value);
					}
					break;
				case fieldTypeConstSFString :
					{
						ConstSFString fieldIn = (ConstSFString)eventInField;
						fieldIn.setValue(value);
					}
					break;
				}
			}
			break;
		case fieldTypeSFVec2f :
			{
				SFVec2f fieldOut = (SFVec2f)eventOutField;
				float value[] = new float[2];
				fieldOut.getValue(value);
				switch (eventInFieldType) {
				case fieldTypeSFVec2f :
					{
						SFVec2f fieldIn = (SFVec2f)eventInField;
						fieldIn.setValue(value);
					}
					break;
				case fieldTypeConstSFVec2f :
					{
						ConstSFVec2f fieldIn = (ConstSFVec2f)eventInField;
						fieldIn.setValue(value);
					}
					break;
				}
			}
			break;
		case fieldTypeConstSFVec2f :
			{
				ConstSFVec2f fieldOut = (ConstSFVec2f)eventOutField;
				float value[] = new float[2];
				fieldOut.getValue(value);
				switch (eventInFieldType) {
				case fieldTypeSFVec2f :
					{
						SFVec2f fieldIn = (SFVec2f)eventInField;
						fieldIn.setValue(value);
					}
					break;
				case fieldTypeConstSFVec2f :
					{
						ConstSFVec2f fieldIn = (ConstSFVec2f)eventInField;
						fieldIn.setValue(value);
					}
					break;
				}
			}
			break;
		case fieldTypeSFVec3f :
			{
				SFVec3f fieldOut = (SFVec3f)eventOutField;
				float value[] = new float[3];
				fieldOut.getValue(value);
				switch (eventInFieldType) {
				case fieldTypeSFVec3f :
					{
						SFVec3f fieldIn = (SFVec3f)eventInField;
						fieldIn.setValue(value);
					}
					break;
				case fieldTypeConstSFVec3f :
					{
						ConstSFVec3f fieldIn = (ConstSFVec3f)eventInField;
						fieldIn.setValue(value);
					}
					break;
				}
			}
			break;
		case fieldTypeConstSFVec3f :
			{
				ConstSFVec3f fieldOut = (ConstSFVec3f)eventOutField;
				float value[] = new float[3];
				fieldOut.getValue(value);
				switch (eventInFieldType) {
				case fieldTypeSFVec3f :
					{
						SFVec3f fieldIn = (SFVec3f)eventInField;
						fieldIn.setValue(value);
					}
					break;
				case fieldTypeConstSFVec3f :
					{
						ConstSFVec3f fieldIn = (ConstSFVec3f)eventInField;
						fieldIn.setValue(value);
					}
					break;
				}
			}
			break;
		case fieldTypeSFColor :
			{
				SFColor fieldOut = (SFColor)eventOutField;
				float value[] = new float[3];
				fieldOut.getValue(value);
				switch (eventInFieldType) {
				case fieldTypeSFColor :
					{
						SFColor fieldIn = (SFColor)eventInField;
						fieldIn.setValue(value);
					}
					break;
				case fieldTypeConstSFColor :
					{
						ConstSFColor fieldIn = (ConstSFColor)eventInField;
						fieldIn.setValue(value);
					}
					break;
				}
			}
			break;
		case fieldTypeConstSFColor :
			{
				ConstSFColor fieldOut = (ConstSFColor)eventOutField;
				float value[] = new float[3];
				fieldOut.getValue(value);
				switch (eventInFieldType) {
				case fieldTypeSFColor :
					{
						SFColor fieldIn = (SFColor)eventInField;
						fieldIn.setValue(value);
					}
					break;
				case fieldTypeConstSFColor :
					{
						ConstSFColor fieldIn = (ConstSFColor)eventInField;
						fieldIn.setValue(value);
					}
					break;
				}
			}
			break;
		case fieldTypeSFRotation :
			{
				SFRotation fieldOut = (SFRotation)eventOutField;
				float value[] = new float[4];
				fieldOut.getValue(value);
				switch (eventInFieldType) {
				case fieldTypeSFRotation :
					{
						SFRotation fieldIn = (SFRotation)eventInField;
						fieldIn.setValue(value);
					}
					break;
				case fieldTypeConstSFRotation :
					{
						ConstSFRotation fieldIn = (ConstSFRotation)eventInField;
						fieldIn.setValue(value);
					}
					break;
				}
			}
			break;
		case fieldTypeConstSFRotation :
			{
				ConstSFRotation fieldOut = (ConstSFRotation)eventOutField;
				float value[] = new float[4];
				fieldOut.getValue(value);
				switch (eventInFieldType) {
				case fieldTypeSFRotation :
					{
						SFRotation fieldIn = (SFRotation)eventInField;
						fieldIn.setValue(value);
					}
					break;
				case fieldTypeConstSFRotation :
					{
						ConstSFRotation fieldIn = (ConstSFRotation)eventInField;
						fieldIn.setValue(value);
					}
					break;
				}
			}
			break;

		////////////////////////////////////////////////
		//	MField
		////////////////////////////////////////////////

		case fieldTypeMFNode :
			{
				MFNode outNode = (MFNode)eventOutField;
				switch (eventInFieldType) {
				case fieldTypeMFNode :
					{
						MFNode inNode = (MFNode)eventInField;
						inNode.copy(outNode);
					}
					break;
				case fieldTypeConstMFNode :
					{
						ConstMFNode inNode = (ConstMFNode)eventInField;
						inNode.copy(outNode);
					}
					break;
				}
			}
			break;
		case fieldTypeConstMFNode :
			{
				ConstMFNode outNode = (ConstMFNode)eventOutField;
				switch (eventInFieldType) {
				case fieldTypeMFNode :
					{
						MFNode inNode = (MFNode)eventInField;
						inNode.copy(outNode);
					}
					break;
				case fieldTypeConstMFNode :
					{
						ConstMFNode inNode = (ConstMFNode)eventInField;
						inNode.copy(outNode);
					}
					break;
				}
			}
			break;
		
		case fieldTypeMFString :
			{
				MFString outString = (MFString)eventOutField;
				switch (eventInFieldType) {
				case fieldTypeMFString :
					{
						MFString inString = (MFString)eventInField;
						inString.copy(outString);
					}
					break;
				case fieldTypeConstMFString :
					{
						ConstMFString inString = (ConstMFString)eventInField;
						inString.copy(outString);
					}
					break;
				}
			}
			break;
		case fieldTypeConstMFString :
			{
				ConstMFString outString = (ConstMFString)eventOutField;
				switch (eventInFieldType) {
				case fieldTypeMFString :
					{
						MFString inString = (MFString)eventInField;
						inString.copy(outString);
					}
					break;
				case fieldTypeConstMFString :
					{
						ConstMFString inString = (ConstMFString)eventInField;
						inString.copy(outString);
					}
					break;
				}
			}
			break;

		case fieldTypeMFColor :
			{
				MFColor outColor = (MFColor)eventOutField;
				switch (eventInFieldType) {
				case fieldTypeMFColor :
					{
						MFColor inColor = (MFColor)eventInField;
						inColor.copy(outColor);
					}
					break;
				case fieldTypeConstMFColor :
					{
						ConstMFColor inColor = (ConstMFColor)eventInField;
						inColor.copy(outColor);
					}
					break;
				}
			}
			break;
		case fieldTypeConstMFColor :
			{
				ConstMFColor outColor = (ConstMFColor)eventOutField;
				switch (eventInFieldType) {
				case fieldTypeMFColor :
					{
						MFColor inColor = (MFColor)eventInField;
						inColor.copy(outColor);
					}
					break;
				case fieldTypeConstMFColor :
					{
						ConstMFColor inColor = (ConstMFColor)eventInField;
						inColor.copy(outColor);
					}
					break;
				}
			}
			break;

		case fieldTypeMFFloat :
			{
				MFFloat outFloat = (MFFloat)eventOutField;
				switch (eventInFieldType) {
				case fieldTypeMFFloat :
					{
						MFFloat inFloat = (MFFloat)eventInField;
						inFloat.copy(outFloat);
					}
					break;
				case fieldTypeConstMFFloat :
					{
						ConstMFFloat inFloat = (ConstMFFloat)eventInField;
						inFloat.copy(outFloat);
					}
					break;
				}
			}
			break;
		case fieldTypeConstMFFloat :
			{
				ConstMFFloat outFloat = (ConstMFFloat)eventOutField;
				switch (eventInFieldType) {
				case fieldTypeMFFloat :
					{
						MFFloat inFloat = (MFFloat)eventInField;
						inFloat.copy(outFloat);
					}
					break;
				case fieldTypeConstMFFloat :
					{
						ConstMFFloat inFloat = (ConstMFFloat)eventInField;
						inFloat.copy(outFloat);
					}
					break;
				}
			}
			break;

		case fieldTypeMFInt32 :
			{
				MFInt32 outInt32 = (MFInt32)eventOutField;
				switch (eventInFieldType) {
				case fieldTypeMFInt32 :
					{
						MFInt32 inInt32 = (MFInt32)eventInField;
						inInt32.copy(outInt32);
					}
					break;
				case fieldTypeConstMFInt32 :
					{
						ConstMFInt32 inInt32 = (ConstMFInt32)eventInField;
						inInt32.copy(outInt32);
					}
					break;
				}
			}
			break;
		case fieldTypeConstMFInt32 :
			{
				ConstMFInt32 outInt32 = (ConstMFInt32)eventOutField;
				switch (eventInFieldType) {
				case fieldTypeMFInt32 :
					{
						MFInt32 inInt32 = (MFInt32)eventInField;
						inInt32.copy(outInt32);
					}
					break;
				case fieldTypeConstMFInt32 :
					{
						ConstMFInt32 inInt32 = (ConstMFInt32)eventInField;
						inInt32.copy(outInt32);
					}
					break;
				}
			}
			break;

		case fieldTypeMFRotation :
			{
				MFRotation outRotation = (MFRotation)eventOutField;
				switch (eventInFieldType) {
				case fieldTypeMFRotation :
					{
						MFRotation inRotation = (MFRotation)eventInField;
						inRotation.copy(outRotation);
					}
					break;
				case fieldTypeConstMFRotation :
					{
						ConstMFRotation inRotation = (ConstMFRotation)eventInField;
						inRotation.copy(outRotation);
					}
					break;
				}
			}
			break;
		case fieldTypeConstMFRotation :
			{
				ConstMFRotation outRotation = (ConstMFRotation)eventOutField;
				switch (eventInFieldType) {
				case fieldTypeMFRotation :
					{
						MFRotation inRotation = (MFRotation)eventInField;
						inRotation.copy(outRotation);
					}
					break;
				case fieldTypeConstMFRotation :
					{
						ConstMFRotation inRotation = (ConstMFRotation)eventInField;
						inRotation.copy(outRotation);
					}
					break;
				}
			}
			break;

		case fieldTypeMFTime :
			{
				MFTime outTime = (MFTime)eventOutField;
				switch (eventInFieldType) {
				case fieldTypeMFTime :
					{
						MFTime inTime = (MFTime)eventInField;
						inTime.copy(outTime);
					}
					break;
				case fieldTypeConstMFTime :
					{
						ConstMFTime inTime = (ConstMFTime)eventInField;
						inTime.copy(outTime);
					}
					break;
				}
			}
			break;
		case fieldTypeConstMFTime :
			{
				ConstMFTime outTime = (ConstMFTime)eventOutField;
				switch (eventInFieldType) {
				case fieldTypeMFTime :
					{
						MFTime inTime = (MFTime)eventInField;
						inTime.copy(outTime);
					}
					break;
				case fieldTypeConstMFTime :
					{
						ConstMFTime inTime = (ConstMFTime)eventInField;
						inTime.copy(outTime);
					}
					break;
				}
			}
			break;

		case fieldTypeMFVec2f :
			{
				MFVec2f outVec2f = (MFVec2f)eventOutField;
				switch (eventInFieldType) {
				case fieldTypeMFVec2f :
					{
						MFVec2f inVec2f = (MFVec2f)eventInField;
						inVec2f.copy(outVec2f);
					}
					break;
				case fieldTypeConstMFVec2f :
					{
						ConstMFVec2f inVec2f = (ConstMFVec2f)eventInField;
						inVec2f.copy(outVec2f);
					}
					break;
				}
			}
			break;
		case fieldTypeConstMFVec2f :
			{
				ConstMFVec2f outVec2f = (ConstMFVec2f)eventOutField;
				switch (eventInFieldType) {
				case fieldTypeMFVec2f :
					{
						MFVec2f inVec2f = (MFVec2f)eventInField;
						inVec2f.copy(outVec2f);
					}
					break;
				case fieldTypeConstMFVec2f :
					{
						ConstMFVec2f inVec2f = (ConstMFVec2f)eventInField;
						inVec2f.copy(outVec2f);
					}
					break;
				}
			}
			break;

		case fieldTypeMFVec3f :
			{
				MFVec3f outVec3f = (MFVec3f)eventOutField;
				switch (eventInFieldType) {
				case fieldTypeMFVec3f :
					{
						MFVec3f inVec3f = (MFVec3f)eventInField;
						inVec3f.copy(outVec3f);
					}
					break;
				case fieldTypeConstMFVec3f :
					{
						ConstMFVec3f inVec3f = (ConstMFVec3f)eventInField;
						inVec3f.copy(outVec3f);
					}
					break;
				}
			}
			break;
		case fieldTypeConstMFVec3f :
			{
				ConstMFVec3f outVec3f = (ConstMFVec3f)eventOutField;
				switch (eventInFieldType) {
				case fieldTypeMFVec3f :
					{
						MFVec3f inVec3f = (MFVec3f)eventInField;
						inVec3f.copy(outVec3f);
					}
					break;
				case fieldTypeConstMFVec3f :
					{
						ConstMFVec3f inVec3f = (ConstMFVec3f)eventInField;
						inVec3f.copy(outVec3f);
					}
					break;
				}
			}
			break;
		}

		////////////////////////////////////////////////
		//	Script
		////////////////////////////////////////////////

		BaseNode node = getEventInNode();
		if (node.isScript()) {
			Script script = (Script)node;
			if (script.hasScript()) {
				Script scriptObject = script.getScriptObject();
				scriptObject.processEvent(getEventInField());
			}
		}
	}

	////////////////////////////////////////////////
	//	output
	////////////////////////////////////////////////

	public void output(PrintStream printStream) {
		printStream.print("ROUTE ");
		
		if (getEventOutNode() != null)
			printStream.print(getEventOutNode().getName() + ".");
		else
			printStream.print(getEventOutNode() + ".");

		if (getEventOutField() != null)
			printStream.print(getEventOutField().getName() + " TO ");
		else
			printStream.print(getEventOutField() + " TO ");
		
		if (getEventInNode() != null)
			printStream.print(getEventInNode().getName() + ".");
		else
			printStream.print(getEventInNode() + ".");

		if (getEventInField() != null)
			printStream.println(getEventInField().getName());
		else
			printStream.println(getEventInField());
	}
};
