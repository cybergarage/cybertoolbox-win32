package vrml.node;

import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class Inline extends GroupingNode {

	private String	urlFieldName				= "url";
	
	public Inline() {
		setHeaderFlag(false);
		setType(inlineTypeName);

		// url exposed field
		MFString url = new MFString();
		addExposedField(urlFieldName, url);
	}

	////////////////////////////////////////////////
	// Url
	////////////////////////////////////////////////

	public void addUrl(String value) {
		MFString url = (MFString)getExposedField(urlFieldName);
		url.addValue(value);
	}
	public int getNUrls() {
		MFString url = (MFString)getExposedField(urlFieldName);
		return url.getSize();
	}
	public String getUrl(int index) {
		MFString url = (MFString)getExposedField(urlFieldName);
		return url.get1Value(index);
	}


	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public Inline next() {
		return (Inline)next(getType());
	}

	public Inline nextTraversal() {
		return (Inline)nextTraversalByType(getType());
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

		MFString url = (MFString)getExposedField(urlFieldName);
		printStream.println(indentString + "\t" + "url [");
		url.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");
	}
}
