[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# industrialli analog input

Biblioteca para manipulação das entradas analógicas da Industrialli Hub, com o uso da biblioteca Hardware Abstraction Layer (HAL). Está biblioteca foi configurada para realizar a leitura dos valores brutos das entradas analógicas via Direct memory access (DMA), esses valores podem ser lidos na variavél global analog_input_values[4].

> [!IMPORTANT]  
> Consulte a biblioteca geral da Industrialli Hub.

## Exemplo
No exemplo abaixo, é inicializado a biblioteca de entradas analógicas, e logo em seguida é configurado a entrada A01 para realizar leitura de 0 - 10V e a entrada A02 para realizar a leitura de 0 - 20V. No loop principal é realizado a leitura dos valores dessa variável.

```cpp
#include "industrialli_hub.hpp"

industrialli_hub hub;

int main(){
    hub.begin();

	analog_input.begin();
	analog_input.set_input_voltage(A01, INPUT_VOLTAGE_10V);
	analog_input.set_input_voltage(A02, INPUT_VOLTAGE_20V);
	leds.update();

    while(1){
  		__IO double a01V = analog_input.analog_read(A01);
  		__IO double a02V = analog_input.analog_read(A02);
    }
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
<summary>set_input_voltage</summary>

Inicializa uma entrada analógica para uma voltagem específica.

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
  
