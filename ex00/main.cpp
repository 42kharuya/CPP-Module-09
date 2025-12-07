#include "BitcoinExchange.hpp"

int main(int ac, char *av[]) {
	if (ac == 1) {
		std::cerr << ERR_OPENFILE << std::endl;
		return EXIT_FAILURE;
	} else if (ac > 2) {
		std::cerr << ERR_NUMARG << std::endl;
		return EXIT_FAILURE;
	}

	BitcoinExchange bt;

	std::ifstream file(av[1]);
	if (!file) {
		std::cerr << ERR_OPENFILE << std::endl;
		return EXIT_FAILURE;
	}

	std::string line;
	while(std::getline(file, line)) {
		std::cout << line << std::endl;
	}

	return EXIT_SUCCESS;
}
