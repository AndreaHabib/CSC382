//all libraries used
#include <iostream>
#include <time.h>   
#include <ctime>
#include <stdlib.h>
#include <random>
#include <iomanip>
#include <string>

using namespace std;

//all function prototypes
void menu();
void Switch(int, int, vector<int>&);
void initializeArr(vector<int>&, int, int);
void printArr(vector<int>&);
void randomNum(vector<int>&, int);
void heapSort(vector<int>&);
void heapify(vector<int>&, int, int);

//global variable for counting each step taken in sorting algorithm
long long STEPS = 0;

//this program perform all tasks in one run

int main() {

    string loop;

    //seed time for random
    srand(time(0));

    while (loop != "no") {

        //function that displays menu for sorting choices
        menu();

        cout << endl;

        cout << "More Sorting? \t";

        cin >> loop;

        cout << endl;

    }

    return 0;
}

void menu() {

    int choice, n, loop = 8;

    //array of n
    int num[8] = { 100, 200, 300, 400, 500, 1000, 4000, 10000 };

    cout << "Sort?" << endl;

    cout << "1. Heap Sort" << endl;
    cout << "2. 50 instances using Heap Sort" << endl;

    cout << "Choice: ";
    cin >> choice;
    cout << endl;

    while (loop != 0) {

        //using vector to run my tests
        vector<int> arr;

        //assign n every iteration
        n = num[loop - 1];

        //function that initalized the vector, run the sort based on choice, and then print the process time and steps.
        Switch(choice, n, arr);

        //clear array for new n
        arr.clear();

        //reset steps
        STEPS = 0;

        loop -= 1;
    }

}

void Switch(int choice, int n, vector<int>& arr) {

    //initalize time_req for process time
    clock_t time_req;
    //total time of the 50 instances
    float total = 0;
    //loop variable for 50 instances
    int instances = 50;
    //to initialize vector in different modes --> sorted, reversed, random permutation
    int mode = 1;

    switch (choice) {

    case 1:

        //organized output
        cout << setfill('-') << setw(75) << "" << endl;
        cout << endl;
        cout << "Numbers: " << n << endl;
        cout << endl;

        while (mode <= 3) {

            //initialize vector
            initializeArr(arr, n, mode);

            //calculate time required
            time_req = clock();
            heapSort(arr);
            time_req = clock() - time_req;

            cout << "Process time of heap sort of " << n << " numbers: " << (float)time_req / CLOCKS_PER_SEC << " ---> STEPS: " << STEPS << endl;

            //printArr(arr);

            STEPS = 0;

            //new mode
            mode++;

            //clear the vector for a new mode to run, otherwise the vector gets n*3 size
            arr.clear();

        }


        break;

    case 2:

        //organized output
        cout << setfill('-') << setw(75) << "" << endl;
        cout << endl;
        cout << "Numbers: " << n << endl;
        cout << endl;

        while (instances > 0) {

            //initalize vector using rand
            randomNum(arr, n);

            //calculate time required
            time_req = clock();
            heapSort(arr);
            time_req = clock() - time_req;

            //accumulate total time each run
            total += (float)time_req / CLOCKS_PER_SEC;

            //clear vector for new instance
            arr.clear();

            instances--;
        }

        cout << "Process time of heap sort of 50 instances of " << n << " numbers: " << total / 50 << " ---> STEPS: " << STEPS / 50 << endl;

        break;

    default:

        //incorrect number --> exit
        cout << "Error!" << endl;
        exit(EXIT_FAILURE);

    }

}

void randomNum(vector<int>& arr, int n) {

    //initialize vector using rand for the 50 instances
    for (int i = 1; i <= n; i++) {
        arr.push_back(rand() % n + 1);
    }
}

void initializeArr(vector<int>& arr, int n, int mode) {

    //if already sorted
    if (mode == 1) {

        cout << "(1) Sorted: ";

        for (int i = 1; i <= n; i++) {
            arr.push_back(i);
        }

    }

    //if reversely sorted
    else if (mode == 2) {

        cout << "(2) Reversely Sorted: ";

        int j = n;
        for (int i = 1; i <= n; i++) {
            arr.push_back(j--);
        }
    }

    //random permutation
    else if (mode == 3) {

        cout << "(3) Random Permutation: ";

        for (int i = 0; i < n; i++) {
            arr.push_back(i);
        }

        //first create a sorted vecotr, then use random_suffle built-in function to shuffle the vector
        random_shuffle(arr.begin(), arr.end());
    }

}

//print testing
void printArr(vector<int>& arr) {

    //print vector for testing
    for (int i = 1; i < arr.size(); i++) {
        cout << i << " " << arr.at(i) << endl;
    }

}

//main heap sort (max heap)
void heapSort(vector<int>& arr)
{
    int n = arr.size(); //size
    STEPS += 3;

    //build heap
    for (int i = n / 2 - 1; i >= 0; i--) {

        heapify(arr, n, i);

        STEPS += 3;
    }

    STEPS++;

    //remove element from heap in loop
    for (int i = n - 1; i > 0; i--)
    {
        //move root to end
        swap(arr[0], arr[i]);

        //max heap
        heapify(arr, i, 0);

        STEPS += 4;
    }

    STEPS++;
}

//heaify vector
void heapify(vector<int>& arr, int n, int i)
{
    int largest = i; //root
    int l = 2 * i + 1; //left
    int r = 2 * i + 2; //right

    STEPS += 3;

    //if left is larger than root
    if (l < n && arr[l] > arr[largest]) {

        largest = l;
        STEPS += 3;

    }

    STEPS++;

    //if right is larger than root
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
        STEPS += 3;
    }

    STEPS++;

    //if largest is not root, then heapify recursively 
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);

        STEPS += 3;
    }

    STEPS++;
}

//Sort ?
//1. Heap Sort
//2. 50 instances using Heap Sort
//Choice : 1
//
//-------------------------------------------------------------------------- -
//
//Numbers : 10000
//
//(1) Sorted: Process time of heap sort of 10000 numbers : 0.038 --->STEPS : 1784360
//(2) Reversely Sorted : Process time of heap sort of 10000 numbers : 0.035 --->STEPS : 1566125
//(3) Random Permutation : Process time of heap sort of 10000 numbers : 0.037 --->STEPS : 1671032
//-------------------------------------------------------------------------- -
//
//Numbers : 4000
//
//(1) Sorted: Process time of heap sort of 4000 numbers : 0.014 --->STEPS : 639824
//(2) Reversely Sorted : Process time of heap sort of 4000 numbers : 0.013 --->STEPS : 555599
//(3) Random Permutation : Process time of heap sort of 4000 numbers : 0.013 --->STEPS : 596285
//-------------------------------------------------------------------------- -
//
//Numbers : 1000
//
//(1) Sorted: Process time of heap sort of 1000 numbers : 0.002 --->STEPS : 131765
//(2) Reversely Sorted : Process time of heap sort of 1000 numbers : 0.003 --->STEPS : 111368
//(3) Random Permutation : Process time of heap sort of 1000 numbers : 0.002 --->STEPS : 122696
//-------------------------------------------------------------------------- -
//
//Numbers : 500
//
//(1) Sorted: Process time of heap sort of 500 numbers : 0.002 --->STEPS : 59076
//(2) Reversely Sorted : Process time of heap sort of 500 numbers : 0.001 --->STEPS : 49290
//(3) Random Permutation : Process time of heap sort of 500 numbers : 0.001 --->STEPS : 54384
//-------------------------------------------------------------------------- -
//
//Numbers : 400
//
//(1) Sorted: Process time of heap sort of 400 numbers : 0.001 --->STEPS : 45647
//(2) Reversely Sorted : Process time of heap sort of 400 numbers : 0.001 --->STEPS : 37799
//(3) Random Permutation : Process time of heap sort of 400 numbers : 0.001 --->STEPS : 41987
//-------------------------------------------------------------------------- -
//
//Numbers : 300
//
//(1) Sorted: Process time of heap sort of 300 numbers : 0 --->STEPS : 32626
//(2) Reversely Sorted : Process time of heap sort of 300 numbers : 0.001 --->STEPS : 26704
//(3) Random Permutation : Process time of heap sort of 300 numbers : 0 --->STEPS : 29812
//-------------------------------------------------------------------------- -
//
//Numbers : 200
//
//(1) Sorted: Process time of heap sort of 200 numbers : 0 --->STEPS : 20181
//(2) Reversely Sorted : Process time of heap sort of 200 numbers : 0 --->STEPS : 16146
//(3) Random Permutation : Process time of heap sort of 200 numbers : 0 --->STEPS : 18219
//-------------------------------------------------------------------------- -
//
//Numbers : 100
//
//(1) Sorted: Process time of heap sort of 100 numbers : 0.001 --->STEPS : 8699
//(2) Reversely Sorted : Process time of heap sort of 100 numbers : 0 --->STEPS : 6881
//(3) Random Permutation : Process time of heap sort of 100 numbers : 0 --->STEPS : 7844
//
//More Sorting ? y
//
//Sort ?
//1. Heap Sort
//2. 50 instances using Heap Sort
//Choice : 2
//
//-------------------------------------------------------------------------- -
//
//Numbers : 10000
//
//Process time of heap sort of 50 instances of 10000 numbers : 0.03666 --->STEPS : 1671859
//-------------------------------------------------------------------------- -
//
//Numbers : 4000
//
//Process time of heap sort of 50 instances of 4000 numbers : 0.01304 --->STEPS : 596995
//-------------------------------------------------------------------------- -
//
//Numbers : 1000
//
//Process time of heap sort of 50 instances of 1000 numbers : 0.00266 --->STEPS : 122265
//-------------------------------------------------------------------------- -
//
//Numbers : 500
//
//Process time of heap sort of 50 instances of 500 numbers : 0.00118 --->STEPS : 54367
//-------------------------------------------------------------------------- -
//
//Numbers : 400
//
//Process time of heap sort of 50 instances of 400 numbers : 0.00094 --->STEPS : 41859
//-------------------------------------------------------------------------- -
//
//Numbers : 300
//
//Process time of heap sort of 50 instances of 300 numbers : 0.00068 --->STEPS : 29674
//-------------------------------------------------------------------------- -
//
//Numbers : 200
//
//Process time of heap sort of 50 instances of 200 numbers : 0.00038 --->STEPS : 18252
//-------------------------------------------------------------------------- -
//
//Numbers : 100
//
//Process time of heap sort of 50 instances of 100 numbers : 0.00018 --->STEPS : 7757
//
//More Sorting ? no