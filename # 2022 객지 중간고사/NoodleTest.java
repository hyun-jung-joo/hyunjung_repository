import java.util.*;
public class NoodleTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		
		ArrayList <Noodle> list = new ArrayList<Noodle>(); 
		System.out.print("�ֹ��� ������ ���� : ");
		int num = input.nextInt();
		
		System.out.print("[Į����(7000), �ø�(11000), �̸�(8000), ���(4000), �ұ���(10000)]����"
				+ " ���� 3���� �Է� : ");
		
		for(int i = 0; i < num; i++) {
			String food = input.next();
			list.add(new Noodle(food));
			list.get(i).getTotalPrice();
		}
		
		System.out.println("�ֹ��� ������ �ѱݾ� : " + list.get(num - 1).getTotalPrice());
	}

}
