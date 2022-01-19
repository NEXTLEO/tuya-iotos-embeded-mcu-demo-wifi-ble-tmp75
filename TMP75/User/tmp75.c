

#include "i2c_driver.h"

#define     TMP75_ADDRESS           0x90    //GND     GND     GND
#define     TemperatureRegister     0x00
#define     ConfigurationRegister   0x01
#define     TemperatureLowLimit     0x02
#define     TemperatureHighLimit    0x03

void tmp75_set_configuration(int temp)
{
    unsigned char data;
    data = temp;
    i2c_write_bytes(TMP75_ADDRESS, ConfigurationRegister, &data, 1);
}

unsigned char tmp75_get_configuration(void)
{
    unsigned char data[1];
    i2c_read_bytes(TMP75_ADDRESS, ConfigurationRegister, &data, 1);
}

float tmp75_get_temperature(void)
{
    unsigned char data[2];
    i2c_read_bytes(TMP75_ADDRESS, TemperatureRegister, data, 2);
    float temp = (float)((((data[0] << 8) | data[1]) >> 4) * 0.0625f);
    return temp;
}

void tmp75_init(void)
{
    i2c_init();
    temp75_set_configuration(3 << 5);
}

void tmp75_task(void)
{
    float temp = tmp75_get_temperature();
    //TODO
}
