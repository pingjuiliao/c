#include<stdint.h>

#define FLIP_BIT(_ar, _b) { \
    uint8_t* _arf = (uint8_t *) _ar ; \
    uint32_t _bf  = (_b) ; \
    _arf[(_bf) >> 3] ^= ( 128 >> ((_bf) & 7) ) ; \
} while(0) ;


