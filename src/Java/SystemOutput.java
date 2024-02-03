/*----------------------------------------------------------------
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	SystemCTB.java
*
----------------------------------------------------------------*/
import java.io.OutputStream;
import java.io.PrintStream;

public class SystemOutput extends OutputStream {
	private native void createJavaConsole();
	private native void output(int b);
	private native void output(String string);
	private native void deleteJavaConsole();

	SystemOutput() {
		createJavaConsole();
		PrintStream pstream = new PrintStream(this);
		System.setOut(pstream);
		System.setErr(pstream);
	}

	public void delete() {
		System.setOut(System.out);
		System.setErr(System.err);
		deleteJavaConsole();
	}

	public void write(int b) {
		output(b);
	}

	static {
		System.loadLibrary("SystemOutput");
	}
}
