import java.util.*;
public class A8_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		
		BankAccount b = new BankAccount();
		try {
			b.deposit(100);
			System.out.println("정상 입금 처리=> 입금액: 100, 잔액: " + b.balance);
		} catch(NegativeBalanceException e) {
			e.printStackTrace();
		}
		
		try {
			b.withdraw(100);
			System.out.println("정상 입금 처리=> 입출액: 100, 잔액: " + b.balance);
		} catch(NegativeBalanceException e) {
			e.printStackTrace();
		}
		
		try {
			b.withdraw(100);
			System.out.println("정상 입금 처리=> 입금액: 100, 잔액: " + b.balance);
		} catch(NegativeBalanceException e) {
			e.printStackTrace();
		}
	}

}
