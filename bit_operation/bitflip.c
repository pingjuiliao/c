#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bitflip.h"

int
main(int argc, char** argv) {
    char s[] = "ABCDE" ;
    int i , max = strlen(s) << 3 ;
    
    for ( i = 0 ; i < max ; ++i ) {
        if ( i % 8 == 0 ) puts("##################") ;
        FLIP_BIT(s, i) ;
        printf("%s\n", s) ;
    }

    return 0 ;
}

