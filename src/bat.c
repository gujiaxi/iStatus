#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bat.h"
#include "utils.h"

int getBatteryCycle()
{
    char result[8];
    char * query = "ioreg -rn AppleSmartBattery | grep \"\\\"CycleCount\\\"\" | awk '{print $3}'";
    getResultByQuery(query, result);
    return atoi(result);
}

int getBatteryDesignCycle()
{
    char result[8];
    char * query = "ioreg -rn AppleSmartBattery | grep \"DesignCycleCount\" | awk '{print $3}'";
    getResultByQuery(query, result);
    return atoi(result);
}

int getBatteryCurCapacity()
{
    char result[8];
    char * query = "ioreg -rn AppleSmartBattery | grep \"CurrentCapacity\" | awk '{print $3}'";
    getResultByQuery(query, result);
    return atoi(result);
}

int getBatteryMaxCapacity()
{
    char result[8];
    char * query = "ioreg -rn AppleSmartBattery | grep \"MaxCapacity\" | awk '{print $3}'";
    getResultByQuery(query, result);
    return atoi(result);
}

int getBatteryDesignCapacity()
{
    char result[8];
    char * query = "ioreg -rn AppleSmartBattery | grep \"DesignCapacity\" | awk '{print $3}'";
    getResultByQuery(query, result);
    return atoi(result);
}
