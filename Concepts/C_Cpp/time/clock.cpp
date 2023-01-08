#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    
    clock_t start, end;
    start = clock(); // clock ticks
    for(int i=0; i<1e7; i++);
    end = clock();
    cout << "Time spent: " << double(end-start) / CLOCKS_PER_SEC  << " sec\n";
    return 0;
}