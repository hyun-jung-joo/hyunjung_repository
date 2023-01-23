
public class VIPCustomer extends Customer {
	private int agentID;
	double saleRatio;
	
	VIPCustomer() {
		customerGrade = "VIP";
		bonusRatio = 0.05;
		saleRatio = 0.1;
	}
	
	VIPCustomer (String name, int aID) {
		customerGrade = "VIP";
		bonusRatio = 0.05;
		saleRatio = 0.1;
		customerName = name;
		agentID = aID;
	}
	
	void calcPrice(int price) {
		saledPrice = (int) (price * saleRatio);
		customerPrice = (int) (price * (1 - saleRatio));
		bonusPoint = (int) (customerPrice * bonusRatio);
	}
	
	public int getAgentID() {return agentID;}
}
