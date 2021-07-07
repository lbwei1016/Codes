/*
***Binary Search*** -- extended array
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 400005;
int p[MAX_N]; //extended array

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%d", &p[i]);
    }
    for(int i=0; i<n; i++) {
        p[n+i] = p[i]; //extended array
    }
    for(int i=1; i<2*n; i++) {
        p[i] += p[i-1]; //prefix sum
    }
    int room = 0; //current room number
    for(int i=0; i<m; i++) {
        int q;
        scanf("%d", &q);
        //we only need the sum of range, not the whole prefix sum
        //instead of removing excessive parts, we add them up to have the same effect
        if(room > 0) q += p[room-1];
        //current room is enough
        if(q <= p[room]) {
            room = (room+1) % n;
            continue;
        }
        //binary search
        for(int jump=(2*n-room)/2; jump>0; jump/=2) {
            while(room+jump<2*n && p[room+jump]<q) {
                room += jump;
            }
        }
        //p[room+1] is the first room >= q, but score is gotten after departure
        //hence, room+2 is the answer
        room = (room+2) % n;
    }
    printf("%d\n", room);
    return 0;
}