import java.util.*;
public class A11_3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Map<String, String> map = new HashMap<String, String>();
		Scanner input = new Scanner(System.in);
		String name;
		String phoneNum;
		int num;
		String str;
		
		System.out.print("�Է��Ϸ��� �������� ���� : ");
		num = input.nextInt();
		System.out.println("�̸��� ��ȭ��ȣ�� �Է��ϼ���. (��: ȫ�浿 010-111-1212)");
		for(int i = 1; i <= num; i++) {
			System.out.print(i + ". �̸�, ��ȭ��ȣ>> ");
			name = input.next();
			phoneNum = input.next();
			map.put(name, phoneNum);
		}
		
		System.out.print("��ȭ��ȣ�� ã������ ȸ���� �̸��� : ");
		str = input.next();
		
		int flag = 1;
		for(Map.Entry<String, String> s : map.entrySet()) {
			String key = s.getKey();
			String value = s.getValue();
			
			if(str.equals(key)) {
				System.out.println(key + "�� ��ȭ��ȣ�� : " + value);
				flag = 0;
			}
		}
		if(flag == 1)
			System.out.println("�ش��ϴ� �̸��� ȸ���� ����Ʈ�� �����ϴ�.");
	}
	

}
