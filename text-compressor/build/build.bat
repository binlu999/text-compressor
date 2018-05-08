IF EXIST src GOTO DOBUILD
mkdir src
:DOBUILD

g++ -O0 -g3 -Wall -c -fmessage-length=0 -o "src\\FileCompressor.o" "..\\src\\FileCompressor.cpp" 
g++ -O0 -g3 -Wall -c -fmessage-length=0 -o "src\\main.o" "..\\src\\main.cpp" 
g++ -O0 -g3 -Wall -c -fmessage-length=0 -o "src\\FileDecompressor.o" "..\\src\\FileDecompressor.cpp" 
g++ -O0 -g3 -Wall -c -fmessage-length=0 -o "src\\Trade.o" "..\\src\\Trade.cpp" 
g++ -O0 -g3 -Wall -c -fmessage-length=0 -o "src\\BaseFileProcessor.o" "..\\src\\BaseFileProcessor.cpp" 
g++ -o text-compressor.exe "src\\BaseFileProcessor.o" "src\\FileCompressor.o" "src\\FileDecompressor.o" "src\\Trade.o" "src\\main.o" 
