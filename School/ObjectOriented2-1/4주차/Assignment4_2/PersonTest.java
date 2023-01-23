import java.lang.reflect.Array;

public class PersonTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Person [] array = new Person[3];
		array[0] = new Person("홍길동", 180);
		array[1] = new Person("이길동", 170);
		array[2] = new Person("김길동", 190);
		
		int key = getMax(array);
		System.out.println("[제일 키 큰 사람]");
		System.out.println("이름 : " + array[key].getName() + ", height : " + array[key].getHeight());
	}
	
	static int getMax(Person [] a) {
		int max = 0;
		for(int i = 0; i < a.length; i++) {
			if(a[max].compareTo(a[i]) == -1)
				max = i;
		}
		return max;
	}
}
