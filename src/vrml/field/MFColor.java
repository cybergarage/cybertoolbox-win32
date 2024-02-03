package vrml.field;

import java.io.PrintStream;
import vrml.*;

public class MFColor extends MField {

	public MFColor() {
		setType(fieldTypeMFColor);
	}

	public MFColor(MFColor colors) {
		setType(fieldTypeMFColor);
		copy(colors);
	}

	public MFColor(ConstMFColor colors) {
		setType(fieldTypeMFColor);
		copy(colors);
	}

	public void addValue(float r, float g, float b) {
		SFColor color = new SFColor(r, g, b);
		add(color);
	}

	public void addValue(float value[]) {
		SFColor color = new SFColor(value);
		add(color);
	}

	public void addValue(SFColor color) {
		add(color);
	}

	public void insertValue(int index, float r, float g, float b) {
		SFColor color = new SFColor(r, g, b);
		insert(color, index);
	}

	public void insertValue(int index, float value[]) {
		SFColor color = new SFColor(value);
		insert(color, index);
	}

	public void insertValue(int index, SFColor color) {
		insert(color, index);
	}

	public void get1Value(int index, float value[]) {
		SFColor color = (SFColor)getObject(index);
		color.getValue(value);
	}

	public void set1Value(int index, float value[]) {
		SFColor color = (SFColor)getObject(index);
		color.setValue(value);
	}

	public void set1Value(int index, float r, float g, float b) {
		SFColor color = (SFColor)getObject(index);
		color.setValue(r, g, b);
	}

	////////////////////////////////////////////////
	//	Output
	////////////////////////////////////////////////

	public void outputContext(PrintStream printStream, String indentString) {
		float value[] = new float[3];
		for (int n=0; n<getSize(); n++) {
			get1Value(n, value);
			if (n < getSize()-1)
				printStream.println(indentString + value[X] + " " + value[Y] + " " + value[Z] + ",");
			else	
				printStream.println(indentString + value[X] + " " + value[Y] + " " + value[Z]);
		}
	}

	////////////////////////////////////////////////
	//	toString
	////////////////////////////////////////////////

	public String toString() {
		return null;
	}
}