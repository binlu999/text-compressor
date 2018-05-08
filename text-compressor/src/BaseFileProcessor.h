/*
 * BaseFileProcessor.h
 *
 *  Created on: May 7, 2018
 *      Author: blu
 */
#include <iostream>
#include <sstream>
using namespace std;

#ifndef BASEFILEPROCESSOR_H_
#define BASEFILEPROCESSOR_H_

class BaseFileProcessor {
protected:
	std::string infile = "";
	std::string outfile = "";
public:
	BaseFileProcessor(string inputfile, string outputfile) {
		infile = inputfile;
		outfile = outputfile;
	}
	;
	long long getFileSize(string fileName);
	long long getInputFileSize();
	long long getOutputFileSize();
	virtual ~BaseFileProcessor();
};

#endif /* BASEFILEPROCESSOR_H_ */
