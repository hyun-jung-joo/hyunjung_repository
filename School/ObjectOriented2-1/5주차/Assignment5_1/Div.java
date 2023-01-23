
public class Div extends Calc{
	int a, b;
	void setValue(int a, int b) {
		this.a = a;
		this.b = b;
	}
	
	int calculate() {
		return a / b;
	}
}
