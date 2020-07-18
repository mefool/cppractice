/* Project Euler - Problem 26
  Reciproval cycles

  p026.exe
  g++ p026a.cpp -o p026a.exe
  
  Comments/Issues:
  > 

*/
#include <iostream>
#include <vector>

#define LIMIT 1000

int cycle_lenght(int d){
  if (d == 0)
    return 0;

  int pos = 1;
  int div = 1;
  
  std::vector<int> last_pos(d,0);

  for(;;){
    int r = div % d;
    if (r == 0)
      return 0;
    if (last_pos[r] != 0)
      return pos - last_pos[r];
    last_pos[r] = pos;
    pos++;
    div = r*10;
  }
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
