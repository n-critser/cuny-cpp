/*
  File: sMappriv.h
  ----------------
  Private section for sMap.h interface for
  an array-based hash map
 */

/*
  Type: keyValuePairT
  --------------------
  This type represents a key-value pair. This implementation of the sMap
  class stores these entries in an array.
 */

struct keyValuePairT {
        std::string key;
        ValueType value;
};

/*  Constants */

static const int INITIAL_CAPACITY = 100;

/* Instance variables   */

keyValuePairT *array;   /* a dynamic array of key/value pairs */
int capacity;           /* Allocated size of the array        */
int count;              /* Current number of entries*/

/* Private function prototypes */
int findKey(std::string key);
void expandCapacity();

