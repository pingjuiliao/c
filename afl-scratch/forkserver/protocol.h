#include <stdio.h>
#include <stdlib.h>
#define TARGET_PROG #solver
#define FORKSRV_FD 87
#define ERROR(s...) do { \
    puts(s) ; \
    exit(-1); \
} while(0);
const char* target_prog = "./solver" ;
void usage(char** argv, char* description) {
    printf("Usage: %s %s", argv[0], description) ;
    exit(0) ;
}
