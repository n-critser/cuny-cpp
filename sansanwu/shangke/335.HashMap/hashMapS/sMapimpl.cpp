/*
  File: sMapimpl.cpp
  -------------------
  HashTable implementation file from:
  http://cs.stanford.edu/people/eroberts/courses/cs106b/chapters/12-implementing-maps.pdf
  
 */

#ifdef _sMap_h

template <typename ValueType>
sMap<ValueType>::sMap() {
        nBuckets = INITIAL_SIZE;
        buckets = new cellT *[nBuckets];
        for (int i = 0; i < nBuckets; i++){
                buckets[i] = NULL;
        }
}

template <typename ValueType>
sMap<ValueType>::~sMap() {
        clear();
        delete[] buckets;
}

template <typename ValueType>
int sMap<ValueType>::size() {
        return nEntries;
}

template <typename ValueType>
bool sMap<ValueType>::isEmpty(){
        return nEntries;
}

template <typename ValueType>
void sMap<ValueType>::clear() {
        for (int i = 0; i < nBuckets; i++){
                deleteChain(buckets[i]);
        }
        nEntries = 0;
}

/*
  Implementation: put
  ----------------
  * This method first looks to see whether the key already
  * exists in the map by calling the findCell method. If one
  * exists, this method simply changes the value; if not, the
  * implementation adds a new cell to the beginning of the chain.
 */

template <typename ValueType>
void sMap<ValueType>::put(std::string key, ValueType value) {
        int index = hash(key) % nBuckets;
        cellT *cell = findCell( buckets[index], key);
        if (cell == NULL){
                cell = new cellT;
                cell->key = key;
                cell->link = buckets[index];
                buckets[index] = cell;
                nEntries++;
        }
        cell->value = value;
                
}


/*
  Implementation: get
  -------------------
  Get calls findCell to search for the specified key. If the key is
  present, get returns the value from the key:value pair.
  If not, get throws an error.
*/
template <typename ValueType>
ValueType sMap<ValueType>::get(std::string key) {
        cellT *cell = findCell(buckets[hash(key) % nBuckets],key);
        if (cell == NULL){
                std::cerr << "ERROR: ATTEMPTING TO GET KEY NOT IN MAP"<<std::endl;
                throw -1;
        }
        return cell->value;
}

/*
  Implementation: containsKey
  ---------------------------
  Checks the result of private method findCell.
*/
template <typename ValueType>
bool sMap<ValueType>::containsKey(std::string key) {
        return (findCell(buckets[hash(key) % nBuckets],key) != NULL);
}

/*
  Implementation: remove
  ----------------------
  * The remove method cannot use the findCell method as it
  * stands because it needs a pointer to the previous entry.
  * Because that code is used only in this method, the loop
  * through the cells in a chain is reimplemented here and
  * therefore does not add any cost to the get/put operations.
*/
template <typename ValueType>
void sMap<ValueType>::remove(std::string key) {
        int index = hash(key) % nBuckets;
        cellT *prev = NULL;
        cellT *cp = buckets[index];
        while( cp != NULL & cp->key != key) {
                prev = cp;
                cp = cp->link;
        }
        if (cp != NULL) {
                if ( prev == NULL) {
                        buckets[index] = cp->link;
                }else {
                        prev->link = cp->link;
                }
                delete cp;
                nEntries--;
        }
        
}

/*
  Implementation: operator[]
  ----------------------------------
  *
  *
  *
  *
  */
template <typename ValueType>
ValueType & sMap<ValueType>::operator[](std::string key){
        int index = hash(key) % nBuckets;
        cellT *cell = findCell(buckets[index], key);
        if( cell ==NULL){
                cell = new cellT;
                cell->key = key;
                cell->link = buckets[index];
                buckets[index] = cell;
                nEntries++;
        }
        return cell->value;
}


template <typename ValueType>
void sMap<ValueType>::mapAll (){//( sMapFnt fn) {   //( mapFnt fn)
        for (int i = 0; i< nBuckets; i++){
                for (cellT *cp = buckets[i]; cp !=NULL; cp = cp->link){
                        //fn(cp->key, cp->value);
                        std::cout<< cp->key << cp->value<<std::endl;
                }
        }
}



/* Private Methods*/

/*
* Implementation notes: hash
* Usage: bucket = hash(key);
* --------------------------
* This function takes the key and uses it to derive a hash code,
* which is a nonnegative integer. The hash code is computed
* using a method called linear congruence.
*/
template < typename ValueType>
int sMap<ValueType>::hash(std::string s) {
        const long MULTIPLIER = -1664117991L;
        unsigned long hashcode = 0;
        for ( unsigned i = 0; i < s.length(); i++){
                hashcode = hashcode * MULTIPLIER + s[i];
        }
        return hashcode & ((unsigned) -1 >> 1);
}



/*
* Implementation notes: findCell
* Usage: cell = findCell(chain, key);
* -----------------------------------
* This function finds a cell in the chain that matches key.
* If a match is found, findCell returns a pointer to that cell;
* if not, findCell returns NULL.
*/
template <typename ValueType>
typename sMap<ValueType>::cellT *sMap<ValueType>::findCell(cellT *chain,
                                                         std::string key){
        for (cellT* cp = chain; cp != NULL; cp= cp->link){
                if (cp->key  == key)
                        return cp;
        }
        return NULL;
}

/*
* Private method: deleteChain
* ---------------------------
* This method deletes all of the cells in a bucket chain.
* It operates recursively by freeing the rest of the chain
* and the freeing the current cell.
*/
template <typename ValueType>
void sMap<ValueType>::deleteChain( cellT *chain) {
        if (chain != NULL) {
                deleteChain(chain->link);
                delete chain;
        }
}

#endif
                
