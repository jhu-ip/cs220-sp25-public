
/*
This program illustrates the utility of nested container classes.  


PART 3 TO DO: Read in words from standard input until end of file
occurs, and populate the map<string, int> named counters so that each
entry has a key which is a word collected and the corresponding value
is the number of times that word appears in the file.  The code to
output the contents of the counters map is already present in this file.



PART 4 TO DO: Run through the counters map you populated in PART 4,
and copy over the data into a new map called words_by_freq, but
rearrange your data so that each entry in the new map has an integer
key, and has an entire vector as its value.  The vector will hold all
strings with the frequency indicated by key.
You can think of the words_by_freq map as a notebook of information,
where each entry is a page, and at the top of the page, you wrote
an integer frequency, and on the rest of the page, you've written
a list of all the words you encountered with that frequency.


PART 5 TO DO: Using const_iterators, write code to output the contents
of the words_by_freq map, arranged by frequency.  So, if the input words were:

and Mama called the doctor and the doctor said no more monkeys

Then the output would be:
Frequency: 1
Mama
called
monkeys
more
no
said

Frequency: 2
and
doctor
the

*/

#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::vector;


int main() {

  map<string, int> counters; // We'll store each word and an associated counter

  //PART 3 TO DO:  fill in code here to populate counters before it gets output

  
  


  
  // Loop through the map and print contents, making use of the iterator
  // it to successively point to each entry in the map in turn.
  // We use it->first and it->second to get current key and value.
  cout << endl;
  for (map<string, int>::const_iterator it = counters.cbegin();
       it != counters.cend();
       ++it) {
    cout << "word " << it->first << " has " << it->second
	 << " occurrences" << endl;

  }

  


  //PART 4 TO DO:  fill in code here to populate words_by_freq
  //Note that this map has int keys and values which are vectors of strings.
  map<int, vector<string> > words_by_freq;








  
  // PART 5 TO DO: write code here to output the contents of the
  // words_by_freq map, arranged by frequency.


  

  

  return 0;
}
