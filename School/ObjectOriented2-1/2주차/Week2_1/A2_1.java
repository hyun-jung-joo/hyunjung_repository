import java.util.*;
public class A2_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int [] num = new int[5];
		double total = 0; 
		String [] name = new String[5];
		
		Scanner input = new Scanner(System.in);
		
		System.out.print("������ �Է��ϼ��� : ");
		for(int i = 0; i < 5; i++) {
			num[i] = input.nextInt();
			total += num[i];
		}
		System.out.println("���� " + total);
		
		System.out.print("�̸��� �Է��ϼ��� : ");
		for(int i = 0; i < 5; i++) 
			name[i] = input.next();
		System.out.print("�Էµ� �̸��� ");
		for(String e : name)
			System.out.print(e + " ");
	}

}
