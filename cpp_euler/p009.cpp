/* Project Euler - Problem 9
  There exists exactly one Pythagorean triplet for which a + b + c = 1000.
  Find the product abc.
  
  p009.cpp
  g++ p009.cpp -o p009.exe
*/
#include <iostream>

int main() {
  int val = 1000;
  int a_py = 1, b_py = 1, c_py = 1;
  
  for (int a = 1; a < val; a++){
    for (int b = a; b < val; b++){
      int c = 1000 - a - b;
      if ((a*a + b*b) == c*c){
        std::cout << "pew" << std::endl;
        a_py = a;
        b_py = b;
        c_py = c;
        break;
      }
    }
  }
  
  std::cout << "a: " << a_py << "\nb: " << b_py << "\nc: " << c_py << "\nProduct: " << a_py*b_py*c_py << std::endl; 
  return 0;
}
