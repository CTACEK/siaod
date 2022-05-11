//
// Created by CTACEK on 5/11/2022.
//
#include <iostream>
#include <iomanip>


using namespace std;


void random_fill(int* array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 201;
    }
}

void input_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
}

void print_array(int* array, int size) {
    cout << "Your array on " << size << " elements." << endl;
    for (int i = 0; i < size; i++) {
        if(i%20==0) cout << endl;
        cout << setw(4) << left << array[i] << " ";
    }
    cout << endl;
}

double bubble_sort_time(int *array, int size) {
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++)
            if (array[j] > array[j + 1]) swap(array[j], array[j + 1]);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> difference = end - start;
    double seconds = difference.count();
    return seconds;
}

void bubble_sort(int *array, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++)
            if (array[j] > array[j + 1]) swap(array[j], array[j + 1]);
}

int main() {
    const int size = 100;
    int array[size];
//    cout << "\nBefore sorting:"<< endl;
    random_fill(array,size);
//    print_array(array,size);
//    cout << "\nAfter sorting:"<< endl;
//    bubble_sort(array,size);
    cout << bubble_sort_time(array,size) * 10;
//    print_array(array,size);

    return 0;
}
