/*
 * BaseFileProcessor.cpp
 *
 *  Created on: May 7, 2018
 *      Author: blu
 */

#include "BaseFileProcessor.h"
#include <iostream>

long long BaseFileProcessor::getFileSize(std::string filename) // path to file
{
    FILE *p_file = NULL;
    p_file = fopen(filename.c_str(),"rb");
    fseek(p_file,0,SEEK_END);
    long long size = ftell(p_file);
    fclose(p_file);
    return size;
}

long long BaseFileProcessor::getInputFileSize()
{
	return getFileSize(infile);
}
long long BaseFileProcessor::getOutputFileSize(){
	return getFileSize(outfile);
}

BaseFileProcessor::~BaseFileProcessor() {
}

