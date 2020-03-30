/* Project Euler - Problem 13
  Work out the first ten digits of the sum of the following(*) one-hundred 50-digit numbers
  
  p013.exe
  g++ p013.cpp -o p013.exe
  
  Comments/Issues:
  
  References:
  >

*/
#include <iostream>
#include <fstream>
#include <string>
int main() {
  /// unsigned long long sum = 0;
  // no C++ standard data type could be used to get the sum
  // unsigned long long max (ULLONG_MAX) from <climit> = 2^64-1
  
  //each digit will have to be calculated
  
  std::ifstream fin;
  fin.open("p013_numbers.txt");
  
  if (!fin.is_open()){
    std::cout << "unable to open the numbers file." << std::endl;
    exit(1);
  }

  std::string num[100];
  for (int i = 0; i < 100; i++)
    std::getline(fin, num[i]);

  fin.close();
  
  int sum[52];
  for(int i = 0; i < 52; i++)
    sum[i]=0;
  
  for(int i = 0; i < 52; i++){
    if(i <= 49)
      for(int j = 0; j < 100; j++){
	/*
	std::cout << "i: " << i << std::endl;
	std::cout << "j: " << j << std::endl;
	std::cout << "num[j][49-i]-'0': " << (int)(num[j][49-i]-'0') << std::endl;
	*/
	sum[i] += (int)(num[j][49-i]-'0');
	if(sum[i]>=10){
	  sum[i]-=10;
	  sum[i+1]+=1;
	}
      }
    else
      while(sum[i]>=10){
	sum[i]-=10;
	sum[i+1]+=1;
      }
  }
  
  std::cout << "Last 10 digits: ";
  for(int i = 51; i > 41; i--)
    std::cout << sum[i];
  std::cout << std::endl;
  return 0;
}

