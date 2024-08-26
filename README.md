[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)



# industrialli analog input

Biblioteca para manipulação das entradas analógicas da Industrialli Hub para o framework Arduino com o uso da biblioteca [stm32ino](https://github.com/stm32duino/).

> [!IMPORTANT]  
> Consulte a biblioteca geral da Industrialli Hub [🔗](https://github.com/Industrialli/Industrialli-Hub).

## Exemplo
No exemplo abaixo, é inicializado a biblioteca de entradas analógicas, e logo em seguida é configurado a entrada A01 para realizar leitura de 0 - 10V e a entrada A02 para realizar a leitura de 0 - 20V. No loop principal é realizado a leitura dos valores dessa variável.

```cpp
#include "industrialli_hub.hpp"

industrialli_hub hub;

void setup(){
	hub.begin();

	analog_input.begin();
    	analog_input.set_resolution(12);
    	analog_input.set_read_mode(A01, READ_20mA);
}

void loop(){
	Serial.println(analog_input.analog_read(A01));
	leds.update();
	delay(10);
}   
```

## Funções

Segue abaixo as funções disponíveis para o usuário manipular as entradas analógicas da Industrialli Hub.

<details>
<summary>begin</summary>

Inicializa as entradas analógicas.

**Parâmetros:** void

**Retorno:** void

**Exemplo**
```cpp
analog_input.begin();
```
</details>

<details>
<summary>set_read_mode</summary>

Inicializa uma entrada analógica para um modo de leitura especifica.

**Parâmetros:**
- ANALOG_PIN: Enum da entrada analógica: A01, A02, A03 e A04.
- INPUT_VOLTAGE: Enum da voltagem da entrada: INPUT_VOLTAGE_10V e INPUT_VOLTAGE_20V.

**Retorno:** void

**Exemplo**
```cpp
analog_input.set_input_voltage(A01, INPUT_VOLTAGE_10V);
analog_input.set_input_voltage(A02, INPUT_VOLTAGE_20V);
```
</details>


<details>
<summary>analog_read</summary>

Realiza a leitura de uma entrada analógica específica.

**Parâmetros:**
- ANALOG_PIN: Enum da entrada analógica: A01, A02, A03 e A04.

**Retorno:** 
- Double: Valor de leitura realizado na entrada analógica.

**Exemplo**
```cpp
__IO double a01V = analog_input.analog_read(A01);
__IO double a02V = analog_input.analog_read(A02);
```
</details>
  
