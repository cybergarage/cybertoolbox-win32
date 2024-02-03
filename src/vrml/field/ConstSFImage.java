package vrml.field;

import java.io.PrintStream;
import vrml.*;

public class ConstSFImage extends ConstMField {

	public ConstSFImage() {
		setType(fieldTypeConstSFImage);
	}

	public void addValue(int value) {
		SFInt32 sfvalue = new SFInt32(value);
		add(sfvalue);
	}

	public void addValue(SFInt32 sfvalue) {
		add(sfvalue);
	}

	public void insertValue(int index, int value) {
		SFInt32 sfvalue = new SFInt32(value);
		insert(sfvalue, index);
	}

	public int get1Value(int index) {
		SFInt32 sfvalue = (SFInt32)getObject(index);
		return sfvalue.getValue();
	}

	public void set1Value(int index, int value) {
		SFInt32 sfvalue = (SFInt32)getObject(index);
		sfvalue.setValue(value);
	}

	////////////////////////////////////////////////
	//	Output
	////////////////////////////////////////////////

	public void outputContext(PrintStream printStream, String indentString) {
		float	value[] = new float[3];
		int		nOutput = 0;
		for (int n=0; n<getSize(); n++) {
			printStream.print(indentString);
			if (n < getSize()) { 
				printStream.print(get1Value(n) + " ");
				nOutput++;
				if (32 < nOutput) {
					printStream.println("");
					printStream.print(indentString);
					nOutput = 0;

				}
			}
			printStream.println("");
		}
	}
	////////////////////////////////////////////////
	//	toString
	////////////////////////////////////////////////

	public String toString() {
		return null;
	}
}