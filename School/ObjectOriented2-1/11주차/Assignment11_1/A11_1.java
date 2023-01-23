import java.util.*;
public class A11_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str;
		Scanner input = new Scanner(System.in);
		Map<String, String> map = new HashMap<String, String>();
		
		map.put("java", "�ڹ�");
		map.put("school", "�б�");
		map.put("map", "����");
		
		System.out.println("*** keySet() ***");
		for(String key : map.keySet())
			System.out.println(String.format(" �ܾ� : %s, �ǹ� : %s", key, map.get(key)));
		
		System.out.println("*** entrySet() ***");
		for(Map.Entry<String, String> entry : map.entrySet()) 
			System.out.println(String.format("(%s, %s)", entry.getKey(), entry.getValue()));
	
		System.out.println();
		while(true) {
			System.out.print("ã�� ���� �ܾ� : ");
			str = input.next();
			if(str.equals("quit")) {
				System.out.println("���α׷� ����");
				break;
			}
			
			int flag = 1;
			for(Map.Entry<String, String> s : map.entrySet()) {
				String key = s.getKey();
				String value = s.getValue();
				
				if(str.equals(key)) {
					System.out.println("�ܾ� �ǹ̴� " + value);
					flag = 0;
				}
			}
			if(flag == 1)
				System.out.println("ã�� �ܾ �����ϴ�.");
		}
	}	
}
