
public abstract class Calc {
	int x;
	int y;
	
	public Calc(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public abstract int calculate();
}
