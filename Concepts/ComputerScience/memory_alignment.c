#include <stdio.h>

struct S {
    char c1;
    int a;
    char c2;
};
// alignment is set to 1
#pragma pack(push, 1)
struct SS {
    char c1;
    int a;
    char c2;
};
// end of assigned alignment
#pragma pack(pop)

struct SSS {
    char c1, c2;
    int a;
};

int main() {
    struct S st;
    struct SS ss;
    struct SSS sss;
    printf("%d\n", sizeof(st)); // 12, but 6 is expected
    /*
        This is because the access of memory isn't once a byte (4 bytes instead).
        Hence, the memory used by a char is padded to 4 byte.
    */
    printf("%x\n%x\n%x\n", &st.c1, &st.a, &st.c2);

    printf("%d\n", sizeof(ss)); // 6, since alignment is set to "1"
    /*
        However, the access of an int will cost "four" operations, for
        only a byte is read a time.
    */
    printf("%x\n%x\n%x\n", &ss.c1, &ss.a, &ss.c2);

    printf("%d\n", sizeof(sss)); // 8, since c1 and c2 share the same 4 byte.
    /*
        A good practice is to put variables with the same type together.
        No compromise to the efficiency, but it saves memory.
    */
    printf("%x\n%x\n%x\n", &sss.c1, &sss.a, &sss.c2);
    return 0;
}