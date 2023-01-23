import java.util.*;
public class A2_4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a, b, c, d, e;
		Scanner input = new Scanner(System.in);
		
		Average obj1 = new Average();
		Average obj2 = new Average();
		
		System.out.print("두 수를 입력하세요");
		a = input.nextInt();
		b = input.nextInt();
		
		System.out.print("세 수를 입력하세요");
		c = input.nextInt();
		d = input.nextInt();
		e = input.nextInt();
		
		System.out.println("두수의 평균 : " + obj1.getAverage(a, b));
		System.out.println("세수의 평균 : " + obj2.getAverage(c, d, e));
	}

}
