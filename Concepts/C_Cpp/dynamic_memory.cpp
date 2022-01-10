#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

    int *p0 = new int;
    int *p1 = new int(100);
    cout << "p0: " << *p0 << "\np1: " << *p1 << '\n';
    
    delete p0, p1;

    int *arr0 = new int[5]; //allocate, but didn't assign
    int *arr1 = new int[5](); //initialize as 0
    int *arr2 = new int[5]{1, 2, 3, 4, 5}; //allocate and assign

    for(int i=0; i<5; i++)
        printf("arr0: %d arr1: %d arr2: %d\n", arr0[i], arr1[i], arr2[i]);

    delete[] arr0, arr1, arr2;

    int **arr_arr = new int* [3]; //two-dimensional array
    for(int i=0; i<3; i++)
        arr_arr[i] = new int[3]();

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << arr_arr[i][j] << ' ';
        }
        cout << '\n';
    }

    for(int i=0; i<3; i++)
        delete[] arr_arr[i];

    /*----------------------Below is C---------------------------*/
    /*
        Update!!! A cast to "void *malloc()" is not needed in C!!!.
        (some say it "shouldn't" be casted at all)
        But casting is needed in C++.
    */
    // "malloc" returns "void*", so a cast of "int*" is mandatory
    int *p1 = (int*)malloc(sizeof(int)); // a single int, uninitialized
    int *arr = (int*)malloc(sizeof *arr * 10); // an array of int
    int *p1 = (int*)calloc(1, sizeof(int)); // initialized with zero of its type
    free(p1); // free the memory block pointed by p1
    
    // arr = malloc(sizeof *arr * 10); OK in C 

    // returns a pointer, consistency to its original pointer(arr) is not guaranteed
    int *arr2 = (int*)realloc(arr, sizeof(int)*10*2); 

    return 0;
}