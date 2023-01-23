
public class MyMath {

	public static <T extends Number> double getAverage(T[] a) {
		double result = 0.0;
		
		for(int i = 0; i < a.length; i++)
			result += Double.parseDouble(a[i] + "");
		result = result / a.length;
		
		return result;
	}
}
