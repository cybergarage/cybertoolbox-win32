package vrml.parser;

import vrml.*;
import vrml.node.*;
import vrml.linkedlist.*;

public class ParserNodeStack extends LinkedListNode {
	private BaseNode	mNode;
	private int			mType;

	public ParserNodeStack(BaseNode node, int type) { 
		setHeaderFlag(false); 
		mNode = node; 
		mType = type;
	}
	
	BaseNode getObject() { 
		return mNode; 
	}
	
	int getType() { 
		return mType; 
	}
};
