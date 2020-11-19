#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

#define NUM_STEPS 32

class ApproxC {
private:
    int steps;
    int nums;
    double results[8][4];
public:
    void approxC();
    void inData();
    void print();
    void printResults();
};

void mode(int);

ApproxC input[NUM_STEPS];

int main() {

    ApproxC call;
    call.inData();

    //call.print();

    call.approxC();

    call.printResults();

    return 0;
}

void ApproxC::inData() {
    ifstream inData("steps.txt");
    if (inData.is_open())
    {
        while (inData)
        {
            for (int i = 0; i < NUM_STEPS; i++) {
                inData >> input[i].nums;
                inData >> input[i].steps;
            }
        }
        inData.close();
    }
    else cout << "Unable to open file";
}

//print testing
void ApproxC::print() {
    for (int i = 0; i < NUM_STEPS; i++) {
        cout << input[i].nums << endl;
        cout << input[i].steps << endl;
    }
}

void ApproxC::approxC() {

    int MAX = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            results[j][i] = input[MAX].steps / pow(input[MAX].nums, 2);
            MAX++;
        }
    }
}

void ApproxC::printResults() {

    for (int i = 0; i < 4; i++) {

        int MAX = 0;
        mode(i);

        for (int j = 0; j < 8; j++) {
            cout << "Num " << input[MAX].nums << ": " << results[j][i] << endl;
            MAX++;
        }
    }
}

void mode(int i) {
    
    switch (i) {

    case 0:
        cout << "Sorted:" << endl;
        break;

    case 1:
        cout << "Reverse:" << endl;
        break;

    case 2:
        cout << "Random:" << endl;
        break;

    case 3:
        cout << "50 Instances:" << endl;
        break;

    default:
        cout << "Error" << endl;
        exit(1);
    }

}