#!/bin/bash

## this assumes you have a directory called "tests" inside the current dir
E_BADARGS=65
## Executable name = trees : Adjust accordingly
# encrypt a dir of files after tar
# usage: gpg-zip --symmetric -o d1.tar.pgp d1/*  
function encrypt {
    gpg-zip  --symmetric -o "$1.tar.gpg" $1/* # > "../cryptFiles/$1.gpg"
}

# to decrypt
# gpg-zip -d d1.tar.pgp >>d1.tar
## Make the program 
#make 
case "${1}" in
  "" ) echo "NEED A DIRECTORY TO ENCRYPT" ; exit $E_BADARGS ;;
esac
CRYPTDIR=${1}
TARCRYPT=$CRYPTDIR.tar.gpg
echo -e $CRYPTDIR
echo -e "NOW ENCRYPTING"
encrypt $CRYPTDIR

echo -e "LIST OF FILES ENCRYPTED"

gpg-zip --list-archive $TARCRYPT


## Run Tests  if echo -e doesn't add new lines remove "-e"
#for i in $( ls $CRYPTDIR/*.h *.cpp ); do
#    echo -e  "\n************RUNNING ENCRYPTION ON FILE $i***********" 
#    encrypt  "$i"
#    echo -e "******ENCRYPTION COMPLETED ON $i*********\n "
#done



