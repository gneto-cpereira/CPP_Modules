#ifndef ROBOTOMY_REQUEST_FORM_H
#define ROBOTOMY_REQUEST_FORM_H

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    const STRING _target;

public:
    /* constructors */
    RobotomyRequestForm();
    RobotomyRequestForm(STRING target);
    RobotomyRequestForm(const RobotomyRequestForm &copy);
    ~RobotomyRequestForm();

    /* overload operators */
	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

    /* other functions */
    void execute(Bureaucrat const &b);
};

#endif