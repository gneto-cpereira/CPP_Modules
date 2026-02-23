#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include "Bureaucrat.h"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat
{
private:
	const STRING _name;
	int _grade;

	/* setters */
	void setGrade(int);

public:
	/* constructors destructors */
	Bureaucrat();
	Bureaucrat(STRING name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat();

	/* overload operators */
	Bureaucrat &operator=(const Bureaucrat &src);

	/* getters */
	STRING getName(void) const;
	int getGrade(void) const;

	/* other funtions */
	void incrementGrade(void);
	void decrementGrade(void);

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
std::ostream &operator<<(std::ostream &output, Bureaucrat &bureaucrat);

#endif