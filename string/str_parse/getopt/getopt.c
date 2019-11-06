#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

// getopt() needs this >>
#include<unistd.h>
 
void usage(char** argv) ;

int
main(int argc, char** argv) {
    int32_t opt ;
    int num = 0 ;
    int a, b, c ;
    a = b = c = 0 ;
    // num = a * b + c
    if ( argc < 2 ) {
        usage(argv) ;
    }
    while((opt = getopt(argc, argv, "+a:b:c:d")) > 0 ) {
        switch(opt) {
            case 'a' :
                a = atoi(optarg) ;
                break ;
            case 'b' :
                b = atoi(optarg) ;
                break ;
            case 'c' :
                c = atoi(optarg) ;
                break ;
            default :
                usage(argv) ;
        }
    }
    num = a * b + c ;
    
    printf("a * b + c == num\n") ;
    printf("%d * %d + %d == %d\n", a, b, c, num) ;
    puts("Debuf info :") ;
    printf("and argc==%d, optind == %u", argc, optind) ;
    
    return 0 ;
}

void 
usage(char** argv) {
    fprintf(stderr, "Usage:%s -a <a> -b <b> -c <c>\n", argv[0]) ;
    exit(1) ;
}
