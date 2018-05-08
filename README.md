# text-compressor

## Purpose
Compresses a comma delimited CVS file and de-compresses the compressed file back to original file.

## Build
### Build in Windows
Open build folder and run build.bat file to build. The output of build is text-compressor.exe
```
build.bat
```
### Build in unix shell
Open build folder and run build.sh file to build. The ouput of build is text-compressor
```
 ./build.sh
 ```
 ## Usage
 ### In Windows
 ```
text-compressor.exe [-c|-d] [input_file_name] [output_file_name]
-c : compress
-d : decompress
Or 
text-compressor.exe -t [input_file_name]
-t : test
 ```
 ### In unix shell
 ```
./text-compressor [-c|-d] [input_file_name] [output_file_name]
-c : compress
-d : decompress
Or 
./text-compressor -t [input_file_name]
-t : test
```
## Test Metrics
Tested with the data file ebat.csv in the data folder. The test results are:
### In Windows
```
 C:\GIT\text-compressor\text-compressor\build>text-compressor.exe -t ../data/ebat.csv
Input file ../data/ebat.csv size is 17150866
Compressed output file ../data/ebat.csv.compressed size is 9349618
Compression ratio: 45.486%
Compression time: 7.21994 seconds
Input file ../data/ebat.csv size is 17150866
Decompressed output file ../data/ebat.csv.decompressed size is 17150866
Compress/Decompress successful since decompressed file has same size as input file
Deompression time: 6.6494 seconds
```
### In unix shell
```
[root@ip-10-160-161-65 build]# ./text-compressor -t ../data/ebat.csv
Input file ../data/ebat.csv size is 16750867
Compressed output file ../data/ebat.csv.compressed size is 8949619
Compression ratio: 46.5722%
Compression time: 1.79792 seconds
Input file ../data/ebat.csv size is 16750867
Decompressed output file ../data/ebat.csv.decompressed size is 16750867
Compress/Decompress successful since decompressed file has same size as input file
Deompression time: 1.59964 seconds

[root@ip-10-160-161-65 build]# diff ../data/ebat.csv ../data/ebat.csv.decompressed
[root@ip-10-160-161-65 build]#
```

## Error handlering
```
The program will 
- return 0 when success.
- return 1 when input file not found and print stdio error message "Input file could not be opened."
- return 1 when any line of the input file has invalid data format and print stdio error message "Invalidate format on line 9"
- return 9 when other errors.
```



