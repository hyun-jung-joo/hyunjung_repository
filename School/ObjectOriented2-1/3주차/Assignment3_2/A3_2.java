import java.util.*;
public class A3_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		Magazine m1;
		
		System.out.print("���� �̸���? ");
		String title = input.nextLine();
		System.out.print("����������? ");
		int pages = input.nextInt();
		input.nextLine();
		System.out.print("���ڴ�? ");
		String author = input.nextLine();
		System.out.print("�߸�����? ");
		String date = input.nextLine();
		
		m1 = new Magazine(title, pages, author, date);
	}

}
