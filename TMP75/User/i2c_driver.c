#include "i2c_driver.h"

// //SDA   PB11
// #define I2C_SDA_OUT     {RCC->IOPENR|=1<<1;GPIOB->MODER&=~(3<<22);GPIOB->MODER|=1<<22;GPIOB->PUPDR|=1<<22;} 
// #define I2C_SDA_IN      {RCC->IOPENR|=1<<1;GPIOB->MODER&=~(3<<22);GPIOB->MODER|=0<<22;} 
// #define I2C_SDA_SET     (GPIOB->ODR|=1<<11)
// #define I2C_SDA_RESET   (GPIOB->ODR&=~(1<<11))
// #define I2C_SCL_STATE   ((GPIOB->IDR & 1<<11) == 1<<11)

// //SCL   PB12
// #define I2C_SCL_OUT     {RCC->IOPENR|=1<<1;GPIOB->MODER&=~(3<<24);GPIOB->MODER|=1<<24;GPIOB->PUPDR|=1<<24;}  
// #define I2C_SCL_IN      {RCC->IOPENR|=1<<1;GPIOB->MODER&=~(3<<24);GPIOB->MODER|=0<<24;} 
// #define I2C_SCL_SET     (GPIOB->ODR|=1<<12)
// #define I2C_SCL_RESET   (GPIOB->ODR&=~(1<<12))
// #define I2C_SCL_STATE   ((GPIOB->IDR & 1<<12) == 1<<12)

inline void config_sda_out(void){}
inline void config_sda_in(void){}
inline void set_sda(void){}
inline void reset_sda(void){}
inline unsigned char get_sda(void){}

inline void config_scl_out(void){}
inline void config_scl_in(void){}
inline void set_scl(void){}
inline void reset_scl(void){}
inline unsigned char get_scl(void){}

static void i2c_delay_us(int us) {}


void i2c_init(void)
{
    config_scl_out();
    config_sda_out();
}

void i2c_start(void)
{
    config_sda_out();
    set_sda();
    set_scl();
    i2c_delay_us(5);
    reset_sda();
    i2c_delay_us(5);
    reset_scl();
}

void i2c_stop(void)
{
    config_sda_out();
    reset_scl();
    reset_sda();
    i2c_delay_us(5);
    set_scl();
    i2c_delay_us(5);
    set_sda();
}

void i2c_ack(void)
{
    reset_scl();
    config_sda_out();
    reset_sda();
    i2c_delay_us(5);
    set_scl();
    i2c_delay_us(5);
    reset_scl();
}

void i2c_nack(void)
{
    reset_scl();
    config_sda_out();
    set_sda();
    i2c_delay_us(5);
    set_scl();
    i2c_delay_us(5);
    reset_scl();
}

unsigned char i2c_wait_ack(void)
{
    unsigned char err_time = 0;
    config_sda_in();
    set_scl();
    i2c_delay_us(5);
    while(get_sda) {
        err_time++;
        if(err_time > 250) {
            i2c_stop();
            return 1;
        }
    }
    reset_scl();
    return 0;
}

void i2c_send_byte(unsigned char data)
{
    config_sda_out();
    reset_scl();
    for(unsigned int idx = 0; idx < 8; ++idx) {
        if((data & 0x80) >> 7) {
            set_sda();
        } else {
            reset_sda();
        }
        data <<= 1;
        i2c_delay_us(5);
        set_scl();
        i2c_delay_us(5);
        reset_scl();
        i2c_delay_us(5);
    }
}

unsigned char i2c_read_byte(unsigned char ack)
{
    unsigned char read_data = 0;
    config_sda_in();
    for(unsigned char idx = 0; idx < 8; ++idx) {
        reset_scl();
        i2c_delay_us(5);
        set_scl();
        read_data <<= 1;
        if(get_sda()) read_data++;
        i2c_delay_us(5);
    }
    if(ack) {
        i2c_ack();
    } else {
        i2c_nack();
    }
    return read_data;
}

unsigned char i2c_write_bytes(unsigned char device_addr, unsigned int register_addr, unsigned char *data, int len)
{
    unsigned char ret_code = 0;
    i2c_start();
    i2c_send_byte(device_addr);
    ret_code |= i2c_wait_ack();
    i2c_send_byte(register_addr);
    ret_code |= i2c_wait_ack();
    while(len--) {
        i2c_send_byte(*data);
        ret_code |= i2c_wait_ack();
        data++;
    }
    i2c_stop();
    i2c_delay_us(10);
    return ret_code;
}

unsigned char i2c_read_bytes(unsigned char device_addr, unsigned int register_addr, uint8_t *data, int len)
{
    unsigned char ret_code = 0;
    i2c_start();
    i2c_send_byte(device_addr);
    ret_code |= i2c_wait_ack();
    i2c_send_byte(register_addr);
    ret_code |= i2c_wait_ack();

    i2c_start();
    i2c_send_byte(device_addr + 1);
    ret_code |= i2c_wait_ack();
    while(len) {
        if(len == 1) {
            *data = i2c_read_byte(0);
        } else {
            *data = i2c_read_byte(1);
        }
        data++;
        len--;
    }
    i2c_stop();
    return ret_code;
}
