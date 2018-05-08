#!/bin/bash
g++ -O0 -g3 -Wall -c -std=c++11 -fmessage-length=0 -o "src/FileCompressor.o" "../src/FileCompressor.cpp" 
g++ -O0 -g3 -Wall -c -std=c++11 -fmessage-length=0 -o "src/main.o" "../src/main.cpp" 
g++ -O0 -g3 -Wall -c -std=c++11 -fmessage-length=0 -o "src/FileDecompressor.o" "../src/FileDecompressor.cpp" 
g++ -O0 -g3 -Wall -c -std=c++11 -fmessage-length=0 -o "src/Trade.o" "../src/Trade.cpp" 
g++ -O0 -g3 -Wall -c -std=c++11 -fmessage-length=0 -o "src/BaseFileProcessor.o" "../src/BaseFileProcessor.cpp" 
g++ -o text-compressor "src/BaseFileProcessor.o" "src/FileCompressor.o" "src/FileDecompressor.o" "src/Trade.o" "src/main.o" 
