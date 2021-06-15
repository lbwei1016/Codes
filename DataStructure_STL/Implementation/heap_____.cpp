#include <iostream>

using namespace std;

template <class h>
class heap
{
    const int MAX_SIZE = 100;
    int cnt;
    public:
        heap() :  cnt(0){};
        h data[];
        void push(int x)
        {
            this->data[this->cnt] = x;
            (this->cnt)++;
        }
        int pop()
        {
            int r = this->data[this->cnt-1];
            this->data[(this->cnt)-1] = 0;
            (this->cnt)--;
            //return ;
        }
};

int main()
{
    heap<int> h;
    h.push(1);
    return 0;
}