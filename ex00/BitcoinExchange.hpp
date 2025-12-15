#ifndef _BITCOIN_EXCHANGE_H_
#define _BITCOIN_EXCHANGE_H_

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#define DATABASE_PATH "./data.csv"

#define ERR_OPENFILE "Error: Could not open file."
#define ERR_NUMARG "Error: ./btc [FILE_PATH]"
#define ERR_INVALID_CSV "Error: The CSV format is incorrect."

class BitcoinExchange
{
	public:
	 BitcoinExchange();
	 ~BitcoinExchange();
	 BitcoinExchange(const BitcoinExchange &other);
	 BitcoinExchange& operator=(const BitcoinExchange &other);

	 void setDataBase();
	 void outputBitcoinExchange(std::string fileName);

	private:
	 std::map<std::string, double> _dataBase;
};

#endif // _BITCOIN_EXCHANGE_H_
