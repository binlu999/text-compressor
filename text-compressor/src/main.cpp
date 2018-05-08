//============================================================================
// Name        : main.cpp
// Author      : Bin Lu
// Version     :
// Copyright   : Open License
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>

#include "Trade.h"
#include "FileCompressor.h"
#include "FileDecompressor.h"

using namespace std;

int compress(string inputfile, string outputfile) {

	FileCompressor compressor = FileCompressor(inputfile, outputfile);
	try {
		compressor.compresse();
		return 0;
	} catch (const char* msg) {
		cout << msg << endl;
		return 1;
	}
}

int decompress(string inputfile, string outputfile) {

	FileDeompressor decompressor = FileDeompressor(inputfile, outputfile);
	try {
		decompressor.decompresse();
		return 0;
	} catch (const char* msg) {
		cout << msg << endl;
		return 1;
	}
}

int test(string inputfile) {

	string compressed = inputfile + ".compressed";
	long long inputSize = 0;

	//Test FileCompressor class
	FileCompressor compressor = FileCompressor(inputfile, compressed);
	try {
		const auto startTime = std::chrono::system_clock::now();
		compressor.compresse();
		const auto endTime = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsedSeconds = endTime - startTime;
		inputSize = compressor.getInputFileSize();
		long long compressedSize = compressor.getOutputFileSize();
		cout << "Input file " << inputfile << " size is "
				<< to_string(inputSize) << endl;
		cout << "Compressed output file " << compressed << " size is "
				<< to_string(compressedSize) << endl;
		double ratio = ((double) (inputSize - compressedSize) / inputSize)
				* 100;
		cout << "Compression ratio: " << ratio << '%' << endl;
		cout << "Compression time: " << elapsedSeconds.count() << " seconds" << endl;

	} catch (const char* msg) {
		cout << msg << endl;
		cout << "Compress " << inputfile << "failed" << endl;
		return 1;
	}

	//Test FileDecompressor class

	string decompressed = inputfile + ".decompressed";
	FileDeompressor decompressor = FileDeompressor(compressed, decompressed);
	try {
		const auto startTime = std::chrono::system_clock::now();
		decompressor.decompresse();
		const auto endTime = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsedSeconds = endTime - startTime;
		long long decompressedSize = decompressor.getOutputFileSize();
		cout << "Input file " << inputfile << " size is "
				<< to_string(inputSize) << endl;
		cout << "Decompressed output file " << decompressed << " size is "
				<< to_string(decompressedSize) << endl;
		if (inputSize == decompressedSize)
			cout
					<< "Compress/Decompress successful since decompressed file has same size as input file"
					<< endl;
		else
			cout
					<< "Compress/Decompress failed since decompressed file has different size as input file"
					<< endl;
		cout << "Deompression time: " << elapsedSeconds.count() << " seconds" << endl;
	} catch (const char* msg) {
		cout << msg << endl;
		return 1;
	}
	return 0;
}

int main(int argc, char* argv[]) {
	std::vector<std::string> args(argv, argv + argc);
	if (args.size() == 4 && args[1] == "-c") {
		return compress(args[2], args[3]);
	} else if (args.size() == 4 && args[1] == "-d") {
		return decompress(args[2], args[3]);
	} else if (args.size() == 3 && args[1] == "-t") {
		return test(args[2]);
	} else {
		cout << "Usage: " << argv[0]
				<< " [-c|-d] [input_file_name] [output_file_name] " << endl;
		cout << "Or " << argv[0] << " -t [input_file_name] " << endl;
	}
	return 9;

}
