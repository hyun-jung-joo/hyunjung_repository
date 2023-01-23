import java.util.*;
public class A10_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int count = 0;
		Set<Member> set = new HashSet<Member>();
		
		set.add(new Member("이길동", 30));
		set.add(new Member("홍길동", 30));
		
		System.out.println("총 객체수 : " + set.size());
		
		Iterator e = set.iterator();
		while(e.hasNext()) {
			Member m = (Member)e.next();
			System.out.println(m.toString());
		}
		
		System.out.println("찾는 이름을 입력 : ");
		String key = input.next();
	
		Iterator e2 = set.iterator();
		while(e2.hasNext()) {
			Member m = (Member)e2.next();
			if(m.getName().equals(key)) {
				System.out.println("찾는 데이터가 있다");
				System.out.print("삭제하려는 이름 입력 : ");
				String newKey = input.next();
				set.remove(m);
				System.out.println(newKey + " 회원이 삭제됨");
				break;
			}
			count++;
		}
		
		if(count >= 2) 
			System.out.println("찾는 데이터가 없다");
	}

}
