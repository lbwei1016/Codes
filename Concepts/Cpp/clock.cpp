#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    
    clock_t start, end;
    start = clock();
    for(int i=0; i<1e7; i++);
    end = clock();
    cout << "Time spent: " << end-start  << " ms\n";
    return 0;
}