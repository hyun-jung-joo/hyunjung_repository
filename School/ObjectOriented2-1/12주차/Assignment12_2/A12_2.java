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
			System.out.print("����� ��ȣ�� �Է��ϼ��� >>");
			num = scan.next();
			System.out.print("����� �̸��� �Է��ϼ��� >>");
			name = scan.next();
			System.out.print("����� ��ȭ��ȣ�� �Է��ϼ��� >>");
			phone = scan.next();
			System.out.print("����� �̸����� �Է��ϼ��� >>");
			address = scan.next();
			
			try {
				pw.print(num + ", " + name + ", " + phone + ", " + address);
				pw.println();
				pw.flush();
			} catch (Exception e) {
				e.printStackTrace();
			}
			
			System.out.print("�Է��� �������� 0, ��� �Է��Ϸ��� 1�� �Է��ϼ��� >>");
			key = scan.nextInt();
		}
		pw.close();
		System.out.print("�˻��� ����� ��ȣ�� �Է��ϼ��� >>");
		keynum = scan.next();
		
		try {
			Scanner scanner = new Scanner(new File("result.txt"));
			scanner.useDelimiter(",");
			while(scanner.hasNext()) {
				String str = scanner.next();
				if(keynum.equals(str)) {
					scanner.next();
					String keyPhone = scanner.next();
					System.out.println("����� ��ȣ " + keynum + "�� ��ȭ��ȣ��" + keyPhone + "�Դϴ�.");
					break;
				}	
			}
		} catch(IOException e) {
			e.printStackTrace();
		}
	}

}
