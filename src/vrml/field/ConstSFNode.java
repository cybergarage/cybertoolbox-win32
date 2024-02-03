package vrml.field;

import vrml.*;

public class ConstSFNode extends ConstField {

	public BaseNode mValue; 

	public ConstSFNode() {
		setType(fieldTypeConstSFNode);
		mValue = null;
	}

	public ConstSFNode(SFNode node) {
		setType(fieldTypeSFTime);
		setValue(node);
	}

	public ConstSFNode(ConstSFNode node) {
		setType(fieldTypeSFTime);
		setValue(node);
	}

	public ConstSFNode(BaseNode node) {
		setType(fieldTypeSFTime);
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