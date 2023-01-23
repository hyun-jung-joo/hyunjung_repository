
public class Member {
	private String name;
	private int age;
	
	public Member(String name, int age) {
		this.name = name;
		this.age = age;
	}
	
	public String getName() {return name;}
	
	public String toString() {
		return "이름 : " + name + ", 나이 : " + age;
	}
	
	public boolean equals(Object obj) {
		if(obj instanceof Member) {
			Member member = (Member) obj;
			return member.name.equals(name) && (member.age == age);
		}
		else
			return false;
	}
	
	//name와 age값이 같으면 동일한 hashCode가 리턴
	public int hashCode() {
		return name.hashCode() + age;
	}
}
