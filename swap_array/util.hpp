#include <vector>
#include <iostream>
#include "../swap_values/util.hpp"

using namespace std;

template<typename T>
void swap(T *array1, T *array2, int length) {
    /*
     * TODO: Swap the values of array1 and array2 without using any other array.
     */
}

template<typename T>
void print_array(T *array, int len) {
    for (int i = 0; i < len; i++) {
        cout << "data" << "[" << i << "] = " << array[i] << endl;
    }
}
