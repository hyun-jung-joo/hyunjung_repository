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
		
		System.out.println("나라 이름과 인구를 3개 입력하세요. (예: Korea 5000)");
		for(int i = 1; i <= 3; i++) {
			System.out.print(i + ". 나라 이름, 인구 >> ");
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
		System.out.println("제일 인구가 많은 나라는 (" + maxName + ", " + max + ")");
	}

}
