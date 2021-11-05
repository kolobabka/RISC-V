#include "common.h"

int main (int argc, char** argv) {

    if (ArgError (argc, argv))
        return -1;
    
    if (StartProgramm (argv [1]))
        return -1;
    return 0;
}

