import java.util.*;
public class A2_3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i;
		int num;
		int count = 0;
		int total = 0;
		
		System.out.println("random() 으로 발생한 수 : ");
		for(i = 0; i < 100; i++) {
			num = (int)(Math.random()*100 + 1);
			total += num;
			System.out.printf("%2d  ", num);
			count++;
			
			if(count % 10 == 0)
				System.out.println("");
		}
		System.out.println("합계 :" + total);	
		System.out.println("평균 :" + (double)total / 100);
	}

}
