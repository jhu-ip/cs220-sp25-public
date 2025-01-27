# this is a configuration file for bash shell

# in the line below, change emacs to vim if that is your preference
export EDITOR=emacs

# introduce shorthand command names so we don't have to type as much
# gccc is for C compiling with standard 601.220 compilation flags
# g+++ is for C++ compiling with standard 601.220 compilation flags
alias gccc='gcc -std=c99 -pedantic -Wall -Wextra'
alias g+++='g++ -std=c++11 -pedantic -Wall -Wextra'
