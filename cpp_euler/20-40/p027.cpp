/* Project Euler - Problem 27
  Quadratic primes

  p027.exe
  g++ p027.cpp -o p027.exe
  
  Comments/Issues:
  > 

  References:
  > 

*/
#include <iostream>

#define LIMIT 1000

int is_prime(int num){
  if(num <= 1) return 0; // <- 1 is not prime 
  for (int i = 2; i * i <= num; i++) 
    if (num % i == 0) return 0;
  return 1;
}

int main() {
  int n_consecutive = 0;
  int best_a = 0, best_b = 0;

  for (int a = -LIMIT; a <= LIMIT; a++){
    for (int b = -LIMIT; b <= LIMIT; b++){
      int i = 0;
      while (is_prime(i*i+a*i+b))
	i++;

      if (n_consecutive < i){
	n_consecutive = i;
	best_a = a;
	best_b = b;
      }
    }
  }

  std::cout << "a: " << best_a << " b: " << best_b
	    << " a*b: " << best_a*best_b
            << " n_con: " << n_consecutive << std::endl;
}
