/* Project Euler - Problem 4
  Find the largest palindrome made from the product of two 3-digit numbers.

  p004.cpp
  g++ p004.cpp -o p4.exe
*/
#include <iostream>

int check_palindrome_6n(int num) { // could also be implemented using bitwise operations (i think)
  return ((num/int(1E5) == num%int(1E1)) &&
          ((num%int(1E5))/int(1E4) == (num/int(1E1))%int(1E1)) &&
          ((num%int(1E4))/int(1E3) == (num/int(1E2))%int(1E1)));
}

int main() {
  int num = 0;
  /*
  std::cout << num/int(1E5) << " == " << num%int(1E1) << std::endl;
  std::cout << (num%int(1E5))/int(1E4) << " == " << (num/int(1E1))%int(1E1) << std::endl;
  std::cout << (num%int(1E4))/int(1E3) << " == " << (num/int(1E2))%int(1E1) << std::endl;
  std::cout << check_palindrome_6n(num) << std::endl;
  */
  for (int i = 999; i > 100; i--){
    for (int j = i; j > 100; j--){
      if (num > i*j) break;
      if (check_palindrome_6n(i*j)){
        std::cout << num << std::endl;
        num = i*j;
      }
    }
    if (num > i*i) break;
  }

  std::cout << num << std::endl; // 906609 (6164 steps)
  return 0;
}
