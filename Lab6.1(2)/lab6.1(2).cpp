#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void fillArray(int b[], int index = 0) {
    if (index < 21) {
        b[index] = rand() % (90 - 10 + 1) + 10;
        fillArray(b, index + 1);
    }
}

void printArray(const int b[], int index = 0) {
    if (index < 21) {
        cout << setw(4) << b[index];
        printArray(b, index + 1);
    }
    else {
        cout << endl;
    }
}

void processArrayRecursive(int b[], int index, int& count, int& sum) {
    if (index < 21) {
        if (!(b[index] % 2 != 0 && b[index] % 3 == 0)) {
            count++;
            sum += b[index];
            b[index] = 0;
        }
        processArrayRecursive(b, index + 1, count, sum);
    }
}

void processArray(int arr[], int& count, int& sum) {
    count = 0;
    sum = 0;
    processArrayRecursive(arr, 0, count, sum);
}

int main() {
    srand(time(0));

    int myArray[25];
    int count, sum;

    fillArray(myArray);
    cout << "Original Array: ";
    printArray(myArray);

    processArray(myArray, count, sum);
    cout << "Modified Array: ";
    printArray(myArray);
    cout << "Count of elements satisfying the criteria: " << count << endl;
    cout << "Sum of elements satisfying the criteria: " << sum << endl;

    return 0;
}