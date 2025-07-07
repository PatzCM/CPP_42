#include "Sed.hpp"

int main(int ac, char **av) {

  if (ac != 4)
    return (std::cout << "Usage: " << av[0]
                      << " <input_file> <string_to_replace> <replacement>"
                      << std::endl,
            1);

	Sed sed(av[1]);
	sed.replace(av[2], av[3]);
}
