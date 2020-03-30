/* Project Euler - Problem 15
  Lattice Paths

  p015.exe
  g++ p015.cpp -o p015.exe
  
  Comments/Issues:
  > Using the binomial_coefficeint recursive way took to long, for a N above 12.
  > Also the return value of the binomial coeficient is quite big.

  References:
  > https://en.wikipedia.org/wiki/Lattice_path
  > https://mathworld.wolfram.com/DyckPath.html <not usefull>
  > https://mathworld.wolfram.com/LatticePath.html
  > https://en.wikipedia.org/wiki/Binomial_coefficient
  >
  >

*/
#define N 21
#include <iostream>
/*
long long binomial_coef(int n, int k){
  if (k == 0 || k == n)
    return 1;
  return binomial_coef(n-1, k-1) + binomial_coef(n-1, k);

  > std::cout << "result: " << binomial_coef(n+n, n) << std::endl;
}*/

int main() {
  // A N*N sized grid will have (N+1)(N+1) intersections/points. 
  long long grid[N][N] = {0};

  grid[0][0] = 1;
  for(int i = 1; i < N; i++){
    for(int j = 0; j <= i; j++){
      grid[j][i] = (j > 0 ? grid[j-1][i] : 0) + grid[j][i-1];
      grid[i][j] = grid[j][i];
    }
  }
  std::cout << "result: " << grid[N-1][N-1] << std::endl;
}

