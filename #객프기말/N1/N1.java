import java.util.*;
public class N1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int num1;
		int num2;
		String math;
		Calc cal;
		
		Scanner sc = new Scanner(System.in);
		
		System.out.print("�� ������ �����ڸ� �Է��Ͻÿ�.(ex. 80 4 /)");
		num1 = sc.nextInt();
		num2 = sc.nextInt();
		math = sc.next();
		
		if(math.equals("+")) {
			cal = new Add(num1, num2);
			System.out.println(cal.calculate());
		}
		else if(math.equals("-")) {
			cal = new Sub(num1, num2);
			System.out.println(cal.calculate());
		}
		else if(math.equals("*")) {
			cal = new Mul(num1, num2);
			System.out.println(cal.calculate());
		}
		else if(math.equals("/")) {
			cal = new Div(num1, num2);
			System.out.println(cal.calculate());
		}
		else
			System.out.println("�߸��� �������Դϴ�.");
		
	}

}
