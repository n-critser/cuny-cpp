Problem
********************************************************************************************************
Your assignment is to determine the actual time taken by your implementation of the following sorting
algorithms. Your program is required to do the following:
• Generate a variable number of items in an array. Generate (at minimum) the following number
of items: 100, 1000, 5000, 10000, 50000, 75000, 100000, 200000, 400000, 750000. The items
should be randomly-generated integers in the positive (signed) integer range (0 – 2147483647).
• Copy the number of items and sort the copy with the following sorting algorithms: Insertion
Sort, Bubble Sort, Merge Sort, Quick Sort. The copy ensures that each sorting algorithm
operates on the same data.
• Output the total time to perform the sorting task.
Once you have the above data, generate a line graph of this data as the total time for the sorting task vs.
the amount of time actually taken. An example (for Selection Sort, which is not required) is below.
***********************************************************************************************************
Design:
Create c++ array generator for the given number of items. 
	maybe a vector generator to array copy (to keep it all nice and usable) or not
	or could just create one array of 750000 and a shuffle and pack function to make
	all the others 
Create c++ copy array function to make data copy 
create c++ timedSort run function ( try (*p)(sortStuff) ? maybe
	This will take a function as a parameter 
  
create c++ algorithm to run each array on each sort.algorithm and collect the data into 
	an output stream to be fed into a text file.  

create a python script to run the c++ program and collect the outputs, then use the 
	outputs to create a line graph with each algorithm. possibly of the style
   ["selectionSort", v1,v2,v3,v4,v5] or "selectionSort" : [v1,v2,v3,v4,v5]


********************************************************************************************************


