/*
  File: sMap.h
  -----------
  Simplified Map template class
 */


#ifndef _sMap_h
#define _sMap_h

#include <iostream>
#include <cstdlib>

/*
  Class: sMap
  -----------
  Definition for a class of key-value pairs.  Keys are always
  Strings but other values can be of any type. Value types use the
  template syntax  sMap<int> or sMap<string>

 */

template <typename ValueType>
class sMap {

public:
/*
  Constuctor: sMap
  Usage: sMap<int> map1;
  ----------------------
  creates a new map
*/
        sMap();

        /*
          Destructor: ~sMap
          Usage: delete mp;
          ------------------
          Frees any heap storage associated with this map.
        */
        ~sMap();


        /*
          Method: size
          Usage: nEntries = map.size();
          ------------------------------
          Returns the number of entries in this map
         */
        int size();

        /*
          Method: isEmpty
          Usage: if (map.isEmpty())...
          -----------------------------
          Returns true if the map contains no entries else
          returns false
         */

        bool isEmpty();

        /*
          Method: clear
          Usage: map.clear();
          ----------------------
          Removes all entries from the map
         */

        void clear();

        /*
          Method: put
          Usage: map.put(key, value);
          ----------------------------
          Associates "key" with "value" in this map. Any value
          previously associated witht his "key" is replaced by the
          new value.
         */

        void put(std::string key, ValueType value);

        /*
          Method: get
          Usage: value = map.get(key);
          ----------------------------
          If key is found in this map, this method returns the associated
          value. If key is not found, the key method raises an error.
          Clients can use the containsKey method to veryify the presence of
          a key before attempting to "get" a key/value .
         */

        ValueType get(std::string key);

        /*
          Method: containsKey
          Usage: if (map.containsKey(key))...
          ------------------------------------
          Returns true if there is an entry for key in this map,
          false otherwise. 
         */

        bool containsKey(std::string key);

        /*
          Method: remove
          Usage:  map.remove(key);
          -------------------------
          Removes any entry for key from this map. If there is no entry
          for the key, the map is unchanged. 
         */

        void remove(std::string key);

        /*
          Method: operator[]
          Usage: map["key"]=value;
          ----------------------------------------


        */
        ValueType & operator[](std::string key);

        /*
          Method: mapAll
          Usage: map.mapAll(fn);
          ---------------------------------------
          Go through every entry in the map and apply fn to it.
        */
        //void mapAll( void (*fn)(std::string, ValueType));
        void mapAll();
        typedef void (*sMapFnT)(std::string , ValueType);
        //typedef void (*visit_function)(T &);

private:
        #include "sMappriv.h"

};

#include "sMapimpl.cpp"

#endif
