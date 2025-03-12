#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstddef>
#include <cctype>

using std::string;
using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::cerr;

// this helper function is complete
bool is_vowel(char c) {
  const string VOWELS = "aeiou";
  return VOWELS.find(tolower(c)) != string::npos;
}

// TODO: finish writing this helper function to create and return
// the abbreviated version of the word parameter
string abbreviate(string word) {
  string result;
  bool last_was_vowel = false;

  for (size_t i = 0; i < word.size(); i++) {
    bool cur_is_vowel = is_vowel(word[i]);

    // TODO: finish coding this loop to complete the function
  }

  return result;
}


int main(int argc, char **argv) {

  if (argc != 3) {
    cerr << "Usage: abbrev <infile> <outfile>" << endl;
    return 1;
  }

  // TODO: implement the primary functionality here

  return 0;
}
