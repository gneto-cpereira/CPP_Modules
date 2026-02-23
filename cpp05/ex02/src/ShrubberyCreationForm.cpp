#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/AForm.hpp"

/** SECTION - constructors destructors **/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	FT_MSG("ShrubberyCreationForm() Constructor")

	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(STRING target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	FT_MSG("ShrubberyCreationForm(string) Constructor")

	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("ShrubberyCreationForm", 145, 137), _target(copy._target)
{
	FT_MSG("ShrubberyCreationForm(ShrubberyCreationForm copy) Constructor")

	*this = copy;

	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	FT_MSG("~ShrubberyCreationForm Destructor")

	return;
}

/* !SECTION */

/** SECTION - overload operators **/

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
		return *this;

	return *this;
}

/* !SECTION */

/** SECTION - other functions **/

void ShrubberyCreationForm::execute(Bureaucrat const &b)
{
	// FT_MSG("ShrubberyCreationForm::execute")

	AForm::beExecuted(b);

	STRING file_name = this->_target + "_shrubbery";

	std::ofstream new_file(file_name.c_str());

	if (new_file.is_open()) {
        new_file << "    _\\/_            _\\/_            _\\/_      \n";
        new_file << "     /\\              /\\              /\\       \n";
        new_file << "     /\\              /\\              /\\       \n";
        new_file << "    /  \\            /  \\            /  \\      \n";
        new_file << "    /~~\\o           /~~\\o           /~~\\o     \n";
        new_file << "   /o   \\          /o   \\          /o   \\     \n";
        new_file << "  /~~*~~~\\        /~~*~~~\\        /~~*~~~\\    \n";
        new_file << " o/    o \\       o/    o \\       o/    o \\    \n";
        new_file << " /~~~~~~~~\\~`    /~~~~~~~~\\~`    /~~~~~~~~\\~` \n";
        new_file << "/__*_______\\    /__*_______\\    /__*_______\\  \n";
        new_file << "     ||              ||              ||          \n";
        new_file << "   \\====/          \\====/          \\====/     \n";
        new_file << "    \\__/            \\__/            \\__/      \n";
        new_file.close();
		PRINT << GREEN BOLT << "ASCII trees created successfully" << RESEND;
    } else {
        std::cerr << "Cannot open file\n";
    }

	PRINT << BLUE BOLT << b.getName() << " executed " << AForm::getName() << RESEND;
}

/* !SECTION */














