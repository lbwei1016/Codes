#include <iostream>
#include <ctime>
#include <random>
using namespace std;

int main() {
    int seed = time(nullptr);
    mt19937 mt(seed);
    cout << mt() << '\n';
    return 0;
}