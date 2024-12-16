#include <iostream>
#include <ctime>
using namespace std;

// Функція для ініціалізації масиву
void initializer(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Функція для виведення масиву
void print(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "] = " << arr[i] << endl;
    }
    cout << endl;
}

// Функція для перевірки, чи число є простим
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Функція для знаходження непростих чисел
int* findNonPrimes(int *arr, int size, int &newSize) {
    newSize = 0;
    int *newArray = new int[size];
    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            newArray[newSize] = arr[i];
            newSize++;
        }
    }
    int *finalArray = new int[newSize];
    for (int i = 0; i < newSize; i++) {
        finalArray[i] = newArray[i];
    }
    delete[] newArray;
    return finalArray;
}

int main() {
    srand(time(nullptr));

    int size;
    cout << "Enter the array size:";
    cin >> size;
    int *arr = new int[size];

    cout << "Array" << endl;


    initializer(arr, size); // Ініціалізація масиву
    print(arr, size); // Вивести масив

    cout << "Non-prime numbers" << endl;

    int newSize = 0;
    int *nonPrimesArr = findNonPrimes(arr, size, newSize); // Знаходження непростих чисел в масиві
    print(nonPrimesArr, newSize); // Вивести масив

    delete[] arr;
    delete[] nonPrimesArr; // Звільнити пам'ять для nonPrimesArr

    return 0;
}