/*
 * FileCompressor.h
 *
 *  Created on: May 7, 2018
 *      Author: blu
 */

#ifndef FILEDECOMPRESSOR_H_
#define FILEDECOMPRESSOR_H_

#include "BaseFileProcessor.h"

class FileDeompressor: public BaseFileProcessor {
public:
	FileDeompressor(string inputfile, string outputfile) :
			BaseFileProcessor(inputfile, outputfile) {
	}
	;
	void decompresse();
	virtual ~FileDeompressor();
};

#endif /* FILECOMPRESSOR_H_ */
