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
		
		System.out.print("입력하려는 데이터의 수는 : ");
		num = input.nextInt();
		System.out.println("이름과 전화번호를 입력하세요. (예: 홍길동 010-111-1212)");
		for(int i = 1; i <= num; i++) {
			System.out.print(i + ". 이름, 전화번호>> ");
			name = input.next();
			phoneNum = input.next();
			map.put(name, phoneNum);
		}
		
		System.out.print("전화번호를 찾으려는 회원의 이름은 : ");
		str = input.next();
		
		int flag = 1;
		for(Map.Entry<String, String> s : map.entrySet()) {
			String key = s.getKey();
			String value = s.getValue();
			
			if(str.equals(key)) {
				System.out.println(key + "의 전화번호는 : " + value);
				flag = 0;
			}
		}
		if(flag == 1)
			System.out.println("해당하는 이름의 회원은 리스트에 없습니다.");
	}
	

}
