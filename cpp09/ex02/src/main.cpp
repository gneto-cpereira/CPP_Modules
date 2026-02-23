#include "../includes/PmergeMe.hpp"

// SECTION - press_any_key()

#include <termios.h>
#include <unistd.h>
void press_any_key()
{
	PRINT << LOW_BRIGHT << "Press any key ( )" << CURSOR_LEFT(2);

	struct termios old_terminal, newt;
	tcgetattr(STDIN_FILENO, &old_terminal);
	newt = old_terminal;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	char c = getchar();
	if (!std::isprint(c))
		c = ' ';
	PRINT << c << CURSOR_RIGHT(1) << RESEND;

	tcsetattr(STDIN_FILENO, TCSANOW, &old_terminal);
}

//! SECTION

// SECTION - main()

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;

	MAIN_MSG("vector and deque")
	try
	{
		PmergeMe<std::vector<int> > print_vector;
		PmergeMe<std::vector<int> > pm_vector;
		PmergeMe<std::deque<int> > pm_deque;

		//
		print_vector.set_numbers(ac, av);
		print_vector.print_container();
		//
		pm_vector.set_time();
		pm_vector.set_numbers(ac, av);
		pm_vector.sort();
		double time_vector = pm_vector.get_time();
		//
		pm_deque.set_time();
		pm_deque.set_numbers(ac, av);		
		pm_deque.sort();
		double time_deque = pm_deque.get_time();
		//
		pm_vector.print_container();
		PRINT << BRIGHT_BLUE << "(vector) Size: " << pm_vector.get_size() << ", Time: " << std::fixed << time_vector << " seconds" << RESEND;
		PRINT << BRIGHT_BLUE << "(deque) Size: " << pm_deque.get_size() << ", Time: " << std::fixed << time_deque << " seconds" << RESEND;
	}
	CATCH
	
	SPACER(2)

	return (0);
}

//! SECTION