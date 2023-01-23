
public class Customer {
	protected String customerName;
	protected String customerGrade;
	int bonusPoint;
	double bonusRatio;
	int saledPrice = 0;
	int customerPrice;
	
	Customer() {
		customerGrade = "SILVER";
		bonusRatio = 0.01;
	}
	
	Customer(String name) {
		customerGrade = "SILVER";
		bonusRatio = 0.01;
		customerName = name;
	}
	
	void calcPrice(int price) {
		customerPrice = price;
		bonusPoint = (int)(price * bonusRatio);
	}
	
	void showCustomerInfo() {
		System.out.println(customerName + "님의 할인금액은 " + saledPrice + "원, 지불금액은 "
				+ customerPrice + "원입니다.\n" + "적립되는 보너스포인트는 " + bonusPoint
				+ "원입니다.");
	}
	
	public void setId(String n) {customerName = n;}
	public String getId() {return customerName;}
	public void setGrade(String g) {customerGrade = g;}
	public String getGrade() {return customerGrade;}
	public void setPoint(int p) {bonusPoint = p;}
	public int getPoint() {return bonusPoint;}
} 
