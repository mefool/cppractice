/**
 * Project Euler - Problem 1
 * Find the sum of all the multiples of 3 or 5 below 1000
 * 
 * p001.java
 * javac p001.java
 * java p001
 */

public class p001 {
    public static void main(String[] args) {
	System.out.println(new p001().run());
    }

    public String run() {
	int sum = 0;
	for (int i = 0; i < 1000; i++){
	    if (i%3 == 0 || i%5 == 0)
		sum += i;
	}
	return Integer.toString(sum);
    }
}
