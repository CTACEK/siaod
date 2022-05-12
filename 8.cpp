//
// Created by CTACEK on 5/11/2022.
//
#include <iostream>
#include <iomanip>
#include <ctime>


using namespace std;


void random_fill(int *array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 201;
    }
}

void input_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
}

void print_array(int *array, int size) {
    cout << "Your array on " << size << " elements." << endl;
    for (int i = 0; i < size; i++) {
        if (i % 20 == 0) cout << endl;
        cout << setw(4) << left << array[i] << " ";
    }
    cout << endl;
}

void bubble_sort(int *array, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++)
            if (array[j] > array[j + 1]) swap(array[j], array[j + 1]);
}

void count_sort(int *array, int size) {
    int localmax = array[0];

    for (int i = 1; i < size; i++)
        if (array[i] > localmax) localmax = array[i];

    int maxcount = max(localmax, size);

    int *count = new int[maxcount + 1];
    int *final = new int[maxcount + 1];

    fill(count, count + maxcount + 1, 0);

    for (int i = 0; i < size; i++) count[array[i]]++;

    for (int i = 1; i <= maxcount; i++) count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        final[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < size; i++) array[i] = final[i];

    delete[] count;
    delete[] final;
}

void stooge_sort(int *array, int left, int right) {
    int temp, k;
    if (array[left] > array[right]) {
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;
    }
    if ((left + 1) >= right)
        return;

    k = (int) ((right - left + 1) / 3);
    stooge_sort(array, left, right - k);
    stooge_sort(array, left + k, right);
    stooge_sort(array, left, right - k);
}

int main() {
    const int size = 100;
    int array[size];

    cout << "\nBefore sorting:" << endl;
    random_fill(array, size);
//    print_array(array,size);


    long double start_time = clock();
//    bubble_sort(array, size);
//    count_sort(array,size);
    stooge_sort(array,0,size);

    long double end_time = clock();
    long double search_time = end_time - start_time;

//    cout << "\nAfter sorting:"<< endl;
//    print_array(array,size);

    cout << "Time: " << fixed << setprecision(14) << search_time / 1000;

    return 0;
}
