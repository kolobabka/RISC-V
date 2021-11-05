#include "common.h"
//-------------------------------------------------------------------------
signed char ArgError (int argc, char** argv) {

    if (IS_NULL(argv))
        return 1;

    if (argc < 2) {

        printf ("Argument is not found!\n");
        return 1;
    }

    if (argc > 2) {

        printf ("Too many arguments!\n");
        return 1;
    }

    return 0;
} 
//-------------------------------------------------------------------------
signed char PerrorCheck (int file) {

    if (file == -1) {

        perror ("File open error:");
        return 1;
    }
    return 0;
}
