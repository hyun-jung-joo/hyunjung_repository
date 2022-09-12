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

		    System.out.println("1.회원추가  2.회원삭제  3.회원출력  4.종료");
			System.out.print("메뉴를 선택 : ");
			num = input.nextInt();
			
			if(num == 1) {
				System.out.print("추가할 회원의 이름 : ");
				name = input.next();
				list.add(name);
				
				continue;
			}
			else if(num == 2) {
				int i = 0;
				System.out.print("삭제할 회원의 이름 : ");
				delete_name = input.next();
				while(i < list.size()){
					if(delete_name.equals(list.get(i))) {
						list.remove(i);
						break;
					}
					i++;
				}
				if(i == list.size())
					System.out.println("회원이 존재하지 않음");
				continue;
			}
			else if(num == 3) {
				System.out.println("* 회원리스트 *");
				for(String e : list) 
					System.out.print(e + "\n");
				continue;
			}
			else if(num == 4)
				break;
		}
	}

}
