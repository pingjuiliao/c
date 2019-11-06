#include <stdlib.h>
#include <stdio.h>

int
main(int argc, char** argv) {
    
    if ( argc < 2 ) {
        fprintf(stderr, "Usage: %s <argv>\n", argv[0]) ;
        exit(-1) ;
    }
    printf("[RESULT]  atoi(%s) == %p\n", argv[1], atoi(argv[1]));
    return 0 ;
}
