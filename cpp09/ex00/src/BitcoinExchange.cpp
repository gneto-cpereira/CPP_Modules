#include "../includes/BitcoinExchange.hpp"

/* SECTION - constructors destructors */

BitcoinExchange::BitcoinExchange() : _input_file("input.txt"), _data_file("data.csv")
{
    FT_MSG("BitcoinExchange() Constructor")
    return;
}

BitcoinExchange::BitcoinExchange(STRING input_file, STRING data_file) : _input_file(input_file), _data_file(data_file)
{
    FT_MSG("BitcoinExchange(string, string) Constructor")
    return;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange *copy)
{
    FT_MSG("BitcoinExchange(BitcoinExchange copy) Constructor")
    *this = copy;
    return;
}

BitcoinExchange::~BitcoinExchange()
{
    FT_MSG("BitcoinExchange() Destructor")
    return;
}

/* !SECTION */

/* SECTION - overload operators */

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this != &src)
    {
        this->_data = src._data;

    }

    return *this;
}

/* !SECTION */

/* SECTION - methods */

void BitcoinExchange::get_csv_data()
{
    std::ifstream file(_data_file.c_str());

    if (!file.is_open())
    {
        throw InvalidFile();
    }

    STRING line;

    while (std::getline(file, line))
    {
        STRING date;
        STRING rate;
        if (line.find(',') == 10 && line.length() >= 12)
        {
            date = line.substr(0, 10);
            rate = line.substr(11);

            _data[date] = atof(rate.c_str());
        }
    }

    file.close();
}

// if line is valid: return true
// else: return false
bool BitcoinExchange::valid_line(STRING line)
{
    if (line.find('|') == 11 &&
        line.length() >= 14 &&
        line.find_first_not_of("0123456789- |.\n") == std::string::npos)
    {
        return true;
    }
    PRINT << RED << "Invalid input: " << _line << RESEND;
    return false;
}

// if value is valid: return true
// else: return false
bool BitcoinExchange::valid_value(double &value_d)
{
    STRING value_s = _line.substr(13);
    if (value_s.find_first_not_of("0123456789.") == std::string::npos &&
        (value_d = atof(value_s.c_str())) < 1000)
    {
        return true;
    }
    PRINT << RED << "Invalid number: " << _line << RESEND;
    return false;
}

// if date is valid: return true
// else: return false
bool BitcoinExchange::valid_date(STRING &date)
{
    date = _line.substr(0, 10);

    if (date.find_first_not_of("0123456789-") == std::string::npos)
    {
        int day = atoi((_line.substr(8, 2)).c_str());
        int month = atoi((_line.substr(5, 2)).c_str());
        int year = atoi((_line.substr(0, 4)).c_str());

        // PRINT << GREEN << "Day: " << day << RESEND;
        // PRINT << GREEN << "Month: " << month << RESEND;
        // PRINT << GREEN << "Year: " << year << RESEND;

        if (day >= 1 && day <= 31)
        {
            switch (month)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (day <= 31)
                    return true;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (day <= 30)
                    return true;
                break;
            case 2:
                // leap year
                if (year % 4 == 0 && (year % 100 != 0 || (year % 100 == 0 && year % 400 == 0)))
                {
                    if (day <= 29)
                        return true;
                }
                // non leap year
                else
                {
                    if (day <= 28)
                        return true;
                }
                break;
            }
        }
    }
    PRINT << RED << "Invalid date: " << _line << RESEND;
    return false;
}

void BitcoinExchange::print_btc_info()
{
    std::ifstream file(_input_file.c_str());

    if (!file.is_open())
    {
        throw InvalidFile();
    }

    int first = true;

    while (std::getline(file, _line))
    {
        if (first == true)
        {
            first = false;
            continue;
        }
        STRING date;
        double value;
        double rate = 0.0;
        if (valid_line(_line))
        {
            if (valid_date(date) && valid_value(value))
            {

                std::map<STRING, double>::iterator first = _data.begin();
                std::map<STRING, double>::iterator last = --_data.end();

                if (date < first->first)
                    rate = 0;
                else if (date > last->first)
                    rate = last->second;
                else
                {
                    std::map<STRING, double>::iterator it;
                    for (it = _data.begin(); it != _data.end(); ++it)
                    {
                        std::map<STRING, double>::iterator next_it;
                        next_it = it;
                        ++next_it;
                        if (it->first <= date && next_it->first > date)
                        {
                            rate = it->second;
                            break;
                        }
                    }
                }

                PRINT << BLUE << date << " : " << value << " = " << value * rate << RESEND;
            }
        }
    }

    file.close();
}

/* !SECTION */

/* SECTION - exceptions */

const char *BitcoinExchange::InvalidFile::what() const throw()
{
    return (RED "Unable to open file" RESET);
}

/* !SECTION */