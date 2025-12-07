#ifndef _BITCOIN_EXCHANGE_H_
#define _BITCOIN_EXCHANGE_H_

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#define ERR_OPENFILE "Error: could not open file."
#define ERR_NUMARG "Error: ./btc [FILE_PATH]"

class BitcoinExchange
{
	public:
	 BitcoinExchange();
	 ~BitcoinExchange();
	 BitcoinExchange(const BitcoinExchange &other);
	 BitcoinExchange& operator=(const BitcoinExchange &other);

	 void outputBitcoinExchange(std::string fileName);

	private:
};

#endif // _BITCOIN_EXCHANGE_H_
