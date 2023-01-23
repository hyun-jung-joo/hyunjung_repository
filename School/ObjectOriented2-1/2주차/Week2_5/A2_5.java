import java.util.*;
public class A2_5 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		String str = input.nextLine();
		
		for(int i = str.length()  - 1; i >= 0; i--) {
			System.out.print(str.charAt(i));
		}
	}

}
