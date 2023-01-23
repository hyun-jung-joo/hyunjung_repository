
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
		System.out.println(customerName + "���� ���αݾ��� " + saledPrice + "��, ���ұݾ��� "
				+ customerPrice + "���Դϴ�.\n" + "�����Ǵ� ���ʽ�����Ʈ�� " + bonusPoint
				+ "���Դϴ�.");
	}
	
	public void setId(String n) {customerName = n;}
	public String getId() {return customerName;}
	public void setGrade(String g) {customerGrade = g;}
	public String getGrade() {return customerGrade;}
	public void setPoint(int p) {bonusPoint = p;}
	public int getPoint() {return bonusPoint;}
} 
