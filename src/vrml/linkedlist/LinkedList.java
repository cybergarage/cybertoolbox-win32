package vrml.linkedlist;

public class LinkedList {
	LinkedListNode	mHeaderNode;		

	public LinkedList () {
		mHeaderNode = new LinkedListNode(true);
	}

	public void setRootNode(LinkedListNode obj) {
		mHeaderNode = obj;
	}

	public LinkedListNode getRootNode () {
		return mHeaderNode;
	}

	public LinkedListNode getNodes () {
		return mHeaderNode.getNextNode();
	}

	public LinkedListNode getNode(int number) {
		LinkedListNode node = getNodes();
		for (int n=0; n<number && node != null; n++)
			node = node.getNextNode();
		return node;
	}

	public LinkedListNode getLastNode () {
		LinkedListNode lastNode = mHeaderNode.getPrevNode();
		if (lastNode.isHeaderNode())
			return null;
		else
			return lastNode;
	}

	public int getNNodes()	{
		int n = 0;
		for (LinkedListNode listNode = getRootNode(); listNode != null; listNode = listNode.getNextNode())
			n++;
		return n;
	}

	public void addNode(LinkedListNode node) {
		node.insert(mHeaderNode.getPrevNode());
	}

	public void deleteNodes() {
		LinkedListNode rootNode = getRootNode();
		while (rootNode.getNextNode() != null) {
			LinkedListNode nextNode = rootNode.getNextNode();
			nextNode.remove();
		}
	}
}
