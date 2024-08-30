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

    /* Configuração da entrada analógica A02 para realizar
     * leitura no modo 0 - 20mA.
     */
    analog_input.set_read_mode(A02, READ_20mA);
}

void loop(){
    /* Converte um valor de leitura que está no intervalo
     * de 4 - 20mA (Característica do sensor) para temperatura
     * de 0 - 200°C. 
     */
    double temperature = analog_input.map_pin(A01, 4, 20, 0, 200);

    /* Converte um valor de leitura que está no intervalo
     * de 4 - 20mA (Característica do sensor) para pressão
     * de 0 - 10 Bar. 
     */
    double pressure = analog_input.map_pin(A02, 4, 20, 0, 10);

    Serial.println(temperature);
    Serial.println(pressure);

    leds.update();
    delay(1000);
}