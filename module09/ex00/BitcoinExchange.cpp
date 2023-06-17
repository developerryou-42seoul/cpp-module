#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref) {
    *this = ref;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref) {
    this->dataBase = ref.dataBase;
    return *this;
}

BitcoinExchange::~BitcoinExchange(void) {};

float BitcoinExchange::getPrice(const std::string& date)
{
	std::map<std::string, float>::iterator it = this->dataBase.upper_bound(date);
	if (it == this->dataBase.begin())
		throw std::runtime_error(ERR_INPUT_BAD + date);
    return (--it)->second;
}

void BitcoinExchange::checkValidDate(const std::string &date)
{
	if (date.empty())
		throw std::runtime_error(ERR_INPUT_EMPTY);

 	const std::size_t dash = date.find('-');
    const std::size_t next_dash = date.find('-', dash + 1);

	if (dash == std::string::npos || next_dash == std::string::npos
	|| date.find_first_not_of("0123456789-") != std::string::npos)
		throw std::runtime_error(ERR_INPUT_BAD + date);

	std::string str_year = date.substr(0, dash);
	std::string str_month = date.substr(dash + 1, next_dash - dash - 1);
	std::string str_day = date.substr(next_dash + 1);
	if (str_year.length() != 4 || str_month.length() != 2 || str_day.length() != 2)
		throw std::runtime_error(ERR_INPUT_BAD + date);

	int year, month, day;

	std::stringstream ss_year(str_year);
	std::stringstream ss_month(str_month);
	std::stringstream ss_day(str_day);
	ss_year >> year;
	ss_month >> month;
	ss_day >> day;

	if (month < 1 || month > 12)
		throw std::runtime_error(ERR_INPUT_BAD + date);
	if (str_day.find_first_not_of("0123456789") != std::string::npos
	|| (day < 1 || day > 31)
	|| (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
	|| (day > 29 && month == 2)
	|| (day == 29 && month == 2 && !((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))))
		throw std::runtime_error(ERR_INPUT_BAD + date);
}

void BitcoinExchange::checkValidValue(const std::string& value, const float fvalue)
{
	if (value.empty() || value.find_first_not_of("0123456789.-") != std::string::npos
	|| value[0] == '.' || value[value.length() - 1] == '.')
		throw std::runtime_error(ERR_VALUE_INVALID);
	else if (value[0] == '-')
		throw std::runtime_error(ERR_VALUE_NOT_POSITIVE);
	else if (fvalue >= 1000)
		throw std::runtime_error(ERR_VALUE_TOO_LARGE);
}

void BitcoinExchange::readDataBase(void)
{
	std::ifstream fin(DB_FILE);
    std::string line;

	if (fin.fail())
		panic(ERR_DB_FILE_OPEN);

	try
	{
		std::getline(fin, line);
		while (std::getline(fin, line))
		{
			const std::size_t index = line.find(',');
			std::string str_price = line.substr(index + 1);
			std::stringstream ss_price(str_price);
			float price;
			ss_price >> price;
			this->dataBase[line.substr(0, index)] = price;
		}
		fin.close();
	}
	catch(const std::exception& e)
	{
		fin.close();
		panic(ERR_DB_FILE_READ);
	}

}

void BitcoinExchange::readInput(const std::string& inputfile)
{
	std::ifstream fin(inputfile.c_str());
    std::string line;

	if (fin.fail())
		panic(ERR_INPUT_FILE_OPEN);

    std::getline(fin, line);
	const std::size_t index = line.find('|');
	if (index == std::string::npos || line.length() < index + 2)
		panic(ERR_HEADER_BAD + line);
	std::string date = line.substr(0, index - 1);
	std::string value = line.substr(index + 2);
	if (date.compare("date") != 0 || value.compare("value") != 0)
		panic(ERR_HEADER_BAD + line);

    while (std::getline(fin, line))
    {
		try
		{
			const size_t index = line.find('|');
			if (index == std::string::npos || line.length() < index + 2)
				throw std::runtime_error(ERR_INPUT_BAD + line);

			std::string date = line.substr(0, index - 1);
			checkValidDate(date);
			std::string str_value = line.substr(index + 2);
			std::stringstream ss_value;
			float fvalue;
			ss_value >> fvalue;
			checkValidValue(str_value, fvalue);
			float price = getPrice(date);

			std::cout<<date<<" => "<<fvalue<<" = "<<fvalue * price <<std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout<<"Error: "<<e.what()<<std::endl;
		}
    }
    fin.close();
}

void BitcoinExchange::panic(const std::string& msg)
{
	std::cerr<<"Error: "<<msg<<std::endl;
	exit(1);
}