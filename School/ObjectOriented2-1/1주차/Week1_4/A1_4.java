import java.lang.Integer;
import java.util.*;
public class A1_4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		String hex;
		int tmp;
		int a;
		
		System.out.print("16���� �� ���� �Է� : ");
		hex = input.nextLine();
		tmp = (int)hex.charAt(0);
		if(tmp <= 101) {
			a = Integer.valueOf(hex , 16);
			System.out.println("10���� ==> " + a);
		}
		else
			System.out.println("16������ �ƴ�");
	}

}
