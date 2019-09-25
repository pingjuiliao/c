#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>


uint32_t
urandom(int max) {
    uint32_t res ;
    int fd = open("/dev/urandom", O_RDONLY) ;
    read(fd, &res, 4) ;
    printf("urandom getting %u\n", res) ;
    res %= (max+1) ;
    return res ;
}

int
main(void) {
    uint32_t r ;
    while ( (r = urandom(6)) != 5 ) ;
    printf("r is %u\n", r) ;
    return 0 ;
}


