
public class BankAccount {
	int balance;
	
	BankAccount() {
		balance = 0;
	}
	
	public void withdraw(int m) throws NegativeBalanceException {
		if(balance < m) 
			throw new NegativeBalanceException("�ܰ� ����");
		else if(m < 0)
			throw new NegativeBalanceException("�߸��� �ݾ�");
		else
			balance -= m;
	}
	
	public void deposit(int m) throws NegativeBalanceException{
		if(m < 0)
			throw new NegativeBalanceException("���� �Աݾ�");
		else
			balance += m;
	}
}
