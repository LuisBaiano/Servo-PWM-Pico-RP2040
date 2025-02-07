
# Controle de Servomotor via PWM em uma Raspberry PICO W 2040

**Autor: Luis Felipe Pereira de Carvalho**

**Técnico em Análises e Desenvolvimento de Sistemas - SENAI**

**Graduando em Bacharelado de Engenharia de Computação - UEFS**

Projeto realizado para a Residência EmbarcaTech 2024/2025

## Índice

* [Objetivos](#objetivos)
* [Descrição](#descri%C3%A7%C3%A3o)
* [Funcionalidades](#funcionalidades)
* [Requisitos de Sistema](#requisitos-de-sistema)
* [Como Executar o Programa](#como-executar-o-programa)
* [Estrutura do Código](#estrutura-do-c%C3%B3digo)
* [Referências](#refer%C3%AAncias)
* [Demonstrativo em Vídeo](#demonstrativo-em-v%C3%ADdeo)

## Objetivos

Este projeto simula o controle do ângulo de um servomotor utilizando o módulo PWM (Pulse Width Modulation) do microcontrolador RP2040 (Raspberry Pi Pico W) com o Pico SDK. A simulação é realizada no ambiente online Wokwi, utilizando um servomotor micro servo padrão. Além disso, é feito um experimento com o LED RGB (GPIO 12) utilizando a ferramenta BitDogLab.

* **Controlar um servomotor via PWM:** Configurar a GPIO 22 para gerar sinais PWM com frequência de 50Hz (período de 20ms) e ajustar o ciclo ativo para posicionar o servomotor em 0°, 90° e 180°.
* **Movimentação suave:** Implementar uma rotina para mover o servomotor periodicamente entre 0° e 180°, com incrementos de 5μs e atraso de 10ms, garantindo uma transição suave.
* **Experimentos com LED:** Utilizar o LED RGB conectado à GPIO 12 (BitDogLab) para realizar testes experimentais e observar o comportamento da iluminação em função do PWM.
* **Integração e simulação:** Utilizar o Pico SDK com VS Code e integrar o projeto ao simulador online Wokwi para validar a implementação.

## Descrição

O programa configura o PWM do Raspberry Pi Pico W para controlar um servomotor. Inicialmente, o código posiciona o servomotor em ângulos fixos:

* **180°:** 2400μs de pulso (posição máxima).
* **90°:** 1470μs de pulso (posição intermediária).
* **0°:** 500μs de pulso (posição mínima).

Após essas posições iniciais, o servomotor se move continuamente entre 0° e 180° de forma suave, ajustando o pulso em incrementos de 5μs com um atraso de 10ms entre cada ajuste. Adicionalmente, o LED RGB na GPIO 12 é utilizado para experimentos com PWM (teste realizado com a ferramenta BitDogLab).

## Funcionalidades

* **Configuração PWM:** Geração de PWM a 50Hz (20ms de período) para controle do servomotor.
* **Posicionamento Fixo:** Definição de ciclos ativos para posições específicas:
  * 180°: 2400μs de pulso.
  * 90°: 1470μs de pulso.
  * 0°: 500μs de pulso.
* **Movimentação Suave:** Loop que varre os ângulos de 0° a 180° (e vice-versa) de maneira gradual.
* **Teste com LED RGB:** Experimento utilizando o LED na GPIO 12 para monitorar efeitos do PWM.
* **Integração com Simulador:** Compatibilidade com o ambiente Wokwi para simulação online sem necessidade de circuitos de interface.

## Requisitos de Sistema

* **Hardware:**
  * Raspberry Pi Pico W.
  * Servomotor micro servo padrão (simulado no Wokwi).
  * LED RGB (GPIO 12) para experimentos com BitDogLab.
* **Software:**
  * Visual Studio Code com as extensões para Raspberry Pi Pico.
  * Pico SDK configurado no ambiente.
  * Simulador online Wokwi.
  * Ferramenta BitDogLab para testes com LED.
* **Linguagem:**
  * C.

## Como Executar o Programa

1. **Clonando o Repositório:**
   ```bash
   git clone <URL_do_repositório>
   cd <nome_do_projeto>
   ```
2. **Compilando o Código:**
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```
3. **Upload/Simulação:**
   * Para hardware real, conecte o firmware ao Raspberry Pi Pico W.
   * Para simulação, carregue o código no Wokwi.

## Estrutura do Código

* **main.c:**
  * Inicialização do STDIO e configuração do GPIO 22 como PWM.
  * Configuração do PWM para 50Hz e ajuste de ciclo ativo.
  * Movimentação do servomotor entre 0° e 180°.
  * Testes com LED RGB (GPIO 12) no BitDogLab.

## Referências

* [Raspberry Pi Pico C SDK](https://datasheets.raspberrypi.com/pico/raspberry-pi-pico-c-sdk.pdf)
* [Wokwi Simulator](https://wokwi.com/)
* [BitDogLab](https://www.bitdoglab.com/)

## Demonstrativo em Vídeo

Assista ao vídeo demonstrativo no seguinte link:

* [Vídeo de Demonstração - Controle de Servomotor por PWM](https://www.dropbox.com/scl/fi/i32f4t9dqggn4c1durb4o/2025-02-04-08-52-05.mkv?rlkey=s6ofq9yumuts3h8chte052cuj&dl=0)
