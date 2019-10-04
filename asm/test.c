#include <stdio.h>

int
main(void) {
    __asm__(
            "mov $0x780, %rdx"
           );
    return 0 ;
}
