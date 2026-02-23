#include "../includes/Bureaucrat.hpp"

int main(void)
{
	// ANCHOR - valid grade instance
	MAIN_MSG("valid grade instance")
	{
		Bureaucrat bob("bob", 2);
	}
	SPACER(3)
	
	// ANCHOR - invalid grade instantiate (0)
	MAIN_MSG("invalid grade instantiate (0)")
	{
		try
		{
			Bureaucrat bob("bob1", 0);
			PRINT << bob << ENDL;
		}
		CATCH
	}
	SPACER(3)

	// ANCHOR - invalid grade instantiate (151)
	MAIN_MSG("invalid grade instantiate (151)")
	{
		try
		{
			Bureaucrat bob("bob1", 151);
			PRINT << bob << ENDL;
		}
		CATCH
	}
	SPACER(3)

	// ANCHOR - getName(), getGrade()
	MAIN_MSG("getName(), getGrade()")
	{
		Bureaucrat bob("bob", 2);
		PRINT << bob.getName() << " grade is " << bob.getGrade() << RESEND;
	}
	SPACER(3)

	// ANCHOR - incrementGrade()
	MAIN_MSG("incrementGrade()")
	{
		Bureaucrat bob("bob", 2);
		PRINT << bob << ENDL;

		try
		{
			bob.incrementGrade();
			PRINT << bob << ENDL;
		}
		CATCH

		try
		{
			bob.incrementGrade();
			PRINT << bob << ENDL;
		}
		CATCH
	}
	SPACER(3)

	// ANCHOR - decrementGrade()
	MAIN_MSG("decrementGrade()")
	{
		Bureaucrat bob("bob", 149);
		PRINT << bob << ENDL;

		try
		{
			bob.decrementGrade();
			PRINT << bob << ENDL;
		}
		CATCH

		try
		{
			bob.decrementGrade();
			PRINT << bob << ENDL;
		}
		CATCH
	}
	SPACER(3)

	return 0;
}
