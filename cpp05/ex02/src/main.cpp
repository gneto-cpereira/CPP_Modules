#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

int main(void)
{
	// ANCHOR - ShrubberyCreationForm
	MAIN_MSG("ShrubberyCreationForm")
	{
		try
		{
			ShrubberyCreationForm tree_paper("tree");
			Bureaucrat bob("bob", 138);

			PRINT << tree_paper << ENDL;
			PRINT << bob << ENDL;

			// unsigned
			try
			{
				tree_paper.execute(bob);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}

			tree_paper.beSigned(bob);

			// bob grade too low
			try
			{
				tree_paper.execute(bob);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}

			bob.incrementGrade();

			// valid
			try
			{
				tree_paper.execute(bob);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		CATCH
	}
	SPACER(10)

	// ANCHOR - RobotomyRequestForm
	MAIN_MSG("RobotomyRequestForm")
	{
		try
		{
			RobotomyRequestForm robotomy_paper("tree");
			Bureaucrat bob("bob", 46);

			PRINT << robotomy_paper << ENDL;
			PRINT << bob << ENDL;

			// unsigned
			try
			{
				robotomy_paper.execute(bob);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}

			robotomy_paper.beSigned(bob);

			// bob grade too low
			try
			{
				robotomy_paper.execute(bob);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}

			bob.incrementGrade();

			// valid
			try
			{
				for (int i = 0; i < 10; i++)
					robotomy_paper.execute(bob);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		CATCH
	}
	SPACER(10)

	// ANCHOR - PresidentialPardonForm
	MAIN_MSG("PresidentialPardonForm")
	{
		try
		{
			PresidentialPardonForm president_paper("tree");
			Bureaucrat bob("bob", 6);

			PRINT << president_paper << ENDL;
			PRINT << bob << ENDL;

			// unsigned
			try
			{
				president_paper.execute(bob);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}

			president_paper.beSigned(bob);

			// bob grade too low
			try
			{
				president_paper.execute(bob);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}

			bob.incrementGrade();

			// valid
			try
			{
				president_paper.execute(bob);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		CATCH
	}
	SPACER(10)

	return 0;
}
