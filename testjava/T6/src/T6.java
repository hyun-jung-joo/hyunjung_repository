import java.util.*;

public class T6 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int num;
		String name;
		String delete_name;
		
		ArrayList <String> list = new ArrayList<String>();
		Scanner input = new Scanner(System.in);
		
		while(true){

		    System.out.println("1.ȸ���߰�  2.ȸ������  3.ȸ�����  4.����");
			System.out.print("�޴��� ���� : ");
			num = input.nextInt();
			
			if(num == 1) {
				System.out.print("�߰��� ȸ���� �̸� : ");
				name = input.next();
				list.add(name);
				
				continue;
			}
			else if(num == 2) {
				int i = 0;
				System.out.print("������ ȸ���� �̸� : ");
				delete_name = input.next();
				while(i < list.size()){
					if(delete_name.equals(list.get(i))) {
						list.remove(i);
						break;
					}
					i++;
				}
				if(i == list.size())
					System.out.println("ȸ���� �������� ����");
				continue;
			}
			else if(num == 3) {
				System.out.println("* ȸ������Ʈ *");
				for(String e : list) 
					System.out.print(e + "\n");
				continue;
			}
			else if(num == 4)
				break;
		}
	}

}
