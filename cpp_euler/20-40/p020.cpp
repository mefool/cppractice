/* Project Euler - Problem 20
  Factorial digit sum
  Find the sum of the digits in the number 100!

  p020.exe
  g++ p020.cpp -o p020.exe
  
  Comments/Issues:
  > 

  References:
  > Problem 16

*/

#define N 300 // actualy only 158
#include <iostream>

int main() {
  int n_fac = 100;
  std::cout << "n (to obtain (n)!): " << n_fac << std::endl;
  int number[N] = {0};
  number[0] = 1;
  for (int i = 1; i < N; i++)
    number[i] = 0;
  
  for(int i = 2; i < n_fac; i++){
    for(int j = 0; j < N; j++)
      number[j] *= i;
    for(int j = 0; j < N; j++){
      while (number[j] >= 10){
	number[j] -= 10;
	number[j+1] += 1;
      }
    }
  }
  
  std::cout << "number: ";
  int flag = 0;
  int sum = 0;
  for(int i = N-1; i >= 0; i--)
    if(number[i] != 0 || flag){
      flag = 1;
      sum += number[i];
      std::cout << number[i];
    }
  
  std::cout << std::endl;
  std::cout << "sum of digits: " << sum << std::endl;
  std::cout << std::endl;  
}
