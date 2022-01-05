/*
    想法:
        若只有 01 或 10，則 11 不存在。
    解法:
        1. 將 num 取 not，為了讓 11 不會被辨識為 01 或 10，而 01 和 10 不受影響
        2. 用 & 將 num 中的 01 取出
        3. 將 10 取出
        4. 把 check1 右移一位，使 10 變得可以與 01 對齊並互相填滿
        5. 若對齊並互相填滿後，完全只剩 0101010101，則無 11
        6. 反之，則有 11
*/
#include <bits/stdc++.h>
#define ZERO 0x55
#define ONE 0xaa
#define CHECK11(x) (ZERO^(((~x)&ZERO)|(((~x)&ONE)>>1)))

using namespace std;

const unsigned zero = 0x55; // 01010101
const unsigned one = 0xaa; // 10101010
bool check11(uint32_t num) {
    num = ~num; // 01100010
    uint32_t check0 = num & zero; // 0100 0000 
    uint32_t check1 = num & one; // 0010 0010
    check1 >>= 1; // 0001 0001
    check0 |= check1; // 0101 0001
    uint32_t check = zero ^ check0; // 0000 0100 != 0
    if(check) return true;
    else return false;
}

int main() {
    uint32_t a = 0b10011101; // 4 bits; one unknown
    uint32_t b = 0b10010110; // clear
    cin >> a;
    // if(check11(a)) cout << "a unknown\n";
    // else cout << "a clear\n";
    // if(check11(b)) cout << "b unknown\n";
    // else cout << "b clear\n";
    if(CHECK11(a)) cout << "a unknown\n";
    else cout << "a clear\n";
    if(CHECK11(b)) cout << "b unknown\n";
    else cout << "b clear\n";
    
    return 0;
}
