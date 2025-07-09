#include "Sed.hpp"

int main(int ac, char **av) {


  if (ac != 4)
    return (std::cout << "Usage: " << av[0]
                      << " <input_file> <string_to_replace> <replacement>"
                      << std::endl,
            1);
	if (std::ifstream(av[1]).good() == false)
		return (std::cout << "Error: Input file does not exist or cannot be opened." << std::endl, 1);

	Sed sed(av[1]);
	sed.replace(av[2], av[3]);
}
