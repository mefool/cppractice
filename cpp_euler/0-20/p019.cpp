/* Project Euler - Problem 19
  Counting Sundays

  p019.exe
  g++ p019.cpp -o p019.exe
  
  Comments/Issues:
  > 

  References:
  > https://en.wikipedia.org/wiki/Zeller's_congruence

*/
#include <iostream>

int dow(int year, int month, int day){
  // Zeller's congruence
  if (month <= 2){
    month += 12;
    year --;
  }
  return (day + 13 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
  // 0 = Sunday, 1 = Monday, ...
}

int main() {
  int count = 0;
  for (int y = 1901; y <= 2000; y++)
    for (int m = 1; m <= 12; m++)
      if (dow(y,m,1) == 0)
	count++;
  std::cout << "result: " << count << std::endl;
}

