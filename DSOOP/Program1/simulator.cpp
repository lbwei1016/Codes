#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int LANDING = 6, RUNWAY = 4; // queue numbers
struct Landing {
    int id, fuel, time_stamp;
    bool operator<(Landing &_la) {
        return fuel < _la.fuel;
    } 
};
struct Takeoff {
    int id, time_stamp;
};
int even_cnt = 0, odd_cnt = 1;
int cur_time;
int land_sum, takeoff_sum;
int emerg_num, crash_num, land_num, takeoff_num;
int fuel_saved;

// handle incoming planes
void arrive(ifstream&, deque<Landing>&, deque<Takeoff>&); 
// determmine which planes can use the runways
void enter_runway(ofstream&, deque<Landing>[], deque<Takeoff>[], vector<int>&);
// print planes about to land
void landing_output(ofstream&, deque<Landing>&);
// print planes about to takeoff
void takeoff_output(ofstream&, deque<Takeoff>&);
// print the status of queues and runways
void output(ofstream&, deque<Landing>[], deque<Takeoff>[], vector<int>&);
// push incoming planes into corresponding queues
void push_into(deque<Landing>&, deque<Landing>[], deque<Takeoff>&, deque<Takeoff>[]);
// show statistics
void statistics();

int main() {
    ifstream iff("input.txt");
    ofstream off("output.txt");
    int time_unit; // how much time unit to simulate
    deque<Landing> landing; // incoming planes about to land
    // planes in queue
    // [0, 1]: runway 2; [2, 3]: runway 3, [4, 5]: runway 4
    deque<Landing> landing_in_que[LANDING]; 
    deque<Takeoff> takeoff; // incoming planes about to takeoff
    deque<Takeoff> takeoff_in_que[RUNWAY]; // planes in queue

    iff >> time_unit;
    for (cur_time=1; cur_time<=time_unit; ++cur_time) {
        vector<int> runways(4, -1);
        // Step 0:
        off << "Simulation time: " << cur_time << "\n\n";
        output(off, landing_in_que, takeoff_in_que, runways);

        // Step 1:
        off << "\nStep 1:\nLanding plane(s):\n";
        arrive(iff, landing, takeoff);
        landing_output(off, landing);
        off << '\n';
        output(off, landing_in_que, takeoff_in_que, runways);

        // Step 2:
        off << "\nStep 2:\nTakeoff plane(s):\n";
        takeoff_output(off, takeoff);
        off << '\n';
        output(off, landing_in_que, takeoff_in_que, runways);

        push_into(landing, landing_in_que, takeoff, takeoff_in_que);
        enter_runway(off, landing_in_que, takeoff_in_que, runways);
        output(off, landing_in_que, takeoff_in_que, runways);

        // off << "crash: " << crash_num << '\n';
        off << "\n-----------------------------------\n";
    }
    
    statistics();

    iff.close(); off.close();
    return 0;
}

void arrive(ifstream &iff, deque<Landing> &la, deque<Takeoff> &ta) {
    int la_num, ta_num, fuel;
    iff >> la_num >> ta_num;
    
    for (int i=0; i < la_num; ++i, even_cnt+=2) {
        iff >> fuel;
        la.push_back(Landing{even_cnt, fuel, cur_time});
    }

    for (int i=0; i < ta_num; ++i, odd_cnt+=2) {
        ta.push_back(Takeoff{odd_cnt, cur_time});
    }
}

void enter_runway(ofstream &off, deque<Landing> la_in_q[], deque<Takeoff> ta_in_q[], vector<int> &run) {
    int run_cnt = 0;
    int land_que_size = 0, takeoff_que_size = 0;
    vector<Landing> emerg; // emergency: fuel = 0

    for (int i=0; i<LANDING; ++i) {
        for (int j=0, sz=la_in_q[i].size(); j<sz; ++j) {
            auto plane = la_in_q[i].front(); la_in_q[i].pop_front();
            if (plane.fuel == cur_time - plane.time_stamp) 
                emerg.push_back(plane);
            else {
                ++land_que_size;
                la_in_q[i].push_back(plane);
            }
        }
    }
    for (int i=0; i<RUNWAY; ++i) 
        takeoff_que_size += ta_in_q[i].size();

    // Step 3:
    off << "\nStep 3:\nEmergency plane(s):\n";
    for (auto &x: emerg) {
        off << "\tid: " << x.id << '\n';
    }
    off << '\n';
    output(off, la_in_q, ta_in_q, run);

    // Step 4:
    off << "\nStep 4:\n\n";
    if (emerg.size() > RUNWAY) 
        crash_num += emerg.size() - RUNWAY; 
    // emergency first
    for (auto &x: emerg) {
        run[run_cnt++] = x.id;
        ++land_num;
        ++emerg_num;
        land_sum += cur_time - x.time_stamp;
        if (run_cnt == RUNWAY) break;
    }

    // put planes onto runways depending on their numbers
    const int dev = 5; // give landing higher priority
    for (int i=run_cnt; i<RUNWAY; ++i) {
        if (land_que_size >= takeoff_que_size - dev && i > 0) {
            if (la_in_q[2*(i-1)].empty() && la_in_q[2*i-1].empty())
                break;
            
            Landing to_land;
            if (la_in_q[2*(i-1)].size() >= la_in_q[2*i-1].size()) {
                to_land = la_in_q[2*(i-1)].front();
                run[i] = to_land.id;
                la_in_q[2*(i-1)].pop_front();
            }
            else  {
                to_land = la_in_q[2*i-1].front();
                run[i] = to_land.id;
                la_in_q[2*i-1].pop_front();
            }
            --land_que_size;
            ++land_num;
            land_sum += cur_time - to_land.time_stamp;
            fuel_saved += to_land.fuel - (cur_time - to_land.time_stamp);
        }
        else {
            if (ta_in_q[i].empty()) break;
            Takeoff to_takeoff = ta_in_q[i].front();
            run[i] = to_takeoff.id;
            ta_in_q[i].pop_front();

            --takeoff_que_size;
            ++takeoff_num;
            takeoff_sum += cur_time - to_takeoff.time_stamp;
        }
    }
}

void landing_output(ofstream &off, deque<Landing> &la) {
    char buff[1000];
    for (auto &x: la) {
        sprintf(buff, "\t(%d, %d)\n", x.id, x.fuel - (cur_time - x.time_stamp));
        off.write(buff, strlen(buff));
    }
}

void takeoff_output(ofstream &off, deque<Takeoff> &ta) {
    char buff[1000];
    for (auto &x: ta) {
        sprintf(buff, "\t%d\n", x.id);
        off.write(buff, strlen(buff));
    }
}

void output(ofstream &off, deque<Landing> la_in_q[], deque<Takeoff> ta_in_q[], vector<int> &run) {
    char buff[1000];
    for (int i=0; i<RUNWAY; ++i) {
        sprintf(buff, "Runway%d(%d)\n", i+1, run[i]);
        off.write(buff, strlen(buff));

        for (int j=0; j<2; ++j) {
            off << "Landing queue " << j+1 << ":\n";
            if (i > 0) {
                landing_output(off, la_in_q[2*(i-1)+j]);
            }
        }
        
        off << "Takeoff queue:\n";
        takeoff_output(off, ta_in_q[i]);
        off << '\n';
        // off << "\n--------------------------------\n";
    }
}

void push_into(deque<Landing> &la, deque<Landing> la_in_q[], deque<Takeoff> &ta, deque<Takeoff> ta_in_q[]) {
    // averagely distribute incoming planes
    sort(la.begin(), la.end()); // less fuel first
    int avg_size = 0;
    for (int i=0; i<LANDING; ++i) {
        avg_size += la_in_q[i].size();
    }
    avg_size /= LANDING;
    while (la.size()) {
        for (int i=0; la.size()&&i<LANDING; ++i) {
            if (la_in_q[i].size() <= avg_size) {
                la_in_q[i].push_back(la.front());
                la.pop_front();
            }
        }
        ++avg_size;
    }

    avg_size = 0;
    for (int i=0; i<RUNWAY; ++i) {
        avg_size += ta_in_q[i].size();
    }
    avg_size /= RUNWAY;
    while (ta.size()) {
        for (int i=0; ta.size()&&i<RUNWAY; ++i) {
            if (ta_in_q[i].size() <= avg_size) {
                ta_in_q[i].push_back(ta.front());
                ta.pop_front();
            }
        }
        ++avg_size;
    }
}

void statistics() {
    ofstream off("statistics.txt");
    off << "Time unit simulated: " << --cur_time << '\n';
    off << "Average landing waiting time: " << land_sum / (double)land_num << "(s)\n";
    off << "Average takeoff waiting time: " << takeoff_sum / (double)takeoff_num << "(s)\n";
    off << "Average fuel saved: " << fuel_saved / (double)cur_time << "(unit/s)\n";
    off << "Total plane(s) in emergency: " << emerg_num << '\n';
    off << "Total plane crashed: " << crash_num << '\n';
    off.close();
}