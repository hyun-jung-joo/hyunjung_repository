
public class Member implements Comparable<Member> {
	String name;
	
	Member(String n) {
		name = n;
	}
	
	public int compareTo(Member stu) {
		return this.name.compareTo(stu.name);
	}
	
	public String getName() {
		return name;
	}
}
