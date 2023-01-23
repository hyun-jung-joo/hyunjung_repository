import java.util.*;
public class A3_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int num;
		int i;
		
		Scanner input = new Scanner(System.in);
		System.out.print("책의 권수>>");
		num = input.nextInt();
		Book[] list = new Book[num];
		input.nextLine();

		for(i = 0; i < list.length; i++) {
			System.out.print("제목>>");
			String title = input.nextLine();
			System.out.print("저자>>");
			String writer = input.nextLine();
			list[i] = new Book(title, writer);
		}
		for(i = 0; i < num; i++) {
			System.out.println(list[i].toString());
		}
		System.out.println("");
		
		System.out.print("찾으려는 책의 제목은 >>");
		String found = input.nextLine();
		for(i = 0; i < num; i++) {
			if(found.equals(list[i].getTitle())) {
				System.out.println("저자는 : " + list[i].getWriter());
				break;
			}
		}
		if(i == num)
			System.out.println("찾으려는 책이 없습니다.");
	}

}
