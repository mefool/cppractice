/* Project Euler - Problem 29
  Distinct powers

  p029.exe
  g++ p029.cpp -o p029.exe
  
  Comments/Issues:
  > Brute force
  > DBL_MAX = 1.79769e+308
  > (paper math)

  References:
  > http://www.mathblog.dk/project-euler-29-distinct-terms-sequence-ab/ -

*/
#include <iostream>
#include <cmath>
#include <set>

int main() {
  std::set<double> terms;
  for (int a = 2; a <= 100; a++){
    for (int b = 2; b <= 100; b++){
      double term = pow(a,b);
      terms.insert(term);
    }
  }
  std::cout << "Number of distinct terms: " << terms.size() << std::endl;
}
