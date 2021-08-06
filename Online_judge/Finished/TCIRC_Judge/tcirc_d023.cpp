/*
***Recursion***
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct S { ll h, pos; }; //height, pos
vector<S> B; //擋板的的集合
ll ans[100005]; //最終水量

bool comp(const S &s1, const S &s2) {
    return s1.h < s2.h;
}
/*
    在區間 [left, right) 以內皆為空水槽，以外為已經填過或無法填的水槽
*/
void rec(int left, int right, ll w, int in) {
    //僅剩一水槽，直接填滿，結束
    if(left+1 == right) {
        ans[left] = w;
        return;
    }
    //找出最高的板子
    while(true) {
        S b = B.back();
        /*
            若該板子不在區間內，將之移除，因為區間是逐漸縮小，
            所以在區間外的水槽(板子)已經不會再被利用。
        */
        if(b.pos >= right || b.pos <= left) {
            B.pop_back();
        } else break;
    }
    S highest = B.back();
    ll H = highest.h, P = highest.pos;
    //若當前的水量足以填滿所有區間內的水槽，將之平均分配
    if(w >= (right-left)*H) {
        ll avg = w / (right-left);
        for(int i=left; i<right; i++) {
            ans[i] = avg;
        }
        return;
    }
    //當注入點在目前最高的板子的左邊
    if(P > in) {
        //溢出
        if(w > (P-left)*H) {
            for(int i=left; i<P; i++) {
                ans[i] = H;
            }
            //縮小區間，減去水量
            rec(P, right, w-(P-left)*H, in);
            return;
        } else {
            //不溢出，縮小區間，水量不變
            rec(left, P, w, in);
            return;
        }
    } else {
        //當注入點在目前最高的板子的左邊
        //溢出
        if(w > (right-P)*H) {
            for(int i=P; i<right; i++) {
                ans[i] = H;
            }
            rec(left, P, w-(right-P)*H, in);
            return;
        } else {
            rec(P, right, w, in);
            return;
        }
    }
    return;
}

int main() {
    int N, I;
    ll W;
    scanf("%d%d%lld", &N, &I, &W);
    for(int i=0; i<N; i++) {
        ll h;
        scanf("%lld", &h);
        B.push_back((S){h, i});
    }
    //依高度由小到大排序
    sort(B.begin(), B.end(), comp);
    rec(0, N-1, W, I);
    for(int i=0; i<N-1; i++) {
        printf("%lld%c", ans[i], i==N-1 ? '\n' : ' ');
    }
    return 0;
}