/*
 * trade.cpp
 *
 *  Created on: May 7, 2018
 *      Author: blu
 */

#include "Trade.h"

#include <iostream>
using namespace std;

Trade::Trade(const string &s) {

	if(!validate(s)){
		throw "Invalidate format ";
	}
	std::stringstream linestream(s);
	std::getline(linestream, ticker, ',');
	std::getline(linestream, exchange, ',');
	std::getline(linestream, side, ',');
	std::getline(linestream, condition, ',');
	std::string stime;
	std::getline(linestream, stime, ',');
	time = stoll(stime);
	std::string sreptime;
	std::getline(linestream, sreptime, ',');
	reptime = stoll(sreptime);
	std::getline(linestream, price, ',');
	std::getline(linestream, size, ',');
	delta = reptime - time;
	initialized = true;
}

bool Trade::validate(const string &s) {
	int count = 0;
	for (int i = 0; (unsigned)i <= s.length() - 1; i++) {
		if (s.at(i) == ',')
			count++;
	}
	return count==7;
}

bool Trade::isInitialized() {
	return initialized;
}
void Trade::retuce(const Trade &t) {
	if (ticker.compare(t.ticker) == 0)
		ticker = "";
	if (exchange.compare(t.exchange) == 0)
		exchange = "";
	if (side.compare(t.side) == 0)
		side = "";
	if (condition.compare(t.condition) == 0)
		condition = "";
	time = time - t.time;
	if (price.compare(t.price) == 0)
		price = "";
	if (size.compare(t.size) == 0)
		size = "";
}

void Trade::restore(const Trade &t) {
	if (ticker.compare("") == 0)
		ticker = t.ticker;
	if (exchange.compare("") == 0)
		exchange = t.exchange;
	if (side.compare("") == 0)
		side = t.side;
	if (condition.compare("") == 0)
		condition = t.condition;
	time = time + t.time;
	reptime = time + reptime;
	if (price.compare("") == 0)
		price = t.price;
	if (size.compare("") == 0)
		size = t.size;
}
string Trade::print() {
	return ticker + "," + exchange + "," + side + "," + condition + ","
			+ to_string(time) + "," + to_string(reptime) + "," + price + ","
			+ size;
}

string Trade::outputReduce() {
	return ticker + "," + exchange + "," + side + "," + condition + ","
			+ to_string(time) + "," + to_string(delta) + "," + price + ","
			+ size;
}

string Trade::outputRestore() {
	return ticker + "," + exchange + "," + side + "," + condition + ","
			+ to_string(time) + "," + to_string(reptime) + "," + price + ","
			+ size;
}

