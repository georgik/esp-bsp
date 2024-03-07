/*
 * SPDX-FileCopyrightText: 2021-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include "bsp/esp-bsp.h"
#include <bsp/display.h>
#include <esp_lcd_panel_ops.h>
#include "esp_log.h"


static esp_lcd_panel_handle_t panelHandle = NULL;
static esp_lcd_panel_io_handle_t ioHandle = NULL;

void app_main(void)
{
    bsp_lcd_handles_t handles = {
        0
    };

    const bsp_display_config_t displayConfig = {

    };

    ESP_ERROR_CHECK(bsp_display_new_with_handles(&displayConfig, &handles));
    panelHandle = handles.panel;
    ioHandle = handles.io;

    // const esp_lcd_dpi_panel_event_callbacks_t cbs = {
    //     .on_color_trans_done = flushReady,
    // };
    // esp_lcd_dpi_panel_register_event_callbacks(panelHandle, &cbs, nullptr);


    ESP_LOGI("example", "Display example");

    uint8_t *framebuffer = heap_caps_malloc(1280 * 800 * 2, MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);


    // Fill the framebuffer with some data
    for (int i = 0; i < 1280*800; i++) {
        framebuffer[i*2] = 0x00;
        framebuffer[i*2+1] = 0x99;
    }

    // lv_obj_t *scr = lv_disp_get_scr_act(NULL);
    ESP_ERROR_CHECK(esp_lcd_panel_draw_bitmap(panelHandle, 0, 0, 800, 1280, framebuffer));
    // bsp_display_unlock();
    // bsp_display_backlight_on();
}
