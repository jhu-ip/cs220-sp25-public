#include <iostream>
#include <cassert>
#include <vector>

void sort( std::vector< int > *values );

int main( void )
{
  std::vector< int > vec;
  size_t count;

  std::cout << "Enter the count: ";

  // PART 2 TO DO: read in the count of random numbers from the standard input.

  // PART 3 TO DO: Make the "vec" vector store "count" random values

  sort( &vec );

  for( size_t i=1 ; i<vec.size() ; i++ ) assert( vec[i-1]<=vec[i] );

  return 0;
}

void sort( std::vector< int > *values )
{
  // PART 5 TO DO: Define the sort function
}

