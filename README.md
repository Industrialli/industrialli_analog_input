[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# industrialli analog input

Biblioteca para manipulação das entradas analógicas da Industrialli Hub para o framework Arduino com o uso da biblioteca [stm32ino](https://github.com/stm32duino/).

> [!IMPORTANT]  
> Consulte a biblioteca principal da Industrialli Hub [🔗](https://github.com/Industrialli/Industrialli-Hub).
> 
> Consulte a versão em HAL desta biblioteca [🔗](https://github.com/Industrialli/industrialli_analog_input/tree/HAL).

## Exemplo
No exemplo abaixo, é inicializado a biblioteca de entradas analógicas, e logo em seguida é configurado a resolução em 12 bits e a entrada A01 para realizar leitura de 0 - 10V e a entrada A02 para realizar a leitura de 0 - 20mA. No loop principal é realizado a leitura dos valores dessa variável.

```cpp
#include "industrialli_hub.hpp"

industrialli_hub hub;

void setup(){
	hub.begin();

	analog_input.begin();
    	analog_input.set_resolution(12);
    	analog_input.set_read_mode(A01, READ_10V);
	analog_input.set_read_mode(A02, READ_20mA);
}

void loop(){
	Serial.println(analog_input.analog_read(A01));
	Serial.println(analog_input.analog_read(A02));
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

Inicializa uma entrada analógica para um modo de leitura específica.

**Parâmetros:**
- uint8_t: porta da entrada analógica: A01, A02, A03 e A04.
- uint8_t: modo de leitura: READ_10V ou READ_20mA.

**Retorno:** void

**Exemplo**
```cpp
analog_input.set_read_mode(A01, READ_10V);
analog_input.set_read_mode(A02, READ_20mA);
```
</details>

<details>
<summary>set_resolution</summary>

Seleciona uma resolução para leitura das entradas analógicas.

**Parâmetros:**
- uint16_t: resolução de leitura: 8, 10, 12 ou 16.

**Retorno:** void

**Exemplo**
```cpp
analog_input.set_resolution(12);
```
</details>

<details>
<summary>analog_read</summary>

Realiza a leitura de uma entrada analógica específica.

**Parâmetros:**
- uint8_t: porta da entrada analógica: A01, A02, A03 e A04.

**Retorno:** 
- Double: Valor de leitura realizado na entrada analógica.

**Exemplo**
```cpp
Serial.println(analog_input.analog_read(A01));
Serial.println(analog_input.analog_read(A02));
```
</details>
  
