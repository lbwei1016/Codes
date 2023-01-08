#include <stdio.h>

union U {
    int a;
    // 因為用同一塊記憶體，所以可以利用 char[] 來分別看 int 的 4 byte
    char byte[4];
};

int main() {
    union U u;
    u.a = 0x12345678;
    for(int i=0; i<4; ++i) {
        // 可以看出 little endian
        printf("%x ", u.byte[i]);
    }
    return 0;
}