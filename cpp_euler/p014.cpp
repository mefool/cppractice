/* Project Euler - Problem 14
  Which starting number, under one million, produces the longest collatz chain.
  
  p014.exe
  g++ p014.cpp -o p014.exe
  
  Comments/Issues:
  > Shouldn't be using "long long" as a chain number/iterator or at least verify if it has gone over the limit.
  > But it did work. If "int" is used the program will run for to long for me, and i'll C-c it.
  
  References:
  > https://en.wikipedia.org/wiki/Collatz_conjecture

*/
#include <iostream>
#include <fstream>
#include <string>
int main() {
  int chain_l, max_chain_l = 0, max_num=1;

  //brute force
  for(int i = 2; i < 1E6; i++){
    long long num = i;
    chain_l = 0;
    while (num != 1){
      if (num % 2 == 0)
	num /= 2;
      else
	num = 3*num+1;
      chain_l++;
    }
    if(chain_l > max_chain_l){
      max_chain_l = chain_l;
      max_num = i;
    }
  }
  std::cout << "max_num: " << max_num << " (chain lenght: "<< max_chain_l << ")"<< std::endl;
}

