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
	//System.out.println(check_palindrome(100001));
	
        for (int i = 999; i > 100; i--){
	    for (int j = i; j > 100; j--){
		if (num > i*j) break;
		if (check_palindrome(i*j)){
		    System.out.println(num);
		    //std::cout << num << std::endl;
		    num = i*j;
		}
	    }
	    if (num > i*i) break;
	}
        return Integer.toString(num);
    }

    public boolean check_palindrome(int num) {
	String str = Integer.toString(num);

	int i = 0, j = str.length() - 1; 
  
        // While there are characters toc compare 
        while (i < j) { 
            if (str.charAt(i) != str.charAt(j)) 
                return false;
            i++; 
            j--; 
        }
	return true;
    }
}
