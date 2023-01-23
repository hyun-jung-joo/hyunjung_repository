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
		
		System.out.print("정수를 입력하세요>> ");
		num1 = input.nextInt();
		System.out.print("실수를 입력하세요>> ");
		num2 = input.nextFloat();
		
		System.out.print(num1 + "의 클래스 이름 : ");
		a(num1);
		System.out.print(num2 + "의 클래스 이름 : ");
		a(num2);
	}

}
