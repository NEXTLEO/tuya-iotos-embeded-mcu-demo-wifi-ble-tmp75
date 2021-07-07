# Tuya IoTOS Embedded Wi-Fi & Bluetooth LE Temperature Sensor

[English](./README.md) | [中文](./README_zh.md)

## Overview

In this demo, we will show you how to develop with the MCU SDK to enable a TMP75 temperature sensor to connect to the Tuya IoT Cloud with the Tuya Smart app.

Feature:

+ Detect temperature





## Get started

### Compile and flash
+ Download Tuya IoTOS Embedded code.

+ Run `test.uvprojx`.

+ Click **Compile** on the software to download the code.


### File introduction

```
├── user
│   ├── main.c
│   ├── MY_ST_config.h
├── CMSIS
│   ├── system_stm32g0xx.c
│   ├── startup_stm32g071xx.s
├── SYSTEM
│   ├── sys.c
│   ├── sys.h
│   ├── RCC.c
│   ├── RCC.h
│   ├── delay.c
│   ├── delay.h
│   ├── USART.c
│   ├── USART.h
│   ├── IO.c
│   ├── IO.h
│   ├── TIM.c
│   ├── TIM.h
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

Entry file: `main.c`

Main function: `main()`

+ Initialize and configure I/Os, USART, and timer of the MCU. All events are polled and determined in `while(1)`.




### Data point (DP)

+ Process DP data: `mcu_dp_value_update()`

| Function name | unsigned char mcu_dp_value_update(unsigned char dpid,unsigned long value) |
| ------ | ------------------------------------------------------------ |
| dpid | DP ID |
| value | DP data |
| Return | SUCCESS: DP data reporting succeeded. ERROR: DP data reporting failed. |



### Pin configuration

| TMP75 | UASRT1 | SWITCH |
| :----------: | :-----: | :----: |
| PB11 IIC_SDA | PC4 TXD | PC13 |
| PB12 IIC_SCL | PC5 RXD |        |

## Reference

[Tuya Project Hub](https://developer.tuya.com/demo)



## Technical Support

You can get support from Tuya with the following methods:

- [Tuya IoT Developer Platform](https://developer.tuya.com/en/)
- [Help Center](https://support.tuya.com/en/help)
- [Service & Support](https://service.console.tuya.com)[](https://service.console.tuya.com/)
