import java.util.InputMismatchException;
import java.util.*;
public class A8_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		char [] day = {'일', '월', '화', '수', '목', '금', '토'};
		int key;
		
		while(true) {
			System.out.print("정수를 입력하세요>>");
			try {
				key = input.nextInt();
				if(key < 0)
					break;
				System.out.println(day[key]);
			} 
			catch(InputMismatchException i) {
				System.out.println("경고! 수를 입력하지 않았습니다.");
				input.nextLine();
			}
		}
		System.out.println("프로그램 종료합니다...");
	}

}
