import java.util.*;
public class A10_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Student> list = new ArrayList<Student>();
		
		list.add(new Student("ȫ�浿", 1, 100, 100, 100));
		list.add(new Student("���߱�", 2, 90, 60, 80));
		list.add(new Student("���ڹ�", 3, 70, 80, 75));
		list.add(new Student("���ڹ�", 4, 80, 75, 90));
		list.add(new Student("���ڹ�", 5, 90, 60, 100));
		
		Collections.sort(list);
		
		Iterator e = list.iterator();
		while(e.hasNext()) {
			Student s = (Student)e.next();
			System.out.println(s.toString());
		}
	}

}
