#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
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
void arrive(deque<Landing>&, deque<Takeoff>&); 
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
    srand(time(0));
    ofstream off("output.txt");
    int time_unit = 500; // how much time unit to simulate
    deque<Landing> landing; // incoming planes about to land
    // planes in queue
    // [0, 1]: runway 2; [2, 3]: runway 3, [4, 5]: runway 4
    deque<Landing> landing_in_que[LANDING]; 
    deque<Takeoff> takeoff; // incoming planes about to takeoff
    deque<Takeoff> takeoff_in_que[RUNWAY]; // planes in queue
    // iff >> time_unit;
    for (cur_time=1; cur_time<=time_unit; ++cur_time) {
        vector<int> runways(4, -1);
        // Step 0:
        off << "Simulation time: " << cur_time << "\n\n";
        output(off, landing_in_que, takeoff_in_que, runways);

        // Step 1:
        off << "\nStep 1:\nLanding plane(s):\n";
        arrive(landing, takeoff);
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

        for (int i=0; i<LANDING; ++i) {
            for (auto &x: landing_in_que[i]) {
                --x.fuel;
            }
        }

        off << "\n-----------------------------------\n";
    }
    
    statistics();

    off.close();
    return 0;
}

void arrive(deque<Landing> &la, deque<Takeoff> &ta) {
    int landing = rand() % 5; // no. of landing planes
    int takeoff = rand() % 5; // no. of takeoff planes
    for (int i=0; i<landing; ++i, even_cnt+=2) {
        int fuel = rand() % 10 + 1;
        la.push_back(Landing{even_cnt, fuel, cur_time});
    }
    
    for (int i=0; i<takeoff; ++i, odd_cnt+=2) {
        ta.push_back(Takeoff{odd_cnt, cur_time});
    }
}

void enter_runway(ofstream &off, deque<Landing> la_in_q[], deque<Takeoff> ta_in_q[], vector<int> &run) {
    int run_cnt = 0;
    vector<Landing> emerg; // emergency: fuel = 0

    for (int i=0; i<LANDING; ++i) {
        for (int j=0, sz=la_in_q[i].size(); j<sz; ++j) {
            auto plane = la_in_q[i].front(); la_in_q[i].pop_front();
            if (plane.fuel == 0) 
                emerg.push_back(plane);
            else {
                la_in_q[i].push_back(plane);
            }
        }
    }

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
        int ft = 2*(i-1), sd = 2*i-1;
        // if (i > 0 && (!la_in_q[ft].empty() || !la_in_q[sd].empty())) {
        if (i > 0 && (!la_in_q[ft].empty() || !la_in_q[sd].empty()) && max(la_in_q[ft].size(), la_in_q[sd].size())+dev>ta_in_q[i].size()) {
        // if (i > 0 && (la_in_q[ft].size() > 2 || la_in_q[sd].size() > 1)) {
            if (la_in_q[ft].empty() && la_in_q[sd].empty())
                break;
            
            Landing to_land;
            if (la_in_q[ft].size() >= la_in_q[sd].size()) {
                to_land = la_in_q[ft].front();
                run[i] = to_land.id;
                la_in_q[ft].pop_front();
            }
            else  {
                to_land = la_in_q[sd].front();
                run[i] = to_land.id;
                la_in_q[sd].pop_front();
            }
            ++land_num;
            land_sum += cur_time - to_land.time_stamp;
            fuel_saved += to_land.fuel;
        }
        else {
            if (ta_in_q[i].empty()) break;
            Takeoff to_takeoff = ta_in_q[i].front();
            run[i] = to_takeoff.id;
            ta_in_q[i].pop_front();

            ++takeoff_num;
            takeoff_sum += cur_time - to_takeoff.time_stamp;
        }
    }
}

void landing_output(ofstream &off, deque<Landing> &la) {
    char buff[1000];
    for (auto &x: la) {
        sprintf(buff, "\t(%d, %d)\n", x.id, x.fuel);
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
                landing_output(off, la_in_q[2*i-2+j]);
            }
        }
        
        off << "Takeoff queue:\n";
        takeoff_output(off, ta_in_q[i]);
        off << '\n';
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
        for (int i=0; la.size()&&i<LANDING; i+=2) {
            if (la_in_q[i].size() <= avg_size && la_in_q[i+1].size() <= avg_size) {
                auto &pl = la_in_q[i].size() < la_in_q[i+1].size() ? la_in_q[i] : la_in_q[i+1];
                pl.push_back(la.front());
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

    // off << "-------------------------\n";
    // off << "land_sum: " << land_sum << '\n';
    // off << "takeoff_sum: " << takeoff_sum << '\n';
    // off << "land_num: " << land_num << '\n';
    // off << "takeoff_num: " << takeoff_num << '\n';
    off.close();
}