// #include <Arduino.h>
// #include <Wire.h>
// #include <SPI.h>
// #include <Adafruit_Sensor.h>
// #include <Adafruit_BME280.h>

// // Definição dos estados
// enum State {
//   WAITING,
//   BME_COLLECT,
//   BME_SEND,
//   ANEMOMETER_COLLECT,
//   ANEMOMETER_SEND
// };

// // Definição das transições
// enum Transition {
//   TIME_EXCEEDED,
//   BME_SENSING_DONE,
//   BME_UPLOAD_DONE,
//   ANEM_SENSING_DONE,
//   ANEM_UPLOAD_DONE
// };

// State currentState = WAITING;

// // Função para imprimir o estado atual
// void printState(State state) {
//   switch (state) {
//     case WAITING:
//         Serial.println();
//         delay(4000);
//         Serial.println("Processador aguardando processos por tempo pré-determinado");
//         break;
//     case BME_COLLECT:
//         Serial.println("BME coleta dados os dados do sensor e retorna temperatura, umidade e altitude");
//         break;
//     case BME_SEND:
//         Serial.println("Conexão BME - Mandando para o dashboard a temperatura, umidade e altitude");
//         break;
//     case ANEMOMETER_COLLECT:
//       Serial.println("Anemômetro - coleta dados os dados do sensor e retorna direção do vento e velocidade do vento");
//       break;
//     case ANEMOMETER_SEND:
//       Serial.println("Conexão Anemômetro - Mandando os dados para o dashboard");
//       break;
//   }
// }

// // Função para mudar o estado baseado na transição
// void changeState(Transition transition) {
//   switch (currentState) {
//     case WAITING:
//       if (transition == TIME_EXCEEDED) {
//         currentState = BME_COLLECT;
//       }
//       break;
//     case BME_COLLECT:
//       if (transition == BME_SENSING_DONE) {
//         currentState = BME_SEND;
//       }
//       break;
//     case BME_SEND:
//       if (transition == BME_UPLOAD_DONE) {
//         currentState = ANEMOMETER_COLLECT;
//       }
//       break;
//     case ANEMOMETER_COLLECT:
//       if (transition == ANEM_SENSING_DONE) {
//         currentState = ANEMOMETER_SEND;
//       }
//       break;
//     case ANEMOMETER_SEND:
//       if (transition == ANEM_UPLOAD_DONE) {
//         currentState = WAITING;
//       }
//       break;
//   }
//   printState(currentState);
// }

// void setup() {
//   Serial.begin(9600);
//   printState(currentState); // Imprime o estado inicial
// }

// void loop() {
//   // Simulações de transições (apenas para demonstração)
//   //delay(2000); // Aguarda 2 segundos

//   // Aqui você pode adicionar condições reais para as transições
//   if (currentState == WAITING) {
//     changeState(TIME_EXCEEDED);
//   } else if (currentState == BME_COLLECT) {
//     changeState(BME_SENSING_DONE);
//   } else if (currentState == BME_SEND) {
//     changeState(BME_UPLOAD_DONE);
//   } else if (currentState == ANEMOMETER_COLLECT) {
//     changeState(ANEM_SENSING_DONE);
//   } else if (currentState == ANEMOMETER_SEND) {
//     changeState(ANEM_UPLOAD_DONE);
//   }
// }
