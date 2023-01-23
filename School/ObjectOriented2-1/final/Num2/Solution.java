import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;

public class Solution {
    public static void main(String[] args) {
    	Scanner input = new Scanner(System.in);
        Map <Person, Integer> map = new TreeMap<Person, Integer>();
        for(int i = 0; i < 3; i++) {
        	String name = input.next();
        	int age = input.nextInt();
        	int num = input.nextInt();
        	map.put(new Person(name, age), num);
        }
        int max = 0;
        int maxnum = -1;
        for(Map.Entry<Person, Integer> entry : map.entrySet()) {
        	int a = entry.getKey().getAge();
        	if(a > max) {
        		max = a;
        		maxnum = entry.getValue();
        	}
        }
        System.out.println(maxnum);
        String key = input.next();
        int flag = 1;
        for(Map.Entry<Person, Integer> entry : map.entrySet()) {
        	String a = entry.getKey().getName();
        	if(a.equals(key)) {
        		System.out.println("있음");
        		flag = 0;
        		break;
        	}
        }
        if(flag == 1)
        	System.out.println("없음");
    }
    
}

class Person implements Comparable<Person>{
	String name;
	int age;
	int num;
	
	Person(String name, int age) {
		this.name=name;
		this.age = age;
	}
	
	public int getAge() {return age;}
	public String getName() {return name;}
	public int compareTo(Person a) {
		return age - a.age;
	}
}

