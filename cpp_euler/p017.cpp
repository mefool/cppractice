/* Project Euler - Problem 16
  Number letter counts

  p017.exe
  g++ p017.cpp -o p017.exe
  
  Comments/Issues:
  > 

  References:
  > 

*/
#include <iostream>
#include <string>
#include <vector>

//using namespace std; // would save me time

std::vector<std::string> ones {"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
std::vector<std::string> teens {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen"};
std::vector<std::string> tens {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

//int chat_count(int num);
//int char_count(string);
std::string spellout(unsigned int number);

int main() {
  int sum = 0;
  int n = 999;
  std::cout << "number: " << n << " spelled out: " << spellout(n)<< " number of characters: "
	    << spellout(n).size() << std::endl;
  
  for(int i = 1; i <= 1000; i++){
    sum += spellout(i).size();
  }
  std::cout << "result: " << sum << std::endl;
}

std::string spellout(unsigned int number){
  if (number < 10)
    return ones[number];
  else if (number < 20)
    return teens[number-10];
  else if (number < 100)
    return tens[number/10] + (number % 10 != 0 ? ones[number%10]: "");
  else if (number < 1000)
    return spellout(number/100) + "hundred" + (number % 100 != 0 ? "and" + spellout(number%100) : "");
  else if (number < 10000)
    return spellout(number/1000) + "thousand" + (number % 1000 != 0 ? spellout(number%1000) : "");
  else
    return "error";
}
