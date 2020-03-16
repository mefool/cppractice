/* Project Euler - Problem 6
  Find the difference between the sum of the squares of the first one hundred
  natural numbers and the square of the sum.

  p006.cpp
  g++ p006.cpp -o p6.exe

  Resources/Notes:
  > http://www.phengkimving.com/calc_of_one_real_var/09_the_intgrl/09_01_summ_notatn_and_formulas.htm
*/
#include <iostream>

int power(int num, int factor);//could just use <math>

int main() {
  int n = 100;
  int square_sum = power( (n*(n+1))/2, 2);
  int sum_square = n*(n+1)*(2*n+1)/6;

  std::cout << "Result: " << square_sum-sum_square << std::endl; // or simply (n^4 / 4) + (n^3 / 6) - (n^2 / 4) - (n / 6)

  return 0;
}

int power(int num, int factor){
  int result = num;
  if (factor == 0)
    return 1;
  for (int i=1; i<factor; i++){
    result*=num;
  }
  return result;
}
