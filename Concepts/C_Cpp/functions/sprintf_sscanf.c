#include <stdio.h>

int main() {
    char str[100];
    int age;
    scanf("%d", &age);
    // 和 printf 一樣，只是輸出到字串
    sprintf(str, "You are %d years old", age);
    puts(str);
    int a;

    // 和 scanf 一樣，只是從字串讀
    /* 
        %*s: the data is to be read from the stream but ignored
        (i.e. it is not stored in the location pointed by an argument)
    */
    sscanf(str, "%*s %*s %d", &a);
    printf("%d\n", a);

    return 0;
}