package vrml.node;

import java.io.PrintStream;
import vrml.*;

public class Group extends GroupingNode {

	public Group() {
		super();

		setHeaderFlag(false);
		setType(groupTypeName);
	}

	////////////////////////////////////////////////
	//	Output
	////////////////////////////////////////////////

	public void outputContext(PrintStream printStream, String indentString) {
	}

	////////////////////////////////////////////////
	//	abstract functions
	////////////////////////////////////////////////
	
	public void initialize() {
	}

	public void update() {
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public Group next() {
		return (Group)next(getType());
	}

	public Group nextTraversal() {
		return (Group)nextTraversalByType(getType());
	}

}
