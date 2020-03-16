/* Project Euler - Problem 11
  What is the greatest product of four adjacent numbers in the same direction
  in a 20*20 grid?
  
  p011.exe
  g++ p011.cpp -o p011.exe
  
  Comments/Issues:
  > There was no need for the file, could ask for the grid as a std::cin. 
  
  References:

*/
#include <fstream>
#include <iostream>
#include <iomanip>

#define N 20

int file_to_grid(std::ifstream &file, int size, int* grid);
void print_grid(int* grid, int size);
int index(int i, int j);

int main() {
  std::ifstream grid_file;
  grid_file.open("p011_grid.txt");
  
  if (!grid_file.is_open()){
    std::cout << "unable to open the grid file." << std::endl;
    exit(1);
  }
  
  int grid[N*N];
  int size = N;
  file_to_grid(grid_file, N, grid);
  //print_grid(grid, N);
  grid_file.close();
  
  int best = 0;
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      int curr;
      //horizontal
      if (i+3 < size){
        curr = grid[index(i,j)]*grid[index(i+1,j)]*grid[index(i+2,j)]*grid[index(i+3,j)];
        if(curr > best)
          best = curr;
      }
      //vertical
      if (j+3 < size){
        curr = grid[index(i,j)]*grid[index(i,j+1)]*grid[index(i,j+2)]*grid[index(i,j+3)];
        if(curr > best)
          best = curr;
      }
      //diagonal downward
      if (i+3 < size && j+3 < size){
        curr = grid[index(i,j)]*grid[index(i+1,j+1)]*grid[index(i+2,j+2)]*grid[index(i+3,j+3)];
        if(curr > best)
          best = curr;
      }
      //diagonal upward
      if (i+3 < size && j > 3){
        curr = grid[index(i,j)]*grid[index(i+1,j-1)]*grid[index(i+2,j-2)]*grid[index(i+3,j-3)];
        if(curr > best)
          best = curr;
      }
    }
  }
  
  std::cout << best << std::endl;
  
  return 0;
}

int file_to_grid(std::ifstream &file, int size, int* grid){
  int num;
  
  for(int i = 0; i< size*size; i++){
    if(file){
      file >> num;
      grid[i] = num;
    } else {
      std::cout << "error" << std::endl;
      return 0;
    }
  }
  return 1;
}

void print_grid(int* grid, int size){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      std::cout << std::setw(2) << std::setfill('0') <<  grid[i*N+j] << " ";
    }
    std::cout << std::endl;
  }
}

int index(int i, int j){
  return i*N+j;
}