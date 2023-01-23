
public class BankAccount {
	int balance;
	
	BankAccount() {
		balance = 0;
	}
	
	public void withdraw(int m) throws NegativeBalanceException {
		if(balance < m) 
			throw new NegativeBalanceException("잔고 부족");
		else if(m < 0)
			throw new NegativeBalanceException("잘못된 금액");
		else
			balance -= m;
	}
	
	public void deposit(int m) throws NegativeBalanceException{
		if(m < 0)
			throw new NegativeBalanceException("음수 입금액");
		else
			balance += m;
	}
}
