import java.io.*;
public class A12_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FileReader in = null;
		FileWriter out = null;
		try{
			in = new FileReader("in.txt");
			out = new FileWriter("out.txt");
			int letter;
			while((letter = in.read()) != -1) {
				if(letter >= 97 && letter <= 122)
					letter = letter - 32;
				out.write((char)letter);
			}
			in.close();
			out.close();
		}catch(IOException e) {
			e.printStackTrace();
		}
	}

}
