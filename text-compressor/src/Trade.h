/*
 * trade.h
 *
 *  Created on: May 7, 2018
 *      Author: blu
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
#ifndef TRADE_H_
#define TRADE_H_

using namespace std;

class Trade {
	std::string ticker="";
	std::string exchange="";
	std::string side="";
	std::string condition="";
	long long time=0;
	long long reptime=0;
	std::string price="";
	std::string size="";
	long long delta=0;
	bool initialized = false;
public:
	Trade(){};
	Trade(const string &s);
	bool validate (const string &s);
	bool isInitialized();
	void retuce(const Trade &t);
	void restore(const Trade &t);
	string print();
	string outputReduce();
	string outputRestore();
};

#endif /* TRADE_H_ */
