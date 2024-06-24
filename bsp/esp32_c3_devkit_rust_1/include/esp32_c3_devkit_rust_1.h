#pragma once

#include "driver/gpio.h"
#include "driver/i2s_pdm.h"
#include "iot_button.h"
#include "bsp/display.h"

/**************************************************************************************************
 *  BSP Capabilities
 **************************************************************************************************/

#define BSP_CAPS_DISPLAY        1
#define BSP_CAPS_TOUCH          0
#define BSP_CAPS_BUTTONS        1
#define BSP_CAPS_AUDIO          0
#define BSP_CAPS_AUDIO_SPEAKER  0
#define BSP_CAPS_AUDIO_MIC      0
#define BSP_CAPS_SDCARD         0
#define BSP_CAPS_IMU            1

// GPIO definitions for ESP32-C3-DevKit-RUST-1
#define GPIO_LCD_SCLK    0
#define GPIO_LCD_MOSI    6
#define GPIO_LCD_MISO    11 // Not used, but defined for completeness
#define GPIO_LCD_CS      5
#define GPIO_LCD_DC      4
#define GPIO_LCD_RESET   3
#define GPIO_LCD_BL      1

#define GPIO_I2C_SDA     10
#define GPIO_I2C_SCL     8

