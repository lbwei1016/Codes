/*
    See "/Algorithm/Sort/heap_sort.cpp"
*/
#include <iostream>
#include <vector>
using namespace std;

// max heap
class heap {
    public:
        heap(int size = 0) {
            data.resize(size);
        };

        // push in a new element from the buttom
        void push(int val) {
            int at = data.size();
            data.push_back(val);
            if(at == 0) return;
            push_data(at);
        }
        // grab the last element to the top and then update the heap
        void pop() {
            data[0] = data.back();
            data.pop_back();
            int chl = 1, sz = data.size();
            while(chl < sz) {
                int big, at = (chl-1) / 2;
                if(chl+1 < sz) 
                    big = data[chl] > data[chl+1] ? chl : chl+1;
                else big = chl;

                if(data[at] < data[big]) {
                    swap(data[at], data[big]);
                    chl = 2*chl+1;
                }
                else break;
            }
        }
        int top() {
            return data.front();
        }
    private:
        vector<int> data;
        // go up like a bubble
        void push_data(int at) {
            if(at == 0) return;
            int par = (at - 1) / 2;
            if(data[par] < data[at]) {
                swap(data[par], data[at]);
                push_data(par);
            }
        }
};

int main()
{   
    int n; cin >> n;
    heap hp;
    for(int i=0; i<n; ++i) {
        int x; cin >> x;
        hp.push(x);
    }
    for(int i=0; i<n; ++i) {
        cout << hp.top() << ' ';
        hp.pop();
    }
    return 0;
}