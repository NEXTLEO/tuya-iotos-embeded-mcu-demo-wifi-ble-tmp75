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
void IIC_Start(void);//����IIC��ʼ�ź�
void IIC_Stop(void);//����IICֹͣ�ź�
void IIC_Ack(void);//����ACKӦ��
void IIC_NAck(void);//������ACKӦ��	
uint8_t IIC_Wait_Ack(void);//�ȴ�Ӧ���źŵ���:1,����Ӧ��ʧ��;0,����Ӧ��ɹ�
void IIC_Send_Byte(uint8_t txd);//IIC����һ���ֽ�; �ȷ��͸�λ
uint8_t IIC_Read_Byte(unsigned char ack);//��һ���ֽڣ��ɼ��Ƿ�Ӧ��λ,1��ack��0����ack �Ӹ�λ��ʼ��
uint8_t IIC_Write_Byte(uint8_t DrvAddr,uint16_t WriteAddr,uint8_t data);//ֱ��дһ���ֽ�
uint8_t IIC_ReadMulByte(uint8_t DrvAddr,uint16_t ReadAddr,uint8_t *pBuffer,uint16_t NumToRead);//���ֽ�
uint8_t IIC_WriteMulByte(uint8_t DrvAddr,uint16_t WriteAddr,uint8_t *pBuffer,uint16_t NumToWrite);//��һ��д����ֽ�
#endif

//LED_CTRL4	 	PA5
#define LED_4_OUT {RCC->IOPENR|=1<<0;GPIOA->MODER&=~(3<<10);GPIOA->MODER|=1<<10;} 
#define LED_4_SET GPIOA->ODR|=1<<5
#define LED_4_RESET  GPIOA->ODR&=~(1<<5)
#define LED_4_TOG GPIOA->ODR^=1<<5

#if USING_TMP75/***************************������TMP75�¶ȴ�����**************************/
/***************************������TMP75�¶ȴ�����**************************/
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

