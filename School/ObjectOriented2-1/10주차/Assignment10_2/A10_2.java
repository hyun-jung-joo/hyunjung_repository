import java.util.*;
public class A10_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int count = 0;
		Set<Member> set = new HashSet<Member>();
		
		set.add(new Member("�̱浿", 30));
		set.add(new Member("ȫ�浿", 30));
		
		System.out.println("�� ��ü�� : " + set.size());
		
		Iterator e = set.iterator();
		while(e.hasNext()) {
			Member m = (Member)e.next();
			System.out.println(m.toString());
		}
		
		System.out.println("ã�� �̸��� �Է� : ");
		String key = input.next();
	
		Iterator e2 = set.iterator();
		while(e2.hasNext()) {
			Member m = (Member)e2.next();
			if(m.getName().equals(key)) {
				System.out.println("ã�� �����Ͱ� �ִ�");
				System.out.print("�����Ϸ��� �̸� �Է� : ");
				String newKey = input.next();
				set.remove(m);
				System.out.println(newKey + " ȸ���� ������");
				break;
			}
			count++;
		}
		
		if(count >= 2) 
			System.out.println("ã�� �����Ͱ� ����");
	}

}
