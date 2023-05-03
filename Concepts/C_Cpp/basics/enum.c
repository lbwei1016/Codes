#include <stdio.h>

// 依次序 + 1
// 可以指定起始值為任意值
enum ACTIONS {
    LEFT=8, RIGHT, UP, DOWN
};
enum E {
    A=2, B=8, C=1, D=113// , UP: namespace 和使用的地方有關
};

int main() {
    enum E en = A; // 可作為整數 (int) 使用 (但不具型別安全 *)
    printf("%d\n%d\n%d\n%d\n", LEFT, RIGHT, UP, DOWN);
    printf("%d\n%d\n%d\n%d\n", A, B, C, D, UP);
    printf("%d\n", ++en);
    en = 10; // 其實不應該有 "10" 的值 (*) (上述的不安全)
    printf("en: %d\n", en);
    return 0;
}