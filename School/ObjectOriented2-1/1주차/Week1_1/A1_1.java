import java.util.*;
public class A1_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int num;
		int count = 1;
		double total;
		
		Scanner input = new Scanner(System.in);
		System.out.println("정수를 입력하고 마지막에 0을 입력하세요");
		
		num = input.nextInt();
		total = num;
		while(num != 0) {
			num = input.nextInt();
			total += num;
			count++;
		}
		
		System.out.println("입력한 수의 개수: " + (count - 1));
		System.out.println("평균: " + total / (count - 1));
	}

}
