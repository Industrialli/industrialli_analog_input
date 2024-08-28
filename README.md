[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# industrialli analog input

Biblioteca para manipulação das entradas analógicas da Industrialli Hub para o framework Arduino com o uso da biblioteca [stm32ino](https://github.com/stm32duino/).

> [!IMPORTANT]  
> Consulte a biblioteca principal da Industrialli Hub [🔗](https://github.com/Industrialli/Industrialli-Hub).
> 
> Consulte a versão em HAL desta biblioteca [🔗](https://github.com/Industrialli/industrialli_analog_input/tree/HAL).

## Exemplo
No exemplo abaixo, é inicializado a biblioteca de entradas analógicas, configurado a resolução de leitura em 12 bits, configurado a entrada A01 para realizar leitura de 0 - 10V e a entrada A02 para realizar a leitura de 0 - 20mA. No loop principal é realizado a leitura dos valores dessa variável e exibido no console.

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
  
<details>
<summary>map</summary>

Realiza o mapeamento de um valor que está em um intervalo para outro intervalo. Essá função pode ser util para converter o valor da entrada analógica para alguma outra informação, por exemplo de mA para temperatura ou pressão.

**Parâmetros:**
- double: valor de entrada.
- double: valor minimo do intervalo de entrada.
- double: valor máximo do intervalo de entrada.
- double: valor minimo do intervalo de saída.
- double: valor máximo do intervalo de saída.

**Retorno:** 
- double: Valor mapeado para o intervalo de saída.

**Exemplo**

No exemplo abaixo, é convertido o valor recebido por um sensor de temperatura que emite uma corrente entre 4 - 20mA para a temperatura entre 0 - 200°C. 

```cpp
double mA = analog_input.analog_read(A01);
double temperatura = map(mA, 4, 20, 0, 200);
```
</details>

<details>
<summary>map_pin</summary>

Realiza o mapeamento de um valor de uma entrada analógica que está em um intervalo para outro intervalo. Essá função pode ser util para converter o valor da entrada analógica para alguma outra informação, por exemplo de mA para temperatura ou pressão.

**Parâmetros:**
- uint8_t: porta da entrada analógica: A01, A02, A03 e A04.
- double: valor minimo do intervalo de entrada.
- double: valor máximo do intervalo de entrada.
- double: valor minimo do intervalo de saída.
- double: valor máximo do intervalo de saída.

**Retorno:** 
- double: Valor de uma entrada analógica mapeada para o intervalo de saída.

**Exemplo**

No exemplo abaixo, é convertido o valor recebido por um sensor de temperatura na entrada A01 que emite uma corrente entre 4 - 20mA para a temperatura entre 0 - 200°C. 

```cpp
double temperatura = map_pin(A01, 4, 20, 0, 200);
```
</details>

<details>
<summary>alarm_020mA</summary>

Verifica se o valor de uma entrada analógica configurada no modo de leitura READ_20mA está operando corretamente. Alguns sensores são configurados para operar a partir de uma corrente, isso possibilita a detecção de problemas no sensor caso opere abaixo desse valor.

**Parâmetros:**
- double: valor lido por uma entrada analógica configurada no modo de leitura READ_20mA.
- double: threshold.

**Retorno:** 
- bool: verdadeiro caso o valor da entrada analógica seja menor que o threshold definido.

**Exemplo**
```cpp
double mA = analog_input.analog_read(A01);

if(alarm_020mA(mA, 4)){
	error = true;
}else {
	double temperatura = map(mA, 4, 20, 0, 200);
}
```
</details>
