/*----------------------------------------------------------------
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	MaterialSetSpecularColor.java
*
----------------------------------------------------------------*/
import vrml.*;
import vrml.node.*;
import vrml.field.*;

public class MaterialSetSpecularColor extends Script {

	Node		node;
	SFColor		specularColor;
	String		inValueString;
	boolean		bExecution;

    public void initialize () {
		SFNode nodeField	= (SFNode)getField("SYSTEM_FIELD_MODULE_TARGET_NODE");
		if (nodeField != null) {
			node = (Node)nodeField.getValue();
			if (node != null)
				specularColor = (SFColor)node.getExposedField("specularColor");
			else
				specularColor = null;
		}
		else {
			node = null;
			specularColor = null;
		}

		inValueString	= null;
   		bExecution		= true;
    }

    public void processEvent (Event e){
		
		if (specularColor == null)
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
					Float	r = new Float(new String(inValueString.toCharArray(), 0, (index1-1)+1));
					Float	g = new Float(new String(inValueString.toCharArray(), index1+1, (index2-1)-(index1)));
					Float	b = new Float(new String(inValueString.toCharArray(), index2+1, (inValueString.length()-1) - index2));
					specularColor.setValue(r.floatValue(), g.floatValue(), b.floatValue());
				}
				catch (NumberFormatException exception) {
				}
			}
		}
    }

}
