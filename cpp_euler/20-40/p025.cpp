/* Project Euler - Problem 25
  1000-digit Fibonnaci number

  p025.exe
  g++ p025.cpp -o p025.exe
  
  Comments/Issues:
  > 

  References:
  > https://en.wikipedia.org/wiki/Fibonacci_number
  > https://en.wikipedia.org/wiki/Fibonacci_number#Decomposition_of_powers

*/
#include <iostream>
#include <cmath>

int main() {
  double g_r = (1 + std::sqrt(5)) / 2; //golden ratio

  // F_n = (g_r^n - (q_r)^(-n))/sqrt(5) -> (g_r^n)/sqrt(5)
  // 1k digits => log10(F_i) = 1000

  // L(F_n) = 1 + log10(g_r^n / sqrt(5))
  //        = 1 + n * log10(g_r) - 0.5 * log10(5)

  // 1000 < 1 +  n * log10(g_r) - 0.5 * log10(5)
  // n > (999 + 0.5 * log10(5))/log10(g_r)
  // n > (999 * log(10) + 0.5 * log(5))/log(g_r)

  double n = (999 * std::log(10) + 0.5 * std::log(5))/std::log(g_r);
  std::cout << "Result: " << std::ceil(n) << " (" << n << ")" << std::endl;
  
  return 0;
}
