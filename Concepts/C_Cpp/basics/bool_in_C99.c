#include <stdio.h>
#include <stdbool.h>

int main() {
    bool a = true; // defined in <stdbool.h>
    _Bool b = 0; // a macro
    printf("%d %d", a, b);
    return 0;
}