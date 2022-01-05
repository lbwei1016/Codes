#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    fgets(str, 98, stdin);
    char *p = strtok(str, " ,.");
    while(p != NULL) {
        printf("%s\n", p);
        p = strtok(NULL, " ,.");
    }

    // also see strtok_r (to slice multiple strings at the same time)
    
    return 0;
}