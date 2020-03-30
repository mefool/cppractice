/* Project Euler - Problem 18
  Find the maximum total from top to bottom of the triangle
  
  p018.exe
  g++ p018.cpp -o p018.exe
  
  Comments/Issues:
  > There was no need for the file, could ask for the grid as a std::cin. 
  
  References:

*/
#include <fstream>
#include <iostream>
#include <iomanip>

#define N 15
#define SIZE N*(N+1)/2

int file_to_arr(std::ifstream &file, int size, int* arr);
void print_triangle(int* grid, int size);
int index(int i, int j);

int main() {
  std::ifstream triangle_file;
  triangle_file.open("p018_triangle.txt");
  
  if (!triangle_file.is_open()){
    std::cout << "unable to open the triangle file." << std::endl;
    exit(1);
  }
  
  int tri[SIZE];
  int size = SIZE;
  file_to_arr(triangle_file, SIZE, tri);
  triangle_file.close();

  /* tested */
  print_triangle(tri, SIZE);
  //int i = N-1, j = N-1;
  //std::cout << "tri("<<i<<","<<j<<") = "<<tri[index(i,j)];

  /* While we could possibly go from the top to bottom, and use a recursive 
     function for all paths, if we look to the problem from the bottom up, 
     the problem becomes simpler. Go figure.
   */
  for (int i = N-2; i >= 0; i--){
    for (int j = 0; j < i+1; j++){
      tri[index(i,j)] += (tri[index(i+1,j)] > tri[index(i+1,j+1)]) ?
	                  tri[index(i+1,j)] : tri[index(i+1,j+1)];	
    }
  }
  print_triangle(tri, SIZE);
  std::cout << "Maximum total: " << tri[0] << std::endl;
  
  return 0;
}

int file_to_arr(std::ifstream &file, int size, int* arr){
  int num;
  
  for(int i = 0; i < size; i++){
    if(file){
      file >> num;
      arr[i] = num;
    } else {
      std::cout << "error" << std::endl;
      return 0;
    }
  }
  return 1;
}

void print_triangle(int* tri, int size){
  int n = 0, i_skip = 0;
  for(int i = 0; i < size; i++){
    std::cout << std::setw(2) << std::setfill('0') <<  tri[i] << " ";
    if (!(i_skip--)){
      i_skip = ++n;
      std::cout << std::endl;
    }
  }
}

int index(int i, int j){
  if (i > N || j > i)
    return 0;
  return i*(i+1)/2 + j;
}
