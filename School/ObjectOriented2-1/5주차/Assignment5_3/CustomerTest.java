import java.util.*;
public class CustomerTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		ArrayList<Customer> list = new ArrayList<Customer>();
		
		System.out.println(">> ���� �����? (s/v/g)");
		char level = input.next().charAt(0);
		System.out.println(">> ���� �̸���?");
		String name = input.next();
		System.out.println(">> ������ ������?");
		int price = input.nextInt();
	
		switch (level) {
		case 's' :
			Customer s = new Customer(name);
			s.calcPrice(price);
			s.showCustomerInfo();
			break;
		case 'v' :
			Customer v = new VIPCustomer(name, 10000);
			v.calcPrice(price);
			v.showCustomerInfo();
			break;
		case 'g' :
			Customer g = new GoldCustomer(name);
			g.calcPrice(price);
			g.showCustomerInfo();
			break;
		}
		
	
		
	}

}
