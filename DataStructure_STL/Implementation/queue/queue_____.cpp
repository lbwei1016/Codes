#include <iostream>
#include <string.h>
#include "queue.h"
using namespace my_imp;

void queue::data_transfer(const int & sz) {
    int *tmp = new int[sz];
    memcpy(tmp, que+front, sizeof(int)*this->sz);
    memset(que+front, 0, sizeof(int)*this->sz);
    memcpy(que, tmp, sizeof(int)*this->sz);
    delete [] tmp;
}

void queue::resize(const int &sz) {
    if(this->sz == sz) return;
    if(capacity >= sz) {
        data_transfer(sz);
    }
    else {
        capacity *= 2;
        data_transfer(capacity);
    }
}

int main() {
    
    return 0;
}