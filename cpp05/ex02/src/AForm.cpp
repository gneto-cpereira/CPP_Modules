#include "../includes/AForm.hpp"

/** SECTION - constructors destructors **/

AForm::AForm() : _name("default"), _signed(false), _sign_grade(150), _execute_grade(150)
{
	FT_MSG("AForm() Constructor")
	return;
}

AForm::AForm(STRING name, int sign_grade, int execute_grade) : _name(name), _signed(false), _sign_grade(this->setGrade(sign_grade)), _execute_grade(this->setGrade(execute_grade))
{
	FT_MSG("AForm(string, int, int) Constructor")
	return;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _sign_grade(copy._sign_grade), _execute_grade(copy._execute_grade)
{
	FT_MSG("AForm(AForm copy) Constructor")

	*this = copy;

	return;
}

AForm::~AForm()
{
	FT_MSG("~AForm Destructor")
	return;
}

/* !SECTION */

/** SECTION - overload operators **/

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
		this->_signed = src._sign_grade;

	return *this;
}

/* !SECTION */

/** SECTION - getters **/

STRING AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned(void) const
{
	return this->_signed;
}

int AForm::getSignGrade(void) const
{
	return this->_sign_grade;
}

int AForm::getExecuteGrade(void) const
{
	return this->_execute_grade;
}

/* !SECTION */

/** SECTION - setters **/

int AForm::setGrade(int grade)
{
	if (grade < MAX_GRADE)
		throw AForm::GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw AForm::GradeTooLowException();
	else
		return grade;
}

/* !SECTION */

/** SECTION - other functions **/

void AForm::beSigned(Bureaucrat &b)
{
	FT_MSG("AForm::beSigned")

	if (b.getGrade() <= this->_sign_grade)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::beExecuted(Bureaucrat const &b)
{
	if (this->_signed == false)
		throw AForm::UnsignedFormException();
	if (b.getGrade() > this->_execute_grade)
		throw AForm::GradeTooLowException();
}

/* !SECTION */

/** SECTION - exceptions **/

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return (RED "Exception: Form: Grade Too Low" RESET);
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return (RED "Exception: Form: Grade Too High" RESET);
}

const char *AForm::UnsignedFormException::what(void) const throw()
{
	return (RED "Exception: Form: Form unsigned" RESET);
}

/* !SECTION */

/** SECTION - overload signals **/

std::ostream &operator<<(std::ostream &output, AForm &Form)
{
	output
		<< CYAN << BOLT << "FORM" << RESEND
		<< CYAN << R_ALIGN(15) << "Name: " << RESET << Form.getName() << ENDL
		<< CYAN << R_ALIGN(15) << "Signed: " << RESET << (Form.getSigned() ? "yes" : "no") << ENDL
		<< CYAN << R_ALIGN(15) << "Sign G.: " << RESET << Form.getSignGrade() << ENDL
		<< CYAN << R_ALIGN(15) << "Execute G.: " << RESET << Form.getExecuteGrade() << ENDL;
	return (output);
}

/* !SECTION */
