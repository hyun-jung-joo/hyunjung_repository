import java.io.*;
import java.util.*;
public class A12_2 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int key = 1;
		String keynum;
		String num;
		String name;
		String phone;
		String address;
		
		Scanner scan = new Scanner(System.in);
		PrintWriter pw = null;
		pw = new PrintWriter(new FileWriter("result.txt"));
		while(true){
			if(key == 0)
				break;
			System.out.print("사용지 번호를 입력하세요 >>");
			num = scan.next();
			System.out.print("사용지 이름을 입력하세요 >>");
			name = scan.next();
			System.out.print("사용지 전화번호를 입력하세요 >>");
			phone = scan.next();
			System.out.print("사용지 이메일을 입력하세요 >>");
			address = scan.next();
			
			try {
				pw.print(num + ", " + name + ", " + phone + ", " + address);
				pw.println();
				pw.flush();
			} catch (Exception e) {
				e.printStackTrace();
			}
			
			System.out.print("입력이 끝났으면 0, 계속 입력하려면 1을 입력하세요 >>");
			key = scan.nextInt();
		}
		pw.close();
		System.out.print("검색할 사용자 번호를 입력하세요 >>");
		keynum = scan.next();
		
		try {
			Scanner scanner = new Scanner(new File("result.txt"));
			scanner.useDelimiter(",");
			while(scanner.hasNext()) {
				String str = scanner.next();
				if(keynum.equals(str)) {
					scanner.next();
					String keyPhone = scanner.next();
					System.out.println("사용자 번호 " + keynum + "의 전화번호는" + keyPhone + "입니다.");
					break;
				}	
			}
		} catch(IOException e) {
			e.printStackTrace();
		}
	}

}
