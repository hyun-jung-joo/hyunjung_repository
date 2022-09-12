
public class Poliy {
	private void f() {
		System.out.println("base class");
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Poliy po = new Derived();
		po.f();
	}

}
