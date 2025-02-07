#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define LED_BLUE_PIN 12 // Pino para teste de PWM na BitDogLab
#define SERVO_PIN 22  // GPIO 22 para controle do servo motor no simulador Wokwi

// Frequência do PWM (50Hz)
#define PWM_FREQ 50
// Período do PWM (20ms para 50Hz)
#define PWM_PERIOD 20000
// Define o valor de wrap (máximo de contagem do PWM)
#define WRAP_VALUE (PWM_PERIOD - 1)


/**
 * @brief Define a largura do pulso PWM para controlar o servo motor.
 * @param slice_num Número do slice PWM associado ao pino do servo.
 * @param pulse_width Largura do pulso em microssegundos.
 */
void set_pwm_pulse_width(uint slice_num, uint pulse_width) {
    pwm_set_gpio_level(SERVO_PIN, pulse_width);
}

int main() {
    stdio_init_all();

    // Configura o pino como saída PWM
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);

    // Obtém o slice PWM correspondente ao pino
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);

    // Configura o divisor de clock para obter 50Hz
    pwm_set_clkdiv(slice_num, (float)125.0);

    // Define o valor de wrap para alcançar o período de 20ms
    pwm_set_wrap(slice_num, WRAP_VALUE);

    // Ativa o módulo PWM
    pwm_set_enabled(slice_num, true);

    // Define o servo para a posição de 180 graus (pulso de 2400μs)
    set_pwm_pulse_width(slice_num, (2400 * (PWM_PERIOD / 20000)));
    sleep_ms(5000);  // Aguarda 5 segundos

    // Define o servo para a posição de 90 graus (pulso de 1470μs)
    set_pwm_pulse_width(slice_num, (1470 * (PWM_PERIOD / 20000)));
    sleep_ms(5000);  // Aguarda 5 segundos

    // Define o servo para a posição de 0 graus (pulso de 500μs)
    set_pwm_pulse_width(slice_num, (500 * (PWM_PERIOD / 20000)));
    sleep_ms(5000);  // Aguarda 5 segundos

    // Movimento contínuo entre 0 e 180 graus de forma suave
    while (true) {
        // Movimenta de 0 para 180 graus com incremento de 5μs a cada 10ms
        for (int pulse = 500; pulse <= 2400; pulse += 5) {
            set_pwm_pulse_width(slice_num, (pulse * (PWM_PERIOD / 20000)));
            sleep_ms(10); 
        }
        // Movimenta de 180 para 0 graus com decremento de 5μs a cada 10ms
        for (int pulse = 2400; pulse >= 500; pulse -= 5) {
            set_pwm_pulse_width(slice_num, (pulse * (PWM_PERIOD / 20000)));
            sleep_ms(10); 
        }
    }

    return 0;
}
