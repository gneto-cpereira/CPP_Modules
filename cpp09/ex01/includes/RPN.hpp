#ifndef RPN_HPP
#define RPN_HPP

#include "Strings.h"

#include <algorithm>
#include <exception>
#include <list>
#include <fstream>
#include <sstream>

#define SHOW_MATHS true

class RPN
{
private:
	/* attributes */
	const STRING _input;
	STRING _arg;
	/* methods */
	bool valid_number(char &);
	bool valid_signal(char &);
	int get_stack_nb(std::list<int> &);

public:
	/* constructors destructors */
	RPN();
	RPN(STRING);
	RPN(const RPN *copy);
	~RPN();

	/* operators */
	RPN &operator=(const RPN &src);

	/* methods */
	int get_result();

	/* exceptions */
	class InvalidInput : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class DivisionByZero : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif