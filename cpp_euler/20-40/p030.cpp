/* Project Euler - Problem 30
  Digit fifth powers

  p030.exe
  g++ p030.cpp -o p030.exe
  
  Comments/Issues:
  > Missing explination on the limit, might be just trial and error but the 
    limit can also be found.

*/
#include <iostream>
#include <string>

int main(/*int argc, char *argv[]*/) {
  int powers[] = {0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049};

  int result = 0;

  for (int i = 2; i<10E7; i++){ // 1! and 2! are not within the interval
    int sum = 0;
    int n = i;
    while (n > 0){
      sum += powers[n % 10];
      n /= 10;
    }
    if (i == sum)
      result += i;
  }
  std::cout << "Sum: " << result << std::endl;
  return 0;
}
