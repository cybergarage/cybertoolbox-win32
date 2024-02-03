package vrml.node;

import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class Switch extends GroupingNode {

	private String	whichChoiceFieldName	= "whichChoice";
	
	public Switch() {
		setHeaderFlag(false);
		setType(switchTypeName);

		// whichChoice field
		SFInt32 whichChoice = new SFInt32(-1);
		addField(whichChoiceFieldName, whichChoice);
	}

	////////////////////////////////////////////////
	//	whichChoice
	////////////////////////////////////////////////

	public void setWhichChoice(int value) {
		SFInt32 whichChoice = (SFInt32)getField(whichChoiceFieldName);
		whichChoice.setValue(value);
	}

	public int getWhichChoice() {
		SFInt32 whichChoice = (SFInt32)getField(whichChoiceFieldName);
		return whichChoice.getValue();
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public Switch next() {
		return (Switch)next(getType());
	}

	public Switch nextTraversal() {
		return (Switch)nextTraversalByType(getType());
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
		printStream.println(indentString + "\t" + "whichChoice " + getWhichChoice());
	}
}
