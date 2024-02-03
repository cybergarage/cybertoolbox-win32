package vrml.node;

import vrml.*;
import vrml.field.*;

public abstract class GroupingNode extends Node {

	private String	addChildrenEventIn			= "addChildren";
	private String	removeChildrenEventIn		= "removeChildren";
	
	private String	bboxCenterFieldName			= "bboxCenter";
	private String	bboxSizeFieldName			= "bboxSize";

	public GroupingNode() {
		setHeaderFlag(false);

		// addChildren eventout field
		MFNode addNodes = new MFNode();
		addEventIn(addChildrenEventIn, addNodes);

		// removeChildren eventout field
		MFNode removeChildren = new MFNode();
		addEventIn(removeChildrenEventIn, removeChildren);

		// bboxBBoxCenter field
		SFVec3f bboxBBoxCenter = new SFVec3f(0.0f, 0.0f, 0.0f);
		bboxBBoxCenter.setName(bboxCenterFieldName);
		addField(bboxBBoxCenter);

		// bboxSize field
		SFVec3f bboxSize = new SFVec3f(-1.0f, -1.0f, -1.0f);
		bboxSize.setName(bboxSizeFieldName);
		addField(bboxSize);
	}

	////////////////////////////////////////////////
	//	BBoxSize
	////////////////////////////////////////////////

	public void setBBoxSize(float value[]) {
		SFVec3f bboxSize = (SFVec3f)getField(bboxSizeFieldName);
		bboxSize.setValue(value);
	}
	public void setBBoxSize(float x, float y, float z) {
		SFVec3f bboxSize = (SFVec3f)getField(bboxSizeFieldName);
		bboxSize.setValue(x, y, z);
	}
	public void getBBoxSize(float value[]) {
		SFVec3f bboxSize = (SFVec3f)getField(bboxSizeFieldName);
		bboxSize.getValue(value);
	}

	////////////////////////////////////////////////
	//	BBoxCenter
	////////////////////////////////////////////////

	public void setBBoxCenter(float value[]) {
		SFVec3f bboxBBoxCenter = (SFVec3f)getField(bboxCenterFieldName);
		bboxBBoxCenter.setValue(value);
	}
	public void setBBoxCenter(float x, float y, float z) {
		SFVec3f bboxBBoxCenter = (SFVec3f)getField(bboxCenterFieldName);
		bboxBBoxCenter.setValue(x, y, z);
	}
	public void getBBoxCenter(float value[]) {
		SFVec3f bboxBBoxCenter = (SFVec3f)getField(bboxCenterFieldName);
		bboxBBoxCenter.getValue(value);
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public GroupingNode next() {
		for (BaseNode node = super.next(); node != null; node = node.next()) {
			if (node.isGroup() || node.isTransform() || node.isBillboard() || node.isCollision() || node.isLOD() || node.isSwitch() || node.isInline())
				return (GroupingNode)node;
		}
		return null;
	}

	public GroupingNode nextTraversal() {
		for (BaseNode node = super.nextTraversal(); node != null; node = node.nextTraversal()) {
			if (node.isGroup() || node.isTransform() || node.isBillboard() || node.isCollision() || node.isLOD() || node.isSwitch() || node.isInline())
				return (GroupingNode)node;
		}
		return null;
	}
}
