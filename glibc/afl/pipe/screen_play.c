#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define NUM_JOEY_LINES 4
#define NUM_CHANDLER_LINES 4
#define BUF_SIZE 100
#define ERROR(s...) do { \
    puts(s) ; \
    exit(-1) ; \
} while (0)

// char* read_until(int fd, , char delim)
char joey[][100] = {
    "Hey, Listen huh. I don't know when to see you again.",
    "Right. Yeah. OK.... Hummm, take care",
    "(Leave and close the door)",
    "(storm in and hug chandler)"
} ;
char chandler[][100] = {
    "I am guessing at tonight the coffee house",
    "Yeah",
    "(stare at the empty apartment and sigh)",
    "(hold Joey's hand)"
};
char* read_until(int fd, char delim) ;
char* joey_lines(void) ;
char* chandler_lines(void) ;

int
main(void) {
    int res, i = 0 ;
    int p2c_fd[2], c2p_fd[2] ;
    pid_t child_pid  ;
    char* s ;
    
    if ( pipe(p2c_fd) || pipe(c2p_fd) ) ERROR("pipe() failed");
    if ( (child_pid = fork()) < 0 )  ERROR("fork() failed");

    if ( ! child_pid ) { // child (Joey)
        while (s = joey_lines()) {
            printf("   Joey   : ") ;
            puts(s) ;
            write(c2p_fd[1], s, strlen(s)+1) ;
            read_until(p2c_fd[0], '\0') ;
        } 
    } else {             // parent (Chandler)
        while (s = chandler_lines()) {
            read_until(c2p_fd[0], '\0') ; // after joey say something
            printf(" Chandler : ") ;
            puts(s) ;
            write(p2c_fd[1], s, strlen(s)+1) ;
        } 
    }
    return 0 ;
}

char*
read_until(int fd, char delim) {
    int bytes_read = 0 ;
    char* buf = malloc(BUF_SIZE) ;
    memset(buf, '@', sizeof(buf)) ;
    while ( read(fd, buf + bytes_read, 1) ) {
        
        if ( bytes_read >= BUF_SIZE ) {
            return NULL ;
        }
        if ( *(buf + bytes_read) == delim ) {
            return buf ;
        }
    }
    ERROR("Read() failed") ;
}

char*
joey_lines(void) {
    static int joey_i = 0;
    if ( joey_i < NUM_JOEY_LINES ) 
        return joey[joey_i++] ;
    return NULL ;
}

char* 
chandler_lines(void) {
    static int chandler_i = 0 ;
    if ( chandler_i < NUM_CHANDLER_LINES )
        return chandler[chandler_i++] ;
    return NULL;
}



