import java.lang.reflect.Array;

public class PersonTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Person [] array = new Person[3];
		array[0] = new Person("ȫ�浿", 180);
		array[1] = new Person("�̱浿", 170);
		array[2] = new Person("��浿", 190);
		
		int key = getMax(array);
		System.out.println("[���� Ű ū ���]");
		System.out.println("�̸� : " + array[key].getName() + ", height : " + array[key].getHeight());
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
