#include "BitcoinExchange.hpp"

#define DATABASE_PATH "./data.csv"

int main(int ac, char *av[]) {

	// argument check
	if (ac != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return EXIT_FAILURE;
    }

    std::string filename = av[1];

	// open inputfile
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return EXIT_FAILURE;
    }

    // initialize BitcoinExchange with the database path
    BitcoinExchange btc;
    try {
        btc = BitcoinExchange(DATABASE_PATH);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

	std::string line;

	// header check
    std::getline(inputFile, line);
    if (!(line == "date | value")) {
        std::cerr << "Error: first line is not a header." << std::endl;
        return EXIT_FAILURE;
    }

	// convert one line at a time.
    while (std::getline(inputFile, line)) {
        try {
            std::cout << btc.exchange(line) << std::endl;
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
	}

    return EXIT_SUCCESS;
}
