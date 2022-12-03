#include <stdint.h>
#include <string.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "halGpio.h"
#include "halLed.h"

static int oldGpioValue = -1;

void app_main()
{
    halGpioConfiguration_t gpioConfig = {.gpioNumber = 18, .gpioMode = halGpioMode_OUTPUT,
        .pullDownEnabled = 0, .pullUpEnabled =0};
    if (!halGpioInit(&gpioConfig))
    {
        ESP_LOGE("main", "%s", "Error initializing GPIO18");
        while(1){}
    }
    gpioConfig.gpioNumber = 14;
    gpioConfig.gpioMode = halGpioMode_OUTPUT;
    gpioConfig.pullDownEnabled = 0;
    gpioConfig.pullUpEnabled =0;
    if (!halGpioInit(&gpioConfig))
    {
        ESP_LOGE("main", "%s", "Error initializing GPIO14");
        while(1){}
    }
    gpioConfig.gpioNumber = 19;
    gpioConfig.gpioMode = halGpioMode_INPUT;
    gpioConfig.pullDownEnabled = 0;
    gpioConfig.pullUpEnabled = 1;
    if (!halGpioInit(&gpioConfig))
    {
        ESP_LOGE("main", "%s", "Error initializing GPIO19");
        while(1){}
    }
    if (!halLedInitialize(2))
    {
        ESP_LOGE("main", "%s", "Error initializing LED");
        while(1){}
    }
    while(1)
    {
        int gpioValue = halGpioGetValue(19);
        if (-1 == oldGpioValue || gpioValue != oldGpioValue)
        {
            ESP_LOGI("main", "%s%d", "GPIO19 level: ", gpioValue);
            if(halGpioSetValue(14, !gpioValue))
            {
                halLedSetValue(!gpioValue);
                oldGpioValue = gpioValue;
            }
            else
            {
                ESP_LOGW("main", "Error setting the GPIO14 output to %d", !gpioValue);
            }
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}