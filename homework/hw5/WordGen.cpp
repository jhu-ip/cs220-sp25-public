#include <string>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cstdlib>

// You are not required to use any of the next three functions, but might find them useful.  Modify them
// if it seems appropriate to do so, or delete them.  They may prove useful for trimming the contents
// of the file that you read.

/* Removes whitespace from the left end of a string */
void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

/* Removes whitespace from the right end of a string */
void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

/* Removes whitespace from both ends of a string */
void trim(std::string &s) {
    rtrim(s);
    ltrim(s);
}



using std::endl;
using std::cout;

int main(int argc, char * argv[]){

    // seed the RNG
    std::srand( ( unsigned int ) std::time( nullptr ) );

    // read command-line arguments
    // arg1: filename
    // arg2: max value of K
    // arg3: num characters to generate (or -m)
    if (4 != argc){
        cout << "ERROR: Wrong number of command-line arguments (expected 3, received " << (argc-1) << ")" << endl;
        return -1;
    }


    // other error checking, rest of your main code to go here :)


    return 0;

}