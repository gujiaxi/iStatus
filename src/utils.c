#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

int getResultByQuery(char * query, char * result)
{
    FILE * stream;
    char buf[128] = {'\0'};
    stream = popen(query, "r");
    fread(buf, sizeof(char), sizeof(buf), stream);
    pclose(stream);
    if (strlen(buf) != 0) {
        strcpy(result, buf);
        return 0;
    } else {
        return 1;
    }
}