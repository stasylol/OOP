#include <iostream>

using namespace std;

int main() {
   
    int* single_ptr = new int(42); 
    int size = 6;
    int* arr = new int[size];

    
    for (int i = 0; i < size; ++i) {
        arr[i] = (i + 1) * 10;
        cout << arr[i] << " ";
    }
    cout << endl;

    
    int* dangling_ptr = single_ptr;
    delete single_ptr;
    single_ptr = nullptr;

    
    int new_val = 99;
    int mid_index = size / 2;
    int new_size = size + 1;

    int* new_arr = new int[new_size];

    for (int i = 0; i < mid_index; ++i) {
        new_arr[i] = arr[i];
    }
    new_arr[mid_index] = new_val;//середина
    for (int i = mid_index; i < size; ++i) {
        new_arr[i + 1] = arr[i];
    }

    delete[] arr;
    arr = new_arr;
    size = new_size;

    
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

   
    delete[] arr;
    arr = nullptr;

    return 0;
}