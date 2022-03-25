#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

int main() {
    srand(time(0));

    ofstream ff("input.txt", ios::out);

    int time_unit = 500;
    int land_cnt = 0, takeoff_cnt = 0;

    ff << time_unit << '\n';
    for (int i=0; i<time_unit; ++i) {
        int landing = rand() % 5; // no. of landing planes
        int takeoff = rand() % 5; // no. of takeoff planes
        land_cnt += landing;
        takeoff_cnt += takeoff;
        ff << landing <<  ' ' << takeoff << '\n';
        for (int la=0; la<landing; ++la) {
            int fuel = rand() % 10 + 1;
            ff << fuel << ' ';
        }
        ff << '\n';
    }
    printf("land num: %d, takeoff num: %d", land_cnt, takeoff_cnt);
    return 0;
}