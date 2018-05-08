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
