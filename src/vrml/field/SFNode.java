package vrml.field;

import vrml.*;

public class SFNode extends Field {

	public BaseNode mValue; 

	public SFNode() {
		setType(fieldTypeSFNode);
		mValue = null;
	}

	public SFNode(SFNode node) {
		setType(fieldTypeSFNode);
		setValue(node);
	}

	public SFNode(ConstSFNode node) {
		setType(fieldTypeSFNode);
		setValue(node);
	}

	public SFNode(BaseNode node) {
		setType(fieldTypeSFNode);
		setValue(node);
	}

	public void setValue(BaseNode node) {
		mValue = node;
	}

	public void setValue(SFNode node) {
		mValue = node.getValue();
	}

	public void setValue(ConstSFNode node) {
		mValue = node.getValue();
	}

	public BaseNode getValue() {
		return mValue;
	}

	////////////////////////////////////////////////
	//	toString
	////////////////////////////////////////////////

	public String toString() {
		return mValue.getType();
	}
}
