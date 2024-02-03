package vrml.node;

import java.lang.ClassLoader;

public class ScriptClassLoader extends ClassLoader {
	public synchronized Class  loadClass(String  name, boolean resolve) throws ClassNotFoundException {
		Class c = findSystemClass(name);
		if (resolve)
			resolveClass(c);
		return c;
	}
}