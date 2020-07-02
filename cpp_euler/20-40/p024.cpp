/* Project Euler - Problem 24
  Lexicographic permutations

  p024.exe
  g++ p024.cpp -o p024.exe
  
  Comments/Issues:
  > 

  References:
  > http://www.cplusplus.com/reference/algorithm/next_permutation/

*/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
  unsigned int n_permutation = 1000000;
  std::string num = "0123456789";
  while (--n_permutation)
    std::next_permutation(current.begin(), current.end());
  std::cout << "Millionth permutation: " << current << std::endl;
  
  return 0;
}
