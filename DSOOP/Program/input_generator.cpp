#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

int main() {
    srand(time(0));

    ofstream ff("input.txt", ios::out);

    int time_unit = rand() % 100 + 1;
    int odd_cnt = 1, even_cnt = 0;

    ff << time_unit << '\n';
    for (int i=0; i<time_unit; ++i) {
        int landing = rand() % 5; // no. of landing planes
        int takeoff = rand() % 4; // no. of takeoff planes
        ff << landing << '\n';
        for (int la=0; la<landing; ++la, even_cnt+=2) {
            int fuel = rand() % 10 + 1;
            ff << even_cnt << ' ' << fuel << '\n';
        }
        ff << takeoff << '\n';
        for (int ta=0; ta<takeoff; ++ta, odd_cnt+=2) {
            ff << odd_cnt << '\n';
        }
        ff << '\n';
    }
    return 0;
}