package vrml.linkedlist;

public class LinkedListNode {
	boolean			mbHeader;
	LinkedListNode	mPrevNode;
	LinkedListNode	mNextNode;

	public LinkedListNode () {
		setHeaderFlag(false);
		mPrevNode = mNextNode = this;
	}

	public LinkedListNode (boolean header) {
		setHeaderFlag(header);
		mPrevNode = mNextNode = this;
	}

	public LinkedListNode (LinkedListNode prevNode) {
		setHeaderFlag(false);
		insert(prevNode);
	}

	public boolean isHeaderNode() {
		return mbHeader;
	}

	public void setHeaderFlag(boolean bHeader) {
		mbHeader = bHeader;
	}

	public LinkedListNode getNextNode() {
		if (mNextNode.isHeaderNode() == true)
			return null;
		else
			return mNextNode;
	}

	public LinkedListNode getPrevNode() {
		return mPrevNode;
	}

	public LinkedListNode getNextCircularNode() {
		if (mNextNode.isHeaderNode() == true)
			return mNextNode.mNextNode;
		else
			return mNextNode;
	}

	public LinkedListNode getPrevCircularNode() {
		if (mPrevNode.isHeaderNode() == true)
			return mPrevNode.mPrevNode;
		else
			return mPrevNode;
	}

	public void insert(LinkedListNode prevNode)
	{
		remove();

		mPrevNode = prevNode;
		mNextNode = prevNode.mNextNode;
		prevNode.mNextNode.mPrevNode = this;
		prevNode.mNextNode = this;
	}

	public void remove() {
		mNextNode.mPrevNode = mPrevNode;
		mPrevNode.mNextNode = mNextNode;
	}
}
