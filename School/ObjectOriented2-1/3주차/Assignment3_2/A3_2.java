import java.util.*;
public class A3_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		Magazine m1;
		
		System.out.print("잡지 이름은? ");
		String title = input.nextLine();
		System.out.print("페이지수는? ");
		int pages = input.nextInt();
		input.nextLine();
		System.out.print("저자는? ");
		String author = input.nextLine();
		System.out.print("발매일은? ");
		String date = input.nextLine();
		
		m1 = new Magazine(title, pages, author, date);
	}

}
