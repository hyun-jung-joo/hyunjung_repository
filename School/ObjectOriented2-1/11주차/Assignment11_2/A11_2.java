import java.util.*;
public class A11_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Map<String, Integer> map = new HashMap<String, Integer>();
		Scanner input = new Scanner(System.in);
		String name;
		int num;
		int max = - 1;
		String maxName = null;
		
		System.out.println("���� �̸��� �α��� 3�� �Է��ϼ���. (��: Korea 5000)");
		for(int i = 1; i <= 3; i++) {
			System.out.print(i + ". ���� �̸�, �α� >> ");
			name = input.next();
			num = input.nextInt();
			map.put(name, num);
		}
		
		for(Map.Entry<String, Integer> s : map.entrySet()) {
			String key = s.getKey();
			int value = s.getValue();
			
			if(value > max) {
				max = value;
				maxName = key;
			}
		}
		System.out.println("���� �α��� ���� ����� (" + maxName + ", " + max + ")");
	}

}
