#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <utility>
#include <string>
#include <sstream>
#include <exception>

namespace Chess
{
	// This class describes the general class of exceptions that can be thrown within the Chess program
	class Exception : public std::exception
	{
	protected:
		std::string _message;
	public:
		Exception( void ) : _message( "" ) {}
		Exception( const std::string &message ) : _message( message ) {}
		const char *what( void ) const noexcept { return _message.c_str(); }
	};
}
#endif // EXCEPTIONS_H
