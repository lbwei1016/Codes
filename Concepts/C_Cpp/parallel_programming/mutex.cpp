// See OS/NYCU-HW/
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

void count(int index) {
    static mutex io_mutex;
    int num = 1000000;
    while (num--) {}

    // a local scope
    {
        lock_guard<mutex> lock(io_mutex);
        cout << "I'm thread " << index << ", local count: 1000000\n";
    }
    // io_mutex is unlocked here (end of scope)
    // Like a destructor, a mutex is unlocked when being out of scope,
    // where this technique is called "RAII".
}

int main(void) {
    thread t[100];

    for (int i = 0; i < 100; i++)
        t[i] = thread(count, i);

    for (int i = 0; i < 100; i++)
        t[i].join();
}
