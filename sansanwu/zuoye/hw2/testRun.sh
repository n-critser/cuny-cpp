#!/bin/bash

## Executable name = trees : Adjust accordingly
function test {
    ./trees $1
}

## Make the program 
make 

## Run Tests  if echo -e doesn't add new lines remove "-e"
for i in $( ls *.txt ); do
    echo -e  "\n************RUNNING TEST ON FILE $i***********" 
    test  "$i"
    echo -e "******TESTING COMPLETED ON FILE $i*********\n "
done

## Clean the .o and executables 
make cleanall