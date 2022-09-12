
public class Gold extends Customer{
	Gold(int price) {
		super(price);
	}
	
	public void discount() {
		int num = (int) (price * 0.9);
		
		System.out.println(num);
	}
}
