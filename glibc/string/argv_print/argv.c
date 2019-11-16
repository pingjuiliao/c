#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char** argv) {
    char** p = argv ;
    while(*p) {
        printf("%s ", *(p++));
    }
    puts("\ndone") ;
    return 0 ;
}
