package vrml;

import java.io.*;
import vrml.linkedlist.*;
import vrml.parser.*;
import vrml.node.*;
import vrml.route.*;

public class SceneGraph extends LinkedListNode implements Constants {
	Parser	mParser = null;

	public SceneGraph() {
		setHeaderFlag(false);
		mParser = new Parser();
	}

	public SceneGraph(String filename) {
		setHeaderFlag(false);
		load(filename);
	}

	public SceneGraph(File file) {
		setHeaderFlag(false);
		load(file);
	}

	////////////////////////////////////////////////
	//	child node list
	////////////////////////////////////////////////

	public BaseNode getRootNode() {
		return mParser.getRootNode();
	}

	public BaseNode getNodes() {
		return mParser.getNodes();
	}

	public BaseNode getNodes(String typeName) {
		BaseNode node = mParser.getNodes();
		if (node == null)
			return null;
		String nodeString = node.getType();
		if (nodeString.compareTo(typeName) == 0)
			return node;
		else
			return node.next(typeName);
	}

	///////////////////////////////////////////////
	//	ROUTE
	///////////////////////////////////////////////

	public static LinkedList	mRouteList		= new LinkedList();

	public Route getRoutes() {
		return mParser.getRoutes();
	}

	public void addRoute(Route route) {
		mParser.addRoute(route);
	}

	public void addRoute(String eventOutNodeName, String eventOutFieldName, String eventInNodeName, String eventInFieldName)
	{
		mParser.addRoute(eventOutNodeName, eventOutFieldName, eventInNodeName, eventInFieldName);
	}

	////////////////////////////////////////////////
	//	find node
	////////////////////////////////////////////////

	public BaseNode findNodeByType(String typeName) {
		BaseNode rootNode = getRootNode();
		return rootNode.nextTraversalByType(typeName);
	}

	public BaseNode findNodeByName(String name) {
		BaseNode rootNode = getRootNode();
		return rootNode.nextTraversalByName(name);
	}

	////////////////////////////////////////////////
	//	child node list
	////////////////////////////////////////////////

	public GroupingNode getGroupingNodes() {
		for (BaseNode node = getNodes(); node != null; node = node.next()) {
			if (node.isGroupingNode())
				return (GroupingNode)node;
		}
		return null;
	}

	public Anchor getAnchors() {
		return (Anchor)getNodes(anchorTypeName);
	}

	public Appearance getAppearances() {
		return (Appearance)getNodes(appearanceTypeName);
	}

	public AudioClip getAudioClips() {
		return (AudioClip)getNodes(audioClipTypeName);
	}

	public Background getBackgrounds() {
		return (Background)getNodes(backgroundTypeName);
	}

	public Billboard getBillboards() {
		return (Billboard)getNodes(billboardTypeName);
	}

	public Box getBoxes() {
		return (Box)getNodes(boxTypeName);
	}

	public Collision getCollisions() {
		return (Collision)getNodes(collisionTypeName);
	}

	public Color getColors() {
		return (Color)getNodes(colorTypeName);
	}

	public ColorInterpolator getColorInterpolators() {
		return (ColorInterpolator)getNodes(colorInterpolatorTypeName);
	}

	public Cone getCones() {
		return (Cone)getNodes(coneTypeName);
	}

	public Coordinate getCoordinates() {
		return (Coordinate)getNodes(coordinateTypeName);
	}

	public CoordinateInterpolator getCoordinateInterpolators() {
		return (CoordinateInterpolator)getNodes(coordinateInterpolatorTypeName);
	}

	public Cylinder getCylinders() {
		return (Cylinder)getNodes(cylinderTypeName);
	}

	public CylinderSensor getCylinderSensors() {
		return (CylinderSensor)getNodes(cylinderSensorTypeName);
	}

	public DirectionalLight getDirectionalLights() {
		return (DirectionalLight)getNodes(directionalLightTypeName);
	}

	public ElevationGrid getElevationGrids() {
		return (ElevationGrid)getNodes(elevationGridTypeName);
	}

	public Extrusion getExtrusions() {
		return (Extrusion)getNodes(extrusionTypeName);
	}

	public Fog getFogs() {
		return (Fog)getNodes(fogTypeName);
	}

	public FontStyle getFontStyles() {
		return (FontStyle)getNodes(fontStyleTypeName);
	}

	public Group getGroups() {
		return (Group)getNodes(groupTypeName);
	}

	public ImageTexture getImageTextures() {
		return (ImageTexture)getNodes(imageTextureTypeName);
	}

	public IndexedFaceSet getIndexedFaceSets() {
		return (IndexedFaceSet)getNodes(indexedFaceSetTypeName);
	}

	public IndexedLineSet getIndexedLineSets() {
		return (IndexedLineSet)getNodes(indexedLineSetTypeName);
	}

	public Inline getInlines() {
		return (Inline)getNodes(inlineTypeName);
	}

	public LOD getLODs() {
		return (LOD)getNodes(lodTypeName);
	}

	public Material getMaterials() {
		return (Material)getNodes(materialTypeName);
	}

	public MovieTexture getMovieTextures() {
		return (MovieTexture)getNodes(movieTextureTypeName);
	}

	public NavigationInfo getNavigationInfos() {
		return (NavigationInfo)getNodes(navigationInfoTypeName);
	}

	public Normal getNormals() {
		return (Normal)getNodes(normalTypeName);
	}

	public NormalInterpolator getNormalInterpolators() {
		return (NormalInterpolator)getNodes(normalInterpolatorTypeName);
	}

	public OrientationInterpolator getOrientationInterpolators() {
		return (OrientationInterpolator)getNodes(orientationInterpolatorTypeName);
	}

	public PixelTexture getPixelTextures() {
		return (PixelTexture)getNodes(pixelTextureTypeName);
	}

	public PlaneSensor getPlaneSensors() {
		return (PlaneSensor)getNodes(planeSensorTypeName);
	}

	public PointLight getPointLights() {
		return (PointLight)getNodes(pointLightTypeName);
	}

	public PointSet getPointSets() {
		return (PointSet)getNodes(pointSetTypeName);
	}

	public PositionInterpolator getPositionInterpolators() {
		return (PositionInterpolator)getNodes(positionInterpolatorTypeName);
	}

	public ProximitySensor getProximitySensors() {
		return (ProximitySensor)getNodes(proximitySensorTypeName);
	}

	public ScalarInterpolator getScalarInterpolators() {
		return (ScalarInterpolator)getNodes(scalarInterpolatorTypeName);
	}

	public Script getScripts() {
		return (Script)getNodes(scriptTypeName);
	}

	public Shape getShapes() {
		return (Shape)getNodes(shapeTypeName);
	}

	public Sound getSounds() {
		return (Sound)getNodes(soundTypeName);
	}

	public Sphere getSpheres() {
		return (Sphere)getNodes(sphereTypeName);
	}

	public SphereSensor getSphereSensors() {
		return (SphereSensor)getNodes(sphereSensorTypeName);
	}

	public SpotLight getSpotLights() {
		return (SpotLight)getNodes(spotLightTypeName);
	}

	public Switch getSwitchs() {
		return (Switch)getNodes(switchTypeName);
	}

	public Text getTexts() {
		return (Text)getNodes(textTypeName);
	}

	public TextureCoordinate getTextureCoordinates() {
		return (TextureCoordinate)getNodes(textureCoordinateTypeName);
	}

	public TextureTransform getTextureTransforms() {
		return (TextureTransform)getNodes(textureTransformTypeName);
	}

	public TimeSensor getTimeSensors() {
		return (TimeSensor)getNodes(timeSensorTypeName);
	}

	public TouchSensor getTouchSensors() {
		return (TouchSensor)getNodes(touchSensorTypeName);
	}

	public Transform getTransforms() {
		return (Transform)getNodes(transformTypeName);
	}

	public Viewpoint getViewpoints() {
		return (Viewpoint)getNodes(viewpointTypeName);
	}

	public VisibilitySensor getVisibilitySensors() {
		return (VisibilitySensor)getNodes(visibilitySensorTypeName);
	}

	public WorldInfo getWorldInfos() {
		return (WorldInfo)getNodes(worldInfoTypeName);
	}

	////////////////////////////////////////////////
	//	find speciic node
	////////////////////////////////////////////////

	public GroupingNode findGroupingNode() {
		for (BaseNode node = (getRootNode()).nextTraversal(); node != null; node = node.nextTraversal()) {
			if (node.isGroupingNode())
				return (GroupingNode)node;
		}
		return null;
	}

	public Anchor findAnchor() {
		return (Anchor)findNodeByType(anchorTypeName);
	}

	public Appearance findAppearance() {
		return (Appearance)findNodeByType(appearanceTypeName);
	}

	public AudioClip findAudioClip() {
		return (AudioClip)findNodeByType(audioClipTypeName);
	}

	public Background findBackground() {
		return (Background)findNodeByType(backgroundTypeName);
	}

	public Billboard findBillboard() {
		return (Billboard)findNodeByType(billboardTypeName);
	}

	public Box findBoxe() {
		return (Box)findNodeByType(boxTypeName);
	}

	public Collision findCollision() {
		return (Collision)findNodeByType(collisionTypeName);
	}

	public Color findColor() {
		return (Color)findNodeByType(colorTypeName);
	}

	public ColorInterpolator findColorInterpolator() {
		return (ColorInterpolator)findNodeByType(colorInterpolatorTypeName);
	}

	public Cone findCone() {
		return (Cone)findNodeByType(coneTypeName);
	}

	public Coordinate findCoordinate() {
		return (Coordinate)findNodeByType(coordinateTypeName);
	}

	public CoordinateInterpolator findCoordinateInterpolator() {
		return (CoordinateInterpolator)findNodeByType(coordinateInterpolatorTypeName);
	}

	public Cylinder findCylinder() {
		return (Cylinder)findNodeByType(cylinderTypeName);
	}

	public CylinderSensor findCylinderSensor() {
		return (CylinderSensor)findNodeByType(cylinderSensorTypeName);
	}

	public DirectionalLight findDirectionalLight() {
		return (DirectionalLight)findNodeByType(directionalLightTypeName);
	}

	public ElevationGrid findElevationGrid() {
		return (ElevationGrid)findNodeByType(elevationGridTypeName);
	}

	public Extrusion findExtrusion() {
		return (Extrusion)findNodeByType(extrusionTypeName);
	}

	public Fog findFog() {
		return (Fog)findNodeByType(fogTypeName);
	}

	public FontStyle findFontStyle() {
		return (FontStyle)findNodeByType(fontStyleTypeName);
	}

	public Group findGroup() {
		return (Group)findNodeByType(groupTypeName);
	}

	public ImageTexture findImageTexture() {
		return (ImageTexture)findNodeByType(imageTextureTypeName);
	}

	public IndexedFaceSet findIndexedFaceSet() {
		return (IndexedFaceSet)findNodeByType(indexedFaceSetTypeName);
	}

	public IndexedLineSet findIndexedLineSet() {
		return (IndexedLineSet)findNodeByType(indexedLineSetTypeName);
	}

	public Inline findInline() {
		return (Inline)findNodeByType(inlineTypeName);
	}

	public LOD findLOD() {
		return (LOD)findNodeByType(lodTypeName);
	}

	public Material findMaterial() {
		return (Material)findNodeByType(materialTypeName);
	}

	public MovieTexture findMovieTexture() {
		return (MovieTexture)findNodeByType(movieTextureTypeName);
	}

	public NavigationInfo findNavigationInfo() {
		return (NavigationInfo)findNodeByType(navigationInfoTypeName);
	}

	public Normal findNormal() {
		return (Normal)findNodeByType(normalTypeName);
	}

	public NormalInterpolator findNormalInterpolator() {
		return (NormalInterpolator)findNodeByType(normalInterpolatorTypeName);
	}

	public OrientationInterpolator findOrientationInterpolator() {
		return (OrientationInterpolator)findNodeByType(orientationInterpolatorTypeName);
	}

	public PixelTexture findPixelTexture() {
		return (PixelTexture)findNodeByType(pixelTextureTypeName);
	}

	public PlaneSensor findPlaneSensor() {
		return (PlaneSensor)findNodeByType(planeSensorTypeName);
	}

	public PointLight findPointLight() {
		return (PointLight)findNodeByType(pointLightTypeName);
	}

	public PointSet findPointSet() {
		return (PointSet)findNodeByType(pointSetTypeName);
	}

	public PositionInterpolator findPositionInterpolator() {
		return (PositionInterpolator)findNodeByType(positionInterpolatorTypeName);
	}

	public ProximitySensor findProximitySensor() {
		return (ProximitySensor)findNodeByType(proximitySensorTypeName);
	}

	public ScalarInterpolator findScalarInterpolator() {
		return (ScalarInterpolator)findNodeByType(scalarInterpolatorTypeName);
	}

	public Script findScript() {
		return (Script)findNodeByType(scriptTypeName);
	}

	public Shape findShape() {
		return (Shape)findNodeByType(shapeTypeName);
	}

	public Sound findSound() {
		return (Sound)findNodeByType(soundTypeName);
	}

	public Sphere findSphere() {
		return (Sphere)findNodeByType(sphereTypeName);
	}

	public SphereSensor findSphereSensor() {
		return (SphereSensor)findNodeByType(sphereSensorTypeName);
	}

	public SpotLight findSpotLight() {
		return (SpotLight)findNodeByType(spotLightTypeName);
	}

	public Switch findSwitch() {
		return (Switch)findNodeByType(switchTypeName);
	}

	public Text findText() {
		return (Text)findNodeByType(textTypeName);
	}

	public TextureCoordinate findTextureCoordinate() {
		return (TextureCoordinate)findNodeByType(textureCoordinateTypeName);
	}

	public TextureTransform findTextureTransform() {
		return (TextureTransform)findNodeByType(textureTransformTypeName);
	}

	public TimeSensor findTimeSensor() {
		return (TimeSensor)findNodeByType(timeSensorTypeName);
	}

	public TouchSensor findTouchSensor() {
		return (TouchSensor)findNodeByType(touchSensorTypeName);
	}

	public Transform findTransform() {
		return (Transform)findNodeByType(transformTypeName);
	}

	public Viewpoint findViewpoint() {
		return (Viewpoint)findNodeByType(viewpointTypeName);
	}

	public VisibilitySensor findVisibilitySensor() {
		return (VisibilitySensor)findNodeByType(visibilitySensorTypeName);
	}

	public WorldInfo findWorldInfo() {
		return (WorldInfo)findNodeByType(worldInfoTypeName);
	}

	////////////////////////////////////////////////
	//	initialize
	////////////////////////////////////////////////

	public void initialize() {
		for (BaseNode node = getNodes(); node != null; node = node.next()) {
			node.initialize();
		}
	}

	////////////////////////////////////////////////
	//	update
	////////////////////////////////////////////////

	public void update() {
		for (BaseNode node = getNodes(); node != null; node = node.nextTraversal())
			node.update();
	}

	public void updateRoute(BaseNode eventOutNode, Field eventOutField) {
		for (Route route = getRoutes(); route != null; route = route.next()) {
			if (route.getEventOutNode() == eventOutNode && route.getEventOutField() == eventOutField) {
				route.update();
				route.getEventInNode().update();
				updateRoute(route.getEventInNode(), route.getEventInField());
			}
		}
	}

	///////////////////////////////////////////////
	//	Output node infomations
	///////////////////////////////////////////////
	
	public void print() {
		for (BaseNode node = getNodes(); node != null; node = node.next()) {
			node.print();
		}
		for (Route route = getRoutes(); route != null; route = route.next()) {
			route.output(System.out);
		}
	}

	///////////////////////////////////////////////
	//	Save infomations
	///////////////////////////////////////////////

	public void load(File file) {
		try {
			// Delete all nodes
			mParser.clearNodes();

			InputStream inputStream = new FileInputStream(file);
			mParser = new Parser(inputStream);
			mParser.Input();

			// Set SceneGraph
			for (BaseNode node = getNodes(); node != null; node = node.nextTraversal())
				node.setSceneGraph(this);
			
			initialize();
		}
		catch (FileNotFoundException e) {
			System.out.println("Couldn't load the file (" + file + ")");
		}
		catch (ParseError e) {
			System.out.println("Parse Error");
		}
	}

	public void load(String filename) {
		try {
			// Delete all nodes
			mParser.clearNodes();

			InputStream inputStream = new FileInputStream(filename);
			mParser = new Parser(inputStream);
			mParser.Input();
			
			// Set SceneGraph
			for (BaseNode node = getNodes(); node != null; node = node.nextTraversal())
				node.setSceneGraph(this);
			
			initialize();
		}
		catch (FileNotFoundException e) {
			System.out.println("Couldn't load the file (" + filename + ")");
		}
		catch (ParseError e) {
			System.out.println("Parse Error");
		}
	}

	///////////////////////////////////////////////
	//	Save infomations
	///////////////////////////////////////////////
	
	public void save(String filename) {
		try {
			FileOutputStream outputStream = new FileOutputStream(filename);
			PrintStream printStream = new PrintStream(outputStream);

			printStream.println("#VRML V2.0 utf8");

			for (BaseNode node = getNodes(); node != null; node = node.next()) {
				node.output(printStream, 0);
			}
			
			for (Route route = getRoutes(); route != null; route = route.next()) {
				route.output(printStream);
			}
			outputStream.close();
		}
		catch (IOException e) {
			System.out.println("Couldn't open the file (" + filename + ")");
		}
	}
}