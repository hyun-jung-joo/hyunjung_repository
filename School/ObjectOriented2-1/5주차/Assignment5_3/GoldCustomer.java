
public class GoldCustomer extends Customer{
	double saleRatio;
	
	GoldCustomer() {
		customerGrade = "Gold";
		bonusRatio = 0.05;
		saleRatio = 0.1;
	}
	
	GoldCustomer(String name) {
		customerGrade = "Gold";
		bonusRatio = 0.02;
		saleRatio = 0.1;
		customerName = name;
	}
	
	void calcPrice(int price) {
		saledPrice = (int) (price * saleRatio);
		customerPrice = (int) (price * (1 - saleRatio));
		bonusPoint = (int) (customerPrice * bonusRatio);
	}
}
