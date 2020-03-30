/* Project Euler - Problem 1
  Find the sum of all the multiples of 3 or 5 below 1000
  
  p001.cpp
  g++ p001.cpp -o p1.exe
*/
#include <iostream>

int main() {
  int sum = 0;
  for (int i = 1; i < 1000; i++)
    if ((i % 3 == 0) || (i % 5 == 0))
      sum+=i;

  std::cout << sum << std::endl;
  return 0;
}
