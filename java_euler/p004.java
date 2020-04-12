/**
 * Project Euler - Problem 4
 * Find the largest palindrome made from the product of two 3-digit numbers.
 * 
 * p004.java
 * javac p004.java
 * java p004
 */

public class p004 {
    public static void main(String[] args) {
	System.out.println(new p004().run());
    }

    public String run() {
	int num = 0;
	for (int i = 999; i > 100; i--){
	     for (int j = i; j > 100; j--){
		 if (num > i*j) break;
		 if (check_palindrome_6n(i*j)){
		     //std::cout << num << std::endl;
		     num = i*j;
		 }
	     }
	     if (num > i*i) break;
	 }
        return Integer.toString(num);
    }

    public boolean check_palindrome_6n(int num) {
	return ((num/(1E5) == num%(1E1)) &&
		((num%(1E5))/(1E4) == (num/(1E1))%(1E1)) &&
		((num%(1E4))/(1E3) == (num/(1E2))%(1E1)));
    }
}
