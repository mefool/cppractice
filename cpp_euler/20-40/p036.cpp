/* Project Euler - Problem 36
  Double-base palindromes

  p036.exe
  g++ p036.cpp -o p036.exe
  
*/
#include <iostream>
#include <string>
#include <algorithm> //reverse

std::string int_to_string(int num, int base){
  std::string str;
  while (num > 0){
    int digit = num % base;
    num /= base;
    str.insert(0, 1, char(digit + '0'));
  }
  return str;
} 

int is_palindrome(int num, int base = 10){
  std::string str = int_to_string(num, base), str_rev = str;
  std::reverse(str_rev.begin(), str_rev.end());

  return str == str_rev;
}

int main(/*int argc, char *argv[]*/) {
  int sum = 0;
  /*
  std::string test{"0123"};
  test.insert(0, 1, 'a');
  std::cout << test << std::endl;
  */
  for (int i = 1; i < 1E6; i++){
    if (is_palindrome(i) && is_palindrome(i,2))
      sum += i;
  }
  
  std::cout << "Sum: " << sum << std::endl;
  return 0;
}

