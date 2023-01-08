#include <stdio.h>
#include <time.h>

int main() {
    time_t res = time(NULL);
    // localtime() returns "struct tm*", which stores time related info.
    // asctime() convert those info. into human-readable time format
    printf("%s", asctime(localtime(&res)));
    return 0;
}