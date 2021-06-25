# Tuya IoTOS Embedded Mcu Demo Wifi Ble TMP75

[English](./README.md) | [中文](./README_zh.md)

## Introduction  

This Demo uses the Tuya smart cloud platform, Tuya smart APP, TMP75 and IoTOS Embedded MCU SDK to realize a temperature detector.

The implemented features include:

+ temperature measurement


## Quick start  

### Compile & Burn
+ Download [Tuya IoTOS Embeded MCU sdk](https://registry.code.tuya-inc.top/hardware_developer/tuya-iotos-embeded-mcu-demo-4g-vending-machine/tree/master) 
+ Execute the test.uvprojx file
+ Click Compile in the software and complete the download


### File introduction 

```
├── user
│   ├── main.c
│   ├── MY_ST_config.h
├── CMSIS
│   ├── system_stm32g0xx.c
│   ├── startup_stm32g071xx.s
├── SYSTEM
│   ├── sys.c
│   ├── sys.h
│   ├── RCC.c
│   ├── RCC.h
│   ├── delay.c
│   ├── delay.h
│   ├── USART.c
│   ├── USART.h
│   ├── IO.c
│   ├── IO.h
│   ├── TIM.c
│   ├── TIM.h
└── SYSTEM
    ├── mcu_api.c
    ├── mcu_api.h
    ├── protocol.c
    ├── protocol.h
    ├── system.c
    ├── system.h
    └── wifi.h
    
```



### Demo entry

Entry file：main.c

Important functions：main()

+ Initialize and configure MCU IO port, USART, timer, etc. All events are polled and judged in while(1)。




### DataPoint related

+ DP point processing: mcu_dp_value_update()

| function name | unsigned char mcu_dp_value_update(unsigned char dpid,unsigned long value) |
| ------------- | ------------------------------------------------------------ |
| dpid          | DP ID number                                                 |
| value         | DP data                                                      |
| Return        | SUCCESS: Success ERROR: Failure                              |



### I/O List  

|    SHT21     | UASRT1  | SWITCH |
| :----------: | :-----: | :----: |
| PB11 IIC_SDA | PC4 TXD |  PC13  |
| PB12 IIC_SCL | PC5 RXD |        |



## Related Documents

  Tuya Demo Center: https://developer.tuya.com/cn/demo/



## Technical Support

  You can get support for Tuya by using the following methods:

- Developer Center: https://developer.tuya.com/cn/
  - Help Center: https://support.tuya.com/en/help
  - Technical Support Work Order Center: [https://service.console.tuya.com](https://service.console.tuya.com/) 

