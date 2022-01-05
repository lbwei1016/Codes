/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include <stdio.h>

int main() {
    int x, y;
    scanf("(%d,%d)", &x, &y);
    printf("(%d,%d)\n", 2*x+6, -x);
    return 0;
}