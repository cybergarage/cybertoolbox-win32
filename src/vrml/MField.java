package vrml;

import java.io.PrintStream;
import java.util.Vector;

public abstract class MField extends Field {

	private Vector	mFieldVector = new Vector();

	public int getSize() {
		return mFieldVector.size();
	}

	public void add(Object object) {
		mFieldVector.addElement(object);
	}

	public void insert(Object object, int index) {
		mFieldVector.insertElementAt(object, index);
	}

	public void clear() {
		mFieldVector.removeAllElements();
	}

	public void delete(int index) {
		mFieldVector.removeElementAt(index);
	}

	public Object getObject(int index) {
		return mFieldVector.elementAt(index);
	}

	public void setObject(int index, Object object) {
		mFieldVector.setElementAt(object, index);
	}

	public void copy(MField srcMField) {
		clear();
		for (int n=0; n<srcMField.getSize(); n++) {
			add(srcMField.getObject(n));
		}
	}

	public void copy(ConstMField srcMField) {
		clear();
		for (int n=0; n<srcMField.getSize(); n++) {
			add(srcMField.getObject(n));
		}
	}

	abstract public void outputContext(PrintStream printStream, String indentString);
};

