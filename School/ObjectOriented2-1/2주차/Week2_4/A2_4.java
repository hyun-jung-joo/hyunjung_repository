import java.util.*;
public class A2_4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a, b, c, d, e;
		Scanner input = new Scanner(System.in);
		
		Average obj1 = new Average();
		Average obj2 = new Average();
		
		System.out.print("�� ���� �Է��ϼ���");
		a = input.nextInt();
		b = input.nextInt();
		
		System.out.print("�� ���� �Է��ϼ���");
		c = input.nextInt();
		d = input.nextInt();
		e = input.nextInt();
		
		System.out.println("�μ��� ��� : " + obj1.getAverage(a, b));
		System.out.println("������ ��� : " + obj2.getAverage(c, d, e));
	}

}
