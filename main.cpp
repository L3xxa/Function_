#include <iostream>
#include <ctime>
using namespace std;

// Функція для ініціалізації масиву
void initializer(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 101 - 50; // Випадкові числа в діапазоні [-100, 100]
    }
}

// Функція для виведення масиву
void print(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "] = " << arr[i] << endl;
    }
    cout << endl;
}

// Функція для розділення масиву на додатні, від'ємні та нульові елементи
void split(int *arr, int size, int *positive, int *negative, int *zero, int &posCount, int &negCount, int &zeroCount) {
    posCount = 0;
    negCount = 0;
    zeroCount = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            positive[posCount] = arr[i];
            posCount++;
        } else if (arr[i] < 0) {
            negative[negCount] = arr[i];
            negCount++;
        } else {
            zero[zeroCount] = arr[i];
            zeroCount++;
        }
    }
}

// Функція для виведення розділених масивів
void printArray(const char *label, int *arr, int size) {
    cout << label << ": ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(nullptr));

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];
    int *positive = new int[size];
    int *negative = new int[size];
    int *zero = new int[size];

    initializer(arr, size);
    cout << "Original array:" << endl;
    print(arr, size);

    int posCount, negCount, zeroCount;

    split(arr, size, positive, negative, zero, posCount, negCount, zeroCount);

    printArray("Positive numbers", positive, posCount);
    printArray("Negative numbers", negative, negCount);
    printArray("Zero elements", zero, zeroCount);

    delete[] arr;
    delete[] positive;
    delete[] negative;
    delete[] zero;

    return 0;
}
