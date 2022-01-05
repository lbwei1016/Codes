#include <stdio.h>

char digit_to_hex_char(int digit) {
    return "0123456789ABCDEF"[digit];
}
int main() {
    int digit;
    scanf("%d", &digit);
    putchar(digit_to_hex_char(digit));
    return 0;
}