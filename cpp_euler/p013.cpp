/* Project Euler - Problem 11
  What is the value of the first triangle number to have over five hundred divisors?
  
  p012.exe
  g++ p012.cpp -o p012.exe
  
  Comments/Issues:
  
  References:
  > https://en.wikipedia.org/wiki/Triangular_number

*/
#include <iostream>

#define N 20

//int triangular_number(int index);
unsigned divisor_count(unsigned long num);

int main() {
  unsigned long i=1, n=1;
  while (divisor_count(n) < 500)
    n += ++i;
  
  std::cout << n << std::endl;
  return 0;
}

/*
int triangular_number(int n){
  return n*(n+1)/2;
}
*/

unsigned divisor_count(unsigned long num){
  unsigned ret = 1;
  unsigned long i;
  for (i=2; i <= num; i++){
    unsigned c = 0;
    while (num % i == 0){
      c++;
      num /= i;
    }
    ret *= c+1;
  }
  return ret;
}
