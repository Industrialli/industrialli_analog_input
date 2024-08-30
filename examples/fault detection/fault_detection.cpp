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
}

void loop(){
    /* Leitura da entrada analógica A01.
     */
    double mA_A01 = analog_input.analog_read(A01);

    /* Converte um valor de leitura que está no intervalo
     * de 4 - 20mA (Característica do sensor) para temperatura
     * de 0 - 200°C. 
     */
    double temperature = analog_input.map(mA_A01, 4, 20, 0, 200);

    /* Caso for detectado uma corrente abaixo de 4mA na leitura
     * do sensor conectado na porta A01, significando uma possível 
     * falha (Característica do sensor), é exibido uma mensagem e 
     * um led irá piscar. Caso contrario é exibido a temperatura. 
     */
    if(analog_input.alarm_020mA(mA_A01, 4)){
        leds.toggle(0);
        Serial.println("Sensor failure.");
    }else {
        Serial.println(temperature);
    }

    leds.update();
    delay(1000);
}