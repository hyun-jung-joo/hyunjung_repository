import java.util.*;

public class A9_4 {

	static <T> void a(T a) {
		System.out.println(a.getClass().getName());
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int num1;
		float num2;
		
		System.out.print("������ �Է��ϼ���>> ");
		num1 = input.nextInt();
		System.out.print("�Ǽ��� �Է��ϼ���>> ");
		num2 = input.nextFloat();
		
		System.out.print(num1 + "�� Ŭ���� �̸� : ");
		a(num1);
		System.out.print(num2 + "�� Ŭ���� �̸� : ");
		a(num2);
	}

}
