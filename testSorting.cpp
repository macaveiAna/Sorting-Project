/*
* @file:		testSorting.cpp
* @author:		Ana Macavei
* @version:		1.0
*
* Demonstrates: The use of different sorting algorithms on datasets of
* sizes 100, 1000, 10000, 100000. Test efficiency by timing each sort,
* and output the data into a comma-separated-value text file.
* All times are reported in seconds.
*/

#include <iostream>		//need to test 
#include <cstdlib>		//need to generate random numbers
#include <ctime>		//need to use clock functionality
#include <fstream>		//need to output/write to file

void printArray(int arr[], int size);
void inOrderInitialization(int arr[], int size);
void reverseInitialization(int arr[], int size);
void randomInitialization(int arr[], int size);
void insertionSort(int arr[], int size);
void swap(int arr[], int first, int second);
int partition(int arr[], int first, int last);
void quickSortRecursive(int arr[], int low, int high);
void quickSort(int arr[], int size);
void merge(int arr[], int left, int middle, int right);
void mergeSortRec(int arr[], int left, int right);
void mergeSort(int arr[], int size);

int main() {
	clock_t startTime, endTime;

	static int dataSet[100000];

	std::ofstream myFile;
	myFile.open("testSorting.csv"); //Anything written in file will output to testSorting.csv file. 
	if (!myFile) {
		std::cout << "open failed";//It's good practice to make sure my file was opening correctly.
		return 0;
	}

	//insertion sort
	myFile << "Insertion,100,1000,10000,100000";
	myFile << "\nIn Order";//inorder insertion sort of 4 different datasizes

	inOrderInitialization(dataSet, 100);
	startTime = clock(); //starting timer
	insertionSort(dataSet, 100); //sort the data with given size of data
	endTime = clock(); //end time
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC; //outputs the elapsed time of the sort

	inOrderInitialization(dataSet, 1000);
	startTime = clock();
	insertionSort(dataSet, 1000);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	inOrderInitialization(dataSet, 10000);
	startTime = clock();
	insertionSort(dataSet, 10000);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	inOrderInitialization(dataSet, 100000);
	startTime = clock();
	insertionSort(dataSet, 100000);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	//-------------------------------------------------------------------------------

	myFile << "\nReverse Order";//reverse order insertion sort of 4 different datasizes
	reverseInitialization(dataSet, 100);
	startTime = clock();
	insertionSort(dataSet, 100);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	reverseInitialization(dataSet, 1000);
	startTime = clock(); //starting timer
	insertionSort(dataSet, 1000); //sort the data
	endTime = clock(); //end time
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	reverseInitialization(dataSet, 10000);
	startTime = clock(); //starting timer
	insertionSort(dataSet, 10000); //sort the data
	endTime = clock(); //end time
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	reverseInitialization(dataSet, 100000);
	startTime = clock(); //starting timer
	insertionSort(dataSet, 100000); //sort the data
	endTime = clock(); //end time
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	//----------------------------------------------------------------------------

	myFile << "\nRandom Order";//random order insertion sort of 4 different datasizes
	randomInitialization(dataSet, 100);
	startTime = clock();
	insertionSort(dataSet, 100);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	randomInitialization(dataSet, 1000);
	startTime = clock(); //starting timer
	insertionSort(dataSet, 1000); //sort the data
	endTime = clock(); //end time
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	randomInitialization(dataSet, 10000);
	startTime = clock(); //starting timer
	insertionSort(dataSet, 10000); //sort the data
	endTime = clock(); //end time
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	randomInitialization(dataSet, 100000);
	startTime = clock(); //starting timer
	insertionSort(dataSet, 100000); //sort the data
	endTime = clock(); //end time
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	//=========================================================================
	//Quick sort
	myFile << "\n\nQuick Sort,100,1000,10000,100000";
	myFile << "\nIn Order";

	inOrderInitialization(dataSet, 100);
	startTime = clock(); //starting timer
	quickSort(dataSet, 100); //sort the data with given size of data
	endTime = clock(); //end time
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC; //outputs the elapsed time of the sort

	inOrderInitialization(dataSet, 1000);
	startTime = clock();
	quickSort(dataSet, 1000);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	inOrderInitialization(dataSet, 10000);
	startTime = clock();
	quickSort(dataSet, 10000);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	inOrderInitialization(dataSet, 100000);
	startTime = clock();
	quickSort(dataSet, 100000);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	//-------------------------------------------------------------------------------

	myFile << "\nReverse Order";
	reverseInitialization(dataSet, 100);
	startTime = clock();
	quickSort(dataSet, 100);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	reverseInitialization(dataSet, 1000);
	startTime = clock(); //starting timer
	quickSort(dataSet, 1000); //sort the data
	endTime = clock(); //end time
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	reverseInitialization(dataSet, 10000);
	startTime = clock(); //starting timer
	quickSort(dataSet, 10000); //sort the data
	endTime = clock(); //end time
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	reverseInitialization(dataSet, 100000);
	startTime = clock(); //starting timer
	quickSort(dataSet, 100000); //sort the data
	endTime = clock(); //end time
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	//----------------------------------------------------------------------------

	myFile << "\nRandom Order";
	randomInitialization(dataSet, 100);
	startTime = clock();
	quickSort(dataSet, 100);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	randomInitialization(dataSet, 1000);
	startTime = clock();
	quickSort(dataSet, 1000);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	randomInitialization(dataSet, 10000);
	startTime = clock();
	quickSort(dataSet, 10000);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	randomInitialization(dataSet, 100000);
	startTime = clock();
	quickSort(dataSet, 100000);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	//=========================================================================
	//Merge sort
	myFile << "\n\nMerge Sort,100,1000,10000,100000";
	myFile << "\nIn Order";

	inOrderInitialization(dataSet, 100);
	startTime = clock(); //starting timer
	mergeSort(dataSet, 100); //sort the data with given size of data
	endTime = clock(); //end time
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC; //outputs the elapsed time of the sort

	inOrderInitialization(dataSet, 1000);
	startTime = clock();
	mergeSort(dataSet, 1000);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	inOrderInitialization(dataSet, 10000);
	startTime = clock();
	mergeSort(dataSet, 10000);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	inOrderInitialization(dataSet, 100000);
	startTime = clock();
	mergeSort(dataSet, 100000);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	//-------------------------------------------------------------------------------

	myFile << "\nReverse Order";
	reverseInitialization(dataSet, 100);
	startTime = clock();
	mergeSort(dataSet, 100);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	reverseInitialization(dataSet, 1000);
	startTime = clock(); //starting timer
	mergeSort(dataSet, 1000); //sort the data
	endTime = clock(); //end time
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	reverseInitialization(dataSet, 10000);
	startTime = clock(); //starting timer
	mergeSort(dataSet, 10000); //sort the data
	endTime = clock(); //end time
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	reverseInitialization(dataSet, 100000);
	startTime = clock(); //starting timer
	mergeSort(dataSet, 100000); //sort the data
	endTime = clock(); //end time
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	//----------------------------------------------------------------------------

	myFile << "\nRandom Order";
	randomInitialization(dataSet, 100);
	startTime = clock();
	mergeSort(dataSet, 100);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	randomInitialization(dataSet, 1000);
	startTime = clock();
	mergeSort(dataSet, 1000);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	randomInitialization(dataSet, 10000);
	startTime = clock();
	mergeSort(dataSet, 10000);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	randomInitialization(dataSet, 100000);
	startTime = clock();
	mergeSort(dataSet, 100000);
	endTime = clock();
	myFile << "," << static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC;

	myFile.close();

	//I know it's very repetitive! I plan to revisit this assingment and learn to make it more consice.
	return 0;
}

//Function prototypes

/*
* Treats the array like a deck of cards and place
* every element at position 'i' after comparing it with all the
* elements before it.
*
* @param	int (array to be printed),
*			int (size of given array)
* @return	void(none)
*/
void insertionSort(int arr[], int size) {

	int key;

	for (int firstOutOfOrder = 1; firstOutOfOrder < size; firstOutOfOrder++) {

		key = arr[firstOutOfOrder]; // picking the element
		int location = firstOutOfOrder - 1;

		/*
		Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position

		Additional notes: compare key with each element
		on the left of it until an element smaller than
		it is found.
		*/
		while (location >= 0 && arr[location] > key) { //need the = sign in location >= 0 so that it prints the array correctly
			arr[location + 1] = arr[location];
			location = location - 1;
		}
		arr[location + 1] = key; //insert the element in the right place
	}
}

/*
* A function to swap two  elements
*
* @param	int arr[], int first, int second
* @return	void(none)
*/
void swap(int arr[], int first, int second) {

	int temp = arr[first];//temp is first element
	arr[first] = arr[second];//swapping first and second element
	arr[second] = temp; //temp is now the second element
}


/*
* A function to partition the array into two sublists, which
* are then sorted and combined into one list in a way so that
* the combined list is sorted.
*
* @param	int arr[],
*			int first,
*			int last
* @return	smallIndex
*/
int partition(int arr[], int first, int last) {

	//step 1: Determine the pivot, and swap pivot with the first element of the list.
	int pivot;
	int smallIndex;
	swap(arr, first, (first + last) / 2);

	pivot = arr[first];
	smallIndex = first;//The smallIndex is initialized to the first element of the list 

	//step 2: Array elements get arranged
	//For the remaining elements in the list:
	//If the current element is less than pivot.
	//Increment smallIndex.
	//swap current element with the array element pointed to by smallIndex.
	for (int index = first + 1; index <= last; index++)
		if (arr[index] < pivot) { //if current element is less than pivot
			//advance smallIndex to next array position
			smallIndex++;  //increment smallIndex
			//swap the index with the smallIndex
			swap(arr, smallIndex, index);//swap the current element with the array element pointed to by smallIndex
		}

	//step 3:
	//swap the low element, which is pivot, with the array element pointed to by smallIndex
	swap(arr, first, smallIndex);

	return smallIndex;
}

/*
* A function that implements the recursive
* version of the quick sort algorithm.
*
* @param	int arr[],
*			int low,
*			int high
* @return	void(none)
*/
void quickSortRecursive(int arr[], int low, int high) {

	int pivotLocation;

	if (low < high) {

		pivotLocation = partition(arr, low, high);

		quickSortRecursive(arr, low, pivotLocation - 1);//sort elements seperately before partition 
		quickSortRecursive(arr, pivotLocation + 1, high);//sort elements after partition
	}
}

/*
* A function that calls the function
* quickSortRecursive on the original array.
*
* @param	int arr[],
*			int size
* @return	void(none)
*/
void quickSort(int arr[], int size) {

	quickSortRecursive(arr, 0, size - 1);
}


/*
* A function used for merging two halves.
*
* @param	int arr[],
*			int left,
*			int middle;
*			int right
* @return	void(none)
*/
void merge(int arr[], int left, int middle, int right) {

	//Merge together two seperate parts of the array
	int firstHalfSize = middle - left + 1; //Compute the number of elements in array from left to the middle
	int secondHalfSize = right - middle; //Compute the number of elements in array from the middle to the right

	//program needs new dynamic sized variable to hold information
	//create temporaty arrays
	int* leftArray = new int[firstHalfSize];
	int* rightArray = new int[secondHalfSize];

	//Copy data to temporary arrays 
	for (int i = 0; i < firstHalfSize; i++)
		leftArray[i] = arr[left + i];
	for (int j = 0; j < secondHalfSize; j++)
		rightArray[j] = arr[middle + 1 + j];

	//Merge the temp arrays back into arr[left .. right]

	//initial index of first subarray
	int leftHalfIndex = 0;

	//initial index of second subarray
	int rightHalfIndex = 0;

	//initial index of merged subarray
	int mergedIndex = left;

	while (leftHalfIndex < firstHalfSize && rightHalfIndex < secondHalfSize) {
		if (leftArray[leftHalfIndex] <= rightArray[rightHalfIndex]) {
			arr[mergedIndex] = leftArray[leftHalfIndex];
			leftHalfIndex++;
		}
		else {
			arr[mergedIndex] = rightArray[rightHalfIndex];
			rightHalfIndex++;
		}
		mergedIndex++;
	}

	//Copy the remaining elements of leftArray[], if there are any.
	while (leftHalfIndex < firstHalfSize) {
		arr[mergedIndex] = leftArray[leftHalfIndex];
		leftHalfIndex++;
		mergedIndex++;
	}

	//Copy the remaining elements of rightArray[], if there are any.
	while (rightHalfIndex < secondHalfSize) {
		arr[mergedIndex] = rightArray[rightHalfIndex];
		rightHalfIndex++;
		mergedIndex++;
	}
}

/*
* Merge Sort is a divide and conquer algorithm.
* It divides the input array into two halves, calls itself
* for the two halves, and then merges the two sorted halves.
*
* @param	int arr[],
*			int left,
*			int right
* @return	void(none)
*/
void mergeSortRec(int arr[], int left, int right) {

	if (left >= right) {
		return;//returns recursively
	}
	//Step 1: Find middle point of array to divide the array into two halves.
	int middle = left + (right - left) / 2;
	//Step 2: Call mergeSort for first half.
	mergeSortRec(arr, left, middle);
	//Step 3: Call mergeSort for second half.
	mergeSortRec(arr, middle + 1, right);
	//Step 4: Merge the two halves sorted in step 2 and 3.
	merge(arr, left, middle, right);
}

void mergeSort(int arr[], int size) {

	mergeSortRec(arr, 0, size - 1);
}

/*
* A function used to test the different
* sorts to make sure they are working
* properly.
*
* @param	int arr[],
*			int size
* @return	void(none)
*/
void printArray(int arr[], int size) {

	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

/*
* Initializes given array in order by
* incrementing the value stored by 1 each loop.
*
* @param	int (array to be printed),
*			int (size of given array)
* @return	void(none)
*/
void inOrderInitialization(int arr[], int size) {

	for (int i = 0; i < size; i++) {
		arr[i] = i + 1; //array is arranged in order
	}
}

/*
* Initializes given array in reverse order
* by decreasing the value stored by 1 each loop.
*
* @param	int (array to be printed),
*			int (size of given array)
* @return	void(none)
*/
void reverseInitialization(int arr[], int size) {

	for (int i = 0; i < size; i++) {
		arr[i] = size - i; //array is arranged in reverse order
	}
}

/*
* Initializes given array in random order.
*
* @param	int (array to be printed),
*			int (size of given array)
* @return	void(none)
*/
void randomInitialization(int arr[], int size) {

	srand(42); //seed random number generator
	for (int i = 0; i < size; i++) {
		arr[i] = rand(); //use rand() to generate random numbers
	}
}



