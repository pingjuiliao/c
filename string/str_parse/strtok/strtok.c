#include <stdio.h>
#include <string.h>
#include <unistd.h>
int
main(void) {
    char buf[50];
    char* tmp ;
    int i  ;
    ssize_t r ; 
    while((r = read(0, &buf, sizeof(buf))) > 0 ) {
        i = 0 ;
        
        tmp = strtok(buf, " ") ;
        while (tmp) {
            printf("%d: %s\n", i++, tmp) ;
            tmp = strtok(NULL, " ") ;          
        }
    }


    return 0 ;
}
