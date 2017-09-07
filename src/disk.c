#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "disk.h"

int getDiskSize(char * result)
{
    char * query = "df -h | awk 'NR==2{print $2}' | tail -n 1";
    getResultByQuery(query, result);
    if (strlen(result) != 0) {
        result[strlen(result)-2] = '\0';
        return 0;
    } else {
        return 1;
    }
}

int getDiskUsed(char * result) {
    char * query = "df -h | awk 'NR==2{print $3}' | tail -n 1";
    getResultByQuery(query, result);
    if (strlen(result) != 0) {
        result[strlen(result)-2] = '\0';
        return 0;
    } else {
        return 1;
    }
}

int getDiskCap(char * result) {
    char * query = "df -h | awk 'NR==2{print $5}' | tail -n 1";
    getResultByQuery(query, result);
    if (strlen(result) != 0) {
        result[strlen(result)-2] = '\0';
        return 0;
    } else {
        return 1;
    }
}