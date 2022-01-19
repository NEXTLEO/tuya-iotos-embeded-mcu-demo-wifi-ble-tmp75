#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_

#ifdef __cplusplus
extern "C" {
#endif

void i2c_init(void);
unsigned char i2c_write_bytes(unsigned char device_addr, unsigned int register_addr, unsigned char *data, int len);
unsigned char i2c_read_bytes(unsigned char device_addr, unsigned int register_addr, unsigned char *data, int len);


#ifdef __cplusplus
}
#endif

#endif  //I2C_DRIVER_H_
