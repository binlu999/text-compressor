/*
 * FileCompressor.cpp
 *
 *  Created on: May 7, 2018
 *      Author: blu
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "FileDecompressor.h"
#include "Trade.h"

void FileDeompressor::decompresse() {
	std::ofstream ostream;
	ostream.open(outfile,ios::out);
	std::ifstream instream(infile);

	if (instream.fail()) {
		throw "Input file could not be opened.";
	}

	std::string line;

	Trade preTrade;
	long long lineNum = 0;
	try {

		while (std::getline(instream, line)) {
			Trade trade = Trade(line);
			trade.restore(preTrade);
			if (preTrade.isInitialized())
				ostream << endl;
			ostream << trade.outputRestore();
			preTrade = trade;
		}
	} catch (const char* msg) {
		cout << msg << "on line " << to_string(lineNum) << endl;
		throw msg;
	}

	ostream.close();
}

FileDeompressor::~FileDeompressor() {
}

