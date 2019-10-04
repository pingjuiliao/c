#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<dirent.h>
#define TARGET_DIR "dir"

int
main(int argc, char** argv) {
    struct dirent** nl ;
    uint32_t file_count ;
    file_count = scandir(TARGET_DIR, &nl, NULL, alphasort) ;
    printf("%d\n", file_count) ;
    
    return 0 ;
}
