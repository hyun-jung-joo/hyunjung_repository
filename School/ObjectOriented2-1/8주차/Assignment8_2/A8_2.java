import java.util.InputMismatchException;
import java.util.*;
public class A8_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		char [] day = {'��', '��', 'ȭ', '��', '��', '��', '��'};
		int key;
		
		while(true) {
			System.out.print("������ �Է��ϼ���>>");
			try {
				key = input.nextInt();
				if(key < 0)
					break;
				System.out.println(day[key]);
			} 
			catch(InputMismatchException i) {
				System.out.println("���! ���� �Է����� �ʾҽ��ϴ�.");
				input.nextLine();
			}
		}
		System.out.println("���α׷� �����մϴ�...");
	}

}
