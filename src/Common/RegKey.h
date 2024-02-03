#ifndef _REG_KEY_H_
#define _REG_KEY_H_

#include "common.h"

#define REGKEY_ROOT_NAME					"Software\\CyberGarage\\CyberToolBox"
									
#define REGKEY_SECTION_PATHNAME				"PathName"
#define REGKEY_SECTION_POSITION				"Position"
#define REGKEY_SECTION_LICENCE				"Licence"

#define REGKEY_KEY_INSTALLDIR_PATHNAME		"InstallDir"
#define REGKEY_KEY_LIB_PATHNAME				"Lib"
#define REGKEY_KEY_SCRIPTS_PATHNAME			"Scripts"
#define REGKEY_KEY_MODULES_PATHNAME			"Modules"
#define REGKEY_KEY_ICONS_PATHNAME			"Icons"
#define REGKEY_KEY_MODELS_PATHNAME			"Models"

#define REGKEY_KEY_POSITION_SCENEGRAPH		"SceneGraph"
#define REGKEY_KEY_POSITION_PERSPECTIVEVIEW	"PerspectiveView"
#define REGKEY_KEY_POSITION_DIAGRAMMODULE	"DiagramModule"
#define REGKEY_KEY_POSITION_ORTHOVIEW		"OrthoView"

#define REGKEY_KEY_SOFTWARE_PRODUCT_ID		"SoftwareProductID"
#define REGKEY_KEY_LICENCE_CODE				"LicenceCode"

BOOL RegKeyWriteValue(char *section, char *key, long value);
BOOL RegKeyWriteValue(char *section, char *key, char *value);
BOOL RegKeyWriteValue(char *section, char *key, int value1, int value2);
BOOL RegKeyWriteValue(char *section, char *key, int value1, int value2, int value3, int value4);

BOOL RegKeyGetValue(char *section, char *key, long *value);
BOOL RegKeyGetValue(char *section, char *key, char *value);
BOOL RegKeyGetValue(char *section, char *key, int *value1, int *value2);
BOOL RegKeyGetValue(char *section, char *key, int *value1, int *value2, int *value3, int *value4);

#endif
