#include "RPN.hpp"

int	main(int argc, char **argv)
{
	RPN rpn;
	if (argc != 2)
	{
        std::cerr<<ERR_ARG<<std::endl;
		return(1);
	}
	if (!rpn.isValid(argv[1]))
    {
        std::cerr<<ERR_ARG_INVALID<<std::endl;
		return(1);
    }
    try {
        std::cout << rpn.calculate(argv[1]) << std::endl;
    }
    catch (std::exception& e) {
        std::cerr<<ERR_ARG_INVALID<<std::endl;
    }
	return (0);
}
