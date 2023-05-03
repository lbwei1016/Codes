#include <stdio.h>

int main() {
    int a = 10000;
    printf("%x\n", a); // 2710 (hex)
    char *p = (char*)&a; // once a byte
    printf("%x %x %x %x", *p, *(p+1), *(p+2), *(p+3)); // 10 27 0 0
    // hence: "Little Endian" (低 byte 放前面)
    return 0;
}