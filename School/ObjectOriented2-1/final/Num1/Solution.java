import java.util.Scanner;

	public class Solution {
	    public static void main(String[] args) {
	        Scanner sc = new Scanner(System.in);
	        String id = sc.next();
			String pwd = sc.next();
	        //�ڵ� �ۼ�
			login(id, pwd);
	    }
	    
	    // login()�޼ҵ� �ۼ�
	    public static void login(String id, String pwd)
	    {
	    	if(!id.equals("java"))
	    		new NotExistIDException();
	    	else {
	    		if(!pwd.equals("1234"))
	    			new WrongPasswordException();
	    		else
	    			System.out.println("�α��� ����");
	    	}
	    }        
	}
	
	class NotExistIDException extends Exception {
		NotExistIDException () {
			System.out.println("���̵� ����");
		}
	}
	class WrongPasswordException extends Exception {
		WrongPasswordException () {
			System.out.println("�н����� Ʋ��");
		}
	}
	
