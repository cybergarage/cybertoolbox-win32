package vrml.node;

import java.io.PrintStream;
import vrml.linkedlist.*;

public class RootNode extends Node {

	public RootNode() {
		setHeaderFlag(true);
	}

	////////////////////////////////////////////////
	//	abstract functions
	////////////////////////////////////////////////
	
	public void initialize() {
	}

	public void update() {
	}

	////////////////////////////////////////////////
	//	infomation
	////////////////////////////////////////////////

	public void outputContext(PrintStream printStream, String indentString) {
	}
}
