#ifndef SHRUBBERY_CREATION_FORM_H
#define SHRUBBERY_CREATION_FORM_H

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    const STRING _target;

public:
    /* constructors */
    ShrubberyCreationForm();
    ShrubberyCreationForm(STRING target);
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    ~ShrubberyCreationForm();

    /* overload operators */
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

    /* other functions */
    void execute(Bureaucrat const &b);
};

#endif