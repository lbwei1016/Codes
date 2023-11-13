#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#define io ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;

class Process {
public:
    int id;
    int arriv, burst, remain, que_time;
    Process(int _id, int _a, int _b): 
        id(_id), arriv(_a), burst(_b), remain(_b), que_time(_a) {} 
};

enum Mode : int {
    FIFO = 0, SRTF = 1, RR = 2
};

class Queue {
private:
    // "priority_queue" implements a max-heap by default
    class SRTF {
    public:
        bool operator()(const Process &lhs, const Process &rhs) const {
            return !(lhs.remain == rhs.remain ? lhs.arriv < rhs.arriv : lhs.remain < rhs.remain);
        }
    };

    class RR {
    public:
        bool operator()(const Process &lhs, const Process &rhs) const {
            return !(lhs.que_time == rhs.que_time ? lhs.arriv > rhs.arriv : lhs.que_time < rhs.que_time);
        }
    };

    queue<Process> FIFO_pq;
    priority_queue<Process, vector<Process>, SRTF> SRTF_pq;
    priority_queue<Process, vector<Process>, RR> RR_pq;

    // called when a process finished executing
    void _finish(Process &proc, int &cur_time, int &interval) {
        interval -= proc.remain;
        cur_time += proc.remain;

        int turnaround = cur_time - proc.arriv;
        int wait = turnaround - proc.burst;
        time_info[proc.id] = TimeInfo{.wait=wait, .turnaround=turnaround};
    }

public:
    Mode mode;
    int time_quantum, tq_remain;

    struct TimeInfo {
        int wait, turnaround;
    };
    static vector<TimeInfo> time_info;

    Queue() {}
    Queue(int _m, int _tq): 
        mode(Mode(_m)), time_quantum(_tq), tq_remain(_tq) {}

    void push(Process proc) {
        switch (mode) {
            case Mode::FIFO:
                FIFO_pq.emplace(proc);
                break;
            case Mode::SRTF:
                SRTF_pq.emplace(proc);
                break;
            case Mode::RR:
                RR_pq.emplace(proc);
                break;
        }
    }

    Process top() {
        switch (mode) {
            case Mode::FIFO:
                return FIFO_pq.front();
            case Mode::SRTF:
                return SRTF_pq.top();
            case Mode::RR:
                return RR_pq.top();
            default:
                return Process(0, 0, 0);
        }
    }

    void pop() {
        switch (mode) {
            case Mode::FIFO:
                FIFO_pq.pop();
                break;
            case Mode::SRTF:
                SRTF_pq.pop();
                break;
            case Mode::RR:
                RR_pq.pop();
                break;
        }
    }

    bool empty() {
        switch (mode) {
            case Mode::FIFO:
                return FIFO_pq.empty();
            case Mode::SRTF:
                return SRTF_pq.empty();
            case Mode::RR:
                return RR_pq.empty();
            default:
                return true;
        }
    }

    bool execute(int &cur_time, int &interval) {
        switch (mode) {
            case Mode::FIFO:
                if (FIFO_pq.empty()) return true;
                if (FIFO_pq.front().remain <= interval) {
                    auto proc = FIFO_pq.front();
                    _finish(proc, cur_time, interval);

                    FIFO_pq.pop();
                    return true;
                }
                else {
                    FIFO_pq.front().remain -= interval;
                    cur_time += interval;
                    return false; 
                }
                break;
            case Mode::SRTF:
                if (SRTF_pq.empty()) return true;
                if (SRTF_pq.top().remain <= interval) {
                    auto proc = SRTF_pq.top();
                    _finish(proc, cur_time, interval);

                    SRTF_pq.pop();
                    return true;
                }
                else {
                    auto proc = SRTF_pq.top(); SRTF_pq.pop();
                    proc.remain -= interval;
                    SRTF_pq.emplace(proc);

                    cur_time += interval;
                    return false; 
                }
                break;
            case Mode::RR:
                if (RR_pq.empty()) return true;
                // finished
                if (RR_pq.top().remain <= tq_remain && RR_pq.top().remain <= interval) {
                    auto proc = RR_pq.top();
                    _finish(proc, cur_time, interval);

                    RR_pq.pop();
                    tq_remain = time_quantum;
                    return true;
                }
                // use up time quantum, but not finished yet
                else if (tq_remain <= interval) {
                    cur_time += tq_remain;

                    auto proc = RR_pq.top(); RR_pq.pop();
                    proc.remain -= tq_remain;
                    RR_pq.push(proc);

                    tq_remain = time_quantum;
                    interval = -1; // flag
                    return false;
                }
                // time quantum not used up
                else {
                    auto proc = RR_pq.top(); RR_pq.pop();
                    proc.remain -= interval;

                    RR_pq.emplace(proc);

                    cur_time += interval;
                    tq_remain -= interval;

                    interval = 0;
                    return false; 
                }
                break;
        }
        return true;
    }
};

vector<Queue::TimeInfo> Queue::time_info = vector<Queue::TimeInfo>();

void scheduling() {
    int n, m;
    cin >> n >> m;

    Queue::time_info.resize(m);

    vector<Queue> ques(n);
    for (int i = 0; i < n; ++i) {
        int mode, time_quantum;
        cin >> mode >> time_quantum;

        ques[i] = Queue(mode, time_quantum);
    }
    

    queue<Process> procs;
    for (int i = 0; i < m; ++i) {
        int arriv, burst;
        cin >> arriv >> burst;
        procs.push(Process(i, arriv, burst));
    }


    int cur_time = procs.front().arriv;
    while (true) {
        while (!procs.empty() && procs.front().arriv <= cur_time) {
            ques[0].push(procs.front()); 
            procs.pop();
        }

        // always schedule from the id-0 queue
        bool do_execute = false;
        for (int i = 0; i < n; ++i) {
            if (ques[i].empty()) continue;

            do_execute = true;
            int next_arriv = procs.empty() ? INT_MAX : procs.front().arriv;
            int interval = next_arriv - cur_time;

            bool finished = ques[i].execute(cur_time, interval);
            if (!finished) {
                int to_que = (n > 1 && i + 1 < n) ? i + 1 : i;
                auto demote = [&]() {
                    auto proc = ques[i].top(); ques[i].pop();

                    proc.que_time = cur_time;
                    ques[to_que].push(proc);
                };

                if (i == 0) {
                    switch (ques[0].mode) {
                        case Mode::SRTF:
                            if (procs.size() && procs.front().burst < ques[0].top().remain) 
                                demote();
                            break;
                        case Mode::RR:
                            if (interval < 0) {
                                demote();
                            }
                            break;
                    }
                }
                else {
                    /* 
                        When a process enters a higher-priority queue, 
                        lower-priority queue's process is preempted.
                    */
                    if (ques[i].mode == Mode::RR) {
                        ques[i].tq_remain = ques[i].time_quantum;
                    }
                    demote();
                }
            }
            break;
        }
        if (!do_execute) {
            if (procs.empty()) break;
            cur_time = procs.front().arriv;
        }
    }

    int total_wait = 0, total_turn = 0;
    for (auto &info: Queue::time_info) {
        cout << info.wait << ' ' << info.turnaround << '\n';
        total_wait += info.wait;
        total_turn += info.turnaround;
    }

    cout << total_wait << '\n' << total_turn << '\n';
}

int main() {
    io;
    scheduling();
    return 0;
}