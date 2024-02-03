package vrml.node;

import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class Anchor extends GroupingNode {

	//// ExposedField ////////////////
	private String	descriptionExposedFieldName		= "description";
	private String	parameterExposedFieldName			= "parameter";
	private String	urlExposedFieldName				= "url";
	
	public Anchor() {
		super();

		setHeaderFlag(false);
		setType(anchorTypeName);

		///////////////////////////
		// Exposed Field 
		///////////////////////////

		// description exposed field
		SFString description = new SFString("");
		addExposedField(descriptionExposedFieldName, description);

		// parameter exposed field
		MFString parameter = new MFString();
		addExposedField(parameterExposedFieldName, parameter);

		// url exposed field
		MFString url = new MFString();
		addExposedField(urlExposedFieldName, url);
	}

	////////////////////////////////////////////////
	//	Description
	////////////////////////////////////////////////

	public void setDescription(String value) {
		SFString description = (SFString)getExposedField(descriptionExposedFieldName);
		description.setValue(value);
	}

	public String getDescription() {
		SFString description = (SFString)getExposedField(descriptionExposedFieldName);
		return description.getValue();
	}

	////////////////////////////////////////////////
	// Parameter
	////////////////////////////////////////////////

	public void addParameter(String value) {
		MFString parameter = (MFString)getExposedField(parameterExposedFieldName);
		parameter.addValue(value);
	}
	public int getNParameters() {
		MFString parameter = (MFString)getExposedField(parameterExposedFieldName);
		return parameter.getSize();
	}
	public String getParameter(int index) {
		MFString parameter = (MFString)getExposedField(parameterExposedFieldName);
		return parameter.get1Value(index);
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
	//	List
	////////////////////////////////////////////////

	public Anchor next() {
		return (Anchor)next(getType());
	}

	public Anchor nextTraversal() {
		return (Anchor)nextTraversalByType(getType());
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

		SFString description = (SFString)getExposedField(descriptionExposedFieldName);
		printStream.println(indentString + "\t" + "description " + description);
		
		MFString parameter = (MFString)getExposedField(parameterExposedFieldName);
		printStream.println(indentString + "\t" + "parameter [");
		parameter.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");

		MFString url = (MFString)getExposedField(urlExposedFieldName);
		printStream.println(indentString + "\t" + "url [");
		url.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");
	}
}
