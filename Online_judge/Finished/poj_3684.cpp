/*
***Cool Thoughts(like Ants)***

    O(N)
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAX_N 100

using namespace std;

const double g = 10.0;
int N, H, R, T;
double y[MAX_N+5]; //record the height of each ball

double calc(int T)
{
    if(T < 0)
        return H;
    double t0 = sqrt(2 * H / g);
    int k = (int)(T / t0);
    double t;
    if(k % 2 == 0) //if the ball is falling down
    {
        t = T - k*t0;
    }
    else //if the ball is bouncing up
        t = k*t0 + t0 - T;
    return H - g * t * t /2;
}

int main()
{
    int c;
    scanf("%d", &c);
    while(c--)
    {
        scanf("%d%d%d%d", &N, &H, &R, &T);
        for(int i=0; i<N; i++)
        {
            y[i] = calc(T-i); //each ball is dropped a second later than its previous ball
        }
        sort(y, y+N); //the sequence of balls doesn't change after collision
        for(int i=0; i<N; i++)
        {
            //remember the radius of balls
            printf("%.2lf%c", y[i] + 2*R*i/100.0, i+1==N ? '\n' : ' '); 
        }
    }
    return 0;
}