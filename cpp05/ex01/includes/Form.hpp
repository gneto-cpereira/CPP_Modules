#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const STRING _name;
	bool _signed;
	const int _sign_grade;
	const int _execute_grade;

	/* setters */
	int setGrade(int);

public:
	/* constructors destructors */
	AForm();
	AForm(STRING name, int sign_grade, int execute_grade);
	AForm(const AForm &copy);
	~AForm();

	/* overload operators */
	AForm &operator=(const AForm &src);

	/* getters */
	STRING getName(void) const;
	bool getSigned(void) const;
	int getSignGrade(void) const;
	int getExecuteGrade(void) const;

	/* other funtions */
	void beSigned(Bureaucrat &bureaucrat);

	/* exceptions */
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

/* overload signals */
std::ostream &operator<<(std::ostream &output, AForm &Form);

#endif