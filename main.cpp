#include <iostream>
#include <ctime>
using namespace std;

// функція для ініціалізації масиву
void initializer(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
}

// функція для виводу масиву
void print(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "] = " << arr[i] << endl;
    }
    cout << endl;
}

// функція для додавання елемента в кінець масиву
void add_end(int *&arr, int &size, int value) {
    int *newArray = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newArray[i] = arr[i];
    }
    newArray[size] = value;

    delete[] arr;
    arr = newArray;
    size++;
}

// функція для вставки елемента за вказаним індексом
void add_index(int *&arr, int &size, int index, int value_2) {
    if (index < 0 || index > size) {
        cout << "Index out of range" << endl;
        return;
    }

    int *newArray = new int[size + 1];
    for (int i = 0, j = 0; i <= size; i++, j++) {
        if (i == index) {
            newArray[j] = value_2;
            j++;
        }
        if (i < size) {
            newArray[j] = arr[i];
        }
    }

    delete[] arr;
    arr = newArray;
    size++;
}

// функція для видалення елемента з масиву
void delete_index(int *&arr, int &size, int index) {
    if (index < 0 || index >= size) {
        cout << "Index out of range" << endl;
        return;
    }

    int *newArray = new int[size - 1];
    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) {
            newArray[j] = arr[i];
            j++;
        }
    }
    delete[] arr;
    arr = newArray;
    size--;
}

int main() {
    srand(time(nullptr));

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];
    initializer(arr, size); // функція для ініціалізації масиву

    print(arr, size); // функція для виводу масиву

    int value;
    cout << "Enter the value to add: ";
    cin >> value;
    add_end(arr, size, value); // функція для додавання елемента
    print(arr, size); // вивід масиву після додавання елемента

    int value_2;
    cout << "Enter the value to add index: ";
    cin >> value_2;
    int index;
    cout << "Enter the index to add: ";
    cin >> index;
    add_index(arr, size, index, value_2); // функція для додавання нового елемента за індексом
    print(arr, size); // вивід масиву після вставки елемента

    int index_2;
    cout << "Enter the index to delete: ";
    cin >> index_2;
    delete_index(arr, size, index_2); // функція для видалення елемента
    print(arr, size); // вивід масиву після видалення елемента

    delete[] arr; // звільнення пам’яті
    return 0;
}
