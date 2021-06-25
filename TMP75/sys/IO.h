#ifndef __IO_H
#define __IO_H 		
#include "MY_ST_config.h"
#include "math.h"
#include "stdbool.h"


//IIC_SDA	  PB11
#define IIC_SDA_OUT {RCC->IOPENR|=1<<1;GPIOB->MODER&=~(3<<22);GPIOB->MODER|=1<<22;GPIOB->PUPDR|=1<<22;} 
#define IIC_SDA_IN  {RCC->IOPENR|=1<<1;GPIOB->MODER&=~(3<<22);GPIOB->MODER|=0<<22;} 
#define IIC_SDA_SET GPIOB->ODR|=1<<11
#define IIC_SDA_RESET  GPIOB->ODR&=~(1<<11)
#define IIC_SDA_State ((GPIOB->IDR & 1<<11) == 1<<11)

//IIC_SCL	  PB12
#define IIC_SCL_OUT {RCC->IOPENR|=1<<1;GPIOB->MODER&=~(3<<24);GPIOB->MODER|=1<<24;GPIOB->PUPDR|=1<<24;}  
#define IIC_SCL_IN  {RCC->IOPENR|=1<<1;GPIOB->MODER&=~(3<<24);GPIOB->MODER|=0<<24;} 
#define IIC_SCL_SET GPIOB->ODR|=1<<12
#define IIC_SCL_RESET  GPIOB->ODR&=~(1<<12)
#define IIC_SCL_State ((GPIOB->IDR & 1<<12) == 1<<12)

//PC13
#define KEY_IN  {RCC->IOPENR|=1<<2;GPIOC->MODER&=~(3<<26);GPIOC->MODER|=0<<26;} 
#define KEY_State ((GPIOC->IDR & 1<<13) == 1<<13)

#if 1
void IIC_Init(void);
void IIC_Start(void);//产生IIC起始信号
void IIC_Stop(void);//产生IIC停止信号
void IIC_Ack(void);//产生ACK应答
void IIC_NAck(void);//不产生ACK应答	
uint8_t IIC_Wait_Ack(void);//等待应答信号到来:1,接收应答失败;0,接收应答成功
void IIC_Send_Byte(uint8_t txd);//IIC发送一个字节; 先发送高位
uint8_t IIC_Read_Byte(unsigned char ack);//读一个字节，可加是否应答位,1加ack，0不加ack 从高位开始读
uint8_t IIC_Write_Byte(uint8_t DrvAddr,uint16_t WriteAddr,uint8_t data);//直接写一个字节
uint8_t IIC_ReadMulByte(uint8_t DrvAddr,uint16_t ReadAddr,uint8_t *pBuffer,uint16_t NumToRead);//读字节
uint8_t IIC_WriteMulByte(uint8_t DrvAddr,uint16_t WriteAddr,uint8_t *pBuffer,uint16_t NumToWrite);//可一次写多个字节
#endif

//LED_CTRL4	 	PA5
#define LED_4_OUT {RCC->IOPENR|=1<<0;GPIOA->MODER&=~(3<<10);GPIOA->MODER|=1<<10;} 
#define LED_4_SET GPIOA->ODR|=1<<5
#define LED_4_RESET  GPIOA->ODR&=~(1<<5)
#define LED_4_TOG GPIOA->ODR^=1<<5

#if USING_TMP75/***************************以下是TMP75温度传感器**************************/
/***************************以下是TMP75温度传感器**************************/
#define     TMP75_ADDRESS 0x90    //GND     GND     GND
#define     TemperatureRegister     0x00
#define     ConfigurationRegister   0x01
#define     TemperatureLowLimit     0x02
#define     TemperatureHighLimit    0x03
#endif
extern uint8_t F_TASK_TMP75;
void TASK_TMP75(void);

void IO_Init(void);
#endif

