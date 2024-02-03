package vrml.node;

import java.io.PrintStream;
import vrml.*;

public class Appearance extends Node {

	public Appearance() {
		setHeaderFlag(false);
		setType(appearanceTypeName);
	}

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	public Appearance next() {
		return (Appearance)next(getType());
	}

	public Appearance nextTraversal() {
		return (Appearance)nextTraversalByType(getType());
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
		Material material = getMaterials();
		if (material != null) {
			printStream.println(indentString + "\t" + "material Material {");
			material.outputContext(printStream, indentString + "\t");
			printStream.println(indentString + "\t" + "}");
		}

		BaseNode texture = getTextureNode();
		if (texture != null) {
			printStream.println(indentString + "\t" + "texture " + texture.getType() + " {");
			texture.outputContext(printStream, indentString + "\t");
			printStream.println(indentString + "\t" + "}");
		}

		TextureTransform textureTransform = getTextureTransforms();
		if (textureTransform != null) {
			printStream.println(indentString + "\t" + "textureTransform TextureTransform {");
			textureTransform.outputContext(printStream, indentString + "\t");
			printStream.println(indentString + "\t" + "}");
		}
	}
}