/* Project Euler - Problem 7
  What is the 10 001st prime number?
  
  p007.exe
  g++ p007.cpp -o p7.exe

  Comments/Issues:
  It's not that effecient or smart. Other algorithms could have been used.

*/
#include <iostream>
#include <vector>
#include <iterator>

void print_vector(std::vector<int> &v);

std::vector<int> get_primes(int desired_size);

int main() {
  std::vector<int> primes = get_primes(10'001);
  //print_vector(primes);
  std::cout << "Last element: " << primes[primes.size()-1] << std::endl;

  return 0;
}

void print_vector(std::vector<int> &v){
  std::copy(v.begin(),v.end(),std::ostream_iterator<int>(std::cout, " " ));
  std::cout << std::endl;
}

std::vector<int> get_primes(int desired_size){
  std::vector<int> primes;

  for (int n=2; primes.size() != desired_size; n++){
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
