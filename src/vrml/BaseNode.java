package vrml;

import java.util.Vector;
import java.io.*;
import vrml.linkedlist.*;
import vrml.node.*;
import vrml.field.SFMatrix;

public abstract class BaseNode extends LinkedListNode  implements Constants {

	String			mName;
	String			mType;

	public BaseNode() {
		setHeaderFlag(true);
		setName(null);
		setParentNode(null);
		setSceneGraph(null);
	}
	
	public BaseNode(String nodeType, String nodeName) {
		setType(nodeType);
		setName(nodeName);
		setParentNode(null);
		setSceneGraph(null);
	}
	
	public void setName(String name) {
		mName = name;
	}

	public String getName() {
		return mName;
	}

	public void setType(String name) {
		mType = name;
	}

	public String getType() {
		return mType;
	}

	////////////////////////////////////////////////
	//	abstract functions
	////////////////////////////////////////////////

	abstract public void update();
	abstract public void initialize();

	////////////////////////////////////////////////
	//	EventIn
	////////////////////////////////////////////////

	abstract public Field getEventIn(String fieldName);
	
	abstract public int getNEventIn();
	
	abstract public void addEventIn(Field field);
	
	abstract public void addEventIn(String name, Field field);

	abstract public Field getEventIn(int index);

	////////////////////////////////////////////////
	//	ExposedField
	////////////////////////////////////////////////

	abstract public Field getExposedField(String fieldName);
	
	abstract public int getNExposedFields();

	abstract public void addExposedField(Field field);

	abstract public void addExposedField(String name, Field field);

	abstract public Field getExposedField(int index);

	////////////////////////////////////////////////
	//	Field
	////////////////////////////////////////////////

	abstract public  Field getField(String fieldName);

	abstract public int getNFields();

	abstract public void addField(Field field);

	abstract public void addField(String name, Field field);

	abstract public Field getField(int index);

	////////////////////////////////////////////////
	//	Parent node
	////////////////////////////////////////////////

	BaseNode		mParentNode;

	public void setParentNode(BaseNode parentNode) {
		mParentNode = parentNode;
	}

	public BaseNode getParentNode() {
		return mParentNode;
	}

	////////////////////////////////////////////////
	//	find node list
	////////////////////////////////////////////////

	public BaseNode nextTraversal() {
		BaseNode nextNode = getChildNodes();
		if (nextNode != null)
			return nextNode;

		nextNode = next();
		if (nextNode == null) {
			BaseNode parentNode = getParentNode();
			while (parentNode != null) { 
				BaseNode parentNextNode = parentNode.next();
				if (parentNextNode != null)
					return parentNextNode;
				parentNode = parentNode.getParentNode();
			}
		}
		return nextNode;
	}

	public BaseNode nextTraversalByType(String type) {
		if (type == null)
			return null;

		for (BaseNode node = nextTraversal(); node != null; node = node.nextTraversal()) {
			if (node.getType() != null) {
				if (type.compareTo(node.getType()) == 0)
					return node;
			}
		}
		return null;
	}

	public BaseNode nextTraversalByName(String name) {
		if (name == null)
			return null;

		for (BaseNode node = nextTraversal(); node != null; node = node.nextTraversal()) {
			if (node.getName() != null) {
				if (name.compareTo(node.getName()) == 0)
					return node;
			}
		}
		return null;
	}

	////////////////////////////////////////////////
	//	next node list
	////////////////////////////////////////////////

	public BaseNode next () {
		return (BaseNode)getNextNode();
	}

	public BaseNode next(String type) {
		for (BaseNode node = next(); node != null; node = node.next()) {
			if (type.compareTo(node.getType()) == 0)
				return node;
		}
		return null;
	}

	////////////////////////////////////////////////
	//	child node list
	////////////////////////////////////////////////

	LinkedList	mChildNodes = new LinkedList();

	public BaseNode getChildNodes() {
		return (BaseNode)mChildNodes.getNodes();
	}

	public BaseNode getChildNodes(String type) {
		for (BaseNode node = getChildNodes(); node != null; node = node.next()) {
			if (type.compareTo(node.getType()) == 0)
				return node;
		}
		return null;
	}

	public BaseNode getChildNode(int n) {
		return (BaseNode)mChildNodes.getNode(n);
	}

	public int getNChildNodes() {
		return mChildNodes.getNNodes();
	}

	public void addChildNode(BaseNode node) {
		mChildNodes.addNode(node); 
		node.setParentNode(this);
		node.setSceneGraph(getSceneGraph());
		node.initialize();
	}

	////////////////////////////////////////////////
	//	Add / Remove children (for Groupingnode)
	////////////////////////////////////////////////

	public boolean isChild(BaseNode parentNode, BaseNode node) {
		for (BaseNode cnode = parentNode.getChildNodes(); cnode != null; cnode = cnode.next()) {
			if (cnode == node)
				return true;
		}
		return false;
	}

	public boolean isChild(BaseNode node) {
		if (getChildNodes() != null) {
			for (BaseNode cnode = getChildNodes(); cnode != null; cnode = cnode.next()) {
				if (cnode == node)
					return true;
				if (isChild(cnode, node))
					return true;
			}
		}
		return false;
	}

	public void	addChildren(BaseNode node[]) {
		for (int n=0; n<node.length; n++) {
			if (!isChild(node[n]))
				addChildNode(node[n]);
		}

	}

	public void	removeChildren(BaseNode node[]) {
		for (int n=0; n<node.length; n++) {
			if (isChild(node[n]))
				node[n].remove();
		}

	}

	////////////////////////////////////////////////
	//	get child node list
	////////////////////////////////////////////////

	public GroupingNode getGroupingNodes() {
		for (BaseNode node = getChildNodes(); node != null; node = node.next()) {
			if (node.isGroupingNode())
				return (GroupingNode)node;
		}
		return null;
	}

	public BaseNode getGeometryNode() {
		for (BaseNode node = getChildNodes(); node != null; node = node.next()) {
			if (node.isGeometryNode())
				return node;
		}
		return null;
	}

	public BaseNode getTextureNode() {
		for (BaseNode node = getChildNodes(); node != null; node = node.next()) {
			if (node.isTextureNode())
				return node;
		}
		return null;
	}

	public Anchor getAnchors() {
		return (Anchor)getChildNodes(anchorTypeName);
	}

	public Appearance getAppearances() {
		return (Appearance)getChildNodes(appearanceTypeName);
	}

	public AudioClip getAudioClips() {
		return (AudioClip)getChildNodes(audioClipTypeName);
	}

	public Background getBackgrounds() {
		return (Background)getChildNodes(backgroundTypeName);
	}

	public Billboard getBillboards() {
		return (Billboard)getChildNodes(billboardTypeName);
	}

	public Box getBoxes() {
		return (Box)getChildNodes(boxTypeName);
	}

	public Collision getCollisions() {
		return (Collision)getChildNodes(collisionTypeName);
	}

	public Color getColors() {
		return (Color)getChildNodes(colorTypeName);
	}

	public ColorInterpolator getColorInterpolators() {
		return (ColorInterpolator)getChildNodes(colorInterpolatorTypeName);
	}

	public Cone getCones() {
		return (Cone)getChildNodes(coneTypeName);
	}

	public Coordinate getCoordinates() {
		return (Coordinate)getChildNodes(coordinateTypeName);
	}

	public CoordinateInterpolator getCoordinateInterpolators() {
		return (CoordinateInterpolator)getChildNodes(coordinateInterpolatorTypeName);
	}

	public Cylinder getCylinders() {
		return (Cylinder)getChildNodes(cylinderTypeName);
	}

	public CylinderSensor getCylinderSensors() {
		return (CylinderSensor)getChildNodes(cylinderSensorTypeName);
	}

	public DirectionalLight getDirectionalLights() {
		return (DirectionalLight)getChildNodes(directionalLightTypeName);
	}

	public ElevationGrid getElevationGrids() {
		return (ElevationGrid)getChildNodes(elevationGridTypeName);
	}

	public Extrusion getExtrusions() {
		return (Extrusion)getChildNodes(extrusionTypeName);
	}

	public Fog getFogs() {
		return (Fog)getChildNodes(fogTypeName);
	}

	public FontStyle getFontStyles() {
		return (FontStyle)getChildNodes(fontStyleTypeName);
	}

	public Group getGroups() {
		return (Group)getChildNodes(groupTypeName);
	}

	public ImageTexture getImageTextures() {
		return (ImageTexture)getChildNodes(imageTextureTypeName);
	}

	public IndexedFaceSet getIndexedFaceSets() {
		return (IndexedFaceSet)getChildNodes(indexedFaceSetTypeName);
	}

	public IndexedLineSet getIndexedLineSets() {
		return (IndexedLineSet)getChildNodes(indexedLineSetTypeName);
	}

	public Inline getInlines() {
		return (Inline)getChildNodes(inlineTypeName);
	}

	public LOD getLODs() {
		return (LOD)getChildNodes(lodTypeName);
	}

	public Material getMaterials() {
		return (Material)getChildNodes(materialTypeName);
	}

	public MovieTexture getMovieTextures() {
		return (MovieTexture)getChildNodes(movieTextureTypeName);
	}

	public NavigationInfo getNavigationInfos() {
		return (NavigationInfo)getChildNodes(navigationInfoTypeName);
	}

	public Normal getNormals() {
		return (Normal)getChildNodes(normalTypeName);
	}

	public NormalInterpolator getNormalInterpolators() {
		return (NormalInterpolator)getChildNodes(normalInterpolatorTypeName);
	}

	public OrientationInterpolator getOrientationInterpolators() {
		return (OrientationInterpolator)getChildNodes(orientationInterpolatorTypeName);
	}

	public PixelTexture getPixelTextures() {
		return (PixelTexture)getChildNodes(pixelTextureTypeName);
	}

	public PlaneSensor getPlaneSensors() {
		return (PlaneSensor)getChildNodes(planeSensorTypeName);
	}

	public PointLight getPointLights() {
		return (PointLight)getChildNodes(pointLightTypeName);
	}

	public PointSet getPointSets() {
		return (PointSet)getChildNodes(pointSetTypeName);
	}

	public PositionInterpolator getPositionInterpolators() {
		return (PositionInterpolator)getChildNodes(positionInterpolatorTypeName);
	}

	public ProximitySensor getProximitySensors() {
		return (ProximitySensor)getChildNodes(proximitySensorTypeName);
	}

	public ScalarInterpolator getScalarInterpolators() {
		return (ScalarInterpolator)getChildNodes(scalarInterpolatorTypeName);
	}

	public Script getScripts() {
		return (Script)getChildNodes(scriptTypeName);
	}

	public Shape getShapes() {
		return (Shape)getChildNodes(shapeTypeName);
	}

	public Sound getSounds() {
		return (Sound)getChildNodes(soundTypeName);
	}

	public Sphere getSpheres() {
		return (Sphere)getChildNodes(sphereTypeName);
	}

	public SphereSensor getSphereSensors() {
		return (SphereSensor)getChildNodes(sphereSensorTypeName);
	}

	public SpotLight getSpotLights() {
		return (SpotLight)getChildNodes(spotLightTypeName);
	}

	public Switch getSwitchs() {
		return (Switch)getChildNodes(switchTypeName);
	}

	public Text getTexts() {
		return (Text)getChildNodes(textTypeName);
	}

	public TextureCoordinate getTextureCoordinates() {
		return (TextureCoordinate)getChildNodes(textureCoordinateTypeName);
	}

	public TextureTransform getTextureTransforms() {
		return (TextureTransform)getChildNodes(textureTransformTypeName);
	}

	public TimeSensor getTimeSensors() {
		return (TimeSensor)getChildNodes(timeSensorTypeName);
	}

	public TouchSensor getTouchSensors() {
		return (TouchSensor)getChildNodes(touchSensorTypeName);
	}

	public Transform getTransforms() {
		return (Transform)getChildNodes(transformTypeName);
	}

	public Viewpoint getViewpoints() {
		return (Viewpoint)getChildNodes(viewpointTypeName);
	}

	public VisibilitySensor getVisibilitySensors() {
		return (VisibilitySensor)getChildNodes(visibilitySensorTypeName);
	}

	public WorldInfo getWorldInfos() {
		return (WorldInfo)getChildNodes(worldInfoTypeName);
	}

	////////////////////////////////////////////////
	//	
	////////////////////////////////////////////////

	public boolean isNode(String nodeType) {
		String nodeString = getType();
		if (nodeString.compareTo(nodeType) == 0)
			return true;
		else
			return false;
	}

	public boolean isGroupingNode() {
		if (isAnchor() || isBillboard() || isCollision() || isGroup() || isInline() || isLOD() || isSwitch() || isTransform())
			return true;
		else
			return false;
	}

	public boolean isGeometryNode() {
		if (isBox() || isCone() || isCylinder() || isElevationGrid() || isExtrusion() || isIndexedFaceSet() || isIndexedLineSet() || isPointSet() || isSphere() || isText())
			return true;
		else
			return false;
	}

	public boolean isTextureNode() {
		if (isMovieTexture() || isPixelTexture() || isImageTexture() )
			return true;
		else
			return false;
	}

	public boolean isAnchor() {
		return isNode(anchorTypeName);
	}

	public boolean isAppearance() {
		return isNode(appearanceTypeName);
	}

	public boolean isAudioClip() {
		return isNode(audioClipTypeName);
	}

	public boolean isBackground() {
		return isNode(backgroundTypeName);
	}

	public boolean isBillboard() {
		return isNode(billboardTypeName);
	}

	public boolean isBox() {
		return isNode(boxTypeName);
	}

	public boolean isCollision() {
		return isNode(collisionTypeName);
	}

	public boolean isColor() {
		return isNode(colorTypeName);
	}

	public boolean isColorInterpolator() {
		return isNode(colorInterpolatorTypeName);
	}

	public boolean isCone() {
		return isNode(coneTypeName);
	}

	public boolean isCoordinate() {
		return isNode(coordinateTypeName);
	}

	public boolean isCoordinateInterpolator() {
		return isNode(coordinateInterpolatorTypeName);
	}

	public boolean isCylinder() {
		return isNode(cylinderTypeName);
	}

	public boolean isCylinderSensor() {
		return isNode(cylinderSensorTypeName);
	}

	public boolean isDirectionalLight() {
		return isNode(directionalLightTypeName);
	}

	public boolean isElevationGrid() {
		return isNode(elevationGridTypeName);
	}

	public boolean isExtrusion() {
		return isNode(extrusionTypeName);
	}

	public boolean isFog() {
		return isNode(fogTypeName);
	}

	public boolean isFontStyle() {
		return isNode(fontStyleTypeName);
	}

	public boolean isGroup() {
		return isNode(groupTypeName);
	}

	public boolean isImageTexture() {
		return isNode(imageTextureTypeName);
	}

	public boolean isIndexedFaceSet() {
		return isNode(indexedFaceSetTypeName);
	}

	public boolean isIndexedLineSet() {
		return isNode(indexedLineSetTypeName);
	}

	public boolean isInline() {
		return isNode(inlineTypeName);
	}

	public boolean isLOD() {
		return isNode(lodTypeName);
	}

	public boolean isMaterial() {
		return isNode(materialTypeName);
	}

	public boolean isMovieTexture() {
		return isNode(movieTextureTypeName);
	}

	public boolean isNavigationInfo() {
		return isNode(navigationInfoTypeName);
	}

	public boolean isNormal() {
		return isNode(normalTypeName);
	}

	public boolean isNormalInterpolator() {
		return isNode(normalInterpolatorTypeName);
	}

	public boolean isOrientationInterpolator() {
		return isNode(orientationInterpolatorTypeName);
	}

	public boolean isPixelTexture() {
		return isNode(pixelTextureTypeName);
	}

	public boolean isPlaneSensor() {
		return isNode(planeSensorTypeName);
	}

	public boolean isPointLight() {
		return isNode(pointLightTypeName);
	}

	public boolean isPointSet() {
		return isNode(pointSetTypeName);
	}

	public boolean isPositionInterpolator() {
		return isNode(positionInterpolatorTypeName);
	}

	public boolean isProximitySensor() {
		return isNode(proximitySensorTypeName);
	}

	public boolean isScalarInterpolator() {
		return isNode(scalarInterpolatorTypeName);
	}

	public boolean isScript() {
		return isNode(scriptTypeName);
	}

	public boolean isShape() {
		return isNode(shapeTypeName);
	}

	public boolean isSound() {
		return isNode(soundTypeName);
	}

	public boolean isSphere() {
		return isNode(sphereTypeName);
	}

	public boolean isSphereSensor() {
		return isNode(sphereSensorTypeName);
	}

	public boolean isSpotLight() {
		return isNode(spotLightTypeName);
	}

	public boolean isSwitch() {
		return isNode(switchTypeName);
	}

	public boolean isText() {
		return isNode(textTypeName);
	}

	public boolean isTextureCoordinate() {
		return isNode(textureCoordinateTypeName);
	}

	public boolean isTextureTransform() {
		return isNode(textureTransformTypeName);
	}

	public boolean isTimeSensor() {
		return isNode(timeSensorTypeName);
	}

	public boolean isTouchSensor() {
		return isNode(touchSensorTypeName);
	}

	public boolean isTransform() {
		return isNode(transformTypeName);
	}

	public boolean isViewpoint() {
		return isNode(viewpointTypeName);
	}

	public boolean isVisibilitySensor() {
		return isNode(visibilitySensorTypeName);
	}

	public boolean isWorldInfo() {
		return isNode(worldInfoTypeName);
	}

	////////////////////////////////////////////////
	//	output
	////////////////////////////////////////////////

	public String getIndentLevelString(int nIndentLevel) {
		char indentString[] = new char[nIndentLevel];
		for (int n=0; n<nIndentLevel; n++)
			indentString[n] = '\t' ;
		return new String(indentString);
	}

	public void outputHead(PrintStream printStream, String indentString) {
		if (getName() != null)
			printStream.println(indentString + "DEF " + getName() + " " + getType() + " {");
		else
			printStream.println(indentString +  getType() + " {");
	}

	public void outputTail(PrintStream printStream, String indentString) {
		printStream.println(indentString + "}");
	}
	////////////////////////////////////////////////
	//	output
	////////////////////////////////////////////////

	abstract public void outputContext(PrintStream printStream, String indentString);

	public void output(PrintStream printStream, int indentLevet) {

		String indentString = getIndentLevelString(indentLevet);

		outputHead(printStream, indentString);
		outputContext(printStream, indentString);
	
		if (!isElevationGrid() && !isShape() && !isSound() && !isPointSet() && !isIndexedFaceSet() && 
			!isIndexedLineSet() && !isText() && !isAppearance()) {
			if (getChildNodes() != null) {
				if (isLOD()) 
					printStream.println(indentString + "\tlevel [");
				else if (isSwitch()) 
					printStream.println(indentString + "\tchoice [");
				else
					printStream.println(indentString + "\tchildren [");
			
				for (BaseNode cnode = getChildNodes(); cnode != null; cnode = cnode.next()) {
					cnode.output(printStream, indentLevet+2);
				}
			
				printStream.println(indentString + "\t]");
			}
		}

		outputTail(printStream, indentString);
	}

	public void print(PrintStream printStream, int indentLevel) {
		output(System.out, indentLevel);
	}

	public void print(){
		output(System.out, 0);
	}

	public void save(FileOutputStream outputStream){
		PrintStream printStream = new PrintStream(outputStream);
		output(printStream, 0);
	}

	public void save(String filename) {
		try {
			FileOutputStream outputStream = new FileOutputStream(filename);
			save(outputStream);
			outputStream.close();
		}
		catch (IOException e) {
			System.out.println("Couldn't open the file (" + filename + ")");
		}
	}

	////////////////////////////////////////////////
	//	getTransformMatrix
	////////////////////////////////////////////////

	public void getTransformMatrix(SFMatrix mxOut) {
		mxOut.init();
		for (BaseNode node=this; node != null ; node=node.getParentNode()) {
			if (node.isTransform()) {
				SFMatrix	mxTransform = new SFMatrix();
				((Transform)node).getSFMatrix(mxTransform);
				mxTransform.add(mxOut);
				mxOut.setValue(mxTransform);
			}
		}
	}

	public SFMatrix getTransformMatrix() {
		SFMatrix	mx = new SFMatrix();
		getTransformMatrix(mx);
		return mx;
	}

	////////////////////////////////////////////////
	//	SceneGraph
	////////////////////////////////////////////////

	SceneGraph	mSceneGraph = null;
	
	public void setSceneGraph(SceneGraph sceneGraph) {
		mSceneGraph = sceneGraph;
		for (BaseNode node = getChildNodes(); node != null; node = node.next())
			node.setSceneGraph(sceneGraph);
	}
	
	public SceneGraph getSceneGraph() {
		return mSceneGraph;
	}

	////////////////////////////////////////////////
	//	Route
	////////////////////////////////////////////////

	public void sendEvent(Field eventOutField) {
		getSceneGraph().updateRoute(this, eventOutField);
	}
}
