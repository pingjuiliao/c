#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#define BUF_SIZE 64

void fatal(char* s) ;

int
main(int argc ,char** argv) {
    char* msg = NULL;
    int shm_id  ;
    
    // shm
    shm_id = shmget(IPC_PRIVATE, BUF_SIZE, IPC_CREAT|IPC_EXCL|0600) ;
    if ( shm_id < 0 ) fatal("shmget() failure") ;
    msg = shmat(shm_id, NULL, 0) ;
    if ( !msg ) fatal("shmat(), failure");
    printf("My shm_id is %d\n", shm_id) ;
    
    // init
    memset(msg, 0, BUF_SIZE ) ;
    
    // wait until the data is correct
    while(1) {
        if ( strcmp(msg, "Hello World!" ) == 0  ) break ;
    }

    puts("sharer gets sharee's message");
    puts(msg) ;

    return 0 ;
}

void
fatal( char* s ) {
    puts(s);
    exit(-1);
}
