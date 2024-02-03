package vrml;

public abstract class Field implements Cloneable, Constants {

	private String	mName = null;
	private int		mType = 0;

	public void setType(int type) {
		mType = type;
	}

	public int getType() {
		return mType;
	}

	public String getTypeName() {
		switch (getType()) {
		// Field
		case fieldTypeSFBool		: return "SFBool";
		case fieldTypeSFColor		: return "SFColor";
		case fieldTypeSFFloat		: return "SFFloat";
		case fieldTypeSFInt32		: return "SFInt32";
		case fieldTypeSFRotation	: return "SFRotation";
		case fieldTypeSFString		: return "SFString";
		case fieldTypeSFTime		: return "SFTime";
	  	case fieldTypeSFVec2f		: return "SFVec2f";
	  	case fieldTypeSFVec3f		: return "SFVec3f";
	  	case fieldTypeSFNode		: return "SFNode";
		case fieldTypeMFBool		: return "MFBool";
		case fieldTypeMFColor		: return "MFColor";
		case fieldTypeMFFloat		: return "MFFloat";
		case fieldTypeMFInt32		: return "MFInt32";
		case fieldTypeMFRotation	: return "MFRotation";
		case fieldTypeMFString		: return "MFString";
		case fieldTypeMFTime		: return "MFTime";
	  	case fieldTypeMFVec2f		: return "MFVec2f";
	  	case fieldTypeMFVec3f		: return "MFVec3f";
	  	case fieldTypeMFNode		: return "MFNode";
		// ConstField
		case fieldTypeConstSFBool		: return "ConstSFBool";
		case fieldTypeConstSFColor		: return "ConstSFColor";
		case fieldTypeConstSFFloat		: return "ConstSFFloat";
		case fieldTypeConstSFInt32		: return "ConstSFInt32";
		case fieldTypeConstSFRotation	: return "ConstSFRotation";
		case fieldTypeConstSFString		: return "ConstSFString";
		case fieldTypeConstSFTime		: return "ConstSFTime";
	  	case fieldTypeConstSFVec2f		: return "ConstSFVec2f";
	  	case fieldTypeConstSFVec3f		: return "ConstSFVec3f";
	  	case fieldTypeConstSFNode		: return "ConstSFNode";
		case fieldTypeConstMFBool		: return "ConstMFBool";
		case fieldTypeConstMFColor		: return "ConstMFColor";
		case fieldTypeConstMFFloat		: return "ConstMFFloat";
		case fieldTypeConstMFInt32		: return "ConstMFInt32";
		case fieldTypeConstMFRotation	: return "ConstMFRotation";
		case fieldTypeConstMFString		: return "ConstMFString";
		case fieldTypeConstMFTime		: return "ConstMFTime";
	  	case fieldTypeConstMFVec2f		: return "ConstMFVec2f";
	  	case fieldTypeConstMFVec3f		: return "ConstMFVec3f";
	  	case fieldTypeConstMFNode		: return "ConstMFNode";
		default:
			System.out.println("Unknown field type : " + getType());
		}
		return null;
	}

	public void setName(String name) {
		mName = name;	
	}

	public String getName() {
		return mName;
	}

	abstract public String toString();
}
