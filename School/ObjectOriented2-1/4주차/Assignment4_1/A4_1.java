import java.util.*;
public class A4_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student [] students;
		
		Scanner input = new Scanner(System.in);
		
		System.out.print("배열의 크기는>>");
		int num = input.nextInt();
		input.nextLine();
		
		students = new Student[num];
		for(int i = 0; i < students.length; i++) {
			System.out.print("학번>>");
			int s_n = input.nextInt();
			System.out.print("이름>>");
			String name = input.next();
			students[i] = new Student(name, s_n);
		}
		
		Arrays.sort(students);
		for(Student s: students)
			System.out.println("학번 =" + s.getNum() + ", 이름 = " + s.getName());
	}

}
