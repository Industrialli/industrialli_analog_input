#include "industrialli_hub.hpp"

industrialli_hub hub;

void setup(){
    hub.begin();

    /* Inicialização da biblioteca de entradas analógicas.
     */
    analog_input.begin();

    /* Configuração da resolução de leitura das entradas
     * analógicas.
     */
    analog_input.set_resolution(12);

    /* Configuração da entrada analógica A01 para realizar
     * leitura no modo 0 - 20mA.
     */
    analog_input.set_read_mode(A01, READ_20mA);

    /* Configuração da entrada analógica A03 para realizar
     * leitura no modo 0 - 10V.
     */
    analog_input.set_read_mode(A03, READ_10V);
}

void loop(){
    /* Leitura da entrada analógica A01.
     */
    double mA_A01 = analog_input.analog_read(A01);

    /* Leitura da entrada analógica A03.
     */
    double V_A03  = analog_input.analog_read(A03);

    Serial.println(mA_A01);
    Serial.println(V_A03);

    leds.update();
    delay(1000);
}