#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/AForm.hpp"

/** SECTION - constructors destructors **/

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	FT_MSG("RobotomyRequestForm() Constructor")
	std::srand(std::time(NULL));

	return;
}

RobotomyRequestForm::RobotomyRequestForm(STRING target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	FT_MSG("RobotomyRequestForm(string) Constructor")
	std::srand(std::time(NULL));

	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("RobotomyRequestForm", 72, 45), _target(copy._target)
{
	FT_MSG("RobotomyRequestForm(RobotomyRequestForm copy) Constructor")

	std::srand(std::time(NULL));
	*this = copy;

	return;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	FT_MSG("~RobotomyRequestForm Destructor")

	return;
}

/* !SECTION */

/** SECTION - overload operators **/

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
		return *this;

	return *this;
}

/* !SECTION */

/** SECTION - other functions **/

void RobotomyRequestForm::execute(const Bureaucrat &b)
{
	// FT_MSG("RobotomyRequestForm::execute")

	AForm::beExecuted(b);

	int min = 1;
	int max = 100;
	int nb = min + std::rand() % ((max + 1) - min);

	if (nb % 2 == 0)
		PRINT << GREEN BOLT << "Robotomy was a success" << RESEND;
	else
		PRINT << ORANGE BOLT << "Robotomy failed" << RESEND;
		
	PRINT << BLUE BOLT << b.getName() << " executed " << AForm::getName() << RESEND;
}

/* !SECTION */
