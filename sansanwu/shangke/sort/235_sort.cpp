/*http://cs.joensuu.fi/~zhao/Courses/DAA2009/Mergesort.htm
 *http://www.princeton.edu/~achaney/tmve/wiki100k/docs/Merge_sort.html
 * http://xlinux.nist.gov/dads//HTML/mergesort.html
 * http://en.literateprograms.org/Merge_sort_(C_Plus_Plus)
 * http://cs.williams.edu/~morgan/code/C++/sort.cpp
 * main.cpp
 *
 *  Created on: Nov 12, 2013
 *      Author: chaos
 */
#include<iostream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<iterator>


template<class T>
void displayArray(T a[],int max){
	std::cout<<"[";
	for (int i=0; i < max; i++){
		std::cout<< a[i];
		if(i<max-1)
			std::cout<<",";
	}
	std::cout<<"]"<<std::endl;
}


void write_Log(const std::string & text){
	std::ofstream log_file("log_file.txt",std::ios::out |std::ios::app);// TODO: allow for clobber mode
	log_file << text ;
}
std::string convertInt(int number)
{
   std::stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}


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
void bubbleSort( T a[], int max){

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
void insertionSort( T a[], int max ){
	//T sorted[max];
	int i,j;
	for ( j=1; j< max; j++){
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
	std::cout<<"smallest index="<< smallest<< std::endl;
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
template<class T>
void selectionSort(T a[], int max){

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
int * mergeTest( T a[], int a_size, int b[], int b_size ){
	int N = a_size + b_size;
	int *result = new int [N];
	std::cout<< "New array created of size:"<< N<< std::endl;
	int count_a=0; int count_b=0;
	int i = 0;
	while ( count_a<a_size && count_b<b_size){
		if (a[count_a] < b[count_b])
			result[i++]=a[count_a++];
		else
			result[i++]=b[count_b++];
		//i++;
	}
	while ( count_a <a_size){
		result[i++]=a[count_a++];
	}
	while ( count_b<b_size){
		result[i++]=b[count_b++];
	}
	std::cout<< "leaving mergeTest"<< std::endl;
	displayArray(result, N);
	return result;
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
void mergeSortD( T a[], int first , int last){
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

/*median3:
 * This is the pivot value algorithm of choice for
 * Weiss
 */
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

/* quickSort:
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
void mixUp(T a[], int max){
	for (int i=0; i < max; i++){
			swap(a[rand()%max], a[i]);
		}
	std::cout<<"****MixedUp******>\n";
	displayArray(a,max);
}

int main(int argc, char* argv[]){
	int max=5;
	//*******ARRAYS TO PLAY WITH ******************
	int bigNums[]= {3453,2222,66656,78565,12121};
	int nums[]={53,2,734,23,34};
	std::string folks[]={"jojo", "helen", "spencer", "milton", "francis"};
	std::vector<unsigned> data;
	for(unsigned i=0; i<10; i++)
	  data.push_back(i);
	//**********ARRAYS AND VECTORS CREATED ABOVE********************



	//linear search
	std::cout<<"Linear searchinging ************"<< std::endl;
	std::cout<< "Found 2222 in a[] at pos:" <<linearSearch(2222,bigNums,max)<< std::endl;
	std::cout<< std::endl;

	//binary search
	std::cout<<"Binary searchinging ******First Sorting ******"<< std::endl;
	quickSort(bigNums, 0, max-1);
	std::cout<< "Found 2222 in a[] at pos:" <<binarySearch(2222,bigNums,max,0,max)<< std::endl;
	std::cout<< std::endl;


	//mergesort gets 2 versions
	std::cout<<"********Fancy vector/stl MergeSort ************"<< std::endl;
	//random shuffle the data vector
	std::random_shuffle(data.begin(), data.end());
	std::copy(data.begin(), data.end(), std::ostream_iterator<unsigned>(std::cout," "));
	std::cout<< std::endl;
	mergeSort(data);
	std::copy(data.begin(), data.end(), std::ostream_iterator<unsigned>(std::cout," "));
	std::cout << std::endl;

	std::cout<<"\n Regular Array MergeSort sorting ************"<< std::endl;
	mixUp(bigNums,max);
	mixUp(folks,max);
	std::cout<<"********sorted**********"<<std::endl;
	mergeSortD(bigNums,0,max-1);
	displayArray(bigNums,max);
	mergeSortD(folks,0,max-1);
	displayArray(folks,max);
	std::cout<< std::endl;


	//quicksort
	std::cout<<"\n*************QuickSort sorting ************"<< std::endl;
	mixUp(bigNums,max);
	std::cout<<"********sorted**********"<<std::endl;
	quickSort(bigNums,0,max-1);
	displayArray(bigNums,max);
	std::cout<< std::endl;

	//bucket sort * 2
	std::cout<<"\n*************Bucket sorting ************"<< std::endl;
	mixUp(bigNums,max);
	std::cout<<"********sorted**********"<<std::endl;
	bucketSort(bigNums,max);
	displayArray(bigNums,max);
	std::cout<< std::endl;
	/*
	std::cout<<"\n*************Bin sorting ************"<< std::endl;
	mixUp(bigNums,max);
	std::cout<<"********sorted**********"<<std::endl;
	binSort(bigNums,max);
	displayArray(bigNums,max);
	std::cout<< std::endl;
*/


	//insertion sort
	std::cout<<"Insertion sorting ************"<< std::endl;
	mixUp(nums,max);
	std::cout<<"********sorted**********"<<std::endl;
	insertionSort(nums,max);
	displayArray(nums,max);
	std::cout<< std::endl;


	//selection sort 2 version
	std::cout<<"Selection sorting ************"<< std::endl;
	mixUp(nums,max);//mix up
	std::cout<<"********sorted**********"<<std::endl;
	selectionSort(nums,max);
	displayArray(nums,max);
	std::cout<< std::endl;

	std::cout<<"Selection sorting Largest to Smallest************"<< std::endl;
	mixUp(nums,max);//mix up
	std::cout<<"********sorted**********"<<std::endl;
	selectionSortSW(nums,max);
	displayArray(nums,max);
	std::cout<< std::endl;

	//bubble sort
	std::cout<<"Bubble sorting ************"<< std::endl;
	mixUp(nums,max);
	mixUp(folks,max);
	std::cout<<"********sorted**********"<<std::endl;
	bubbleSort(nums,max);
	displayArray(nums,max);
	bubbleSort(folks,max);
	displayArray(folks,max);
	std::cout<<"\n  Entering the test merge area***** " << std::endl;
	int alpha[6]= {3,4,61,34,77,44};
	std::cout<<"alpha=";
	displayArray(alpha,6);
	int beta[7] = {34,23,34,12,33,67,456};
	std::cout<<"beta=";
	displayArray(beta,7);
	int *gamma= mergeTest(alpha,6,beta,7);
	displayArray(gamma,13);

	delete gamma;
	gamma = NULL;

	return 0;
}



