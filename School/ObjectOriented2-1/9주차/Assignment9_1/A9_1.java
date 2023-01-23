import java.util.*;

public class A9_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		String str;
		//String [] str2 = new String[100];
		int count = 0;
		int i = 0;
		
		System.out.print("단어 문자열을 입력하세요 >>");
		str = input.nextLine();
		StringTokenizer st = new StringTokenizer(str);
		
		count = st.countTokens();
		
		String [] str2 = new String[count];
		while(st.hasMoreTokens()) {
			str2[i] = st.nextToken();
			i++;
		}
		
		System.out.println("모두" + count + "개의 단어를 있습니다.");
		System.out.println(" [분리된 토큰] ");
		
		for(String s : str2) 
			System.out.println(s);
		
		System.out.println(" 토큰수 : " + count);
		System.out.println("===== sort =====");
		Arrays.sort(str2);
		
		for(String s : str2) 
			System.out.println(s);
	}

}
