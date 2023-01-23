import java.util.*;
public class A2_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int [] num = new int[5];
		double total = 0; 
		String [] name = new String[5];
		
		Scanner input = new Scanner(System.in);
		
		System.out.print("정수를 입력하세요 : ");
		for(int i = 0; i < 5; i++) {
			num[i] = input.nextInt();
			total += num[i];
		}
		System.out.println("합은 " + total);
		
		System.out.print("이름을 입력하세요 : ");
		for(int i = 0; i < 5; i++) 
			name[i] = input.next();
		System.out.print("입력된 이름은 ");
		for(String e : name)
			System.out.print(e + " ");
	}

}
