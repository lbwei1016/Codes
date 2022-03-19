#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include <string.h>
using namespace std;

const int LANDING = 6, RUNWAY = 4;
struct Landing {
    int id, fuel; 
};

void arrive(ifstream&, deque<Landing>[], deque<int>[]);
void enter_runway(ofstream&, deque<Landing>[], deque<Landing>[], deque<int>[], deque<int>[], vector<int>&);
void landing_output(ofstream&, deque<Landing>[], int);
void takeoff_output(ofstream&, deque<int>[], int);
void output(ofstream&, deque<Landing>[], deque<int>[], vector<int>&);
void push_into(deque<Landing>[], deque<Landing>[], deque<int>[], deque<int>[]);

int main() {
    ifstream iff("input.txt");
    ofstream off("output.txt");
    int time_unit;
    deque<Landing> landing[LANDING], landing_in_que[LANDING];
    deque<int> takeoff[RUNWAY], takeoff_in_que[RUNWAY];

    iff >> time_unit;
    for (int i=1; i<=time_unit; ++i) {
        vector<int> runways(4, -1);
        // Step 0:
        off << "Simulation time: " << i << "\n\n";
        output(off, landing_in_que, takeoff_in_que, runways);

        // Step 1:
        off << "\nStep 1:\nLanding plane(s):\n";
        arrive(iff, landing, takeoff);
        for (int j=0; j<LANDING; ++j) {
            landing_output(off, landing, j);
        }
        off << '\n';
        output(off, landing_in_que, takeoff_in_que, runways);

        // Step 2:
        off << "\nStep 2:\nTakeoff plane(s):\n";
        for (int j=0; j<RUNWAY; ++j) {
            takeoff_output(off, takeoff, j);
        }
        off << '\n';
        output(off, landing_in_que, takeoff_in_que, runways);

        enter_runway(off, landing, landing_in_que, takeoff, takeoff_in_que, runways);
        off << "\n-----------------------------------\n";

        push_into(landing, landing_in_que, takeoff, takeoff_in_que);
    }
    return 0;
}

void arrive(ifstream &iff, deque<Landing> la[], deque<int> ta[]) {
    int plane_num, id, fuel;
    iff >> plane_num;
    
    for (int i=0; i<plane_num; ++i) {
        iff >> id >> fuel;
        la[i%LANDING].push_back(Landing{id, fuel});
    }

    iff >> plane_num;
    for (int i=0; i<plane_num; ++i) {
        iff >> id;
        ta[i%RUNWAY].push_back(id);
    }
}

void enter_runway(ofstream &off, deque<Landing> la[], deque<Landing> la_in_q[], deque<int> ta[], deque<int> ta_in_q[], vector<int> &run) {
    int run_cnt = 0;
    int landing_num = 0, takeoff_num = 0;
    vector<int> emerg;
    for (int i=0; i<LANDING; ++i) {
        for (int j=0, sz=la[i].size(); j<sz; ++j) {
            auto plane = la[i].front(); la[i].pop_front();
            if (plane.fuel == 0) {
                // run[run_cnt++] = plane.id;
                emerg.push_back(plane.id);
            }
            else la[i].push_back(plane);
        }
        landing_num += la[i].size();
    }
    for (int i=0; i<RUNWAY; ++i) {
        takeoff_num += ta[i].size();
    }

    push_into(la, la_in_q, ta, ta_in_q);

    // Step 3:
    off << "\nStep 3:\nEmergency plane(s):\n";
    for (auto &x: emerg) {
        off << "\tid: " << x << '\n';
    }
    off << '\n';
    output(off, la_in_q, ta_in_q, run);

    // Step 4:
    off << "\nStep 4:\n\n";
    for (auto &x: emerg) {
        run[run_cnt++] = x;
    }

    for (int i=run_cnt; i<RUNWAY; ++i) {
        int mx_size = 0, who;
        if (landing_num > takeoff_num && i > 0) {
            for (int j=0; j<LANDING; j+=2) {
                if (la_in_q[j].size() > mx_size) {
                    mx_size = la_in_q[j].size();
                    who = j;
                }
                if (la_in_q[j+1].size() > mx_size) {
                    mx_size = la_in_q[j].size();
                    who = j;
                }
            }   
            run[i] = la_in_q[who].front().id;
            la_in_q[who].pop_front();
            --landing_num;
        }
        else {
            for (int j=0; j<RUNWAY; ++j) {
                if (ta_in_q[j].size() > mx_size) {
                    mx_size = ta_in_q[j].size();
                    who = j;
                }
            }    
            run[i] = ta_in_q[who].front();
            ta_in_q[who].pop_front();
            --takeoff_num;
        }
        if (landing_num == 0 && takeoff_num == 0)
            break;
    }
    output(off, la_in_q, ta_in_q, run);
}

void landing_output(ofstream &off, deque<Landing> la[], int at) {
    char buff[1000];
    for (auto &x: la[at]) {
        sprintf(buff, "\t(%d, %d)\n", x.id, x.fuel);
        off.write(buff, strlen(buff));
    }
}

void takeoff_output(ofstream &off, deque<int> ta[], int at) {
    char buff[1000];
    for (auto &x: ta[at]) {
        sprintf(buff, "\t%d\n", x);
        off.write(buff, strlen(buff));
    }
}

void output(ofstream &off, deque<Landing> la[], deque<int> ta[], vector<int> &run) {
    char buff[1000];
    for (int i=0; i<RUNWAY; ++i) {
        sprintf(buff, "Runway%d(%d)\n", i+1, run[i]);
        off.write(buff, strlen(buff));

        for (int j=0; j<2; ++j) {
            off << "Landing queue " << j+1 << ":\n";
            if (i > 0) {
                landing_output(off, la, 2*(i-1)+j);
            }
        }
        
        off << "Takeoff queue:\n";
        takeoff_output(off, ta, i);
        off << '\n';
        // off << "\n--------------------------------\n";
    }
}

void push_into(deque<Landing> la[], deque<Landing> la_in_q[], deque<int> ta[], deque<int> ta_in_q[]) {
    for (int i=0; i<LANDING; ++i) {
        while (la[i].size()) {
            la_in_q[i].push_back(la[i].front());
            la[i].pop_front();
        }
    }
    for (int i=0; i<RUNWAY; ++i) {
        while (ta[i].size()) {
            ta_in_q[i].push_back(ta[i].front());
            ta[i].pop_front();
        }
    }
}