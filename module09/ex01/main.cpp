#include "RPN.hpp"

int	main(int argc, char **argv)
{
	RPN rpn;
	if (argc != 2)
	{
        std::cout<<ERR_ARG<<std::endl;
		return(1);
	}
	if (!rpn.isValid(argv[1]))
    {
        std::cout<<ERR_ARG_INVALID<<std::endl;
		return(1);
    }
    try {
        std::cout << rpn.calculate(argv[1]) << std::endl;
    }
    catch (std::exception& e) {
        std::cout<<ERR_ARG_INVALID<<std::endl;
    }
	return (0);
}
