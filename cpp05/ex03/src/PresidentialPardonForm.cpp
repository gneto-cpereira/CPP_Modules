#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/AForm.hpp"

/** SECTION - constructors destructors **/

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	FT_MSG("PresidentialPardonForm() Constructor")

	return;
}

PresidentialPardonForm::PresidentialPardonForm(STRING target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	FT_MSG("PresidentialPardonForm(string) Constructor")

	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm("PresidentialPardonForm", 25, 5), _target(copy._target)
{
	FT_MSG("PresidentialPardonForm(PresidentialPardonForm copy) Constructor")

	*this = copy;

	return;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	FT_MSG("~PresidentialPardonForm Destructor")

	return;
}

/* !SECTION */

/** SECTION - overload operators **/

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
		return *this;

	return *this;
}

/* !SECTION */

/** SECTION - other functions **/

void PresidentialPardonForm::execute(const Bureaucrat &b)
{
	// FT_MSG("PresidentialPardonForm::execute")

	AForm::beExecuted(b);

	PRINT << GREEN BOLT << this->_target << "has been pardoned by Zaphod Beeblebrox" << RESEND;

	PRINT << BLUE BOLT << b.getName() << " executed " << AForm::getName() << RESEND;
}

/* !SECTION */
