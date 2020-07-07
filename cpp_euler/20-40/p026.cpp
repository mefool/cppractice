/* Project Euler - Problem 26
  Reciproval cycles

  p026.exe
  g++ p026.cpp -o p026.exe
  
  Comments/Issues:
  > 

  References:
  >> unordered set vs vector
  > https://stackoverflow.com/questions/33875407/prefer-unordered-set-over-vector

*/
#include <iostream>
#include <vector>
#include <algorithm>

#define LIMIT 1000

int cycle_lenght(int d){
  int lenght = 0;
  int num = 1;
  int r = 0;
  int zeros = 0;
  std::vector<int> v = {};
  
  do{
    if (zeros != 0 || num / d  > 0){
       v.push_back(r);
       zeros = 1;
    }
    num = num % d * 10;
    lenght++;
    std::cout << num;
  } while (std::find(v.begin(), v.end(), r) == v.end());
  std::cout << std::endl;
  return lenght;
}

int main(int argc, char *argv[]) {
  if (argc > 1){
    int d = (std::stoi(argv[1]));
    int result = cycle_lenght(d);
    std::cout << "Result: " << result << std::endl;
  } else
    std::cout << "argv[1] -> denominator " << std::endl;
  return 0;
	 
}
