/* Project Euler - Problem 3
  Find the largest prime factor of the number 600851475143.
  
  g++ p003.cpp -o p3.exe

  Comments/Issues:
  > While the algorithm works for the number in question, a large number
  (greater than INT_MAX) may not, if it's prime. The performance could also 
  be improved by adding a vector of primes, to check if it is a factor of 
  the number, skipping the for cycle used in the current solution.
*/
#include <iostream>

int main() {
  long long num = 600851475143;;
  int i, largest_factor = 1;

  while (num != 1){
    for(i=2; num%i != 0 /*or int_max*/; i++);
    /*if (i == int_max) {(...)}*/
    std::cout << num << " / " << i << " = " << num/i << std::endl;
    if (largest_factor < i)
      largest_factor = i;
    num /= i;
  }

  std::cout << "Largest prime factor: "<< largest_factor << std::endl;
  return 0;
}
