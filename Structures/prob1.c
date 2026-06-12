/*Problem Statement: Multi Mode Smart Device Data Display System
A smart embedded device can operate in different measurement modes depending on   user selection. The device supports the following modes.
1. TEMP mode -> measures temperature (integer value in Centigrade)
2. Battery mode -> measures battery percentage (integer value in %)
3. Voltage mode -> measures voltage level (floating point value in volts)

At any given time, the device operated in only one mode and stores only one corresponding sensor value.

The application must:

Stores the device id
Store the current operating mode as a string
Store the sensor value using a union (since only one value is active at a time)
Display the correct sensor reading based on the selected mode
Use switch-case statement

Objective: Write a C program that efficiently handles multiple sensor types using a structure + union combination, and display the correct output based on the current operating mode.*/
#include <stdio.h>
#include <string.h>
union SensorValue
{
    int temperature;
    int battery;
    float voltage;
};
struct SmartDevice
{
    int deviceId;
    char mode[20];
    union SensorValue value;
};
int main()
{
    struct SmartDevice d;
    printf("Enter Device ID: ");
    scanf("%d", &d.deviceId);
    printf("Enter Mode (TEMP/BATTERY/VOLTAGE): ");
    scanf("%s", d.mode);
    if(strcmp(d.mode, "TEMP") == 0)
    {
        printf("Enter Temperature: ");
        scanf("%d", &d.value.temperature);
    }
    else if(strcmp(d.mode, "BATTERY") == 0)
    {
        printf("Enter Battery Percentage: ");
        scanf("%d", &d.value.battery);
    }
    else if(strcmp(d.mode, "VOLTAGE") == 0)
    {
        printf("Enter Voltage: ");
        scanf("%f", &d.value.voltage);
    }
    else
    {
        printf("Invalid Mode\n");
        return 0;
    }
    printf("Device ID: %d\n", d.deviceId);
    switch(d.mode[0])
    {
        case 'T':
            printf("Mode: TEMP\n");
            printf("Temperature = %d C\n", d.value.temperature);
            break;
        case 'B':
            printf("Mode: BATTERY\n");
            printf("Battery = %d %%\n", d.value.battery);
            break;
        case 'V':
            printf("Mode: VOLTAGE\n");
            printf("Voltage = %.2f V\n", d.value.voltage);
            break;
        default:
            printf("Invalid Mode\n");
    }
    return 0;
}