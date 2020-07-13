/* Project Euler - Problem 34
  Digit factorials

  p034.exe
  g++ p034.cpp -o p034.exe
  
  Comments/Issues:
  > Missing explination on the limit, might be just trial and error but the 
    limit can also be found.

*/
#include <iostream>
#include <string>

int main(/*int argc, char *argv[]*/) {
  int factorials[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

  int result = 0;

  for (int i = 3; i<10E7; i++){ // 1! and 2! are not within the interval
    int sum = 0;
    int n = i;
    while (n > 0){
      sum += factorials[n % 10];
      n /= 10;
    }
    if (i == sum)
      result += i;
  }
  std::cout << "Sum: " << result << std::endl;
  return 0;
}
