import java.util.Scanner;

	public class Solution {
	    public static void main(String[] args) {
	        Scanner sc = new Scanner(System.in);
	        String id = sc.next();
			String pwd = sc.next();
	        //코드 작성
			login(id, pwd);
	    }
	    
	    // login()메소드 작성
	    public static void login(String id, String pwd)
	    {
	    	if(!id.equals("java"))
	    		new NotExistIDException();
	    	else {
	    		if(!pwd.equals("1234"))
	    			new WrongPasswordException();
	    		else
	    			System.out.println("로그인 성공");
	    	}
	    }        
	}
	
	class NotExistIDException extends Exception {
		NotExistIDException () {
			System.out.println("아이디 없음");
		}
	}
	class WrongPasswordException extends Exception {
		WrongPasswordException () {
			System.out.println("패스워드 틀림");
		}
	}
	
