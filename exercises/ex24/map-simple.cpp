/*

This program uses a map (a container from the Standard Template
Library or STL) to house a very simple collection of phone contacts.
A map is an _associative_ container that holds items which are each
key-value pairs (like dictionaries in Python).  That is, a map
associates a value with each key present.  In a map, unlike in a
vector, we can no longer access items in the container by position
number.  Instead, we access a mapped value by specifying the key
associated with it.  Key values in a map must therefore be unique.

Note the use below of what looks like array usage in the expression:
   contacts[name] = phone;

But here, name is a key value rather than an int index.  Using the []
operator this way will cause a new map entry to be created with the
given key value if one does not already exist.  (If we don't want such
behavior, we could instead use the .count or .find methods in the map 
class to check for a particular entry without automatically creating 
one.)

Note also the use of the iterator to traverse the items in the map.
When iterator it is pointing to a particular pair in the map, we can
use it->first to refer to the pair's key and it->second to refer to
the pair's mapped value.

For more information about maps, include more map class methods, see
the map class description at
   http://www.cplusplus.com/reference/map/map/

*/

#include <iostream>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;


int main() {
  string name, phone;

  // This map will store ordered pairs consisting of
  // a single name and single phone number
  map<string, string> contacts;
  
  // Read the input, keeping track of each contact's data
  while (cin >> name >> phone) {

    //Note that line below creates a new entry, if name is a new key,
    //or just updates an existing entry if name is a repeated key.
    //The assignment enters 'phone' as the (new) value associated
    //with the key 'name'.
    contacts[name] = phone;  //syntax looks like array, but it's a map!
  }

  // Now loop through the map and print whats in it.  Using const_iterator
  // instead of iterator ensures that no changes get made to map while
  // iterating.
  cout << endl << "CONTACT LIST" << endl;

  for (map<string, string>::const_iterator it = contacts.cbegin();
       it != contacts.cend();
       ++it) {

    // Use it->first and it->second to get current key and value,
    // respectively.
    cout << it->first << ": " << it->second  << endl;
  }
  
  return 0;
}
