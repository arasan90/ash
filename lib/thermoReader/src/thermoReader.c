/** @file thermoReader.c
 * @brief Module managing the thermostate reading
 * @ingroup thermoReader
 */

/*--------------------Includes--------------------*/
#include "thermoReader.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "halGpio.h"
#include "esp_log.h"

/*----------------Type definitions----------------*/
/*--------------------Constants-------------------*/
#define LOG_NAME "thermoReader"

/*--------------------Variables-------------------*/
static TaskHandle_t xHandle = NULL;
static int oldHeatRequest = 0;

/*----------Static function declarations----------*/
void vTaskCode( void * pvParameters );

/*--------------Function definitions--------------*/
void thermoReaderInit(void)
{
    halGpioConfiguration_t gpioConfig = {.gpioNumber = 18, .gpioMode = halGpioMode_OUTPUT,
        .pullDownEnabled = 0, .pullUpEnabled =0};
    if (!halGpioInit(&gpioConfig))
    {
        ESP_LOGE(LOG_NAME, "Error initializing GPIO18");
        while(1){}
    }
    gpioConfig.gpioNumber = 19;
    gpioConfig.gpioMode = halGpioMode_INPUT;
    gpioConfig.pullDownEnabled = 0;
    gpioConfig.pullUpEnabled = 1;
    if (!halGpioInit(&gpioConfig))
    {
        ESP_LOGE(LOG_NAME, "Error initializing GPIO19");
        while(1){}
    }
    xTaskCreate( vTaskCode, "ThermoTask", 2048, NULL, tskIDLE_PRIORITY, &xHandle );
    configASSERT( xHandle );
}

/*-----------Static function definitions----------*/
void vTaskCode( void * pvParameters )
{
    while(1)
    {
        int gpioValue = halGpioGetValue(19);
        int heatRequest = !gpioValue;
        if (heatRequest != oldHeatRequest)
        {
            ESP_LOGI(LOG_NAME, "Heat requested: %s", 1 == heatRequest ? "yes" : "no");
            oldHeatRequest = heatRequest;
        }
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}