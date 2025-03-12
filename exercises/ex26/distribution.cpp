#include <iostream>
#include <vector>
#include <random>
#include <cassert>
#include <chrono>
#include <cmath>

std::vector< double >::const_iterator naive_find_last_iterator( std::vector< double >::const_iterator begin , std::vector< double >::const_iterator end , double v );
std::vector< double >::const_iterator  fast_find_last_iterator( std::vector< double >::const_iterator begin , std::vector< double >::const_iterator end , double v );

// PART 2 TODO: Declare a function called "make_cumulative" that converts a std::vector< double > from a probability density function to a cumulative distribution function.

int main( void )
{
  unsigned int bin_num , sample_num , find_num;
  std::default_random_engine generator;
  std::vector< double > distribution;
  std::uniform_real_distribution< double > uniform_distribution( 0.0 , 1.0 );

  // Read in the number of bins in the distribution
  std::cout << "Number of bins: ";
  std::cin >> bin_num;

  // Read in the number of random samples that should be used to sample the distribution
  std::cout << "Number of random samples: ";
  std::cin >> sample_num;

  // Get the number of find tests that should be run
  std::cout << "Number of find tests: ";
  std::cin >> find_num;

  // Set the values of the distribution
  distribution.resize( bin_num , 0 );
  std::binomial_distribution< int > binomial_distribution( bin_num-1 , 0.5 );
  for( int i=0 ; i<sample_num ; i++ ) distribution[ binomial_distribution( generator ) ] += 1./sample_num;

  // Turn the distribution of probabilities into a cumulative distribution
  make_cumulative( distribution );

  // Validate that this is a CDF
  for( size_t i=1 ; i<distribution.size() ; i++ ) assert( distribution[i-1]<=distribution[i] );
  assert( std::abs( distribution.back() - 1. )<1e-8 );
  std::cout << "Confirmed that the CDF seems reasonable" << std::endl;

  // Validate that the naive method finds a correct iterator
  generator.seed(0);
  for( unsigned int i=0 ; i<find_num ; i++ )
    {
      double v = uniform_distribution( generator );
      
      std::vector< double >::const_iterator iter = naive_find_last_iterator( distribution.begin() , distribution.end() , v );
      assert( iter!=distribution.end() );
      assert( *iter<=v );
      assert( iter+1==distribution.end() || *(iter+1)>=v );
    }
  std::cout << "Confirmed that the naive find seems reasonable" << std::endl;

  // Validate that the fast method finds a correct iterator
  generator.seed(0);
  for( unsigned int i=0 ; i<find_num ; i++ )
    {
      double v = uniform_distribution( generator );
      
      std::vector< double >::const_iterator iter = fast_find_last_iterator( distribution.begin() , distribution.end() , v );
      assert( iter!=distribution.end() );
      assert( *iter<=v );
      assert( iter+1==distribution.end() || *(iter+1)>=v );
    }
  std::cout << "Confirmed that the fast find seems reasonable" << std::endl;


  // Get the time required to find the iterator using the naive algorithm
  generator.seed(0);
  std::chrono::steady_clock::time_point naive_begin = std::chrono::steady_clock::now();
  for( unsigned int i=0 ; i<find_num ; i++ )
      naive_find_last_iterator( distribution.begin() , distribution.end() , uniform_distribution( generator ) );
  std::chrono::steady_clock::time_point naive_end = std::chrono::steady_clock::now();

  // Get the time required to find the prev iterator using the fast algorithm
  generator.seed(0);
  std::chrono::steady_clock::time_point fast_begin = std::chrono::steady_clock::now();
  for( unsigned int i=0 ; i<find_num ; i++ )
      fast_find_last_iterator( distribution.begin() , distribution.end() , uniform_distribution( generator ) );
  std::chrono::steady_clock::time_point fast_end = std::chrono::steady_clock::now();

  std::cout << "Naive find time = " << std::chrono::duration_cast<std::chrono::milliseconds>(naive_end - naive_begin).count() << "(ms)" << std::endl;
  std::cout << " Fast find time = " << std::chrono::duration_cast<std::chrono::milliseconds>( fast_end -  fast_begin).count() << "(ms)" << std::endl;
  
  return 0;
}

// PART 2 TODO: Define a function that converts a std::vector< double > from a probability density function to a cumulative distribution function.

std::vector< double >::const_iterator naive_find_last_iterator( std::vector< double >::const_iterator begin , std::vector< double >::const_iterator end , double v )
{
  // PART 4 TODO: Implement the function returning the iterator with the property that value of v is between the indexed entry and the next one
  return end;
}

std::vector< double >::const_iterator fast_find_last_iterator( std::vector< double >::const_iterator begin , std::vector< double >::const_iterator end , double v )
{
  // PART 5 TODO: Implement the function returning the iterator with the property that value of v is between the indexed entry and the next one
  return end;
}



