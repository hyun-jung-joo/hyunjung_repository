import java.util.*;
public class A3_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int num;
		int i;
		
		Scanner input = new Scanner(System.in);
		System.out.print("å�� �Ǽ�>>");
		num = input.nextInt();
		Book[] list = new Book[num];
		input.nextLine();

		for(i = 0; i < list.length; i++) {
			System.out.print("����>>");
			String title = input.nextLine();
			System.out.print("����>>");
			String writer = input.nextLine();
			list[i] = new Book(title, writer);
		}
		for(i = 0; i < num; i++) {
			System.out.println(list[i].toString());
		}
		System.out.println("");
		
		System.out.print("ã������ å�� ������ >>");
		String found = input.nextLine();
		for(i = 0; i < num; i++) {
			if(found.equals(list[i].getTitle())) {
				System.out.println("���ڴ� : " + list[i].getWriter());
				break;
			}
		}
		if(i == num)
			System.out.println("ã������ å�� �����ϴ�.");
	}

}
