import java.util.*;
public class A2_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String number;
		char keynum;
		String c;
		
		Scanner input = new Scanner(System.in);
		
		while(true) {
			System.out.print("당신의 주민번호를 입력하세요.  (012345-1234567) >> ");
			number = input.next();
			
			keynum = number.charAt(7);
			
			if(keynum == '1' || keynum == '3')
				System.out.println("당신은 남자입니다.");
			else if(keynum == '2' || keynum == '4')
				System.out.println("당신은 여자입니다.");
			else
				System.out.println("유효하지 않은 주민번호입니다.");
			
			System.out.print("입력을 계속하겠습니까?  (y/n)");
			c = input.next();
			
			if(c.equals("n"))
				break;
		}
	}

}
