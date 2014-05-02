#!/bin/bash

## this assumes you have a directory called "tests" inside the current dir
E_BADARGS=65
## Executable name = trees : Adjust accordingly
function encrypt {
    gpg  --symmetric -o "$1.gpg" $1 # > "../cryptFiles/$1.gpg"
}

## Make the program 
#make 
case "${1}" in
  "" ) echo "NEED A DIRECTORY TO ENCRYPT" ; exit $E_BADARGS ;;
esac
CRYPTDIR=${1}
## Run Tests  if echo -e doesn't add new lines remove "-e"
for i in $( ls $CRYPTDIR/*.h *.cpp ); do
    echo -e  "\n************RUNNING ENCRYPTION ON FILE $i***********" 
    encrypt  "$i"
    echo -e "******ENCRYPTION COMPLETED ON $i*********\n "
done



