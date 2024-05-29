#include <Arduino.h>  // Inclui a biblioteca principal do Arduino

// Verifica se o FreeRTOS está configurado para usar um núcleo
#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;  // Define o núcleo de aplicação como 0
#else
static const BaseType_t app_cpu = 1;  // Define o núcleo de aplicação como 1
#endif

const char msg[] = "Wish you were here";  // Define uma mensagem constante

// Handles para as tarefas
static TaskHandle_t task_1 = NULL;
static TaskHandle_t task_2 = NULL;

// Função da tarefa 1
void startTask1(void *parameter){
    int msg_len = strlen(msg);  // Calcula o comprimento da mensagem

    while(1){
        Serial.println();  // Imprime uma linha em branco
        for (int i = 0; i < msg_len; i++){
            Serial.print(msg[i]);  // Imprime cada caractere da mensagem
        }
        Serial.println();  // Imprime uma nova linha
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // Espera 1 segundo
    }
}

// Função da tarefa 2
void startTask2(void *parameter){
    while(1){
        Serial.print("*");  // Imprime um asterisco
        vTaskDelay(100 / portTICK_PERIOD_MS);  // Espera 100 milissegundos
    }
}

void setup(){
    Serial.begin(300);  // Inicializa a comunicação serial com baud rate de 300

    vTaskDelay(1000 / portTICK_PERIOD_MS);  // Espera 1 segundo
    Serial.println();    
    Serial.println("Getting Started with RTOS");  // Mensagem inicial

    Serial.print("Setup and loop task running on core ");
    Serial.print(xPortGetCoreID());  // Imprime o núcleo no qual a função setup está rodando
    Serial.print(" with priority ");
    Serial.println(uxTaskPriorityGet(NULL));  // Imprime a prioridade da tarefa atual

    // Cria a tarefa 1 e a fixa no núcleo especificado
    xTaskCreatePinnedToCore(startTask1,
                            "Task 1",  // Nome da tarefa
                            1024,  // Tamanho da pilha
                            NULL,  // Parâmetro para a tarefa
                            1,  // Prioridade da tarefa
                            &task_1,  // Handle da tarefa
                            app_cpu);  // Núcleo da CPU

    // Cria a tarefa 2 e a fixa no núcleo especificado
    xTaskCreatePinnedToCore(startTask2,
                            "Task 2",  // Nome da tarefa
                            1024,  // Tamanho da pilha
                            NULL,  // Parâmetro para a tarefa
                            2,  // Prioridade da tarefa
                            &task_2,  // Handle da tarefa
                            app_cpu);  // Núcleo da CPU
}

void loop(){
    for (int i = 0; i < 3; i++){
        vTaskSuspend(task_2);  // Suspende a tarefa 2
        vTaskDelay(2000 / portTICK_PERIOD_MS);  // Espera 2 segundos
        vTaskResume(task_2);  // Retoma a tarefa 2
        vTaskDelay(2000 / portTICK_PERIOD_MS);  // Espera mais 2 segundos
    }

    if (task_1 != NULL){
        vTaskDelete(task_1);  // Deleta a tarefa 1
        task_1 = NULL;  // Define o handle da tarefa 1 como NULL
    }
}