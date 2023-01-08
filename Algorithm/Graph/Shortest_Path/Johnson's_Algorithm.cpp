/*
***Graph*** -- Shortest path
概述:
    Floyd-Warshall 很好寫，但是看起來在稀疏圖上，跑 V 次 Dijkstra 的 O(V E log V ) 會
更好一點，然而 Dijkstra 只能用在非負權圖上。於是，這個演算法的目的就是把帶負權的
圖變成正權圖。
　　所使用的方法，是為每一個點加上一個點權 H(i)，並且令所有邊的新權重，等於原權重加上起點
的點權、減掉終點的點權。不難證明這個調整邊權的作法有兩個性質：
1. 同一點對 (S, T) 的最短路徑 P(A, B) 並不會改變，但權重會加上 H(S) - H(T)。
2. 任何環的權重都不改變。
　　因此這是一個良好的調整邊權作法。那要如何讓每個邊權都變為非負呢？我們先列出式子：
        w(i, j) + H(i) - H(j) >= 0
　　然後移個項：
        H(i) + w(i, j) >= H(j)
　　有沒有似曾相識？還記得我們之前做鬆弛的條件是 d(i) + w(i, j) < d(j)，若令
H(i) = d(i)，上式代表的是「不能再進行鬆弛」，也就是說任一組單點源最短路徑的解都
是符合條件的點權。至此這個演算法大致成形：對任一點做 Bellman-Ford（順便判斷有沒
有負環），得到點權之後，用調整完的邊權做 V 次 Dijkstra，時間複雜度 O(V E log V )，在較稀疏
的圖上表現會比 Floyd-Warshall 好。
　　然而還有一個小問題。前面有提過，當圖為有向圖的時候，一次遍歷有可能無法遍
歷完全圖，也就是有可能會發生有點沒有點權的狀況（因為找不到最短路）。這個問題很
好解決：新增一個點，讓它連到所有點，並且邊權都是 0，再對這個點做 Bellman-Ford 即
可。

小結:
    全點對最短路徑，先找一次單源最短路徑 (Bellman-Ford)，並將從起點到任意點的最短距離作為各自的
    點權，來修改原本的邊權，則原先的負權邊將 >= 0。因此 dijkatra 就可以用了 !!!
    O(V*E*log V)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    return 0;
}