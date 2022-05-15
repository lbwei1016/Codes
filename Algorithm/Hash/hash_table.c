/*
***Hash*** -- rolling hash
    Description:
        找出 k 個長度 l 的字串中，兩字串至多一字元相異的對數 (number of pairs)。
    Solution:
        對於所有字串，一次將一個字元取代為 wildcard，並拿去做 hash，也就是將
        字串做 l 次 hash，並以 hash table 對應。
    Note:
        完全相同的字串會多算，所以先 sort 過後找出來，然後減掉。
    O(k * l)
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ll long long

const int MOD = 1572869; // prime
int k, l;
int table[1572869]; // hash table

int cmp (const void *s1, const void *s2) {
    return strcmp(s1, s2);
}

ll calc(int l, char (*str)[l+1]) {
    ll sum = 0;
    int *pow10 = malloc((l) * sizeof(int));
    pow10[0] = 1;
    for (int i=1; i<l; ++i) 
        pow10[i] = pow10[i-1] * 10 % MOD;

    for (int i=0; i<k; ++i) {
        ll hash = 0;
        // rolling hash
        for (int j=0; j<l; ++j) {
            hash += str[i][j]*pow10[j];
            hash %= MOD;
        }
        // 一次去除一個字元，hash 後放入 hash table
        for (int j=0; j<l; ++j) {
            ll sub = hash + (ll)(128 - str[i][j])*pow10[j];
            sub %= MOD;
            sum += table[sub]++;
        }
    }
    return sum;
}

int main() {
    scanf("%d %d %d", &k, &l);
    char str[k][l+1];
    for (int i=0; i<k; ++i) {
        scanf("%s", str[i]);
    }

    qsort(str, k, sizeof str[0], cmp);

    int cnt = 1; // how many consecutive strings are identical
    ll sum = 0; // sum of pair of strings that are similar
    // 因為 calc 的方法對於完全相同的字串會多算，所以先扣掉多的
    for (int i=0; i<k-1; ++i) {
        if (cmp(str[i], str[i+1]) == 0) {
            sum -= cnt * l;
            sum += cnt;
            ++cnt;
        }
        else cnt = 1;
    }
    sum += calc(l, str);
    printf("%lld\n", sum);
    return 0;
}