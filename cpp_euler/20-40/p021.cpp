/* Project Euler - Problem 21
  Amicable numbers
  Evaluate the sum of all the amicable numbers ender 10000.

  p021.exe
  g++ p021.cpp -o p021.exe
  
  Comments/Issues:
  > 

  References:
  > 

*/
#include <iostream>

int main() {
  int sum = 0;

  std::cout << "Amicable numbers: " << std::endl;
  
  for (int i = 2; i < 10000; i++){
    int a = i;
    int b = 0;
    int c = 0;
    
    for (int j = 1; j < a; j++)
      if (a % j == 0)
	b += j;
    
    for (int j = 1; j < b; j++)
      if (b % j == 0)
	c += j;

    if (c == a && b != a){
      std::cout << a << std::endl;
      sum += a;
    }
  }
  std::cout << "result: " << sum << std::endl;
}
