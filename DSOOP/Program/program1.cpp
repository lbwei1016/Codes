#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

const int FUEL_BOUND = 3;
struct Landing {
    int id, fuel, runway; 
};

void arrive(ifstream &ff, auto &queue, int state) {
    int plane_num;
    ff >> plane_num;

    int id, fuel, run_cnt = 1; 
    while (plane_num--) {
        ff >> id;
        if (state) {
            ff >> fuel;
            queue.push_back(Landing{id, fuel, run_cnt});
            run_cnt = run_cnt % 3 + 1;
        }
        else queue.push_back(id);
    }
}

void enter_runway(list<Landing> &la, list<int> &ta, vector<int> &run) {
    for (auto it=la.begin(); it!=la.end(); ++it) {
        if (it->fuel == 0) {
            run[0] = it->id;
            la.erase(it--);
        }
        else if (it->fuel <= FUEL_BOUND) {
            run[it->runway] = it->id;
            la.erase(it--);
        }
    }
}

int main() {
    ifstream ff("input.txt");
    int time_unit;
    list<Landing> landing;
    list<int> takeoff;
    vector<int> runways(4, -1);

    ff >> time_unit;
    for (int i=0; i<time_unit; ++i) {
        arrive(ff, landing, 1);
        arrive(ff, takeoff, 0);
    }
    return 0;
}