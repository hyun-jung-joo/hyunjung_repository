import java.util.*;

public class A4_3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int choice;
		int size = 0;
		String[][] members;

		System.out.println("------------------------------------------");
		System.out.println("1. ȸ���� | 2. �����Է� | 3. ȸ������Ʈ | 4. ����");
		System.out.println("------------------------------------------");
		System.out.print("����> ");
		choice = input.nextInt();

		if (choice == 1) {
			System.out.print("ȸ����> ");
			size = input.nextInt();
			members = new String[size][2];

			while (choice != 4) {
				System.out.println("------------------------------------------");
				System.out.println("1. ȸ���� | 2. �����Է� | 3. ȸ������Ʈ | 4. ����");
				System.out.println("------------------------------------------");
				System.out.print("����> ");
				choice = input.nextInt();
				
				if (choice == 2)
					for (int i = 0; i < size; i++) {
						System.out.print("�̸��� �Է��ϼ��� : ");
						members[i][0] = input.next();
						input.nextLine();
						System.out.print("��ȭ��ȣ�� �Է��ϼ��� : ");
						members[i][1] = input.nextLine();
					}
				else if (choice == 3) {
					System.out.println("\n** ȸ�� ���� **");
					for(int i = 0; i < members.length; i++) {
						for(int j = 0; j < members[0].length; j++) {
							System.out.print(members[i][j] + "\t");
						}
						System.out.println();
					}
				}
			}

		}
	}

}
