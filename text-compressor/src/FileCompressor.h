/*
 * FileCompressor.h
 *
 *  Created on: May 7, 2018
 *      Author: blu
 */

#ifndef FILECOMPRESSOR_H_
#define FILECOMPRESSOR_H_

#include "BaseFileProcessor.h"

class FileCompressor: public BaseFileProcessor {
public:
	FileCompressor(string inputfile, string outputfile) :
			BaseFileProcessor(inputfile, outputfile) {
	}
	;
	void compresse();
	virtual ~FileCompressor();
};

#endif /* FILECOMPRESSOR_H_ */
