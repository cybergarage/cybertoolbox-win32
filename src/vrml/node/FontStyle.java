package vrml.node;

import java.util.Vector;
import java.lang.String;
import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class FontStyle extends Node {
	
	//// Field ////////////////
	private String	familyFieldName			= "family";
	private String	styleFieldName			= "style";
	private String	languageFieldName		= "language";
	private String	justifyFieldName		= "justify";
	private String	sizeFieldName			= "size";
	private String	spacingFieldName		= "spacing";
	private String	horizontalFieldName		= "horizontal";
	private String	leftToRightFieldName	= "leftToRight";
	private String	topToBottomFieldName	= "topToBottom";

	public FontStyle() {
		setHeaderFlag(false);
		setType(fontStyleTypeName);

		///////////////////////////
		// Field 
		///////////////////////////

		// family field
		SFString family = new SFString("SERIF");
		family.setName(familyFieldName);
		addField(family);

		// style field
		SFString style = new SFString("PLAIN");
		style.setName(styleFieldName);
		addField(style);

		// language field
		SFString language = new SFString("");
		language.setName(languageFieldName);
		addField(language);

		// justify field
		MFString justify = new MFString();
		justify.setName(justifyFieldName);
		addField(justify);

		// size field
		SFFloat size = new SFFloat(1);
		addField(sizeFieldName, size);

		// spacing field
		SFFloat spacing = new SFFloat(1);
		addField(spacingFieldName, spacing);

		// horizontal field
		SFBool horizontal = new SFBool(true);
		addField(horizontalFieldName, horizontal);

		// leftToRight field
		SFBool leftToRight = new SFBool(true);
		addField(leftToRightFieldName, leftToRight);

		// topToBottom field
		SFBool topToBottom = new SFBool(true);
		addField(topToBottomFieldName, topToBottom);
	}

	////////////////////////////////////////////////
	//	Size
	////////////////////////////////////////////////

	public void setSize(float value) {
		SFFloat size = (SFFloat)getField(sizeFieldName);
		size.setValue(value);
	}
	public float getSize() {
		SFFloat size = (SFFloat)getField(sizeFieldName);
		return size.getValue();
	}

	////////////////////////////////////////////////
	//	Family
	////////////////////////////////////////////////
	
	public void setFamily(String value) {
		SFString family = (SFString)getField(familyFieldName);
		family.setValue(value);
	}
	public String getFamily() {
		SFString family = (SFString)getField(familyFieldName);
		return family.getValue();
	}

	////////////////////////////////////////////////
	//	Style
	////////////////////////////////////////////////
	
	public void setStyle(String value) {
		SFString style = (SFString)getField(styleFieldName);
		style.setValue(value);
	}
	public String getStyle() {
		SFString style = (SFString)getField(styleFieldName);
		return style.getValue();
	}

	////////////////////////////////////////////////
	//	Language
	////////////////////////////////////////////////
	
	public void setLanguage(String value) {
		SFString language = (SFString)getField(languageFieldName);
		language.setValue(value);
	}
	public String getLanguage() {
		SFString language = (SFString)getField(languageFieldName);
		return language.getValue();
	}

	////////////////////////////////////////////////
	//	Horizontal
	////////////////////////////////////////////////
	
	public void setHorizontal(boolean value) {
		SFBool horizontal = (SFBool)getField(horizontalFieldName);
		horizontal.setValue(value);
	}
	public boolean getHorizontal() {
		SFBool horizontal = (SFBool)getField(horizontalFieldName);
		return horizontal.getValue();
	}

	////////////////////////////////////////////////
	//	LeftToRight
	////////////////////////////////////////////////
	
	public void setLeftToRight(boolean value) {
		SFBool leftToRight = (SFBool)getField(leftToRightFieldName);
		leftToRight.setValue(value);
	}
	public boolean getLeftToRight() {
		SFBool leftToRight = (SFBool)getField(leftToRightFieldName);
		return leftToRight.getValue();
	}

	////////////////////////////////////////////////
	//	TopToBottom
	////////////////////////////////////////////////
	
	public void setTopToBottom(boolean value) {
		SFBool topToBottom = (SFBool)getField(topToBottomFieldName);
		topToBottom.setValue(value);
	}
	public boolean getTopToBottom() {
		SFBool topToBottom = (SFBool)getField(topToBottomFieldName);
		return topToBottom.getValue();
	}

	////////////////////////////////////////////////
	// Justify
	////////////////////////////////////////////////

	public void addJustify(String value) {
		MFString justify = (MFString)getField(justifyFieldName);
		justify.addValue(value);
	}
	public int getNJustifys() {
		MFString justify = (MFString)getField(justifyFieldName);
		return justify.getSize();
	}
	public String getJustify(int index) {
		MFString justify = (MFString)getField(justifyFieldName);
		return justify.get1Value(index);
	}

	////////////////////////////////////////////////
	//	Spacing
	////////////////////////////////////////////////

	public void setSpacing(float value) {
		SFFloat spacing = (SFFloat)getField(spacingFieldName);
		spacing.setValue(value);
	}
	public float getSpacing() {
		SFFloat spacing = (SFFloat)getField(spacingFieldName);
		return spacing.getValue();
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public FontStyle next() {
		return (FontStyle)next(getType());
	}

	public FontStyle nextTraversal() {
		return (FontStyle)nextTraversalByType(getType());
	}

	////////////////////////////////////////////////
	//	abstract functions
	////////////////////////////////////////////////
	
	public void initialize() {
	}

	public void update() {
	}

	////////////////////////////////////////////////
	//	Justifymation
	////////////////////////////////////////////////

	public void outputContext(PrintStream printStream, String indentString) {
		SFString family = (SFString)getField(familyFieldName);
		SFBool horizontal = (SFBool)getField(horizontalFieldName);
		SFBool leftToRight = (SFBool)getField(leftToRightFieldName);
		SFBool topToBottom = (SFBool)getField(topToBottomFieldName);
		SFString style = (SFString)getField(styleFieldName);
		SFString language = (SFString)getField(languageFieldName);

		printStream.println(indentString + "\t" + "size " + getSize() );
		printStream.println(indentString + "\t" + "family " + family );
		printStream.println(indentString + "\t" + "style " + style );
		printStream.println(indentString + "\t" + "horizontal " + horizontal );
		printStream.println(indentString + "\t" + "leftToRight " + leftToRight );
		printStream.println(indentString + "\t" + "topToBottom " + topToBottom );
		printStream.println(indentString + "\t" + "language " + language );
		printStream.println(indentString + "\t" + "spacing " + getSpacing() );

		MFString justify = (MFString)getField(justifyFieldName);
		printStream.println(indentString + "\t" + "justify [");
		justify.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");
	}
}
