#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define LED_BLUE_PIN 12 // Usado para teste de PWM na BitDogLab
#define SERVO_PIN 22  // GPIO 22 para controle do servo motor no simulador Wokwi

// Frequência de PWM (50Hz)
#define PWM_FREQ 50
// Período de 20ms (50Hz)
#define PWM_PERIOD 20000
// Função para calcular o valor de wrap (máximo de contagem)
#define WRAP_VALUE (PWM_PERIOD - 1)

void set_pwm_pulse_width(uint slice_num, uint pulse_width) {
    pwm_set_gpio_level(SERVO_PIN, pulse_width);
}

int main() {
    stdio_init_all();

    // Configure o pino para saída PWM
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);

    // Encontre o slice PWM associado ao pino
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);


    // Configure o intervalo de contagem PWM para 50Hz
    pwm_set_clkdiv(slice_num, (float)125.0);  // Divisor de clock para 50Hz

    // Defina o valor de wrap para o período de 20ms
    pwm_set_wrap(slice_num, WRAP_VALUE);

    // Inicialize o PWM
    pwm_set_enabled(slice_num, true);

    // Muda pra 180 graus (2.400μs de pulso)
    set_pwm_pulse_width(slice_num, (2400 * (PWM_PERIOD / 20000)));
    sleep_ms(5000);  // Aguarde 5 segundos

    // Muda pra 90 graus (1.470μs de pulso)
    set_pwm_pulse_width(slice_num, (1470 * (PWM_PERIOD / 20000)));
    sleep_ms(5000);  // Aguarde 5 segundos

    // volta para 0 graus (500μs de pulso)
    set_pwm_pulse_width(slice_num, (500 * (PWM_PERIOD / 20000)));
    sleep_ms(5000);  // Aguarde 5 segundos

    // Por ultimo se move entre 0 e 180 graus 
    while (true) {
        // Movimento de 0 a 180 graus
        for (int pulse = 500; pulse <= 2400; pulse += 5) {
            set_pwm_pulse_width(slice_num, (pulse * (PWM_PERIOD / 20000)));
            sleep_ms(10); 
        }
        // Movimento de 180 a 0 graus
        for (int pulse = 2400; pulse >= 500; pulse -= 5) {
            set_pwm_pulse_width(slice_num, (pulse * (PWM_PERIOD / 20000)));
            sleep_ms(10); 
        }
    }

    return 0;
}