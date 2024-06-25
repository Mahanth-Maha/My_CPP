#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Logger.h"
#include "SC_extern.C"

extern int incr(void);
// NOTE : For functions they are by default Extern 
int decr(void);
extern int x = 0;


int main(int argc, char const *argv[])
{
    extern int intMax;
    logger(intMax);
    logger(incr());
    logger(decr());

    return 0;
}

