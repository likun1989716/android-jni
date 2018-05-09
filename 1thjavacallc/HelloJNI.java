class HelloJNI
{
	native void printHello();
	native void printString(String str);
	
	static { System.loadLibrary("hellojni\n"); }
	public static void main(String args[])
	{
		HelloJNI myJNI = new HelloJNI();
		myJNI.printHello();
		myJNI.printString("Hello Word from printString fun\n");
		//System.out.println(System.getProperty("java.library.path"));
	}
}
