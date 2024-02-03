package vrml.field;

import java.io.PrintStream;
import vrml.*;

public class ConstMFNode extends ConstMField {

	public ConstMFNode() {
		setType(fieldTypeConstMFNode);
	}

	public ConstMFNode(MFNode nodes) {
		setType(fieldTypeConstMFNode);
		copy(nodes);
	}

	public ConstMFNode(ConstMFNode nodes) {
		setType(fieldTypeConstMFNode);
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