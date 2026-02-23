#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "Strings.h"

#include <algorithm>
#include <exception>
#include <map>
#include <fstream>

class BitcoinExchange
{
private:
	/* attributes */
	std::map<STRING, double> _data;
	const STRING _input_file;
	const STRING _data_file;
	STRING _line;
	/* methods */
	bool valid_line(STRING);
	bool valid_value(double &);
	bool valid_date(STRING &);

public:
	/* constructors destructors */
	BitcoinExchange();
	BitcoinExchange(STRING, STRING);
	BitcoinExchange(const BitcoinExchange *copy);
	~BitcoinExchange();

	/* operators */
	BitcoinExchange &operator=(const BitcoinExchange &src);

	/* methods */
	void get_csv_data();
	void print_btc_info();

	/* exceptions */
	class InvalidFile : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif