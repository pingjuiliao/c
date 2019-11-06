#include <stdio.h>
#include <stdint.h>
#include <string.h>
typedef uint8_t u8 ;


int
main(void) {
    char buf[8] ;
    
    memset(buf, 'a', sizeof(buf)); 
    for (int i = 0 ;i < 128 ; ++ i) {
        
            buf[4] ++ ;
    }

    for ( int i = 0 ; i < 8 ; ++i ) {
        printf("%p\n", buf[i]) ;
    }

    return 0 ;
}
