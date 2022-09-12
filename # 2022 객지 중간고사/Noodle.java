import java.util.*;
public class Noodle implements Delivery {
	int p;
	static int result = 0;
	String name;
	String[] menu = {"Ä®±¹¼ö", "³Ã¸é", "ÂÌ¸é", "¶ó¸é", "½Ò±¹¼ö"};
	int [] price = {7000, 11000, 8000, 4000, 10000};
 	
	Noodle(String name) {
		this.name = name;
	}

	public int getTotalPrice() {
		for(int i = 0; i < 5; i++)
			if(name.equals(menu[i]))
				result += price[i];
		return result;
	}
}
