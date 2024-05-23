#include <Arduino.h>

#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

static const int led_pin = LED_BUILTIN;

void toggleLed(void *parameter){
  while(1){
    digitalWrite(led_pin,HIGH);
    vTaskDelay(500/ portTICK_PERIOD_MS);
    digitalWrite(led_pin,LOW);
    vTaskDelay(500/ portTICK_PERIOD_MS);
  }
}

void setup() {
  pinMode(led_pin,OUTPUT);
  xTaskCreatePinnedToCore(
    toggleLed,
    "Toggle LED",
    1024,
    NULL,
    1,
    NULL,
    app_cpu);

}

void loop() {
}

