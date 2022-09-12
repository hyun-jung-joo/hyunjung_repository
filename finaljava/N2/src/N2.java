import java.util.*;
public class N2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Discountable p1 = new Silver(10000);
		Discountable p2 = new Gold(10000);
		Discountable p3 = new Guest(10000);
		
		System.out.print("Silver: ");
		p1.discount();
		System.out.print("Gold: ");
		p2.discount();
		System.out.print("Guest: ");
		p3.discount();
	}

}
