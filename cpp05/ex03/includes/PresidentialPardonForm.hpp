#ifndef PRESIDENTIAL_PARDON_FORM_H
#define PRESIDENTIAL_PARDON_FORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    const STRING _target;

public:
    /* constructors */
    PresidentialPardonForm();
    PresidentialPardonForm(STRING target);
    PresidentialPardonForm(const PresidentialPardonForm &copy);
    ~PresidentialPardonForm();

    /* overload operators */
	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

    /* other functions */
    void execute(const Bureaucrat &b);
};

#endif