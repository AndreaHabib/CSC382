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
void quickSort(vector<int>&, int, int, bool);
int partition(vector<int>&, int, int, bool);

//global variable for counting each step taken in sorting algorithm
long long STEPS = 0;

//this program perform all tasks in one run

int main() {

    string loop;

    //seed time for random
    srand(time(0));

    while (loop != "no" || loop != "n") {

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
    int num[8] = { 100, 200 , 300, 400, 500, 1000, 4000, 10000 };

    cout << "Sort?" << endl;

    cout << "1. Quick Sort" << endl;
    cout << "2. 50 instances using Quick Sort" << endl;
    cout << "3. Randomized Quick Sort" << endl;
    cout << "4. 50 instances using Randomized Quick Sort" << endl;

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
            quickSort(arr, 0, arr.size() - 1, false);
            time_req = clock() - time_req;

            cout << "Process time of quick sort of " << n << " numbers: " << (float)time_req / CLOCKS_PER_SEC << " ---> STEPS: " << STEPS << endl;

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
            quickSort(arr, 0, arr.size() - 1, false);
            time_req = clock() - time_req;

            //accumulate total time each run
            total += (float)time_req / CLOCKS_PER_SEC;

            //clear vector for new instance
            arr.clear();

            instances--;
        }

        STEPS = STEPS / 50;

        cout << "Process time of quick sort of 50 instances of " << n << " numbers: " << total / 50 << " ---> STEPS: " << STEPS << endl;

        break;

    case 3:

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
            quickSort(arr, 0, arr.size() - 1, true);
            time_req = clock() - time_req;

            cout << "Process time of randomized quick sort of " << n << " numbers: " << (float)time_req / CLOCKS_PER_SEC << " ---> STEPS: " << STEPS << endl;

            //printArr(arr);

            STEPS = 0;

            //new mode
            mode++;

            //clear the vector for a new mode to run, otherwise the vector gets n*3 size
            arr.clear();

        }


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
            quickSort(arr, 0, arr.size() - 1, true);
            time_req = clock() - time_req;

            //accumulate total time each run
            total += (float)time_req / CLOCKS_PER_SEC;

            //clear vector for new instance
            arr.clear();

            instances--;
        }

        STEPS = STEPS / 50;

        cout << "Process time of randomized quick sort of 50 instances of " << n << " numbers: " << total / 50 << " ---> STEPS: " << STEPS << endl;
        
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

void quickSort(vector<int>& arr, int low, int high, bool isRandom)
{
    while (low < high) {
        STEPS++;

        int j = partition(arr, low, high, isRandom);
        STEPS++;

        if (j - low < high - j) {
            STEPS += 3;
            quickSort(arr, low, j - 1, isRandom);
            STEPS++;
            low = j + 1;
            STEPS++;
        }
        else {
            quickSort(arr, j + 1, high, isRandom);
            STEPS++;
            high = j - 1;
            STEPS++;
        }
        STEPS++;
    }
    STEPS++;
}

int partition(vector<int>& arr, int low, int high, bool isRandom)
{

    if (isRandom) {
        STEPS++;

        int random = low + rand() % (high - low);
        STEPS++;

        swap(arr[random], arr[high]);
        STEPS++;
    }
    STEPS++;

    int pivot = arr[high]; 
    int i = (low - 1); 
    STEPS += 2;

    for (int j = low; j <= high - 1; j++)
    {
        STEPS += 2;
        if (arr[j] < pivot)
        {
            i++;  
            swap(arr[i], arr[j]);
            STEPS += 3;
        }
        STEPS++;
    }
    swap(arr[i + 1], arr[high]);
    STEPS += 3;
    return (i + 1);
}

//Sort ?
//1. Quick Sort
//2. 50 instances using Quick Sort
//3. Randomized Quick Sort
//4. 50 instances using Randomized Quick Sort
//Choice : 1
//
//-------------------------------------------------------------------------- -
//
//Numbers : 10000
//
//(1) Sorted: Process time of quick sort of 10000 numbers : 8.7 --->STEPS : 300089989
//(2) Reversely Sorted : Process time of quick sort of 10000 numbers : 5.052 --->STEPS : 225104989
//(3) Random Permutation : Process time of quick sort of 10000 numbers : 0.016 --->STEPS : 732259
//-------------------------------------------------------------------------- -
//
//Numbers: 4000
//
//(1) Sorted: Process time of quick sort of 4000 numbers : 1.368 --->STEPS : 48035989
//(2) Reversely Sorted : Process time of quick sort of 4000 numbers : 0.798 --->STEPS : 36041989
//(3) Random Permutation : Process time of quick sort of 4000 numbers : 0.007 --->STEPS : 294835
//-------------------------------------------------------------------------- -
//
//Numbers : 1000
//
//(1) Sorted: Process time of quick sort of 1000 numbers : 0.086 --->STEPS : 3008989
//(2) Reversely Sorted : Process time of quick sort of 1000 numbers : 0.05 --->STEPS : 2260489
//(3) Random Permutation : Process time of quick sort of 1000 numbers : 0.002 --->STEPS : 55672
//-------------------------------------------------------------------------- -
//
//Numbers : 500
//
//(1) Sorted: Process time of quick sort of 500 numbers : 0.022 --->STEPS : 754489
//(2) Reversely Sorted : Process time of quick sort of 500 numbers : 0.013 --->STEPS : 567739
//(3) Random Permutation : Process time of quick sort of 500 numbers : 0.001 --->STEPS : 30532
//-------------------------------------------------------------------------- -
//
//Numbers : 400
//
//(1) Sorted: Process time of quick sort of 400 numbers : 0.014 --->STEPS : 483589
//(2) Reversely Sorted : Process time of quick sort of 400 numbers : 0.008 --->STEPS : 364189
//(3) Random Permutation : Process time of quick sort of 400 numbers : 0.001 --->STEPS : 22363
//-------------------------------------------------------------------------- -
//
//Numbers : 300
//
//(1) Sorted: Process time of quick sort of 300 numbers : 0.008 --->STEPS : 272689
//(2) Reversely Sorted : Process time of quick sort of 300 numbers : 0.005 --->STEPS : 205639
//(3) Random Permutation : Process time of quick sort of 300 numbers : 0 --->STEPS : 14056
//-------------------------------------------------------------------------- -
//
//Numbers : 200
//
//(1) Sorted: Process time of quick sort of 200 numbers : 0.004 --->STEPS : 121789
//(2) Reversely Sorted : Process time of quick sort of 200 numbers : 0.002 --->STEPS : 92089
//(3) Random Permutation : Process time of quick sort of 200 numbers : 0 --->STEPS : 9112
//-------------------------------------------------------------------------- -
//
//Numbers : 100
//
//(1) Sorted: Process time of quick sort of 100 numbers : 0.001 --->STEPS : 30889
//(2) Reversely Sorted : Process time of quick sort of 100 numbers : 0.001 --->STEPS : 23539
//(3) Random Permutation : Process time of quick sort of 100 numbers : 0 --->STEPS : 3955
//
//More Sorting ? y
//
//Sort ?
//1. Quick Sort
//2. 50 instances using Quick Sort
//3. Randomized Quick Sort
//4. 50 instances using Randomized Quick Sort
//Choice : 2
//
//-------------------------------------------------------------------------- -
//
//Numbers : 10000
//
//Process time of quick sort of 50 instances of 10000 numbers : 0.01766 --->STEPS : 787951
//-------------------------------------------------------------------------- -
//
//Numbers : 5000
//
//Process time of quick sort of 50 instances of 5000 numbers : 0.00824 --->STEPS : 364954
//-------------------------------------------------------------------------- -
//
//Numbers : 1000
//
//Process time of quick sort of 50 instances of 1000 numbers : 0.00134 --->STEPS : 58333
//-------------------------------------------------------------------------- -
//
//Numbers : 500
//
//Process time of quick sort of 50 instances of 500 numbers : 0.00062 --->STEPS : 26370
//-------------------------------------------------------------------------- -
//
//Numbers : 400
//
//Process time of quick sort of 50 instances of 400 numbers : 0.0004 --->STEPS : 19928
//-------------------------------------------------------------------------- -
//
//Numbers : 300
//
//Process time of quick sort of 50 instances of 300 numbers : 0.00036 --->STEPS : 14132
//-------------------------------------------------------------------------- -
//
//Numbers : 200
//
//Process time of quick sort of 50 instances of 200 numbers : 0.00024 --->STEPS : 8767
//-------------------------------------------------------------------------- -
//
//Numbers : 100
//
//Process time of quick sort of 50 instances of 100 numbers : 0.0001 --->STEPS : 3827
//
//More Sorting ? y
//
//Sort ?
//1. Quick Sort
//2. 50 instances using Quick Sort
//3. Randomized Quick Sort
//4. 50 instances using Randomized Quick Sort
//Choice : 3
//
//-------------------------------------------------------------------------- -
//
//Numbers : 10000
//
//(1) Sorted: Process time of randomized quick sort of 10000 numbers : 0.019 --->STEPS : 832744
//(2) Reversely Sorted : Process time of randomized quick sort of 10000 numbers : 0.019 --->STEPS : 806188
//(3) Random Permutation : Process time of randomized quick sort of 10000 numbers : 0.019 --->STEPS : 778390
//-------------------------------------------------------------------------- -
//
//Numbers: 4000
//
//(1) Sorted: Process time of randomized quick sort of 4000 numbers : 0.007 --->STEPS : 274492
//(2) Reversely Sorted : Process time of randomized quick sort of 4000 numbers : 0.007 --->STEPS : 293182
//(3) Random Permutation : Process time of randomized quick sort of 4000 numbers : 0.007 --->STEPS : 289225
//-------------------------------------------------------------------------- -
//
//Numbers : 1000
//
//(1) Sorted: Process time of randomized quick sort of 1000 numbers : 0.001 --->STEPS : 56644
//(2) Reversely Sorted : Process time of randomized quick sort of 1000 numbers : 0.001 --->STEPS : 58165
//(3) Random Permutation : Process time of randomized quick sort of 1000 numbers : 0.002 --->STEPS : 60859
//-------------------------------------------------------------------------- -
//
//Numbers : 500
//
//(1) Sorted: Process time of randomized quick sort of 500 numbers : 0 --->STEPS : 24985
//(2) Reversely Sorted : Process time of randomized quick sort of 500 numbers : 0 --->STEPS : 27832
//(3) Random Permutation : Process time of randomized quick sort of 500 numbers : 0.001 --->STEPS : 29791
//-------------------------------------------------------------------------- -
//
//Numbers : 400
//
//(1) Sorted: Process time of randomized quick sort of 400 numbers : 0 --->STEPS : 18982
//(2) Reversely Sorted : Process time of randomized quick sort of 400 numbers : 0 --->STEPS : 19762
//(3) Random Permutation : Process time of randomized quick sort of 400 numbers : 0 --->STEPS : 20170
//-------------------------------------------------------------------------- -
//
//Numbers : 300
//
//(1) Sorted: Process time of randomized quick sort of 300 numbers : 0 --->STEPS : 15010
//(2) Reversely Sorted : Process time of randomized quick sort of 300 numbers : 0.001 --->STEPS : 13921
//(3) Random Permutation : Process time of randomized quick sort of 300 numbers : 0 --->STEPS : 14686
//-------------------------------------------------------------------------- -
//
//Numbers : 200
//
//(1) Sorted: Process time of randomized quick sort of 200 numbers : 0.001 --->STEPS : 11389
//(2) Reversely Sorted : Process time of randomized quick sort of 200 numbers : 0.001 --->STEPS : 9811
//(3) Random Permutation : Process time of randomized quick sort of 200 numbers : 0 --->STEPS : 10108
//-------------------------------------------------------------------------- -
//
//Numbers : 100
//
//(1) Sorted: Process time of randomized quick sort of 100 numbers : 0 --->STEPS : 4021
//(2) Reversely Sorted : Process time of randomized quick sort of 100 numbers : 0 --->STEPS : 4039
//(3) Random Permutation : Process time of randomized quick sort of 100 numbers : 0 --->STEPS : 3715
//
//More Sorting ? y
//
//Sort ?
//1. Quick Sort
//2. 50 instances using Quick Sort
//3. Randomized Quick Sort
//4. 50 instances using Randomized Quick Sort
//Choice : 4
//
//-------------------------------------------------------------------------- -
//
//Numbers : 10000
//
//Process time of randomized quick sort of 50 instances of 10000 numbers : 0.01906 --->STEPS : 808809
//-------------------------------------------------------------------------- -
//
//Numbers: 4000
//
//Process time of randomized quick sort of 50 instances of 4000 numbers : 0.0069 --->STEPS : 291364
//-------------------------------------------------------------------------- -
//
//Numbers : 1000
//
//Process time of randomized quick sort of 50 instances of 1000 numbers : 0.00134 --->STEPS : 59299
//-------------------------------------------------------------------------- -
//
//Numbers : 500
//
//Process time of randomized quick sort of 50 instances of 500 numbers : 0.00064 --->STEPS : 27018
//-------------------------------------------------------------------------- -
//
//Numbers : 400
//
//Process time of randomized quick sort of 50 instances of 400 numbers : 0.00042 --->STEPS : 20711
//-------------------------------------------------------------------------- -
//
//Numbers : 300
//
//Process time of randomized quick sort of 50 instances of 300 numbers : 0.00036 --->STEPS : 14777
//-------------------------------------------------------------------------- -
//
//Numbers : 200
//
//Process time of randomized quick sort of 50 instances of 200 numbers : 0.0002 --->STEPS : 9165
//-------------------------------------------------------------------------- -
//
//Numbers : 100
//
//Process time of randomized quick sort of 50 instances of 100 numbers : 0.0001 --->STEPS : 4021
//
//More Sorting ? n