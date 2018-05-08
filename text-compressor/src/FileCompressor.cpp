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
#include "FileCompressor.h"
#include "Trade.h"

void FileCompressor::compresse() {
	std::ofstream ostream;
	ostream.open(outfile,ios::out);

	std::ifstream instream(infile);

	if(instream.fail()){
		throw "Input file could not be opened.";
	}

	std::string line;

	Trade preTrade;
	long long lineNum=0;
	try{
	while (std::getline(instream, line)) {
		lineNum +=1;
		Trade trade = Trade(line);
		Trade tmpTrade = trade;
		trade.retuce(preTrade);
		if(preTrade.isInitialized())
			ostream << endl;
		ostream << trade.outputReduce();
		preTrade = tmpTrade;
	}
	}catch (const char* msg){
		cout << msg << "on line " << to_string(lineNum)<<endl;
		throw msg;
	}

	ostream.close();
}

FileCompressor::~FileCompressor() {
}

