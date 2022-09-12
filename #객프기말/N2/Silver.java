
public class Silver extends Customer{
	Silver(int price) {
		super(price);
	}
	
	public void discount() {
		int num = (int) (price * 0.95);
		
		System.out.println(num);
	}
 }
