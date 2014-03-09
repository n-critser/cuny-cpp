/*
  File: sMapimpl.cpp
  -------------------
  Implementation of map interface using the array-based representation.
  
 */

#ifdef _sMap_h

template <typename ValueType>
sMap<ValueType>::sMap() {
        capacity = INITIAL_CAPACITY;
        array = new keyValuePairT[capacity];
        count = 0;
}

template <typename ValueType>
sMap<ValueType>::~sMap() {
        delete[] array;
}

template <typename ValueType>
int sMap<ValueType>::size() {
        return count;
}

template <typename ValueType>
bool sMap<ValueType>::isEmpty(){
        return count;
}

template <typename ValueType>
void sMap<ValueType>::clear() {
        count = 0;
}

/*
  Implementation: put
  ----------------
  The put method calls findKey to search for an existing key.
  If the key is found, the new value replaces the old value.
  If not, the new key value pair are added, expanding the capacity
  if necessary.
 */

template <typename ValueType>
void sMap<ValueType>::put(std::string key, ValueType value) {
        int index = findKey(key);
        if (index == -1) {
                if (count == capacity) expandCapacity();
                index = count++;
                array[index].key = key;
        }

        array[index].value = value;
}


/*
  Implementation: get
  -------------------
  Get calls findKey to serch for the specified key. If the key is
  present, get returns the value from the key:value pair.
  If not, get throws an error.
*/
template <typename ValueType>
ValueType sMap<ValueType>::get(std::string key) {
        int index = findKey(key);
        if (index == -1 ) {
                throw -1;// Key not in map error ?
        }
        return array[index].value;
}

/*
  Implementation: containsKey
  ---------------------------
  Checks the result of private method findKey.
*/
template <typename ValueType>
bool sMap<ValueType>::containsKey(std::string key) {
        return (findKey(key) != -1);
}

/*
  Implementation: remove
  ----------------------
  The code for remove saves a little time by copying the key/value pair
  from the last entry into this cell. Note that there is no reason to check
  whether th edeleted item is the last element. If it is, the copy is
  harmless, and the key/value pair will no longer be part of the active
  region of the array. Note also that count can't be zero if findKey has
  found a match.
*/
template <typename ValueType>
void sMap<ValueType>::remove(std::string key) {
        int index = findKey(key);
        if (index != -1){
                array[index] = array[--count];
        }
}

/* Private Methods*/

/*
  Private Method: findKey
  Usage: int index = findKey(key);
  --------------------------------
  This method searches through all keys in the map for the cell containing
  the specified key. If it finds one, it returns the index of that element
  in the array . If no such key exists, findkey returns -1.
*/
template <typename ValueType>
int sMap<ValueType>::findKey(std::string key) {
        for (int i = 0; i < count; i++){
                if (array[i].key == key) return i;
        }
        return -1;
}

/*
  Implementation: expandCapacity
  -------------------------------
  This private method doubles the capacity of the array whenever it runs
  out of space. To do so, it must allocate a new array, copy all the
  elements from the old array to the new one, and free the old storage.
*/
template <typename ValueType>
void sMap<ValueType>::expandCapacity() {
        int count = size();
        capacity *= 2;
        keyValuePairT *oldArray = array;
        array = new keyValuePairT[capacity];
        for (int i = 0; i < count; i++){
                array[i] = oldArray[i];
        }
        delete[] oldArray;
}
#endif
                
