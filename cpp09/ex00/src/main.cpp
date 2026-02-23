#include "../includes/BitcoinExchange.hpp"
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
	if (ac != 2)
		return (1);
	{
		BitcoinExchange btc(av[1], "assets/data.csv");
		// MAIN_MSG("test get csv data")
		try
		{
			btc.get_csv_data();
			btc.print_btc_info();
		}
		CATCH
	}
	// press_any_key();
	SPACER(2)

	return (0);
}

//! SECTION