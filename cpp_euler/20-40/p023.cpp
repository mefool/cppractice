/* Project Euler - Problem 23
  Non-abundant sum

  p023.exe
  g++ p023.cpp -o p023.exe
  
  Comments/Issues:
  > 

  References:
  > 

*/
#define NON_ABUNDANT_LIMIT 28123

#include <iostream>
#include <set>

std::set<int> abundant_set;

bool is_sum_of_abundants(int num){
  if (num >= NON_ABUNDANT_LIMIT)
    return true;

  for (auto i : abundant_set){
    if (i >= num)
      return false;
    int remain = num - i;
    if (abundant_set.count(remain) == 0)
      continue;
    return true;
  }
  return false;
}

int sum_of_divisors(int num){
  int sum = 1;
  for (int i = 2; i*i <= num; i++){
    if (num % i == 0){
      sum += i;
      if (num/i != i)
	sum += num/i;
    }
  }
  return sum;
}

int main() {
  for (int i = 1; i < NON_ABUNDANT_LIMIT; i++){
    if (sum_of_divisors(i) > i)
      abundant_set.insert(i);
  }

  long sum = 0;
  for (int i = 0; i < NON_ABUNDANT_LIMIT; i++)
    if (is_sum_of_abundants(i) == false)
      sum += i;

  std::cout << "Sum: " << sum << std::endl;

  return 0;
}
