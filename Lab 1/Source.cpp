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
void insertionSort(vector<int>&);
void mergeSort(vector<int>&, int, int);
void menu();
void Switch(int, int, vector<int>&);
void initializeArr(vector<int>&, int, int);
void printArr(vector<int>&);
void merge(vector<int>&, int, int, int);
void randomNum(vector<int>&, int);

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

    cout << "1. Insertion Sort" << endl;
    cout << "2. Merge Sort" << endl;
    cout << "3. 50 instances using Insertion Sort" << endl;
    cout << "4. 50 instances using Merge Sort" << endl;

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
            insertionSort(arr);
            time_req = clock() - time_req;

            cout << "Process time of insertion sort of " << n << " numbers: " << (float)time_req / CLOCKS_PER_SEC << " ---> STEPS: " << STEPS << endl;

            //printArr(arr);

            STEPS = 0;

            //new mode
            mode++;

            //clear the vector for a new mode to run
            arr.clear();
        }

        break;

    case 2:

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
            mergeSort(arr, 0, (arr.size() - 1));
            time_req = clock() - time_req;

            cout << "Process time of merge sort of " << n << " numbers: " << (float)time_req / CLOCKS_PER_SEC << " ---> STEPS: " << STEPS << endl;

            //printArr(arr);

            STEPS = 0;

            //new mode
            mode++;

            //clear the vector for a new mode to run, otherwise the vector gets n*3 size
            arr.clear();

        }

        break;

    case 3:

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
            insertionSort(arr);
            time_req = clock() - time_req;

            //accumulate total time each run
            total += (float)time_req / CLOCKS_PER_SEC;

            //clear vector for new instance
            arr.clear();

            instances--;
        }

        cout << "Process time of insertion sort of 50 instances of " << n << " numbers: " << total / 50 << " ---> STEPS: " << STEPS / 50 << endl;
        
        break;

    case 4:

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
            mergeSort(arr, 0, (arr.size() - 1));
            time_req = clock() - time_req;

            //accumulate total time each run
            total += (float)time_req / CLOCKS_PER_SEC;

            //clear vector for new instance
            arr.clear();

            instances--;
        }

        cout << "Process time of merge sort of 50 instances of " << n << " numbers: " << total / 50 << " ---> STEPS: " << STEPS / 50 << endl;

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

void initializeArr(vector<int> &arr, int n, int mode) {

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

void insertionSort(vector<int> &arr) {

    int i, key, j;
    STEPS++;

    for (i = 1; i < arr.size(); i++) {

        STEPS += 2;

        key = arr[i];
        j = i - 1;

        STEPS += 2;

        while (j >= 0 && arr[j] > key) {

            STEPS += 2;

            arr[j + 1] = arr[j];
            j = j - 1;

            STEPS += 2;
        }

        STEPS++;

        arr[j + 1] = key;
        STEPS++;

    }

    STEPS++;

}

void mergeSort(vector<int> &arr, int l, int r) {

    if (l < r) {

        STEPS++;

        //calculate middle
        int m = l + (r - l) / 2;
        STEPS++;

        //recursive call twice
        mergeSort(arr, l, m);
        STEPS++;
        mergeSort(arr, (m + 1), r);
        STEPS++;

        //call merging algorithm
        merge(arr, l, m, r);
        STEPS++;
    }

    STEPS++;
    
}

void merge(vector<int>& arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L;
    vector<int> R;

    STEPS += 3;

    for (i = 0; i < n1; i++) {

        STEPS += 2;
        L.push_back(arr[l + i]);
        STEPS++;

    }

    STEPS++;

    for (j = 0; j < n2; j++) {

        STEPS += 2;
        R.push_back(arr[m + 1 + j]);
        STEPS++;

    }

    STEPS += 2;

    i = 0; 
    j = 0;
    k = l;

    STEPS += 3;

    while (i < n1 && j < n2) {

        STEPS += 2;

        if (L[i] <= R[j]) {
          
            arr[k] = L[i];
            i++;
            STEPS += 3;

        }
        else {

            arr[k] = R[j];
            j++;
            STEPS += 2;
        }

        k++;
        STEPS += 2;

    }

    STEPS++;

    while (i < n1) {

        arr[k] = L[i];
        i++;
        k++;
        STEPS += 4
;
    }

    STEPS++;

    while (j < n2) {
        
        arr[k] = R[j];
        j++;
        k++;
        STEPS += 4;

    }

    STEPS++;
}

void printArr(vector<int> &arr) {

    //print vector for testing
    for (int i = 1; i < arr.size(); i++) {
        cout << i << " " << arr.at(i) << endl;
    }

}

//Sort ?
//1. Insertion Sort
//2. Merge Sort
//3. 50 instances using Insertion Sort
//4. 50 instances using Merge Sort
//Choice : 1
//
//-------------------------------------------------------------------------- -
//
//Numbers: 10000
//
//(1) Sorted: Process time of insertion sort of 10000 numbers : 0.001 --->STEPS : 59996
//(2) Reversely Sorted : Process time of insertion sort of 10000 numbers : 4.166 --->STEPS : 200039996
//(3) Random Permutation : Process time of insertion sort of 10000 numbers : 2.105 --->STEPS : 100932572
//-------------------------------------------------------------------------- -
//
//Numbers : 4000
//
//(1) Sorted: Process time of insertion sort of 4000 numbers : 0 --->STEPS : 23996
//(2) Reversely Sorted : Process time of insertion sort of 4000 numbers : 0.666 --->STEPS : 32015996
//(3) Random Permutation : Process time of insertion sort of 4000 numbers : 0.338 --->STEPS : 16263960
//-------------------------------------------------------------------------- -
//
//Numbers : 1000
//
//(1) Sorted: Process time of insertion sort of 1000 numbers : 0 --->STEPS : 5996
//(2) Reversely Sorted : Process time of insertion sort of 1000 numbers : 0.042 --->STEPS : 2003996
//(3) Random Permutation : Process time of insertion sort of 1000 numbers : 0.021 --->STEPS : 1024900
//-------------------------------------------------------------------------- -
//
//Numbers : 500
//
//(1) Sorted: Process time of insertion sort of 500 numbers : 0 --->STEPS : 2996
//(2) Reversely Sorted : Process time of insertion sort of 500 numbers : 0.01 --->STEPS : 501996
//(3) Random Permutation : Process time of insertion sort of 500 numbers : 0.005 --->STEPS : 247720
//-------------------------------------------------------------------------- -
//
//Numbers : 400
//
//(1) Sorted: Process time of insertion sort of 400 numbers : 0.001 --->STEPS : 2396
//(2) Reversely Sorted : Process time of insertion sort of 400 numbers : 0.007 --->STEPS : 321596
//(3) Random Permutation : Process time of insertion sort of 400 numbers : 0.003 --->STEPS : 160472
//-------------------------------------------------------------------------- -
//
//Numbers : 300
//
//(1) Sorted: Process time of insertion sort of 300 numbers : 0 --->STEPS : 1796
//(2) Reversely Sorted : Process time of insertion sort of 300 numbers : 0.003 --->STEPS : 181196
//(3) Random Permutation : Process time of insertion sort of 300 numbers : 0.002 --->STEPS : 96680
//-------------------------------------------------------------------------- -
//
//Numbers : 200
//
//(1) Sorted: Process time of insertion sort of 200 numbers : 0 --->STEPS : 1196
//(2) Reversely Sorted : Process time of insertion sort of 200 numbers : 0.002 --->STEPS : 80796
//(3) Random Permutation : Process time of insertion sort of 200 numbers : 0.001 --->STEPS : 38224
//-------------------------------------------------------------------------- -
//
//Numbers : 100
//
//(1) Sorted: Process time of insertion sort of 100 numbers : 0 --->STEPS : 596
//(2) Reversely Sorted : Process time of insertion sort of 100 numbers : 0.001 --->STEPS : 20396
//(3) Random Permutation : Process time of insertion sort of 100 numbers : 0 --->STEPS : 10592
//
//More Sorting ? yes
//
//Sort ?
//1. Insertion Sort
//2. Merge Sort
//3. 50 instances using Insertion Sort
//4. 50 instances using Merge Sort
//Choice : 2
//
//-------------------------------------------------------------------------- -
//
//Numbers: 10000
//
//(1) Sorted: Process time of merge sort of 10000 numbers : 0.147 --->STEPS : 1332318
//(2) Reversely Sorted : Process time of merge sort of 10000 numbers : 0.147 --->STEPS : 1254510
//(3) Random Permutation : Process time of merge sort of 10000 numbers : 0.15 --->STEPS : 1427374
//-------------------------------------------------------------------------- -
//
//Numbers : 4000
//
//(1) Sorted: Process time of merge sort of 4000 numbers : 0.056 --->STEPS : 483838
//(2) Reversely Sorted : Process time of merge sort of 4000 numbers : 0.056 --->STEPS : 458766
//(3) Random Permutation : Process time of merge sort of 4000 numbers : 0.057 --->STEPS : 518459
//-------------------------------------------------------------------------- -
//
//Numbers : 1000
//
//(1) Sorted: Process time of merge sort of 1000 numbers : 0.013 --->STEPS : 103946
//(2) Reversely Sorted : Process time of merge sort of 1000 numbers : 0.013 --->STEPS : 98678
//(3) Random Permutation : Process time of merge sort of 1000 numbers : 0.013 --->STEPS : 110605
//-------------------------------------------------------------------------- -
//
//Numbers : 500
//
//(1) Sorted: Process time of merge sort of 500 numbers : 0.006 --->STEPS : 47714
//(2) Reversely Sorted : Process time of merge sort of 500 numbers : 0.007 --->STEPS : 45330
//(3) Random Permutation : Process time of merge sort of 500 numbers : 0.007 --->STEPS : 50531
//-------------------------------------------------------------------------- -
//
//Numbers : 400
//
//(1) Sorted: Process time of merge sort of 400 numbers : 0.005 --->STEPS : 37470
//(2) Reversely Sorted : Process time of merge sort of 400 numbers : 0.005 --->STEPS : 35326
//(3) Random Permutation : Process time of merge sort of 400 numbers : 0.005 --->STEPS : 39413
//-------------------------------------------------------------------------- -
//
//Numbers : 300
//
//(1) Sorted: Process time of merge sort of 300 numbers : 0.004 --->STEPS : 27022
//(2) Reversely Sorted : Process time of merge sort of 300 numbers : 0.004 --->STEPS : 25458
//(3) Random Permutation : Process time of merge sort of 300 numbers : 0.004 --->STEPS : 28361
//-------------------------------------------------------------------------- -
//
//Numbers : 200
//
//(1) Sorted: Process time of merge sort of 200 numbers : 0.003 --->STEPS : 17026
//(2) Reversely Sorted : Process time of merge sort of 200 numbers : 0.003 --->STEPS : 16054
//(3) Random Permutation : Process time of merge sort of 200 numbers : 0.002 --->STEPS : 17779
//-------------------------------------------------------------------------- -
//
//Numbers : 100
//
//(1) Sorted: Process time of merge sort of 100 numbers : 0.001 --->STEPS : 7654
//(2) Reversely Sorted : Process time of merge sort of 100 numbers : 0.001 --->STEPS : 7218
//(3) Random Permutation : Process time of merge sort of 100 numbers : 0.001 --->STEPS : 7962
//
//More Sorting ? y
//
//Sort ?
//1. Insertion Sort
//2. Merge Sort
//3. 50 instances using Insertion Sort
//4. 50 instances using Merge Sort
//Choice : 3
//
//-------------------------------------------------------------------------- -
//
//Numbers: 10000
//
//Process time of insertion sort of 50 instances of 10000 numbers : 2.05418 --->STEPS : 99933357
//-------------------------------------------------------------------------- -
//
//Numbers : 4000
//
//Process time of insertion sort of 50 instances of 4000 numbers : 0.33198 --->STEPS : 15984243
//-------------------------------------------------------------------------- -
//
//Numbers : 1000
//
//Process time of insertion sort of 50 instances of 1000 numbers : 0.0206 --->STEPS : 1003553
//-------------------------------------------------------------------------- -
//
//Numbers : 500
//
//Process time of insertion sort of 50 instances of 500 numbers : 0.00516 --->STEPS : 252467
//-------------------------------------------------------------------------- -
//
//Numbers : 400
//
//Process time of insertion sort of 50 instances of 400 numbers : 0.0033 --->STEPS : 161061
//-------------------------------------------------------------------------- -
//
//Numbers : 300
//
//Process time of insertion sort of 50 instances of 300 numbers : 0.002 --->STEPS : 91087
//-------------------------------------------------------------------------- -
//
//Numbers : 200
//
//Process time of insertion sort of 50 instances of 200 numbers : 0.00086 --->STEPS : 40618
//-------------------------------------------------------------------------- -
//
//Numbers : 100
//
//Process time of insertion sort of 50 instances of 100 numbers : 0.00016 --->STEPS : 10482
//
//More Sorting ? y
//
//Sort ?
//1. Insertion Sort
//2. Merge Sort
//3. 50 instances using Insertion Sort
//4. 50 instances using Merge Sort
//Choice : 4
//
//-------------------------------------------------------------------------- -
//
//Numbers: 10000
//
//Process time of merge sort of 50 instances of 10000 numbers : 0.1476 --->STEPS : 1427481
//-------------------------------------------------------------------------- -
//
//Numbers : 4000
//
//Process time of merge sort of 50 instances of 4000 numbers : 0.05616 --->STEPS : 518519
//-------------------------------------------------------------------------- -
//
//Numbers : 1000
//
//Process time of merge sort of 50 instances of 1000 numbers : 0.0131 --->STEPS : 110630
//-------------------------------------------------------------------------- -
//
//Numbers : 500
//
//Process time of merge sort of 50 instances of 500 numbers : 0.0063 --->STEPS : 50558
//-------------------------------------------------------------------------- -
//
//Numbers : 400
//
//Process time of merge sort of 50 instances of 400 numbers : 0.00494 --->STEPS : 39444
//-------------------------------------------------------------------------- -
//
//Numbers : 300
//
//Process time of merge sort of 50 instances of 300 numbers : 0.00364 --->STEPS : 28374
//-------------------------------------------------------------------------- -
//
//Numbers : 200
//
//Process time of merge sort of 50 instances of 200 numbers : 0.00236 --->STEPS : 17812
//-------------------------------------------------------------------------- -
//
//Numbers : 100
//
//Process time of merge sort of 50 instances of 100 numbers : 0.0011 --->STEPS : 7948
//
//More Sorting ? no