
public class Member {
	private String name;
	private int age;
	
	public Member(String name, int age) {
		this.name = name;
		this.age = age;
	}
	
	public String getName() {return name;}
	
	public String toString() {
		return "�̸� : " + name + ", ���� : " + age;
	}
	
	public boolean equals(Object obj) {
		if(obj instanceof Member) {
			Member member = (Member) obj;
			return member.name.equals(name) && (member.age == age);
		}
		else
			return false;
	}
	
	//name�� age���� ������ ������ hashCode�� ����
	public int hashCode() {
		return name.hashCode() + age;
	}
}
