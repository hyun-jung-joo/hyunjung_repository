import java.util.*;
public class A3_3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		
		Book[] list = new Book[2];
		
		for(int i=0; i < 2; i++) {
			System.out.print("����>>");
			String t = input.nextLine();
			System.out.print("����>>");
			String a = input.nextLine();
			list[i] = new Book(t, a);
		}
		
		for(int i=0; i < 2; i++) {
			System.out.println(" (" + list[i].title + ", " + list[i].author + ")");
		}
	}

}
