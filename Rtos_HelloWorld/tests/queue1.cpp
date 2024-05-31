#include <Arduino.h>  // Inclui a biblioteca principal do Arduino
#include <Arduino.h>
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Verifica se o FreeRTOS está configurado para usar um núcleo
#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;  // Define o núcleo de aplicação como 0
#else
static const BaseType_t app_cpu = 1;  // Define o núcleo de aplicação como 1
#endif

//define queue length
static const uint8_t msg_queue_length = 5;
static QueueHandle_t msg_queue;

// Handles para as tarefas
static TaskHandle_t task_1 = NULL;
static TaskHandle_t task_2 = NULL;
static TaskHandle_t task_3 = NULL;

// Função da tarefa 1
void task(void *parameter){

    int item;

    while(1){
        if(xQueueReceive(msg_queue, (void *)&item, 0)==pdTRUE){
            Serial.println(item);
        }
    vTaskDelay(500/ portTICK_PERIOD_MS);
    }
}

void setup(){
    Serial.begin(115200);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
    Serial.println();
    Serial.println("--FreeRtos Queue Demo--");

    msg_queue = xQueueCreate(msg_queue_length,sizeof(int));

    xTaskCreatePinnedToCore(
        task,
        "task",
        1024,
        NULL,
        1,
        NULL,
        app_cpu);
}

void loop(){
    static int num = 0;

    if (xQueueSend(msg_queue, (void *)&num, 10) != pdTRUE){
        Serial.println("Queue full");
    }
    num++;
    vTaskDelay(500/ portTICK_PERIOD_MS);

}