import java.util.*;
public class A2_3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i;
		int num;
		int count = 0;
		int total = 0;
		
		System.out.println("random() ���� �߻��� �� : ");
		for(i = 0; i < 100; i++) {
			num = (int)(Math.random()*100 + 1);
			total += num;
			System.out.printf("%2d  ", num);
			count++;
			
			if(count % 10 == 0)
				System.out.println("");
		}
		System.out.println("�հ� :" + total);	
		System.out.println("��� :" + (double)total / 100);
	}

}
