package vrml.node;

import java.io.PrintStream;
import java.util.Date;
import vrml.*;
import vrml.field.*;

public class Text extends Node {
	
	//// ExposedField ////////////////
	private String	maxExtentExposedFieldName	= "maxExtent";
	private String	stringExposedFieldName		= "string";
	private String	lengthExposedFieldName		= "length";

	public Text() {
		setHeaderFlag(false);
		setType(textTypeName);

		///////////////////////////
		// ExposedField 
		///////////////////////////

		// maxExtent exposed field
		SFFloat maxExtent = new SFFloat(1);
		addExposedField(maxExtentExposedFieldName, maxExtent);

		// length exposed field
		MFFloat length = new MFFloat();
		addExposedField(lengthExposedFieldName, length);

		// string exposed field
		MFString string = new MFString();
		addExposedField(stringExposedFieldName, string);
	}

	////////////////////////////////////////////////
	//	MaxExtent
	////////////////////////////////////////////////
	
	public void setMaxExtent(float value) {
		SFFloat sffloat = (SFFloat)getExposedField(maxExtentExposedFieldName);
		sffloat.setValue(value);
	}
	public float getMaxExtent() {
		SFFloat sffloat = (SFFloat)getExposedField(maxExtentExposedFieldName);
		return sffloat.getValue();
	} 

	////////////////////////////////////////////////
	// String
	////////////////////////////////////////////////

	public void addString(String value) {
		MFString string = (MFString)getExposedField(stringExposedFieldName);
		string.addValue(value);
	}
	public int getNStrings() {
		MFString string = (MFString)getExposedField(stringExposedFieldName);
		return string.getSize();
	}
	public String getString(int index) {
		MFString string = (MFString)getExposedField(stringExposedFieldName);
		return string.get1Value(index);
	}

	////////////////////////////////////////////////
	// length
	////////////////////////////////////////////////

	public void addLength(float value) {
		MFFloat length = (MFFloat)getExposedField(lengthExposedFieldName);
		length.addValue(value);
	}
	public int getNLengths() {
		MFFloat length = (MFFloat)getExposedField(lengthExposedFieldName);
		return length.getSize();
	}
	public float getLength(int index) {
		MFFloat length = (MFFloat)getExposedField(lengthExposedFieldName);
		return length.get1Value(index);
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public Text next() {
		return (Text)next(getType());
	}

	public Text nextTraversal() {
		return (Text)nextTraversalByType(getType());
	}

	////////////////////////////////////////////////
	//	abstract functions
	////////////////////////////////////////////////
	
	public void initialize() {
	}

	public void update() {
	}

	////////////////////////////////////////////////
	//	Stringmation
	////////////////////////////////////////////////

	public void outputContext(PrintStream printStream, String indentString) {
		printStream.println(indentString + "\t" + "maxExtent " + getMaxExtent() );

		MFString string = (MFString)getExposedField(stringExposedFieldName);
		printStream.println(indentString + "\t" + "string [");
		string.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");

		MFFloat length = (MFFloat)getExposedField(lengthExposedFieldName);
		printStream.println(indentString + "\t" + "length [");
		length.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");

		FontStyle fontStyle = getFontStyles();
		if (fontStyle != null) {
			printStream.println(indentString + "\t" + "fontStyle FontStyle {");
			fontStyle.outputContext(printStream, indentString + "\t");
			printStream.println(indentString + "\t" + "}");
		}
	}
}
