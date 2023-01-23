import java.util.*;
public class A2_6 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		Phone p1 = new Phone();
		Phone p2 = new Phone();
		
		System.out.print("이름, 전화번호를 입력하세요. >> ");
		String name = input.next();
		String tel = input.next();
		p1.setName(name);
		p1.setTel(tel);
		System.out.println(p1.getName() + "의 번호는 " + p1.getTel());
		
		System.out.print("이름, 전화번호를 입력하세요. >> ");
		String name2 = input.next();
		String tel2 = input.next();
		p2.setName(name2);
		p2.setTel(tel2);
		System.out.println(p2.getName() + "의 번호는 " + p2.getTel());
	}

}
