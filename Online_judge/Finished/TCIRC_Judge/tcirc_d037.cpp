/*
***Sliding Window*** -- deque
    Solution:
        Whenever there is a negative number, it is more likely 
        to go to the "mq" min deque；on the other hand, positive
        numbers go to "Mq" max deque. That's why we don't need
        to worry about negqtive numbers, since the final result 
        is taken with abs(), eliminating the need to evaluate 
        whether numbers are negative or not. 
*/
#include <bits/stdc++.h>
using namespace std;

struct P { int x, y; };
int N, L;
deque<P> Mq, mq;
vector<P> v;

bool comp(P &p1, P &p2) {
    return p1.x < p2.x;
}
void put_max(P p) {
    while(!Mq.empty() && Mq.back().y <= p.y) 
        Mq.pop_back();
    Mq.push_back(p);
}
void put_min(P p) {
    while(!mq.empty() && mq.back().y >= p.y) 
        mq.pop_back();
    mq.push_back(p);
}

int main() {
    scanf("%d%d", &N, &L);
    v.resize(N);
    for(int i=0; i<N; i++) {
        scanf("%d", &v[i].x);
    }
    for(int i=0; i<N; i++) {
        scanf("%d", &v[i].y);
    }
    sort(v.begin(), v.end(), comp);

    int res = 0;
    put_max(v[0]);
    put_min(v[0]);
    for(int i=1; i<N; i++) {
        P p = v[i];
        int x = v[i].x, y = v[i].y;
        if(!Mq.empty() && x - Mq.front().x > L) Mq.pop_front();
        if(!mq.empty() && x - mq.front().x > L) mq.pop_front();
        put_max(p);
        put_min(p);
        res = max(res, abs(Mq.front().y - mq.front().y));
    }
    printf("%d\n", res);
    return 0;
}
/* First version -- some vebose deques, AC as well
#include <bits/stdc++.h>
using namespace std;

struct P { int x, y; };
int N, L;
deque<P> Mpq, mpq, Mnq, mnq;
vector<P> v;

bool comp(P &p1, P &p2) {
    return p1.x < p2.x;
}
void put_max(deque<P> &Q, P p) {
    while(!Q.empty() && Q.back().y <= p.y) 
        Q.pop_back();
    Q.push_back(p);
}
void put_min(deque<P> &Q, P p) {
    while(!Q.empty() && Q.back().y >= p.y) 
        Q.pop_back();
    Q.push_back(p);
}

int main() {
    scanf("%d%d", &N, &L);
    v.resize(N);
    for(int i=0; i<N; i++) {
        scanf("%d", &v[i].x);
    }
    for(int i=0; i<N; i++) {
        scanf("%d", &v[i].y);
    }
    sort(v.begin(), v.end(), comp);

    int res = 0;
    if(v[0].y > 0) {
        put_max(Mpq, v[0]);
        put_min(mpq, v[0]);
    } else {
        put_max(Mnq, v[0]);
        put_min(mnq, v[0]);
    }
    for(int i=1; i<N; i++) {
        P p = v[i];
        int x = v[i].x, y = v[i].y;
        if(!Mpq.empty() && x - Mpq.front().x > L) Mpq.pop_front();
        if(!mpq.empty() && x - mpq.front().x > L) mpq.pop_front();
        if(!Mnq.empty() && x - Mnq.front().x > L) Mnq.pop_front();
        if(!mnq.empty() && x - mnq.front().x > L) mnq.pop_front();
        if(y > 0) {
            put_max(Mpq, p);
            put_min(mpq, p);
        } else {
            put_max(Mnq, p);
            put_min(mnq, p);
        }
        int diff[4] = {0};
        if(!Mpq.empty()) {
            if(!mpq.empty()) diff[0] = Mpq.front().y - mpq.front().y;
            if(!mnq.empty()) diff[1] = Mpq.front().y - mnq.front().y;
        }
        if(!Mnq.empty()) {
            if(!mpq.empty()) diff[2] = Mnq.front().y - mpq.front().y;
            if(!mnq.empty()) diff[3] = Mnq.front().y - mnq.front().y;
        }
        for(int i=0; i<4; i++) {
            res = max(res, abs(diff[i]));
        }
    }
    printf("%d\n", res);
    return 0;
}
*/