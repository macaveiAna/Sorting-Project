# Sorting-Project
CS260 - Programming Assignment 4 - Sorting

The purpose of this assignment is to give you some experience with sorting algorithms and algorithm analysis.  Additionally, you’ll get more practice outputting data in a format that can be easily imported into excel for analysis, further manipulation, or graphing.


Overview

You’ll create a program that performs at least three different sorts on datasets of varying size, time each sort, and output the data into a comma-separated-value text file (which can then be easily imported into excel) 


Details

You should choose at least three different sorting algorithms. Pseudocode for all can be found online; pick a reliable site and analyze each algorithm so you know how it works.

Each sort should be run on 12 different datasets (4 different sizes, each in 3 different orders).
Dataset sizes: 100, 1000, 10000, 100000. (optional: and 1000000)
Dataset orders (before sorting):  in order (1 to n),   reverse order (n to 1), and random
To generate random numbers, include <cstdlib>, use srand(42) to seed the random number generator (at the top of the randomInitialization routine) and use rand() to generate random numbers.

Note: If a large array is put on the stack you may get a stack overflow  So to force the array to be allocated on the heap you can make it static (put the word static before the array declaration).

The run time for each run of each sort should be timed.  And only the sort should be timed, not the setup or output.  So for each run, you’ll need to do the following:
initialize dataset
start timer  (i.e. use clock() get start time)
sort the data
stop the timer (i.e. use clock() get ending time)
output the elapsed time of the sort

While the sorted data doesn’t need to be output, when testing you should output it at least once to verify the sort works before moving on to timing it.

When complete, compare your results to the given performance of each sort (Big O notation) to see how they match.

Output

Output should be to a text file with a .csv extension.  This will make it easy to import into excel or google sheets.

You’ll have 3 sets of output that look like the example below.  All will be in the same file.  Each set should be formatted as shown below.:
Sort Type will be Bubble, Selection, Heap, etc.. (I’d recommend using at least one of the NlogN sorts)
Sort Order will be “In Order”, “Reverse Order”, and “Random”
time will be the elapsed time of each sort

Sort Type, 100, 1000, 10000, 100000 ,(1000000) optional
Sort Order, time, time, time, time
Sort Order, time, time, time, time
Sort Order, time, time, time, time


Submission requirements and grading

Draft Submission:
For your draft submission, you only need one one of the sorts implemented, including its associated output (for all sizes and orders).

Final Submission
Final Submission needs output from at least 3 sorts
To get full credit on your final submission, you need to use a spreadsheet to produce a nice graph showing the performance of each sort relative to dataset size.   (90% is the best you can do without the graph).
Program should be well written, function properly, and be both easy and efficient to use. 
All programs should follow the class's Coding Conventions
For extra credit avoid all code duplication by using one set of nested loops to control all processing (will require using arrays of function pointers that contain pointers to your data initializing functions and sorting functions.
Submit a zip file containing
your .cpp and .h files
the executable
your .csv output file showing the output from all the the sorts
a spreadsheet file with the graphs, or an image file showing the graphs you created (for the last 10% of the grade) 
