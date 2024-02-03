package vrml.node;

import java.util.Vector;
import java.lang.String;
import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class PixelTexture extends Node {
	
	//// Exposed Field ////////////////
	private String	imageExposedFieldName	= "image";

	//// Field ////////////////
	private String	repeatSFieldName		= "repeatS";
	private String	repeatTFieldName		= "repeatT";

	public PixelTexture() {
		setHeaderFlag(false);
		setType(pixelTextureTypeName);

		///////////////////////////
		// Exposed Field 
		///////////////////////////

		// image field
		SFImage image = new SFImage();
		addExposedField(imageExposedFieldName, image);

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
	// Image
	////////////////////////////////////////////////

	public void addImage(int value) {
		SFImage image = (SFImage)getExposedField(imageExposedFieldName);
		image.addValue(value);
	}
	public int getNImages() {
		SFImage image = (SFImage)getExposedField(imageExposedFieldName);
		return image.getSize();
	}
	public int getImage(int index) {
		SFImage image = (SFImage)getExposedField(imageExposedFieldName);
		return image.get1Value(index);
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public PixelTexture next() {
		return (PixelTexture)next(getType());
	}

	public PixelTexture nextTraversal() {
		return (PixelTexture)nextTraversalByType(getType());
	}

	////////////////////////////////////////////////
	//	abstract functions
	////////////////////////////////////////////////
	
	public void initialize() {
	}

	public void update() {
	}

	////////////////////////////////////////////////
	//	Imagemation
	////////////////////////////////////////////////

	public void outputContext(PrintStream printStream, String indentString) {
		SFBool repeatS = (SFBool)getField(repeatSFieldName);
		SFBool repeatT = (SFBool)getField(repeatTFieldName);

		SFImage image = (SFImage)getExposedField(imageExposedFieldName);
		printStream.println(indentString + "\t" + "image [");
		image.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");

		printStream.println(indentString + "\t" + "repeatS " + repeatS );
		printStream.println(indentString + "\t" + "repeatT " + repeatT );
	}
}
