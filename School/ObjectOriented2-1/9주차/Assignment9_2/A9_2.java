import java.util.*;

public class A9_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		String str;
		
		System.out.println("���ٷ� ������ �Է��ϼ���. (����� exit�� �Է�) >> ");
		str = input.nextLine();
		while(!str.equals("exit")) {
			StringTokenizer st = new StringTokenizer(str);
			System.out.println("���� ������ " + st.countTokens());
			System.out.println("������ ������ " + (st.countTokens() - 1));
			
			System.out.println("���ٷ� ������ �Է��ϼ���. (����� exit�� �Է�) >> ");
			str = input.nextLine();
		}
		System.out.println("�����մϴ�...");
	}

}
