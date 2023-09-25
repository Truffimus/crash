#include "shell.h"
/**
 * bfree - frees space
 *@ptr:pointer
 */

void bfree(void **ptr) {
    if (ptr != NULL && *ptr != NULL) 
    {
        free(*ptr);
        *ptr = NULL; 
    }
}
