import java.util.*;

public class A9_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		String str;
		
		System.out.println("한줄로 문장을 입력하세요. (종료는 exit을 입력) >> ");
		str = input.nextLine();
		while(!str.equals("exit")) {
			StringTokenizer st = new StringTokenizer(str);
			System.out.println("어절 개수는 " + st.countTokens());
			System.out.println("공백의 개수는 " + (st.countTokens() - 1));
			
			System.out.println("한줄로 문장을 입력하세요. (종료는 exit을 입력) >> ");
			str = input.nextLine();
		}
		System.out.println("종료합니다...");
	}

}
