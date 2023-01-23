import java.util.*;
public class A1_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s;
		int tmp;
		Scanner input = new Scanner(System.in);
		
		System.out.print("문자를 입력하세요 : ");
		s = input.next();
		tmp = (int)s.charAt(0);
		while (tmp != 48) {
			if((65 <= tmp) && (tmp <= 90))
				System.out.println((char)(tmp + 32));
			else if((97 <= tmp) && (tmp <= 122))
				System.out.println((char)(tmp - 32));
			else
				System.out.println("영문자가 아닙니다.");
			
			System.out.print("문자를 입력하세요 : ");
			s = input.next();
			tmp = (int)s.charAt(0);
		}
	}

}
