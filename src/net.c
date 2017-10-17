#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "net.h"
#include "utils.h"

int getNetAddr(char * result)
{
    char * query = "ifconfig | grep inet | grep -v inet6 | cut -d\" \" -f2 | head -n2 | tail -n1";
    getResultByQuery(query, result);
    if (strlen(result) != 0) {
        result[strlen(result) - 1] = '\0';
        return 0;
    } else {
        return 1;
    }
}
