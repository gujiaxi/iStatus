#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bat.h"

int grepIoreg(char * keyword) {
    FILE * stream;
    char buf[64] = {'\0'};
    char query[64] = {'\0'};
    char * pSubstr;
    int result;
    sprintf(query, "ioreg -rn AppleSmartBattery | grep \"%s\"", keyword);
    stream = popen(query, "r");
    fread(buf, sizeof(char), sizeof(buf), stream);
    pSubstr = strrchr(buf, ' ');
    result = atoi(pSubstr + 1);
    pclose(stream);
    return result;
}

int getBatteryCycle()
{
    return grepIoreg("\\\"CycleCount\\\"");
}

int getBatteryDesignCycle()
{
    return grepIoreg("DesignCycleCount");
}

int getBatteryCurCapacity()
{
    return grepIoreg("CurrentCapacity");
}

int getBatteryMaxCapacity()
{
    return grepIoreg("MaxCapacity");
}

int getBatteryDesignCapacity()
{
    return grepIoreg("DesignCapacity");
}