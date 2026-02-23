#include "../includes/RPN.hpp"

/* SECTION - constructors destructors */

RPN::RPN() : _input("")
{
    FT_MSG("RPN() Constructor")
    return;
}

RPN::RPN(STRING str) : _input(str)
{
    FT_MSG("RPN(string) Constructor")
    return;
}

RPN::RPN(const RPN *copy) : _input(copy->_input)
{
    FT_MSG("RPN(RPN copy) Constructor")
    *this = copy;
    return;
}

RPN::~RPN()
{
    FT_MSG("RPN() Destructor")
    return;
}

/* !SECTION */

/* SECTION - overload operators */

RPN &RPN::operator=(const RPN &src)
{
    if (this != &src)
    {
        ;
    }

    return *this;
}

/* !SECTION */

/* SECTION - methods */

// if number is valid: return true
// else: return false
bool RPN::valid_number(char &nb)
{
    if (_arg.length() == 1 &&
        _arg.find_first_not_of("0123456789") == std::string::npos)
    {
        nb = _arg[0];
        return true;
    }
    return false;
}

// if value is valid: return true
// else: return false
bool RPN::valid_signal(char &signal)
{
    if (_arg.length() == 1 &&
        _arg.find_first_not_of("+-/*") == std::string::npos)
    {
        signal = _arg[0];
        return true;
    }
    return false;
}

// return and removes last element
int RPN::get_stack_nb(std::list<int> &stack)
{
    if (stack.empty())
        throw InvalidInput();

    int nb;

    nb = stack.back();
    stack.pop_back();
    return nb;
}

int RPN::get_result()
{
    std::stringstream ss(_input);
    std::string token;

    std::list<int> stack;
    while (ss >> token) 
    {
        int nb1;
        int nb2;
        char value;

        _arg = token;

        if (valid_number(value))
        {
            stack.push_back(value - '0');
        }
        else if (valid_signal(value))
        {
            nb2 = get_stack_nb(stack);
            nb1 = get_stack_nb(stack);
            
            switch (value)
            {
            case '+':
                stack.push_back(nb1 + nb2);
                break;

            case '-':
                stack.push_back(nb1 - nb2);
                break;

            case '*':
                stack.push_back(nb1 * nb2);
                break;

            case '/':
                if (nb2 == 0)
                    throw DivisionByZero();
                stack.push_back(nb1 / nb2);
                break;
            }
            if (SHOW_MATHS == true)

                PRINT << BRIGHT_CYAN << nb1 << " " << value << " " << nb2 << " = " << stack.back() << RESEND;
        }
        else
        {
            throw InvalidInput();
        }
    }
    if (stack.size() != 1)
        throw InvalidInput();
    return stack.back();
}

/* !SECTION */

/* SECTION - exceptions */

const char *RPN::InvalidInput::what() const throw()
{
    return (RED "Invalid input" RESET);
}

const char *RPN::DivisionByZero::what() const throw()
{
    return (RED "Division by zero" RESET);
}

/* !SECTION */