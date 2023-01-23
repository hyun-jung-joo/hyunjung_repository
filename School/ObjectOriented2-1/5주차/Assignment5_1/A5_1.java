import java.util.*;
public class A5_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int a , b;
		char calc;
		
		System.out.print("두 정수와 연산자를 입력하시오>> ");
		a = input.nextInt();
		b = input.nextInt();
		calc = input.next().charAt(0);
		
		switch(calc) {
		case '+' :
			Add add = new Add();
			add.setValue(a, b);
			System.out.println(add.calculate());
			break;
		case '-' : 
			Sub sub = new Sub();
			sub.setValue(a, b);
			System.out.println(sub.calculate());
			break;
		case '*' :
			Mul mul = new Mul();
			mul.setValue(a, b);
			System.out.println(mul.calculate());
			break;
		case '/' :
			Div div = new Div();
			div.setValue(a, b);
			System.out.println(div.calculate());
			break;
		}
	}

}
