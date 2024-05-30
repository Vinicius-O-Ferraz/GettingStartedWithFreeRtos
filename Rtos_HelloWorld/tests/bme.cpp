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
static const uint8_t msg_queue_length = 32;
static QueueHandle_t msg_queue;

// Handles para as tarefas
static TaskHandle_t task_1 = NULL;
static TaskHandle_t task_2 = NULL;
static TaskHandle_t task_3 = NULL;

// Função da tarefa 1
void bme(void *parameter){

    while(1){
        Serial.println();  // Imprime uma linha em branco
            Serial.print("Temperature = ");
            //Serial.print(bme.readTemperature());
            Serial.println(" °C");

            Serial.print("Pressure = ");
            //Serial.print(bme.readPressure() / 100.0F);
            Serial.println(" hPa");

            Serial.print("Approx. Altitude = ");
            //Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
            Serial.println(" m");

            Serial.print("Humidity = ");
            //Serial.print(bme.readHumidity());
            Serial.println(" %");
                }
        Serial.println();  // Imprime uma nova linha
        vTaskDelay(6000 / portTICK_PERIOD_MS);  // Espera 1 segundo
    }

// Função da tarefa 2
void anem(void *parameter){
    while(1){
        //Sample++;
        //Serial.print(Sample);
        Serial.print("Start measurement...");
        //windvelocity();
        Serial.println("   finished.");
        Serial.print("Counter: ");
        //Serial.print(counter);
        Serial.println("RPM: ");
        //RPMcalc();
        //Serial.print(RPM);
        Serial.println("Wind speed: ");

        Serial.println();  // Imprime uma nova linha
        vTaskDelay(6000 / portTICK_PERIOD_MS);  // Espera 1 segundo
    }
}

void connection(void *parameter){
    Serial.println();
    Serial.println("Connecting to server via mqts");
    for (int i =0; i > 4; i++){
            delay(100);
            Serial.print(".");
    }
}

void setup(){
    Serial.begin(300);  // Inicializa a comunicação serial com baud rate de 300

    vTaskDelay(1000 / portTICK_PERIOD_MS);  // Espera 1 segundo
    Serial.println();    
    Serial.print("Setup and loop task running on core ");
    Serial.print(xPortGetCoreID());  // Imprime o núcleo no qual a função setup está rodando
    Serial.print(" with priority ");
    Serial.println(uxTaskPriorityGet(NULL));  // Imprime a prioridade da tarefa atual

    // Cria a tarefa 1 e a fixa no núcleo especificado
    xTaskCreatePinnedToCore(bme,
                            "Task 1",  // Nome da tarefa
                            1024,  // Tamanho da pilha
                            NULL,  // Parâmetro para a tarefa
                            2,  // Prioridade da tarefa
                            &task_1,  // Handle da tarefa
                            app_cpu);  // Núcleo da CPU

    // Cria a tarefa 2 e a fixa no núcleo especificado
    xTaskCreatePinnedToCore(anem,
                            "Task 2",  // Nome da tarefa
                            1024,  // Tamanho da pilha
                            NULL,  // Parâmetro para a tarefa
                            1,  // Prioridade da tarefa
                            &task_2,  // Handle da tarefa
                            app_cpu);  // Núcleo da CPU

    xTaskCreatePinnedToCore(connection,
                            "Task 3",  // Nome da tarefa
                            1024,  // Tamanho da pilha
                            NULL,  // Parâmetro para a tarefa
                            1,  // Prioridade da tarefa
                            &task_3,  // Handle da tarefa
                            app_cpu);  // Núcleo da CPU
}

void loop(){
 
}