#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    int arr[2][3] = //row column
    {
      {0, 1, 2},
      {2, 3, 4},
    };
    
    for(auto &r : arr)
    {
      for(auto i : r)
        cout << i << ' ';
      cout << '\n';
    }
     int maze[2][3] = {
                         {-9, 2, 3},
                         {8, 5, 6}
                     };

    for(auto row : maze) {
        for(int i = 0; i < 3; i++) {
            cout << row[i] << "\t"; 
        }
        cout << endl; 
    } 

    for(int (*it)[3] = begin(maze); it < end(maze); it++) {
        int *row = *it;
        for(int i = 0; i < 3; i++) {
            cout << row[i] << "\t"; 
        }
        cout << endl; 
    } 
    cout << (*(begin(maze))) << ' ' << **(end(maze)-1) <<'\n';

    int arr[4][3] = {2, 7, 5, 3};
    int *i[3] = {arr[0], arr[1], arr[2]};
    int *row = *i;
    if(row == arr[0])
      cout << "point to the same memory" << endl;
    return 0;
}
