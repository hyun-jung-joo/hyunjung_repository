import java.util.*;
public class A8_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		
		BankAccount b = new BankAccount();
		try {
			b.deposit(100);
			System.out.println("���� �Ա� ó��=> �Աݾ�: 100, �ܾ�: " + b.balance);
		} catch(NegativeBalanceException e) {
			e.printStackTrace();
		}
		
		try {
			b.withdraw(100);
			System.out.println("���� �Ա� ó��=> �����: 100, �ܾ�: " + b.balance);
		} catch(NegativeBalanceException e) {
			e.printStackTrace();
		}
		
		try {
			b.withdraw(100);
			System.out.println("���� �Ա� ó��=> �Աݾ�: 100, �ܾ�: " + b.balance);
		} catch(NegativeBalanceException e) {
			e.printStackTrace();
		}
	}

}
