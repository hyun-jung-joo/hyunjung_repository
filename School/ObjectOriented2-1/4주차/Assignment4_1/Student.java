
public class Student implements Comparable {
	private String name;
	private int student_num;
	
	public Student(String n, int sn) {
		name = n;
		student_num = sn;
	}
	
	public String getName() {return name;}
	public int getNum() {return student_num;}
	
	public int compareTo(Object obj) {
		Student other = (Student) obj;
		if(student_num < other.student_num)
			return -1;
		else if(student_num > other.student_num)
			return 1;
		else
			return 0;
	}
}
