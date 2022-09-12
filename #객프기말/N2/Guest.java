
public class Guest extends Customer{
	Guest(int price) {
		super(price);
	}
	
	public void discount() {
		System.out.println(price);
	}
}
