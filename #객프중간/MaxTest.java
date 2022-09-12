import java.util.*;
public class MaxTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList <Double> list = new ArrayList<Double>();
		Double num;
		Double total = 0.0;
		Scanner input = new Scanner(System.in);
		
		for(int i = 0; i < 5; i++) {
			num = input.nextDouble();
			list.add(num);
			total += num;
		}
		
		System.out.println("합은" + total + " ,최댓값은 " + findMax(list));
	}

	public static Double findMax(ArrayList<Double> list) {
		double max;
		max = list.get(0);
		for(double e : list)
			if(max < e)
				max = e;
		return max;
	}
}
