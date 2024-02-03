package vrml.node;

import java.io.PrintStream;
import vrml.*;
import vrml.field.*;

public class LOD extends GroupingNode {

	private String	centerFieldName		= "center";
	private String	rangeFieldName		= "range";
	
	public LOD() {
		setHeaderFlag(false);
		setType(lodTypeName);

		// center field
		SFVec3f center = new SFVec3f(0.0f, 0.0f, 0.0f);
		addField(centerFieldName, center);

		// range field
		MFFloat range = new MFFloat();
		addField(rangeFieldName, range);
	}

	////////////////////////////////////////////////
	//	center
	////////////////////////////////////////////////

	public void setCenter(float value[]) {
		SFVec3f center = (SFVec3f)getField(centerFieldName);
		center.setValue(value);
	}

	public void setCenter(float x, float y, float z) {
		SFVec3f center = (SFVec3f)getField(centerFieldName);
		center.setValue(x, y, z);
	}

	public void getCenter(float value[]) {
		SFVec3f center = (SFVec3f)getField(centerFieldName);
		center.getValue(value);
	}

	////////////////////////////////////////////////
	//	range 
	////////////////////////////////////////////////

	public void addRange(float value) {
		MFFloat range = (MFFloat)getField(rangeFieldName);
		range.addValue(value);
	}

	public int getNRanges() {
		MFFloat range = (MFFloat)getField(rangeFieldName);
		return range.getSize();
	}

	public float getRange(int index) {
		MFFloat range = (MFFloat)getField(rangeFieldName);
		return range.get1Value(index);
	}


	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public LOD next() {
		return (LOD)next(getType());
	}

	public LOD nextTraversal() {
		return (LOD)nextTraversalByType(getType());
	}

	////////////////////////////////////////////////
	//	abstract functions
	////////////////////////////////////////////////
	
	public void initialize() {
	}

	public void update() {
	}

	////////////////////////////////////////////////
	//	Infomation
	////////////////////////////////////////////////

	public void outputContext(PrintStream printStream, String indentString) {
		SFVec3f center = (SFVec3f)getField(centerFieldName);
		printStream.println(indentString + "\t" + "center " + center);

		MFFloat range = (MFFloat)getField(rangeFieldName);
		printStream.println(indentString + "\t" + "range [");
		range.outputContext(printStream, indentString + "\t\t");
		printStream.println(indentString + "\t" + "]");
	}
}
