/* Project Euler - Problem 2
  By considering the terms in the Fibonacci sequence whose values do
  not exceed four million, find the sum of the even-valued terms.
  
  p002.cpp
  g++ p002.cpp -o p2.exe
*/
#include <iostream>

int main() {
  int i = 1, j = 2, e;
  int sum = 2;

  while (sum < 4E6){
    e = i+j;
    if (e % 2 == 0)
      sum += e;
    // get the values for the next term of the fib. seq.
    i=j;
    j=e;
  }

  std::cout << sum << std::endl; // 4613732

  return 0;
}
