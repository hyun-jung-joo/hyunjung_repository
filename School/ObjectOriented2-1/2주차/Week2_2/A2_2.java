import java.util.*;
public class A2_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String number;
		char keynum;
		String c;
		
		Scanner input = new Scanner(System.in);
		
		while(true) {
			System.out.print("����� �ֹι�ȣ�� �Է��ϼ���.  (012345-1234567) >> ");
			number = input.next();
			
			keynum = number.charAt(7);
			
			if(keynum == '1' || keynum == '3')
				System.out.println("����� �����Դϴ�.");
			else if(keynum == '2' || keynum == '4')
				System.out.println("����� �����Դϴ�.");
			else
				System.out.println("��ȿ���� ���� �ֹι�ȣ�Դϴ�.");
			
			System.out.print("�Է��� ����ϰڽ��ϱ�?  (y/n)");
			c = input.next();
			
			if(c.equals("n"))
				break;
		}
	}

}
