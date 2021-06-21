/*
    "memcpy" can copy the value from the memory block pointed 
    by the source, but it may fail when destination and source
    are on the same memory block,(however it seems okay here)
    which means "memcpy" should not overlap 
    (for overlapping memory blocks, memmove is a safer approach).
*/
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char s1[] = "My name is William.";
    char s2[100];

    memset(s2, '&', 20);
    puts(s2);
    memcpy(s2, s1, strlen(s1)+1); //memcpy(destination, source, size_bytes -> sizeof())
    puts(s2);

    memmove(s1+21, s1, strlen(s1)+1); //memcpy(destination, source, size_bytes)
    puts(s1);

    int cmp = memcmp(s1, s2, strlen(s1)+1);
    if(!cmp) {
        printf("two strings are identical!\n");
    } 
    else if(cmp > 1) {
        printf("string1 is greater!\n");
    }
    else {
        printf("string2 is greater!\n");
    }
    return 0;
}