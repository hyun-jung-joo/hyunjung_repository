import java.util.Scanner;

public class A5_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int key_num;
		int [] num = {0, 0, 0, 0, 0};
		int count = 0;
		
		while(true) {
			System.out.println("------------------------------------");
			System.out.println("1 2 3 4 5 ");
			System.out.println("------------------------------------");
			for(int i = 0; i < num.length; i++)
				System.out.print(num[i] + " ");
			System.out.println();
			
			if(count == 5)
				 break;
			
			System.out.print("�����Ϸ��� �¼���ȣ�� �Է��ϼ��� : ");
			key_num = input.nextInt();
			
			if(num[key_num - 1] == 0) {
				num[key_num - 1] = 1;
				System.out.println("����Ǿ����ϴ�.");
				count++;
			}
			else 
				System.out.println("�̹� ����� �ڸ��Դϴ�.");
		}
		System.out.println("�����Դϴ�.");
	}

}
