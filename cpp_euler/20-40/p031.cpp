/* Project Euler - Problem 31
  Coin Sums

  p031.exe
  g++ p031.cpp -o p031.exe
  
  Reference:
  > https://www.xarg.org/puzzle/project-euler/problem-31/
  
  Comments: 
  > :^[
*/
#include <iostream>

int main(/*int argc, char *argv[]*/) {
  int target = 200;
  
  int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
  int table[target+1];
  
  for (int i = 0; i <= target; i++)
    table[i] = 0;

  table[0] = 1;
  for (int i = 0; i < 8; i++){
    for (int j = coins[i]; j <= target; j++){
      table[j] += table[j - coins[i]];
    }
  }
    
  std::cout << "Result: " << table[target] << std::endl;
  return 0;
}
