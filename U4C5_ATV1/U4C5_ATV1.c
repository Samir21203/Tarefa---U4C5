#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define RED_LED 13
#define BLUE_LED 12
#define GREEN_LED 11

volatile int estado = 0; // 0: vermelho, 1: amarelo, 2: verde

bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs
    gpio_put(RED_LED, 0);
    gpio_put(BLUE_LED, 0);
    gpio_put(GREEN_LED, 0);
    
    // Liga o LED correspondente ao estado atual
    switch (estado) {
        case 0:
            gpio_put(RED_LED, 1);
            break;
        case 1:
            gpio_put(BLUE_LED, 1);
            break;
        case 2:
            gpio_put(GREEN_LED, 1);
            break;
    }
    
    // Alterna para o próximo estado
    estado = (estado + 1) % 3;
    return true; // Mantém o timer repetindo
}

int main() {
    stdio_init_all();
    
    // Configuração dos GPIOs como saída
    gpio_init(RED_LED);
    gpio_set_dir(RED_LED, GPIO_OUT);
    gpio_init(BLUE_LED);
    gpio_set_dir(BLUE_LED, GPIO_OUT);
    gpio_init(GREEN_LED);
    gpio_set_dir(GREEN_LED, GPIO_OUT);
    
    // Inicializa com o LED vermelho ligado
    gpio_put(RED_LED, 1);
    
    // Criação do temporizador de 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    
    while (1) {
        printf("Semáforo ativo. Estado atual: %d\n", estado);
        sleep_ms(1000); // Aguarda 1 segundo antes da próxima impressão
    }
    
    return 0;
}
