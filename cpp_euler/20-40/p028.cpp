/* Project Euler - Problem 28
  Number spiral diagonals

  p028.exe
  g++ p028.cpp -o p028.exe
  
  Comments/Issues:
  > (paper math)

  References:
  > 

*/
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc > 1){
    int n = (std::stoi(argv[1]) - 1) / 2;
    long long result = 2 * n * (8 * n * n + 15 * n + 13) / 3 + 1;
    std::cout << "Result: " << result << std::endl;
  } else
    std::cout << "argv[1] -> size " << std::endl;
  return 0;
}
