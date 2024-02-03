package vrml.field;

import java.io.PrintStream;
import vrml.*;

public class MFNode extends MField {

	public MFNode() {
		setType(fieldTypeMFNode);
	}

	public MFNode(MFNode nodes) {
		setType(fieldTypeMFNode);
		copy(nodes);
	}

	public MFNode(ConstMFNode nodes) {
		setType(fieldTypeMFNode);
		copy(nodes);
	}

	public void addValue(BaseNode node) {
		add(node);
	}

	public void insertValue(int index, BaseNode node) {
		insert(node, index);
	}

	public BaseNode get1Value(int index) {
		BaseNode node = (BaseNode)getObject(index);
		return node;
	}

	public void set1Value(int index, BaseNode node) {
		setObject(index, node);
	}

	////////////////////////////////////////////////
	//	Output
	////////////////////////////////////////////////

	public void outputContext(PrintStream printStream, String indentString) {
	}

	////////////////////////////////////////////////
	//	toString
	////////////////////////////////////////////////

	public String toString() {
		return null;
	}
}