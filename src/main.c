#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "thermoReader.h"

void app_main()
{
    thermoReaderInit();
    while(1)
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
