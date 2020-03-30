/* Project Euler - Problem 8
  Find the thirteen adjacent digits in the 1000-digit number that have the greatest product.
  What is the value of this product?
  
  p008.exe
  g++ p008.cpp -o p8.exe

*/
#include <iostream>
#include <string>
#include <climits>
#include <cmath>

unsigned long long product_from_str(std::string num_str); 
// 
int main() {
  std::string num_str = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450"; 
  //std::cout << "Number: "<< num_str << std::endl;
  /*
  // Which type of variables should be used?
  std::cout << "Max Product of 13 adjecent digits (9^13): " << (double) std::pow(9,13) << std::endl;
  std::cout << "UINT_MAX: " << (double) UINT_MAX << std::endl;
  std::cout << "ULONG_MAX: " << (double) ULONG_MAX << std::endl;
  std::cout << "ULLONG_MAX: " << (double) ULLONG_MAX << std::endl;
  
  // How to get the product of 13 adjecent digits?
  std::cout << "First 13 digits of the number: "<< num_str.substr(0,13) << std::endl;
  std::cout << "First digits of the number: "<< num_str.at(0) << std::endl;
  std::cout << "Product of the first 13 digits: " << (double) product_from_str(num_str.substr(0,13)) << std::endl;
  std::cout << "Product of 13 neins: " << (double) product_from_str("9999999999999") << std::endl;
  
  // How to iterate?
  std::cout << "num_str size: " << num_str.size() << std::endl;
  std::cout << "num_str.substr(0,13) size: " << num_str.substr(0,13).size() << std::endl;
  */
  int i_max = 0;
  unsigned long long val, max_val = 0;
  for(int i=0; i < num_str.size()-12; i++){
    //std::string sub_num_str = num_str.substr(i,13);
    //std::cout << i << " " << i + 13 << " " << sub_num_str << std::endl;
    val = product_from_str(num_str.substr(i,13));
    if(val > max_val){
      max_val = val;
      i_max = i;
    }
  }
  
  std::cout << "13 digit substring with the maximum product: " << num_str.substr(i_max,13) << std::endl;
  std::cout << "Value of the product: " << product_from_str(num_str.substr(i_max,13)) << std::endl;

  return 0;
}

unsigned long long product_from_str(std::string num_str){
  unsigned long long product = 1; // up to 20 neins for ull
  std::string digit;
  for(int i=0; i < num_str.size(); i++){
    digit = num_str.at(i);  
    product *= std::stoi(digit);
  }
  return product;
}
