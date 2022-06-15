/*
***Divide and Conquer / Sweep Line*** 
    Solution:
        1.  Sort the points by "x", for the purpose of dividing 
            from the middle each time.
        2.  When diciding the set of feasible points, we have to 
            pick out them in O(n), or it will TLE. Thus, no bin-
            ary search is allowed ( O(n logn) ).
        3.  Once the recursion goes to the button, the sorted
            order of "x" is no longer needed (since the middle
            points have already decided).
        4.  Combine 2. & 3., we can rearrange the "P[]" array 
            to meet the need of "sort by y" to find out feasible
            points；this can be carried out with "Merge Sort" when 
            implementing current "DaC" itself!!!
        5.  Traverse [l, r), sieve the points qualified.
        6.  Adopt a "Sweep Line" to sweep the picked points from 
            which with least "y" and go upwards；O(n).

    O(n * log n)
*/
#include <bits/stdc++.h>
using namespace std;

struct Point { int x, y; };
const int MAX_N = 1e5+5;
int n;
Point P[MAX_N]; //points

bool cmp(Point p1, Point p2) {
    return p1.x < p2.x;
}
int rec(int l, int r) {
    if(l+1 >= r) return 1e9;
    int m = (l+r) >> 1;
    int mid_x = P[m].x; // 要在遞迴前先取中點 x 值，因為遞迴後就變成依照 y 排序 !!!
    int dis = min(rec(l, m), rec(m, r));

    int j = m;
    /*
        This array is used for two purposes:
            1. a temporary memory for merge sort
            2. to store valid points whose x coordinate is 
               [P[m].x - dis, P[m].x + dis]
    */
    Point t[r-l];
    //merge sort by "y"
    for(int i=l, k=0; i<m; i++) {
        while(j<r && P[j].y < P[i].y) {
            t[k++] = P[j++];
        }
        t[k++] = P[i];
    }
    for(int i=l; i<j; i++) {
        P[i] = t[i-l];
    }

    int k = 0;
    //go over every element (sorted by "y") and check their "x"
    for(int i=l; i<r; i++) {
        if(abs(P[i].x-mid_x) < dis)
            t[k++] = P[i];
    }
    //sweep from the point with least "y"
    for(int i=0; i<k; i++) {
        //O(1): the loop will maximally execute 8 times
        for(j=i+1; j<k && t[j].y-t[i].y<dis; j++) {
            dis = min(dis, abs(t[i].x-t[j].x)+abs(t[j].y-t[i].y));
        }
    }
    return dis;
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &P[i].x, &P[i].y);
    }
    //sort first by "x"
    sort(P, P+n, cmp);
    printf("%d\n", rec(0, n));
    return 0;
}