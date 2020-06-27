/* Project Euler - Problem 22
  Names scores
  What is the total of all the name scores in the file?

  p022.exe
  g++ p022.cpp -o p022.exe
  
  Comments/Issues:
  > 

  References:
  > 

*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> //std::sort

int main() {
  std::ifstream file;
  file.open("p022_names.txt");
  
  if (!file.is_open()){
    std::cout << "unable to open the names file." << std::endl;
    exit(1);
  }
  std::vector<std::string> name_vec;
  std::string aux;
  while (getline(file,aux,','))
    name_vec.push_back(aux);
  
  file.close();
  
  std::sort(name_vec.begin(), name_vec.end());

  int sum = 0;
  for (int i = 0; i < name_vec.size(); i++){
    for (int j = 1; j < name_vec[i].size()-1; j++){
      sum += (name_vec[i][j] - 'A' + 1) * (i+1);
    }
  }

  std::cout << "Score: " << sum << std::endl;
}
