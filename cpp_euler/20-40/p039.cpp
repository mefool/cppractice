/* Project Euler - Problem 39
  Integer right triangles

  p039.exe
  g++ p039.cpp -o p039.exe
  
*/
#include <iostream>

int main(/*int argc, char *argv[]*/) {
  int result = 0, n_max = 0;
  
for (int p = 2; p <= 1000; p += 2) {
  int n = 0;
  for (int a = 2; a < (p/3); a++) {
    if(p*(p-2*a) % (2*(p-a)) == 0){
      n++;
    }
  }
  if(n > n_max){
    n_max = n;
    result = p;
  }
 }
  
  std::cout << "Result: " << result << std::endl;
  return 0;
}

