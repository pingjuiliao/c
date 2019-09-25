#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "protocol.h"

pid_t forksrv_pid;
uint32_t number  ;
char we_are_ok_signature[4] = "ok!\0";
void solve_prime(void); 
void init_forkserver_maybe(void) ;

int
main(void) {
    init_forkserver_maybe() ;
    solve_prime() ;
    return 0 ;
}

void
init_forkserver_maybe(void) {
    int status ;
    pid_t child_pid ;
    char buf[4] ;

    if ( forksrv_pid ) return ;
    
    forksrv_pid = getpid() ;

    if ( write(FORKSRV_FD+1, &we_are_ok_signature, 4) != 4 ) 
        ERROR("write() failed") ;
    
    
    while (1) {
        
        if ( read(FORKSRV_FD, &number, 4) != 4 ) ERROR("We are done here!") ;
        
        if ( (child_pid = fork()) < 0 ) ERROR("Forkserver fork() failed") ;
    
        if ( !child_pid ) { // child
            // printf("%u\n", number) ;
            return ;
        }

        // parent
        
        if ( (waitpid(child_pid, &status, 0)) < 0 ) ERROR("Cannot wait");
        write(FORKSRV_FD+1, &child_pid, 4) ;
        // write(FORKSRV_FD+1, &status, 4) ;
    }
       
}


void 
solve_prime(void) {
    int i = 2 ;
    while ( i * i <= number ) {
        if ( number % i  == 0 ) {
            // its not prime
            printf("%u is NOT prime\n", number);
            return ;
        } 
        ++i ;
    }
    // its prime
    printf("Bingo, %u is prime\n", number) ;
}
