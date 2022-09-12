import java.util.*;
public class NoodleTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		
		ArrayList <Noodle> list = new ArrayList<Noodle>(); 
		System.out.print("주문할 음식의 수는 : ");
		int num = input.nextInt();
		
		System.out.print("[칼국수(7000), 냉면(11000), 쫄면(8000), 라면(4000), 쌀국수(10000)]에서"
				+ " 음식 3개를 입력 : ");
		
		for(int i = 0; i < num; i++) {
			String food = input.next();
			list.add(new Noodle(food));
			list.get(i).getTotalPrice();
		}
		
		System.out.println("주문한 음식의 총금액 : " + list.get(num - 1).getTotalPrice());
	}

}
