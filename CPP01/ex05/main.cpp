#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./harl <level>" << std::endl;
		return 1;
	}

	Harl harl;
	harl.complain(av[1]);
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	harl.complain("UNKNOWN"); // Testing an unknown level
	harl.complain(""); // Testing a no level 
}
