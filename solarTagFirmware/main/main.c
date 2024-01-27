#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"

static uint8_t s_led_state = 0;

void app_main(void)
{
    gpio_reset_pin(8);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(8, GPIO_MODE_OUTPUT);

     while (1) {

        gpio_set_level(8, s_led_state);
        /* Toggle the LED state */
        s_led_state = !s_led_state;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}