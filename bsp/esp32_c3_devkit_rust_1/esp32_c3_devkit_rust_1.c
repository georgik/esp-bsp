#include <stdio.h>
#include "esp32_c3_devkit_rust_1.h"

esp_err_t bsp_i2c_init(void)
{
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = GPIO_I2C_SDA,
        .scl_io_num = GPIO_I2C_SCL,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = 100000,
    };
    i2c_param_config(I2C_NUM_0, &conf);
    return i2c_driver_install(I2C_NUM_0, conf.mode, 0, 0, 0);
}

esp_err_t bsp_spi_init(void)
{
    spi_bus_config_t buscfg = {
        .miso_io_num = GPIO_LCD_MISO,
        .mosi_io_num = GPIO_LCD_MOSI,
        .sclk_io_num = GPIO_LCD_SCLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
    };
    spi_bus_initialize(HSPI_HOST, &buscfg, 1);

    spi_device_interface_config_t devcfg = {
        .clock_speed_hz = 10*1000*1000,           // Clock out at 10 MHz
        .mode = 0,                                // SPI mode 0
        .spics_io_num = GPIO_LCD_CS,              // CS pin
        .queue_size = 7,                          // We want to be able to queue 7 transactions at a time
    };
    spi_device_handle_t handle;
    return spi_bus_add_device(HSPI_HOST, &devcfg, &handle);
}

esp_err_t bsp_display_init(void)
{
    // Initialize display with the configured SPI and GPIO settings
    // Placeholder function for initializing display specific to this board
    // Implementation should match the Rust example provided
    return ESP_OK;
}