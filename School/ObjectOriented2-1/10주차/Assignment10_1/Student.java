
public class Student implements Comparable<Student>{
	String name;
	int num;
	int korean;
	int english;
	int math;
	
	Student(String n, int num, int k, int e, int m) {
		this.name = n;
		this.num = num;
		this.korean = k;
		this.english = e;
		this.math = m;
	}
	
	int getTotal() {
		return korean + english + math;
	}
	
	double getAvg() {
		return (double)getTotal() / 3;
	}
	
	public int compareTo(Student stu) {
		return this.name.compareTo(stu.name);
	}
	
	public String toString() {
		return name + ", " + num + ": " + korean + ", " + english+ ", " + math + ", " + getTotal() + ", " + getAvg();
	}
}
