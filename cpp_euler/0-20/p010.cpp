/* Project Euler - Problem 10
  Find the sum of all the primes below two million.
  
  p010.exe
  g++ p010.cpp -o p010.exe

  Comments/Issues:
  It's not that effecient or smart. Other algorithms could have been used.
  
  References:
  > Problem 7 - hmm
  > Sieve of Eratosthenes

*/
#include <iostream>
#include <vector>
#include <iterator>

std::vector<unsigned int> get_primes(int max);

int main() {
  std::vector<unsigned int> primes = get_primes(2'000'000);
  std::cout << "out of primes" << std::endl;
  
  unsigned long long sum = 0;
  for (auto& n : primes)
    sum += n;

  std::cout << "Sum: " << sum << std::endl;

  return 0;
}

std::vector<unsigned int> get_primes(int max){
  std::vector<unsigned int> primes;
  
  primes.push_back(2); //the only even prime
  
  for (int n=3; n < max; n+=2){
    int prime_fl = 1; //may swap to bool

    for (auto p : primes){
      if (p*p > n)
        break;
      if (n % p == 0){
        prime_fl = 0;
        break;
      }
    }
    if (prime_fl){
      primes.push_back(n);
    }
  }

  return primes;
}