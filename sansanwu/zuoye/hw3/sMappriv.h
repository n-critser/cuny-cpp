/*
  File: sMappriv.h
  ----------------
  Private section for sMap.h interface for
  an array-based hash map

  Code taken from site Below: 
  http://cs.stanford.edu/people/eroberts/courses/cs106b/chapters/12-implementing-maps.pdf

 */

/*
  Type: cellT
  --------------------
  This type represents a key-value pair. This implementation of the sMap
  class stores these entries in an dynamic array.
 */

struct cellT {
        std::string key;
        ValueType value;
        cellT *link;
};

/*  Constants */

static const int INITIAL_SIZE = 8191;

/* Instance variables   */

cellT **buckets;
int nBuckets;           /* Allocated size of the array */
int nEntries;              /* Current number of entries*/

/* Private function prototypes */
int hash(std::string s);
cellT *findCell(cellT *chain, std::string key);
void deleteChain(cellT *chain);

