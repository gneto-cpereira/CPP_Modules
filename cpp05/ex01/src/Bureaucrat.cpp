#include "../includes/Bureaucrat.hpp"

/* SECTION - constructors destructors */

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	FT_MSG("Bureaucrat() Constructor")
	return;
}

Bureaucrat::Bureaucrat(STRING name, int grade) : _name(name)
{
	FT_MSG("Bureaucrat(string, int) Constructor")

	this->setGrade(grade);

	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name)
{
	FT_MSG("Bureaucrat(Bureaucrat copy) Constructor")

	*this = copy;
	return;
}

Bureaucrat::~Bureaucrat()
{
	FT_MSG("~Bureaucrat Destructor")
	return;
}

/* !SECTION */

/* SECTION - overload operators */

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
		this->_grade = src._grade;

	return *this;
}

/* !SECTION */

/* SECTION - getters */

STRING Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

/* !SECTION */

/* SECTION - setters */

void Bureaucrat::setGrade(int grade)
{
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

/* !SECTION */

/* SECTION - other functions */

void Bureaucrat::incrementGrade(void)
{
	FT_MSG("Bureaucrat::incrementGrade")

	this->setGrade(this->_grade - 1);
}

void Bureaucrat::decrementGrade(void)
{
	FT_MSG("Bureaucrat::decrementGrade")

	this->setGrade(this->_grade + 1);
}

void Bureaucrat::signForm(AForm &form)
{
	FT_MSG("Bureaucrat::signForm")

	if (this->_grade <= form.getSignGrade())
	{
		PRINT << YELLOW << "Bureaucrat " << this->_name << " signed \"" << form.getName() << "\"" << RESEND;
		form.beSigned(*this);
	}
	else
		PRINT << YELLOW << "Bureaucrat " << this->_name << " grade is too low to sign \"" << form.getName() << "\"" << RESEND;
		
}

/* !SECTION */

/* SECTION - exceptions */

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (RED "Exception: Bureaucrat: Grade Too Low" RESET);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (RED "Exception: Bureaucrat: Grade Too High" RESET);
}

/* !SECTION */

/* SECTION - overload signals */

std::ostream &operator<<(std::ostream &output, Bureaucrat &Bureaucrat)
{
	output
		<< CYAN << BOLT << "BUREAUCRAT" << RESEND
		<< CYAN << R_ALIGN(15) << "Name: " << RESET << Bureaucrat.getName() << ENDL
		<< CYAN << R_ALIGN(15) << "Grade: " << RESET << Bureaucrat.getGrade() << ENDL;
	return (output);
}

/* !SECTION */
