/*235.proj4 main.cpp
 *
 *
 *  Created on: Nov 25, 2013
 *      Author: chaos
 */
/*http://cs.joensuu.fi/~zhao/Courses/DAA2009/Mergesort.htm
 *http://www.princeton.edu/~achaney/tmve/wiki100k/docs/Merge_sort.html
 * http://xlinux.nist.gov/dads//HTML/mergesort.html
 * http://en.literateprograms.org/Merge_sort_(C_Plus_Plus)
 * http://cs.williams.edu/~morgan/code/C++/sort.cpp
 * main.cpp
 *
 */

#define CLOCKS_PER_SEC 1000000


#include<iostream>	//basic io stream
#include<vector>	//vectors for main data conatainer
#include<cstdlib>	//TODO
#include<cmath>		//TODO
#include<string>	//TODO
#include<algorithm>	//TODO
#include<fstream>	//file stream for logger
#include<sstream>  	//digit to string conversion
#include<iterator>  // for vector::interator
#include<ctime>		//TODO
#include<time.h>    // for clock_t



	/* Range of array lengths for sorting data
	 * 100, 1000, 5000, 10000, 50000, 75000, 100000, 200000, 400000, 700000
	 *
	 */

const int HUN= 100;
const int THOU= 1000;
const int FIVE= 5000;
const int TEN= 10000;
const int FIFTY= 50000;
const int SEVENFIVE= 75000;
const int HUNTHOU= 100000;
const int TWOHUNTHOU= 200000;
const int FOURHUNTHOU= 400000;
const int SEVENHUNTHOU= 700000;

void write_Log(const std::string & text){
	std::ofstream log_file("log_file.txt",std::ios::out |std::ios::app);// TODO: allow for clobber mode
	log_file << text ;
}
std::string convertDigit(double number)
{
   std::stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

/*
double getUnixTime(clock_t Aclock){
	Aclock = clock();

}
*/

/*linearSearch:  complexity = O(n)
*/
template< class T>
int linearSearch(T target, T a[], int max){
	for(int i =0; i< max; i++){
		if (a[i]==target)
			return i;
	}
	return -1;
}

/*binarySearch:
 * complexity:
 * best: 	O(logn)
 * average:	O(logn)
 * worst: 	O(logn)
 *
 */
template<class T>
int binarySearch(T target, T a[], int size, int min,int max){
	int mid = (min+max)/2;
	if (min>max)// error check
		return -1;
	if (a[mid]==target)//base case
		return mid;
	else if( a[mid]< target)//a[mid] < target branch to larger side
		return binarySearch(target, a,size, mid+1,max);
	else// otherwise branch to smaller side of a[mid]
		return binarySearch(target, a,size, min, max-1);
}

/**********************************************
 * END SEARCHES
 ***********************************************/
template<class T>
void swap (T &a, T &b){
	T temp;
	temp = a;
	a=b;
	b=temp;
}

/**************************************************
 * BEGIN SORTS
 *************************************************/

/*bubbleSort:
 * complexity:
 * worst case  O(n**2)  ,
 * average case O(n**2)
 * best case O(n) flag for sorted array
 */
template<class T>
void bubbleSort( T a[], const int& max){

	for (int j =0; j < max; j++){
		for( int i = 0; i < max-j-1; i++){
			if ( a[i+1] < a[i])
				swap( a[i+1], a[i]);
		}
	}
}

/* insertionSort:
 * Complexity:
 * worst:   O(n**2)
 * average: O(n**2)
 * best: 	O(n) TODO
 *
 */
template<class T>
void insertionSort( T a[], int startPos, int endPos ){
	//T sorted[max];
	int i,j;
	for ( j=startPos; j< endPos; j++){
		T key = a[j];
		for (i = j-1; (i>=0) && (a[i]> key); i--){
			// reorder values by key until the loop invariant becomes False
			a[i+1]= a[i];
		}
		std::cout << "before insertion value of i ="<< i << std::endl;
		// I reduced to -1 at the end of above loop
		a[i+1]= key;
	}
}



template <class T>
int findSmallest( T a[], int max, int fromPos){
	int smallest= fromPos;
	for (int i = fromPos; i < max; i++){
		if ( a[i] < a[smallest])
			smallest = i;
	}
	//std::cout<<"smallest index="<< smallest<< std::endl;
	return smallest;
}

/* selectionSort:
 *
 * Complexity:
 * worst:  O(n**2)
 * average:O(n**2)
 * best:   O(n**2)
 *
 */
//template<class T>
void selectionSort(int a[],const int& max){

	for ( int i=0; i< max; i++){
		int smallest = findSmallest(a,max,i);
		swap(a[i], a[smallest]);
	}
}

template <class T>
int index_of_maximum_key( T a[],  int last){
	int largest= 0; //assume the largest element is at a[0]
	for (int i = 0; i <= last; i++){ //last is size-1 in sort
		if ( a[i] > a[largest])
			largest = i;
	}
	std::cout<<"index of largest="<< largest<< std::endl;
	return largest;
}


template <class T>
void selectionSortSW(T a[], int size){
	int largest;
	int last;
	for (last= size-1; last >=1; last--){
		largest = index_of_maximum_key(a,last);
		swap(a[largest],a[last]);//swap with impunity
	}
}

/* mergeSort:
 * Recursive split and sort algorithm that splits the size of Data in half
 * for each recursive call. 'logn' comes from the recursion and 'n' from the merge
 * function cycling through each element for comparison
 * Complexity:
 * worst:   O(nlogn)
 * average:	O(nlogn)
 * best:	O(nlogn)
 */
template<class T>
void mergeSort(std::vector<T>& vec){
  for (unsigned m =1; m <= vec.size(); m*=2){
    for(unsigned i=0; i< vec.size()-m; i+=m*2){
      std::inplace_merge(
			 vec.begin() + i,
			 vec.begin() + i + m,
			 vec.begin() + std::min<unsigned>(i + m * 2, (unsigned)vec.size()));
    }
  }

}



template <class T>
void mergeD(T a[], int first, int mid, int last){
	T tempArr[5];
	std::cout<< "mergeD\t"<<"first="<<first<<"\tmid="<<mid<<"\tlast="<<last<<std::endl;
	int first1= first;
	int last1 = mid;
	int first2= mid+1;
	int last2 = last;

	int index = first1;

	while((first1<= last1) && (first2 <= last2)){
		// if a[first1] < a[first2] then it goes into the temp array
		if (a[first1] < a[first2]){
			//std::cout << "first1: tempArr["<<index<<"]="<<a[first1]<<std::endl;
			tempArr[index] = a[first1++];
		}else { //otherwise a[first2] goes into the temp array
			//std::cout << "first2: tempArr["<<index<<"]="<<a[first2]<<std::endl;
			tempArr[index]= a[first2++];
		}
		index++;
	}
	while (first1 <= last1){//if half 1 and 2 are odd length
		//std::cout<< "while (first1<= last1)"<<std::endl;
		tempArr[index++] = a[first1++];
	}
	while(first2 <= last2){ //if half 1 and 2 are odd length
		//std::cout<< "while (first2<= last2)"<<std::endl;
		tempArr[index++]= a[first2++];
	}
	//copy temp back into a[]
	for(index=first; index <=last; ++index){
		a[index] = tempArr[index];
	}
}

/* mergeSort:
 * Recursive split and sort algorithm that splits the size of Data in half
 * for each recursive call. 'logn' comes from the recursion and 'n' from the merge
 * function cycling through each element for comparison
 * Complexity:
 * worst:   O(nlogn)
 * average:	O(nlogn)
 * best:	O(nlogn)
 */
template<class T>
void mergeSortD( T a[], const int& first , const int &last){
	if ( first < last){
		int mid = (first+last)/2;
		std::cout << "First="<< first<<"\tmid="<<mid<<"\tlast="<<last<<std::endl;
		mergeSortD(a, first, mid);
		mergeSortD(a, mid+1,last);
		mergeD(a, first, mid, last);
	}
}

//bucketsort called binsort
//FIXME: broken sort, fix or remove
template<class T>
void binSort( T a[], unsigned size){
	std::size_t bMax = 9;
	std::vector<std::vector<T> > bins(bMax+1);
	for(unsigned i = 0; i < size; ++i){
	        bins[a[i]].push_back(a[i]);
	    }
    std::size_t current = 0;
    for(std::size_t i = 0; i < bMax; ++i){
        for(unsigned j = 0; j < size; ++j){
            a[current++] = bins[i][j];
        }
    }
}

template <class T>
const T & median3(T a[], const int & left, const int & right ){
	int center = (left + right)/2;
	if( a[center] < a[left])
		swap( a[left], a[center]);
	if (a[right] < a[left])
		swap( a[left], a[right]);
	if (a [right] < a[center])
		swap ( a[center], a[right]);
	//place pivot at position right -1
	swap(a[center], a[right-1]);
	return a[right-1];
}


/* quickSort: FIXME: MEDIAN OF 3 FOR PIVOT AND TRY TO DEBUG RECURSION
 * Complexity:
 * worst:   O(nlogn)
 * average: O(nlogn)
 * best:	O(n**2) If the pivot is at an extreme for every pivot choice
 *
 */
template<class T>
void quickSort(T a[], const int & leftarg, const int & rightarg){
	//use median3 pivot selection for array lengths less than 10
	if (leftarg + 10 <= rightarg){
		T pivotValue = median3(a,leftarg,rightarg);

		//begin partitioning
		int left = leftarg;
		int right = rightarg- 1;

		for(;;){//infinite loop needs the break below
			/* left and right are sentinel values that travel toward each other
			 * when they stop at values > or < the pivot and while left < right
			 * they swap.  [pivot, left---> ,x , , y, <-----right]
			 */
			while (a[--right]> pivotValue);// shift a[right-1] then test against pivot value
			while (a[++left]< pivotValue);//  shift a[left+1] then test against pivot value
			if (left < right)
				swap (a[left],a[right]);
			else
				break; //if left >= right leave the loop
		}
		swap (a[left], a[rightarg-1]);//put the pivot back into its sorted position
		quickSort(a,leftarg, left-1);
		quickSort(a,left+1,rightarg);

	}
	else
		insertionSort(a,leftarg,rightarg);
}



/* bucketSort:
 * Postman sorting algorithm which splits data up into categories like powers of
 * 10 or state,city,zip.  Knowledge of the data being sorted is necessary to create
 * buckets efficiently.
 * Complexity:
 * worst:   O(n*k) k = the length of data
 * average:	O(n*k) k = the length of data
 * best:	O(n*k) k = the length of data
 *
 */
template<class T>
void bucketSort( T a[], int size){
	//write_Log("\nnow entering bucket sort\n");
	std::vector<std::vector<T> > buckets(10);
	int temp;
	int m=0;
	for(int i=0;i<7; i++){
		for(int j=0; j<size;j++){
			temp=(T)((a[j])/ pow(10,i))%10;
			//write_Log("\nnow in the j loop");
			//write_Log("temp = ");
			//write_Log(convertInt(temp));
			buckets[temp].push_back((a[j]));
			//write_Log("\nnow leaving the j loop");
		}
		//transfer buckets back to array ???sort???
		for(int k=0; k<10; k++){
			//write_Log("\n now in the k loop\n");
			for(unsigned p=0; p<buckets[k].size();p++){
				//write_Log("\n now in the p loop\n");
				//write_Log("m = ");
				//write_Log(convertInt(m));
				a[m]=buckets[k][p];
				m++;
			}//clear the bucket
			buckets[k].clear();
		}
		m = 0;
	}
	//clear outer buckets
	buckets.clear();

}

template<class T>
void displayArray(T a[],int max){
	std::cout<<"[";
	for (int i=0; i < max; i++){
		std::cout<< a[i];
		if(i<max-1)
			std::cout<<",";
		if(i %30 == 0)
			std::cout << std::endl;
	}
	std::cout<<"]"<<std::endl;
}

template<class T>
void mixUp(T a[], int max){
	for (int i=0; i < max; i++){
			swap(a[rand()%max], a[i]);
		}
	std::cout<<"****MixedUp******>\n";
	displayArray(a,max);
}

//TODO: MAKE SURE THIS WORKS FOR ALL SORT FUNCTIONS!!!
//TODO: MAKE SURE THIS TIMER WORKS CLEARLY
//template<class T>
typedef  void (*sortFn)(int a[], const int &max, const int &limit);
typedef  void (*sortFn2)(int a[], const int &max);
//template<class T>

//typedef void (*visit_function)(T &);
//void pre_order (node *treePtr, visit_function visit);
//template<class T>
double timedSort(sortFn sort, int a[], const int& max, const int &limit){
	//void (*function)(int[], int);

	std::clock_t start = std::clock();

	sort(a,max,limit);
	std::cout << "start ="<<start  << std::endl;
	//std::clock_t c_end = std::clock();

	double exTime = (double)(clock()-start)/ (double)CLOCKS_PER_SEC;
	std::cout << exTime << "= execution time in timedSort" << std::endl;
	return exTime;
}
double timedSort(sortFn2 sort, int a[], const int & max){
	//void (*function)(int[], int);
	//selection sort 2 version
	//function=sort;

	std::clock_t start = clock();

	sort(a,max);

	std::cout << "start ="<<start  << std::endl;
	double exTime = (double)(clock()-start)/ CLOCKS_PER_SEC;
	std::cout << exTime << "= execution time in timedSort" << std::endl;
	return exTime;

}

void fillArray(std::vector<unsigned> & vec, int array[], const int size){
	//first set the whole array[] to all 0's
	for(int i =0; i< size; i++)
		array[i]=0;
	std::copy(vec.begin(),vec.begin()+size, array);
}



int main(int argc, char* argv[]){
	//int max=5;

	std::vector<unsigned> data;
	//std::copy(v.begin(), v.end(), a) ; a is an array v is a vector
	for(unsigned i=0; i<750000; i++){
		data.push_back(i);
	}
	std::random_shuffle(data.begin(), data.end());
	/* Range of array lengths for sorting data
	 * 100, 1000, 5000, 10000, 50000, 75000, 100000, 200000, 400000, 700000
	 *
	 *const int HUN= 100;
const int THOU= 1000;
const int FIVE= 5000;
const int TEN= 10000;
const int FIFTY= 50000;
const int SEVENFIVE= 75000;
const int HUNTHOU= 100000;
const int TWOHUNTHOU= 200000;
const int FOURHUNTHOU= 400000;
const int SEVENHUNTHOU= 700000;
	 */

	//ARRAY OF 100 RANDOM NUMBERS BETWEEN 0 AND 750000
	int sHund[HUN],sThou[THOU],sFive[FIVE],sTen[TEN], sFifty[FIFTY],
		sSevenFive[SEVENFIVE], sHunthou[HUNTHOU], sTwohunthou[TWOHUNTHOU],
		sFourhunthou[FOURHUNTHOU], sSevenhunthou[SEVENHUNTHOU];
	fillArray(data, sHund, HUN);
	fillArray(data, sThou, THOU);
	fillArray(data, sFive, FIVE);
	fillArray(data, sTen, TEN);
	fillArray(data, sFifty, FIFTY);
	fillArray(data, sSevenFive, SEVENFIVE);
	fillArray(data, sHunthou, HUNTHOU);
	fillArray(data, sTwohunthou, TWOHUNTHOU);
	fillArray(data, sFourhunthou, FOURHUNTHOU);
	fillArray(data, sSevenhunthou, SEVENHUNTHOU);

	//**********ARRAYS AND VECTORS CREATED ABOVE********************

//Insertion Sort, Bubble Sort, Merge Sort, Quick Sort

	std::cout << "You have 10 arrays ranging from 100 to 750000 items in random order.\n"
			<< " 1: Selection Sort\n"
			<< " //NO 2: Insertion Sort\n"
			<< " 3: Bubble Sort\n"
			<< " 4: Merge Sort\n"
			<< " 5: Quick Sort\n"
			<< std::endl;

	write_Log("Array sizes display accordingly\n");
	write_Log("[100, 1000, 5000, 10000, 50000, 75000, 100000, 200000, 400000, 700000]\n\n");
/*
	std::cout<<"Selection sorting ************"<< std::endl;

	//int sThou[1000]=thou;
	write_Log("{SelectionSort:");
	write_Log("[ ");
	write_Log(convertDigit(timedSort(selectionSort,sHund,HUN)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(selectionSort,sThou,THOU)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(selectionSort,sFive,FIVE)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(selectionSort,sTen,TEN)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(selectionSort,sFifty,FIFTY)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(selectionSort,sSevenFive,SEVENFIVE)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(selectionSort,sHunthou,HUNTHOU)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(selectionSort,sTwohunthou,TWOHUNTHOU)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(selectionSort,sFourhunthou,FOURHUNTHOU)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(selectionSort,sSevenhunthou,SEVENHUNTHOU)));
	write_Log(" ]}\n");

	std::cout<< std::endl;
	std::cout<<"Bubble sorting ************"<< std::endl;
	fillArray(data, sHund, HUN);
	fillArray(data, sThou, THOU);
	fillArray(data, sFive, FIVE);
	fillArray(data, sTen, TEN);
	fillArray(data, sFifty, FIFTY);
	fillArray(data, sSevenFive, SEVENFIVE);
	fillArray(data, sHunthou, HUNTHOU);
	fillArray(data, sTwohunthou, TWOHUNTHOU);
	fillArray(data, sFourhunthou, FOURHUNTHOU);
	fillArray(data, sSevenhunthou, SEVENHUNTHOU);

	write_Log("{BubbleSort: ");
	write_Log("[ ");
	write_Log(convertDigit(timedSort(bubbleSort,sHund,HUN)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(bubbleSort,sThou,THOU)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(bubbleSort,sFive,FIVE)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(bubbleSort,sTen,TEN)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(bubbleSort,sFifty,FIFTY)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(bubbleSort,sSevenFive,SEVENFIVE)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(bubbleSort,sHunthou,HUNTHOU)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(bubbleSort,sTwohunthou,TWOHUNTHOU)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(bubbleSort,sFourhunthou,FOURHUNTHOU)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(bubbleSort,sSevenhunthou,SEVENHUNTHOU)));
	write_Log(" ]}\n");
*/
	std::cout<< std::endl;

	std::cout<<"******** MergeSort ************"<< std::endl;

	fillArray(data, sHund, HUN);
	fillArray(data, sThou, THOU);
	fillArray(data, sFive, FIVE);
	fillArray(data, sTen, TEN);
	fillArray(data, sFifty, FIFTY);
	fillArray(data, sSevenFive, SEVENFIVE);
	fillArray(data, sHunthou, HUNTHOU);
	fillArray(data, sTwohunthou, TWOHUNTHOU);
	fillArray(data, sFourhunthou, FOURHUNTHOU);
	fillArray(data, sSevenhunthou, SEVENHUNTHOU);


	//mergeSortD( T a[], int first , int last)
	write_Log("{MergeSort: ");
	write_Log("[ ");
	write_Log(convertDigit(timedSort(mergeSortD,sHund,HUN,0)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(mergeSortD,sThou,THOU,0)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(mergeSortD,sFive,FIVE,0)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(mergeSortD,sTen,TEN,0)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(mergeSortD,sFifty,FIFTY,0)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(mergeSortD,sSevenFive,SEVENFIVE,0)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(mergeSortD,sHunthou,HUNTHOU,0)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(mergeSortD,sTwohunthou,TWOHUNTHOU,0)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(mergeSortD,sFourhunthou,FOURHUNTHOU,0)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(mergeSortD,sSevenhunthou,SEVENHUNTHOU,0)));
	write_Log(" ]}\n");


	std::cout<<"********QuickSort ************"<< std::endl;

	fillArray(data, sHund, HUN);
	fillArray(data, sThou, THOU);
	fillArray(data, sFive, FIVE);
	fillArray(data, sTen, TEN);
	fillArray(data, sFifty, FIFTY);
	fillArray(data, sSevenFive, SEVENFIVE);
	fillArray(data, sHunthou, HUNTHOU);
	fillArray(data, sTwohunthou, TWOHUNTHOU);
	fillArray(data, sFourhunthou, FOURHUNTHOU);
	fillArray(data, sSevenhunthou, SEVENHUNTHOU);

//void quickSort(T a[], const int & leftarg, const int & rightarg){
	//quickSort(bigNums, 0, max-1);
	write_Log("{QuickSort: ");
	write_Log("[ ");
	write_Log(convertDigit(timedSort(quickSort,sHund,0,HUN-1)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(quickSort,sThou,0,THOU-1)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(quickSort,sFive,0,FIVE-1)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(quickSort,sTen,0,TEN-1)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(quickSort,sFifty,0,FIFTY-1)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(quickSort,sSevenFive,0,SEVENFIVE-1)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(quickSort,sHunthou,0,HUNTHOU-1)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(quickSort,sTwohunthou,0,TWOHUNTHOU-1)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(quickSort,sFourhunthou,0,FOURHUNTHOU-1)));
	write_Log(" , ");
	write_Log(convertDigit(timedSort(quickSort,sSevenhunthou,0,SEVENHUNTHOU-1)));
	write_Log(" ]}\n");


	std::cout<< std::endl;




	return 0;
}







