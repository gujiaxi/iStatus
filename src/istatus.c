/*
 * A command line to show system information of macOS.
 */

#include <stdio.h>
#include <string.h>

#include "smc.h"
#include "bat.h"

int main(int argc, char *argv[])
{
    /*
     * variables
     */
    double cpu_temp;
    double bat_temp;
    float fan_speed[10] = {-1};

    /*
     * processing
     */
    SMCOpen();
    int fan_num = SMCGetFanNumber(SMC_KEY_FAN_NUM);
    for (int i = 0; i < 10; i++) {
        if (i < fan_num) {
            fan_speed[i] = SMCGetFanSpeed(i);
        }
    }
    cpu_temp = SMCGetTemperature(SMC_KEY_CPU_TEMP);
    bat_temp = SMCGetTemperature(SMC_KEY_BATTERY_TEMP);
    SMCClose();

    /*
     * output results
     */
    // cpu
    printf ("--- CPU ---\n");
    printf ("CPU temperature:\t%0.1f°C\n", cpu_temp);
    printf ("\n");
    // fan
    printf ("--- Fan ---\n");
    for (int i = 0; i < fan_num; i++) {
        printf ("Fan %i speed:\t\t%0.0f RPM\n", i, fan_speed[i]);
    }
    printf ("\n");
    // battery
    printf ("--- Battery ---\n");
    if (hasBattery()) {
        const char * bat_health = getBatteryHealth();
        int bat_cycle = getBatteryCycle();
        int bat_cycle_design = getBatteryDesignCycle();
        int bat_charge_max = getBatteryMaxCapacity();
        int bat_charge_design = getBatteryDesignCapacity();
        printf ("Battery temperature:\t%0.1f°C\n", bat_temp);
        printf ("Battery cycle:\t\t%i counts\t%0.1f%%\n", bat_cycle, 100.0 * bat_cycle / bat_cycle_design);
        printf ("Battery capacity:\t%i mAh\t%0.1f%%\n", bat_charge_max, 100.0 * bat_charge_max / bat_charge_design);
        printf ("Battery health:\t\t%s\n", bat_health);
    } else {
        printf ("--- No Battery found on this machine. ---\n");
    }

    return 0;
}
