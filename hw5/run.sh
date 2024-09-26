#!/bin/bash
#Christian Aruba
#cma3939
#slopan_karn93
#if the number of inputs is less than 1, send an error message and end the program
if [ $# -lt 1 ]; then
    echo "You must enter 1 positive integer."
    exit
fi

#if the input is less then or equal to 0, then send another error message
#telling the user that their input must be greater than or equal to 0 and end the message
if [ $1 -le 0 ]; then
    echo "Your integer must be greater than 0."
    exit
fi

if [ $1 == -h ]; then
    echo "Usage: run.sh nnn 
where nnn is a positive integer"
    exit
fi

#send the input to the cpp file with an executable with the piping (|) operator and echo
#echo $1 | ./fizzBuzz

#make directories src and build if they don't exist

if [ ! -d "build" ]; then
   echo "'Build' directory not detected. Making one now."
   mkdir "build"
   echo "Finished creating directory 'Build'."
else
    echo "Directory 'build' detected."


if [ ! -d "src" ]; then
    echo "'src' directory not detected. Making 'src' now."
    mkdir "src"
    echo "Finished creating directory 'src'."
else
    echo "Directory 'src' detected."

#alert the user if the program can't detect CMakeLists.txt
if [ -f "CMakeLists.txt" ]; then
    echo "File 'CMakeLists.txt detected. Copying to src"
    cp CMakeLists.txt src
else
    echo "File 'CMakeLists.txt' missing."
    exit
fi

#alert the user if the source file doesn't exist
if [ -f "fizzBuzz.cpp" ]; then
    echo "File 'fizzBuzz.cpp detected. Copying to src."
    cp fizzBuzz.cpp src
    exit
fi

#change directories to build, run cmake, make the install directory and the exectuble
cd build

cmake -D CMAKE_INSTALL_PREFIX=../install ../src/

make

make install

#move directories to the install directory and run fizzBuzz executable
cd ..

cd /src/install

echo $1 | ./fizzBuzz

exit

fi
