/*----------------------------------------------------------------
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	LightSetDirection.java
*
----------------------------------------------------------------*/
import vrml.*;
import vrml.node.*;
import vrml.field.*;

public class LightSetDirection extends Script {

	Node		node;
	SFVec3f		direction;
	String		inValueString;
	boolean		bExecution;

    public void initialize () {
		SFNode nodeField	= (SFNode)getField("SYSTEM_FIELD_MODULE_TARGET_NODE");
		if (nodeField != null) {
			node = (Node)nodeField.getValue();
			if (node != null)
				direction = (SFVec3f)node.getExposedField("direction");
			else
				direction = null;
		}
		else {
			node = null;
			direction = null;
		}

		inValueString	= null;
   		bExecution		= true;
    }

    public void processEvent (Event e){
		
		if (direction == null)
			return;

		if (e.getName().equals("SYSTEM_EVENTIN_MODULE_EXECUTION") == true) { 
			String value = ((ConstSFString)e.getValue()).getValue().toUpperCase();
			if (value.compareTo("TRUE") == 0)
				bExecution = true;
			else if (value.compareTo("FALSE") == 0)
				bExecution = false;
		}

		if (e.getName().equals("value") == true)  
			inValueString = ((ConstSFString)e.getValue()).getValue();

		if (bExecution == true) { 
			int index1 = inValueString.indexOf(',');
			int index2 = inValueString.indexOf(',', index1+1);
			if (index1 != -1 && index2 != -1 && index1 < index2) {
				try {
					Float	x = new Float(new String(inValueString.toCharArray(), 0, (index1-1)+1));
					Float	y = new Float(new String(inValueString.toCharArray(), index1+1, (index2-1)-(index1)));
					Float	z = new Float(new String(inValueString.toCharArray(), index2+1, (inValueString.length()-1) - index2));
					direction.setValue(x.floatValue(), y.floatValue(), z.floatValue());
				}
				catch (NumberFormatException exception) {
				}
			}
		}
    }

}
