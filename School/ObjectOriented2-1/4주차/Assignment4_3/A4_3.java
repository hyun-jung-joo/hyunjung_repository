import java.util.*;

public class A4_3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int choice;
		int size = 0;
		String[][] members;

		System.out.println("------------------------------------------");
		System.out.println("1. 회원수 | 2. 정보입력 | 3. 회원리스트 | 4. 종료");
		System.out.println("------------------------------------------");
		System.out.print("선택> ");
		choice = input.nextInt();

		if (choice == 1) {
			System.out.print("회원수> ");
			size = input.nextInt();
			members = new String[size][2];

			while (choice != 4) {
				System.out.println("------------------------------------------");
				System.out.println("1. 회원수 | 2. 정보입력 | 3. 회원리스트 | 4. 종료");
				System.out.println("------------------------------------------");
				System.out.print("선택> ");
				choice = input.nextInt();
				
				if (choice == 2)
					for (int i = 0; i < size; i++) {
						System.out.print("이름을 입력하세요 : ");
						members[i][0] = input.next();
						input.nextLine();
						System.out.print("전화번호를 입력하세요 : ");
						members[i][1] = input.nextLine();
					}
				else if (choice == 3) {
					System.out.println("\n** 회원 정보 **");
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
