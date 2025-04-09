#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <stdexcept>

/* Collect integers from a file; store them in a vector */
std::vector<int> readFile(char* filename) {
  std::ifstream fin(filename);
  std::vector<int> numbers(10);

  int n = 0;
  size_t index = 0;
  while(true) {
    fin >> n;
    if (fin.eof()) { // if we're out of file, return
      return numbers;
    }
    if (fin.fail()) { // if we failed to read an int, throw an exception
      throw std::invalid_argument("File contains non-integer data!\n");
    }
    // otherwise, just add it into the vector
    numbers.at(index) = n;
    index++;
  }

  throw std::logic_error("ERROR: should never get here!");
  return numbers;
}


int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Error: program requires a filename as an argument\n";
    return 0;
  }

  std::vector<int> numbers;
  numbers = readFile(argv[1]);

  std::cout << "Read numbers: ";
  for(int &i : numbers) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
