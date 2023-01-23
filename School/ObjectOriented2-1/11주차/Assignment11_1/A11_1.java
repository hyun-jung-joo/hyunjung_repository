import java.util.*;
public class A11_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str;
		Scanner input = new Scanner(System.in);
		Map<String, String> map = new HashMap<String, String>();
		
		map.put("java", "자바");
		map.put("school", "학교");
		map.put("map", "지도");
		
		System.out.println("*** keySet() ***");
		for(String key : map.keySet())
			System.out.println(String.format(" 단어 : %s, 의미 : %s", key, map.get(key)));
		
		System.out.println("*** entrySet() ***");
		for(Map.Entry<String, String> entry : map.entrySet()) 
			System.out.println(String.format("(%s, %s)", entry.getKey(), entry.getValue()));
	
		System.out.println();
		while(true) {
			System.out.print("찾고 싶은 단어 : ");
			str = input.next();
			if(str.equals("quit")) {
				System.out.println("프로그램 종료");
				break;
			}
			
			int flag = 1;
			for(Map.Entry<String, String> s : map.entrySet()) {
				String key = s.getKey();
				String value = s.getValue();
				
				if(str.equals(key)) {
					System.out.println("단어 의미는 " + value);
					flag = 0;
				}
			}
			if(flag == 1)
				System.out.println("찾는 단어가 없습니다.");
		}
	}	
}
