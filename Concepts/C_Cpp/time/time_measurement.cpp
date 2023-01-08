/*
***time***
    Description:
        This is inspired by DS-OO class I took in 2022 spring semester.
*/
#include <bits/stdc++.h>
using namespace std;

void func() {
    for(int i=0; i<20000000; ++i);
}

int main() {
    double elapsedtime = 0;
    time_t start, end;
    int cnt = 0;

    /*
        A good way to measure time:
            Sometimes, a single execution time only takes less than a minute, and hence
            it's reasonable to take more measurements and calculate the mean value.

            However, deviation still exists.
            For example, we keep executing for at least "10 seconds", while the unit of
            "time()" is "1 second". In this case, the deviation rate (not sure this is the 
            right way to say that) is "1 / 10 = 10%", since when "end - start == 10", the 
            actual elapsed time may be "10.00000000001 sec" or "10.999999999 sec"; that's 
            how the deviation rate(?) is calculated.

    */
    start = time(nullptr);
    do {
        ++cnt;
        func();
        end = time(nullptr);
    } while(end - start < 10); 
    printf("first timing result: %lf, cnt: %d\n", (end-start)/(double)cnt, cnt);

    /*
        A bad way to measure time:
            Here, time() returns "seconds" after a specific date (e.g. 1970/1/1), and
            thus the accuracy is limited to "sec". If we adopt the method below, we lose
            some time to "end and restart" the timer (assign "start" inside the loop), and
            thus the measured time may be more inaccurate when measurement is taken for 
            a long period of time (perhaps an hour?).
    */
    cnt = 0;
    do {
        ++cnt;
        start = time(nullptr);
        func();
        end = time(nullptr);
        if(end - start > 0)
            cout << end - start << '\n';
        elapsedtime += (end - start);
    } while(elapsedtime < 10); 
    printf("second timing result: %lf, cnt: %d\n", (elapsedtime)/(double)cnt, cnt);
    return 0;
}