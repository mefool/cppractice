/**
 * Project Euler - Problem 3
 * Find the largest prime factor of the number 600851475143.
 * 
 * p003.java
 * javac p003.java
 * java p003
 */

public class p003 {
    public static void main(String[] args) {
	System.out.println(new p003().run());
    }

    public String run() {
        long num = 600851475143L; //added L after the number
	int largest_factor = 1;
	int i;
	while (num != 1){
	    for (i = 2; num%i != 0; i++);
	    System.out.println(num+"/"+i+" = "+num/i);
	    if (largest_factor < i)
		largest_factor = i;
	    num /= i;
	}
        return Integer.toString(largest_factor);
    }
}
