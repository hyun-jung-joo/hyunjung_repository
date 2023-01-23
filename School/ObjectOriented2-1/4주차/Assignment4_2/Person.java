
public class Person implements Comparable {
	private double height;
	private String name;
	
	Person(String n, double g) {
		name = n;
		height = g;
		
	}
	
	public double getHeight() {return height;}
	public String getName() {return name;}
	
	public int compareTo(Object obj) {
		Person other = (Person) obj;
		if(height < other.height)
			return -1;
		else if(height > other.height)
			return 1;
		else
			return 0;
	}
}
