#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

class Intern
{
public:
	/* constructors destructors */
	Intern();
	Intern(const Intern &copy);
	~Intern();

	/* overload operators */
	Intern &operator=(const Intern &src);

	/* other funtions */
	AForm *makeForm(STRING form_name, STRING form_target);

	/* exceptions */
	class InvalidForm : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif