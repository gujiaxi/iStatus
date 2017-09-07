#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cpu.h"
#include "utils.h"

int getCpuBrand(char * result)
{
    char *query = "sysctl -n machdep.cpu.brand_string";
    getResultByQuery(query, result);
    if (strlen(result) != 0) {
        result[strlen(result)-1] = '\0';
        return 0;
    } else {
        return 1;
    }
}