#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <sstream>
# include <stdlib.h> 
# include <string>
# include <map>
# include <iostream>
# include <string>
# include <fstream>

# define DB_FILE "./data.csv"

# define ERR_DB_FILE_OPEN "could not open data file."
# define ERR_DB_FILE_READ "could not read data file."

# define ERR_HEADER_BAD "bad header => "

# define ERR_VALUE_INVALID "invalid number format."
# define ERR_VALUE_NOT_POSITIVE "not a positive number."
# define ERR_VALUE_TOO_LARGE "too large a number."

# define ERR_INPUT_FILE_OPEN "could not open file."
# define ERR_INPUT_EMPTY "empty input."
# define ERR_INPUT_BAD "bad input => "

class BitcoinExchange {
private:
	std::map<std::string, float> dataBase;
	float getPrice(const std::string& date);

	void checkValidDate(const std::string& date);
	void checkValidValue(const std::string& value, const float fvalue);

public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange& ref);
	BitcoinExchange& operator=(const BitcoinExchange& ref);
	~BitcoinExchange(void);

	void readDataBase(void);
	void readInput(const std::string& inputfile);

	void panic(const std::string& msg);
};

#endif