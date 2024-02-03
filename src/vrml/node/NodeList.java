package vrml.node;

import vrml.linkedlist.*;

public class NodeList extends LinkedList {

	public NodeList() {
		RootNode rootNode = new RootNode();
		setRootNode(rootNode);
	}
}