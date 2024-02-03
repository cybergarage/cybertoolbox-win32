package vrml.node;

import java.util.Vector;
import java.lang.String;
import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class ImageTexture extends Node {
	
	//// Exposed Field ////////////////
	private String	urlFieldName		= "url";

	//// Field ////////////////
	private String	repeatSFieldName	= "repeatS";
	private String	repeatTFieldName	= "repeatT";

	public ImageTexture() {
		setHeaderFlag(false);
		setType(imageTextureTypeName);

		///////////////////////////
		// Exposed Field 
		///////////////////////////
 
		// url field
		MFString url = new MFString();
		addExposedField(urlFieldName, url);

		///////////////////////////
		// Field 
		///////////////////////////

		// repeatS field
		SFBool repeatS = new SFBool(true);
		addField(repeatSFieldName, repeatS);

		// repeatT field
		SFBool repeatT = new SFBool(true);
		addField(repeatTFieldName, repeatT);
	}

	////////////////////////////////////////////////
	//	RepeatS
	////////////////////////////////////////////////
	
	public void setRepeatS(boolean value) {
		SFBool repeatS = (SFBool)getField(repeatSFieldName);
		repeatS.setValue(value);
	}
	public boolean getRepeatS() {
		SFBool repeatS = (SFBool)getField(repeatSFieldName);
		return repeatS.getValue();
	}

	////////////////////////////////////////////////
	//	RepeatT
	////////////////////////////////////////////////
	
	public void setRepeatT(boolean value) {
		SFBool repeatT = (SFBool)getField(repeatTFieldName);
		repeatT.setValue(value);
	}
	public boolean getRepeatT() {
		SFBool repeatT = (SFBool)getField(repeatTFieldName);
		return repeatT.getValue();
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

	public ImageTexture next() {
		return (ImageTexture)next(getType());
	}

	public ImageTexture nextTraversal() {
		return (ImageTexture)nextTraversalByType(getType());
	}

	////////////////////////////////////////////////
	//	abstract functions
	////////////////////////////////////////////////
	
	public void initialize() {
	}

	public void update() {
	}

	////////////////////////////////////////////////
	//	Urlmation
	////////////////////////////////////////////////

	public void outputContext(PrintStream printStream, String indentString) {
		SFBool repeatS = (SFBool)getField(repeatSFieldName);
		SFBool repeatT = (SFBool)getField(repeatTFieldName);

		printStream.println(indentString + "\t" + "repeatS " + repeatS );
		printStream.println(indentString + "\t" + "repeatT " + repeatT );

		MFString url = (MFString)getExposedField(urlFieldName);
		printStream.println(indentString + "\t" + "url [");
		url.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");
	}
}
