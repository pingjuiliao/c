#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#define SHM_BUF_SIZE 30


void fatal(char* s) ;

int
main(int argc, char** argv) {
    
    pid_t child_pid ; // Process ID
    int status      ; // used for wait(), waitpid()
    int shm_id      ; // shared memory identifier
    char* shm_ptr   ; // shared memory pointer
   

    // shm
    shm_id  = shmget(IPC_PRIVATE, SHM_BUF_SIZE, IPC_CREAT|IPC_EXCL|0600) ;
    if ( shm_id < 0 ) fatal("shmget() failure") ;
    shm_ptr = shmat(shm_id, NULL, 0) ;
    if ( shm_ptr == (void *) -1 ) fatal("shmat() failure") ;

    // fork    
    child_pid = fork();  
    if ( child_pid < 0 ) fatal("Fork() failure") ;
    
    if ( child_pid ) {
        puts("i am parent") ;
        while (1) {
            if ( strlen(shm_ptr) > 0 ) break ;
        }
        puts("The phone Ringed");
        puts("The parent gets the following msg :");
        puts(shm_ptr);
        puts("(Secretly relieved) You are grounded!") ;
    } else {
        puts("The child phoning the parent");
        strcpy(shm_ptr, "Mom I am ok !") ;
    }

    return 0 ;
}

void
fatal(char* s) {
    puts(s) ;
    exit(-1) ;
}

