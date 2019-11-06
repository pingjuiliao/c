#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/types.h>

void fatal(char* s) ;

int
main(int argc, char** argv) {
    char* msg = NULL;
    char* buf = "Hello World!" ;
    int shm_id;
    
    if ( argc < 2 ) {
        fatal("Usage: ./sharee <shm_id>");
    }

    shm_id = atoi(argv[1]) ;
    if ( !shm_id ) fatal("wrong number") ;
    msg = shmat(shm_id, NULL, 0) ;
    if ( msg == (void*) -1 ) fatal("shmat() failure") ;
    printf("msg address : %p\n", msg) ;

    msg = shmat(shm_id, NULL, 0) ;
    if ( msg == (void*) -1 ) fatal("shmat() failure") ;
    printf("msg address : %p\n", msg) ;
    
    strcpy(msg, buf) ;
    puts("String has been copied") ;
    puts(msg) ;
    return 0 ;
}

void
fatal(char* s) {
    puts(s) ;
    exit(0) ;
}
