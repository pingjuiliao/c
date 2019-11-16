#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "protocol.h"
#define MAX_PRIME 65536

static uint32_t fsrv_st_fd  ;
static uint32_t fsrv_ctl_fd ;

static void init_forkserver(char** argv) ;
static void request_one() ;

int
main(int argc, char** argv) {
    uint32_t i ;
    
    init_forkserver(argv) ;
    for (i = 2 ; i < MAX_PRIME; ++i) {
        request_one(i) ;
    }

    return 0 ;
}

static void
init_forkserver(char** argv) {
    pid_t forksrv_pid ;
    int status ;
    int st_pipe[2], ctl_pipe[2] ;
    if ( pipe(st_pipe) || pipe(ctl_pipe) ) ERROR("pipe() failed") ;

    forksrv_pid = fork() ;
    if ( !forksrv_pid ) {
        if ( dup2(ctl_pipe[0], FORKSRV_FD) < 0 ) ERROR("dup2() failed") ;
        if ( dup2(st_pipe[1], FORKSRV_FD+1) < 0 ) ERROR("dup2() failed") ;
        close(ctl_pipe[0]);
        close(ctl_pipe[1]);
        close(st_pipe[0]);
        close(st_pipe[1]);
        execv(target_prog, argv) ;
    }
    fsrv_ctl_fd = ctl_pipe[1] ;
    fsrv_st_fd  = st_pipe[0]  ;
    while ( read(fsrv_st_fd, &status, 4) != 4 ) ;
    puts("Forkserver is Up") ;
}

static void
request_one(uint32_t number) {
    pid_t child_pid ;
    int32_t res ;
    if ( (res=write(fsrv_ctl_fd, &number, 4))  != 4 ) ERROR("write() failed") ;
    if ( (res=read(fsrv_st_fd, &child_pid, 4)) != 4 ) ERROR("read() failed") ;
    if ( child_pid <= 0 ) ERROR("Forkserver is misbehaving") ;
    
}
