import java.util.*;
public class A1_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s;
		int tmp;
		Scanner input = new Scanner(System.in);
		
		System.out.print("���ڸ� �Է��ϼ��� : ");
		s = input.next();
		tmp = (int)s.charAt(0);
		while (tmp != 48) {
			if((65 <= tmp) && (tmp <= 90))
				System.out.println((char)(tmp + 32));
			else if((97 <= tmp) && (tmp <= 122))
				System.out.println((char)(tmp - 32));
			else
				System.out.println("�����ڰ� �ƴմϴ�.");
			
			System.out.print("���ڸ� �Է��ϼ��� : ");
			s = input.next();
			tmp = (int)s.charAt(0);
		}
	}

}
