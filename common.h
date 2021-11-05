#ifndef COMMON_H__
#define COMMON_H__

#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>

#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#include <errno.h>
#include "parser/parser.h"

signed char ArgError (int argc, char** argv);
signed char PerrorCheck (int file);

#define IS_NULL(ptr) (!ptr) 

#endif
