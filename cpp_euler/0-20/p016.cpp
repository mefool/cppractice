/* Project Euler - Problem 16
  Power digit sum

  p016.exe
  g++ p016.cpp -o p016.exe
  
  Comments/Issues:
  > Limiting the number of digits wont work once the numbers go over 10^N.

  References:
  > Wiki knowns better ways to do this. I read but didnt implement.

*/
#define N 310
#include <iostream>

int main() {
  int power = 1000;
  std::cout << "power: " << power << std::endl;
  //2^1000 = 10^(log10(2^100)) +-= 10^301
  int number[N] = {0};
  number[0] = 1;
  for (int i=1; i<N; i++)
    number[i]=0;
  
  for(int i = 0; i < power; i++){
    for(int j = 0; j < N; j++)
      number[j]*=2;
    for(int j = 0; j < N; j++){
      if(number[j] >= 10){
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
