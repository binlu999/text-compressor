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

using namespace std;

void compress(string inputfile, string outputfile) {

	cout << "Compressing input file " << inputfile << endl;

	/*
	 std::ifstream file(inputfile);
	 /*
	 std::string str;
	 while (std::getline(file, str)) {
	 cout << str;
	 }
	 */
	std::ifstream file(inputfile);
	std::string line;

	while (std::getline(file, line)) {
		cout << "LINE:" << line << endl;


		std::stringstream linestream(line);

		std::string data;
		int val1;
		int val2;

		std::getline(linestream, data, ',');
		cout << data << endl;

	}

	std::ifstream infile(inputfile, fstream::in);
	if (infile.is_open()) {
		std::string ticker;
		char exchange;
		char side;
		char condition;
		int time;
		int reptime;
		std::string price;
		std::string size;
		char c;

		cout << "Read input file " << inputfile << endl;

		while (infile >> ticker >> c && c == ',')
			//>> c >> exchange >> c >> side >> c >> condition
			//>> c >> time >> c >> reptime >> c >> price >> c >> size)
			//&& c == ',')
			std::cout << ticker << "|" << endl;
		/*
		 << exchange << "|" << side << "|"
		 << condition << "|" << time << "|" << reptime << "|"
		 << price << "|" << size << "\n";
		 */
	}
	infile.close();

	unsigned char nextChar;
	fstream fin(inputfile, fstream::in);

	if (!fin) {
		cout << "Unable to open file " << inputfile;
		exit(1); // terminate with error
	}

	// first, calculate the frequencies of each character
	while (fin >> noskipws >> nextChar) {
		cout << nextChar;
	}

	cout << "Compressed input file " << inputfile << endl;

}

int main(int argc, char* argv[]) {
	std::vector<std::string> args(argv, argv + argc);
	if (args.size() == 4 && args[1] == "-c") {
		compress(args[2], args[3]);
	} else if (args.size() == 3 && args[1] == "-d") {

	} else {
		cout << "Usage: " << argv[0]
				<< " [-c|-d] [input_file_name] [output_file_name] " << endl;
	}
	return 0;
}
