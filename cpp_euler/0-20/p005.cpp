/* Project Euler - Problem 5
  What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
  
  p005.cpp
  g++ p005.cpp -o p5.exe

  Comments/Issues:
  It's not that effecient or smart. Other algorithms could have been used.

  Resources/Notes: https://en.wikipedia.org/wiki/Least_common_multiple
*/
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>

void print_vector(std::vector<int> &v);

std::vector<int> get_primes(int limit);
void prime_factors(int n, const std::vector<int> &primes, std::vector<int> &factors);

std::vector<int> primes_pow_factors(const std::vector<int> &primes, const std::vector<int> &factors);
int power(int num, int factor);//could just use <math>
long long product_vector(std::vector<int> &v);

int main() {
  std::vector<int> primes = get_primes(20);
  std::vector<int> max_prime_factors(primes.size());

  //print_vector(primes);
  for (int i = 2; i < 20; i++) {
    prime_factors(i, primes, max_prime_factors);
  }
  std::vector<int> v = primes_pow_factors(primes, max_prime_factors);

  std::cout << "Product: " << product_vector(v) << std::endl; // 232792560

  return 0;
}

void print_vector(std::vector<int> &v){
  std::copy(v.begin(),v.end(),std::ostream_iterator<int>(std::cout, " " ));
  std::cout << std::endl;
}

std::vector<int> get_primes(int limit){
  std::vector<int> primes;

  for (int n=2; n <= limit; n++){
    int prime_fl=1; //may swap to bool
    if (primes.size() == 0){
      primes.push_back(n);
      continue;
    }
    for (int i=0; i < primes.size(); i++)
      if (n % primes[i] == 0){
        prime_fl = 0;
        break;
      }
    if (prime_fl){
      primes.push_back(n);
    }
  }
  //print_vector(primes);
  return primes;
}

void prime_factors(int n, const std::vector<int> &primes, std::vector<int> &factors){
  while (n > 1){
    int i_prime = 0;
    for (int i = 0; i < primes.size() && n >= primes[i]; i++) {
      int rep_factor = 0;
      while(n % primes[i] == 0){
        rep_factor++;
        n/=primes[i];
      }
      if (factors[i_prime] < rep_factor)
        factors[i_prime] = rep_factor;
      i_prime++;
    }
  }
  //print_vector(factors);
}

std::vector<int> primes_pow_factors(const std::vector<int> &primes, const std::vector<int> &factors){
  std::vector<int> numbers(primes.size());
  for (int i = 0; i < primes.size(); i++)
    numbers[i] = power(primes[i],factors[i]);

  return numbers;
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

long long product_vector(std::vector<int> &v){
  return std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
}
