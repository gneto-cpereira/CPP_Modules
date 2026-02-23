#include "../includes/Intern.hpp"

/* SECTION - constructors destructors */

Intern::Intern()
{
	FT_MSG("Intern() Constructor")
	return;
}

Intern::Intern(const Intern &copy)
{
	FT_MSG("Intern(Intern copy) Constructor")

	*this = copy;
	return;
}

Intern::~Intern()
{
	FT_MSG("~Intern Destructor")
	return;
}

/* !SECTION */

/* SECTION - overload operators */

Intern &Intern::operator=(const Intern &src)
{
	if (this != &src)
		return *this;

	return *this;
}

/* !SECTION */

/* SECTION - other functions */

AForm *Intern::makeForm(STRING form_name, STRING form_target)
{
	STRING form_list[] = {"PresidentialPardonForm", "ShrubberyCreationForm", "RobotomyRequestForm"};
	int len = 3;
	int code = 0;

	for (int i = 0; i < len; i++)
	{
		if (form_name == form_list[i])
			code = i + 1;
	}

	switch (code)
	{
	case 1:
		return (new PresidentialPardonForm(form_target));

	case 2:
		return (new ShrubberyCreationForm(form_target));

	case 3:
		return (new RobotomyRequestForm(form_target));

	default:
		throw InvalidForm();
		break;
	}

	return NULL;
}

/* !SECTION */

const char *Intern::InvalidForm::what() const throw()
{
    return (RED "Form doesn't exist" RESET);
}
