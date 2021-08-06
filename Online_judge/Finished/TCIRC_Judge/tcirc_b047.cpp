/*
    Huffman Coding:
        Using binary heap, and the length of a single coding(e.g 001 is three)
        is identical to its depth in the binary tree；thus, the total length 
        of a single char is "freq * depth", and that's why priority_queue can 
        perfectly fits the job of counting. (Just like "Fence Repair")
*/
#include <bits/stdc++.h>

using namespace std;

int freq[126+1];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    priority_queue<int, vector<int>, greater<int> > pq;
    int sum = 0;
    string s;
    cin >> s;
    int l = s.length();
    for(int i=0; i<l; i++)
        freq[s[i]]++;
    for(int i=33; i<=126; i++)
    {
        if(freq[i])
        {
            pq.push(freq[i]);
        }
    }
    while(pq.size() > 1)
    {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        sum += a+b;
        pq.push(a+b);
    }
    cout << sum << '\n';

    return 0;
}