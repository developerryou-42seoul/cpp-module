#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	BitcoinExchange exchanger;
	if (argc < 2)
		exchanger.panic(ERR_INPUT_FILE_OPEN);
	if (argc > 2)
		exchanger.panic("too many arguments");

	exchanger.readDataBase();
	exchanger.readInput(argv[1]);

	return (0);
}
