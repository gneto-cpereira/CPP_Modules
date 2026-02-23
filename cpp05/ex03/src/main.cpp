#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Intern.hpp"

int main(void)
{
	// ANCHOR - Intern
	MAIN_MSG("Intern")
	{
		try
		{
			Intern alex;
			Bureaucrat bob("bob", 1);
			AForm *tree_paper = alex.makeForm("RobotomyRequestForm", "jeb");

			PRINT << *tree_paper << ENDL;
			PRINT << bob << ENDL;

			// valid
			try
			{
				bob.signForm(*tree_paper);				
				tree_paper->execute(bob);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}

			delete tree_paper;
		}
		CATCH
	}
	SPACER(10)

	return 0;
}
