/**
 * Project Euler - Problem 1
 * Consider the terms in the Fibonacci sequence whose values do not exceed four million.
 * Find the sum of the even-valued terms.
 * 
 * p002.java
 * javac p002.java
 * java p002
 */

public class p002 {
    public static void main(String[] args) {
	System.out.println(new p002().run());
    }

    public String run() {
	int sum = 0;
	int i = 1;
	int j = 2;
	while (i <= 4000000) {
	    if (i%2 == 0)
		sum += i;
	    int temp = i+j;
	    i = j;
	    j = temp;
	}
	return Integer.toString(sum);
    }
}
