import java.util.*;
public class A1_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int num;
		int count = 1;
		double total;
		
		Scanner input = new Scanner(System.in);
		System.out.println("������ �Է��ϰ� �������� 0�� �Է��ϼ���");
		
		num = input.nextInt();
		total = num;
		while(num != 0) {
			num = input.nextInt();
			total += num;
			count++;
		}
		
		System.out.println("�Է��� ���� ����: " + (count - 1));
		System.out.println("���: " + total / (count - 1));
	}

}
