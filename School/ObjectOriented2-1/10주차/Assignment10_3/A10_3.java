import java.util.*;

public class A10_3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		
		TreeSet<String> names = new TreeSet<>(Collections.reverseOrder());
		
		System.out.println("3���� �̸��� �Է� : ");
		for(int i = 0; i < 3; i++) {
			String name = input.nextLine();
			Member m = new Member(name);
			names.add(m.getName());
		}
		
		System.out.println(names);
	}

}
