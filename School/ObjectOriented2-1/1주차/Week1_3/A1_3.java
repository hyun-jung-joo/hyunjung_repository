import java.util.*;
public class A1_3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a;
		int b;
		int c;
		int d;
		int total;
		
		Scanner input = new Scanner(System.in);
		
		System.out.print("500원 동전 개수 : ");
		a = input.nextInt();
		System.out.print("100원 동전 개수 : ");
		b = input.nextInt();
		System.out.print("50원 동전 개수 : ");
		c = input.nextInt();
		System.out.print("10원 동전 개수 : ");
		d = input.nextInt();
		
		total = a * 500 + b * 100 + c * 50 + d * 10;
		
		System.out.println("금액은 " + total + "원 입니다.");
	}

}
