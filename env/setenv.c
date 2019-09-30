#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int
main(void) {
    char* s;
    setenv("HELLO", "helko", 1);
    s = getenv("HELLO") ;
    puts(s) ;
    return 0 ;
}
