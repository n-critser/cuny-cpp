#!/bin/bash

## this assumes you have a directory called "tests" inside the current dir
TESTDIR=tests
## Executable name = trees : Adjust accordingly
function test {
    ./hw2 $1
}

## Make the program 
make 

## Run Tests  if echo -e doesn't add new lines remove "-e"
for i in $( ls $TESTDIR/*.txt ); do
    echo -e  "\n************RUNNING TEST ON FILE $i***********" 
    test  "$i"
    echo -e "******TESTING COMPLETED ON FILE $i*********\n "
done

## Clean the .o and executables 
make cleanall