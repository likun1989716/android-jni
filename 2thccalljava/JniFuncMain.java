class JniTest
{
	private int b;
	//构造方法
	public JniTest(int num)
	{
		int b = num;
		System.out.println("[java]调用JniTest的构造方法");
	}
	public int callByNative(int num)
	{
		System.out.println("[java]调用callByNative得到num");
		return num;
	}
	public void callTest()
	{
		System.out.println("[java]调用callTest得到b值"+b);
	}
}
class JniFuncMain
{
	private static int a = 300;
	static {System.loadLibrary("jnifunc");}
	public static native JniTest createJniObject();
	
	public static void main(String[] args)
	{
		//调用本地方法，生成JniTest对象
		System.out.println("[java]调用createJniObject本地方法");
		JniTest jniObj = createJniObject();
		//调用JniTest对象方法
		jniObj.callTest();
	}
}
