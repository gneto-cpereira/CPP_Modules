#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void)
{
	// ANCHOR - Form
	MAIN_MSG("Form")
	{
		try
		{
			AForm paper("paper", 3, 1);
			PRINT << paper << ENDL;
		}
		CATCH
	}
	SPACER(3)

	// ANCHOR - Form invalid grade (0)
	MAIN_MSG("Form invalid grade (0)")
	{
		try
		{
			AForm paper("paper", 0, 1);
			PRINT << paper << ENDL;
		}
		CATCH
	}
	SPACER(3)

	// ANCHOR - Form invalid grade (151)
	MAIN_MSG("Form invalid grade (151)")
	{
		try
		{
			AForm paper("paper", 151, 1);
			PRINT << paper << ENDL;
		}
		CATCH
	}
	SPACER(3)

	// ANCHOR - Form beSigned() valid
	MAIN_MSG("Form beSigned() valid")
	{
		AForm paper("paper", 1, 1);
		Bureaucrat bob("bob", 1);

		PRINT << paper << ENDL;
		PRINT << bob << ENDL;

		try
		{
			paper.beSigned(bob);
		}
		CATCH

		PRINT << paper << ENDL;
	}
	SPACER(3)

	// ANCHOR - Form beSigned() invalid
	MAIN_MSG("Form beSigned() invalid")
	{
		AForm paper("paper", 1, 1);
		Bureaucrat bob("bob", 3);

		PRINT << paper << ENDL;
		PRINT << bob << ENDL;
		try
		{
			paper.beSigned(bob);
		}
		CATCH

		PRINT << paper << ENDL;
	}
	SPACER(3)

	// ANCHOR - Bureaucrat signForm() valid
	MAIN_MSG("Bureaucrat signForm() valid")
	{
		AForm paper("paper", 1, 1);
		Bureaucrat bob("bob", 1);

		PRINT << paper << ENDL;
		PRINT << bob << ENDL;
		try
		{
			bob.signForm(paper);
		}
		CATCH

		PRINT << paper << ENDL;
	}
	SPACER(3)

	// ANCHOR - Bureaucrat signForm() invalid
	MAIN_MSG("Bureaucrat signForm() invalid")
	{
		AForm paper("paper", 1, 1);
		Bureaucrat bob("bob", 2);

		PRINT << paper << ENDL;
		PRINT << bob << ENDL;
		try
		{
			bob.signForm(paper);
		}
		CATCH

		PRINT << paper << ENDL;
	}
	SPACER(3)

	return 0;
}
