#include <iostream> 

using namespace std; 

int main() 
{ 
    int maze[2][3] = {
                         {1, 2, 3},
                         {4, 5, 6}
                     };
    int arr[2] = {1, 2};
    // for(int (*it)[3] = begin(maze); it < end(maze); it++) {
    //     int *row = *it;
    //     for(int i = 0; i < 3; i++) {
    //         cout << row[i] << "\t"; 
    //     }
    //     cout << endl; 
    // } 
    int *ptr = arr;
    cout << begin(arr) << '\n' << ptr << '\n';
    cout << end(arr) << '\n' << ptr + (sizeof(arr)/sizeof(int)) << endl;

    int *p = arr; //p points to arr(first element of arr)
    int (*pp)[3] = maze; // pp[3] points to maze[0](first element of maze)
    cout << *(pp[0]+1) << ' ' << *pp[1] << ' ' << pp[0][1];

    return 0; 
}