#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAP_SIZE_POW 16

static uint32_t afl_area_ptr ;
static uint32_t afl_temp ;
static uint32_t afl_

void afl_maybe_log(void) ;
static void afl_store(void) ;
static void afl_return(void) ;


void
afl_maybe_log(void) {
    if (!*afl_area_ptr ) {
        
    }  

}

static void
afl_store(void) {

}

static void
afl_return(void) {

}
