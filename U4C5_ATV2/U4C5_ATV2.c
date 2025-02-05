#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define BLUE_LED 11
#define GREEN_LED 12
#define RED_LED 13

#define BUTTON 5

volatile bool led_sequence_active = false; // Impede múltiplas ativações do botão

// Callback para desligar o LED vermelho e manter apenas o azul aceso
int64_t turn_off_red_callback(alarm_id_t id, void *user_data) {
    gpio_put(RED_LED, 0);
    return 0;
}

// Callback para desligar o LED azul e manter apenas o verde aceso
int64_t turn_off_blue_callback(alarm_id_t id, void *user_data) {
    gpio_put(BLUE_LED, 0);
    return 0;
}

// Callback para desligar o LED verde e liberar o botão
int64_t turn_off_green_callback(alarm_id_t id, void *user_data) {
    gpio_put(GREEN_LED, 0);
    led_sequence_active = false; // Libera o botão para uma nova ativação
    return 0;
}

void button_callback(uint gpio, uint32_t events) {
    if (!led_sequence_active) { // Garante que o botão só funcione quando permitido
        led_sequence_active = true;
        gpio_put(BLUE_LED, 1);
        gpio_put(RED_LED, 1);
        gpio_put(GREEN_LED, 1);
        
        // Dispara os temporizadores para desligamento progressivo dos LEDs
        add_alarm_in_ms(3000, turn_off_red_callback, NULL, false);
        add_alarm_in_ms(6000, turn_off_blue_callback, NULL, false);
        add_alarm_in_ms(9000, turn_off_green_callback, NULL, false);
    }
}

int main() {
    stdio_init_all();
    
    // Configuração dos LEDs
    gpio_init(BLUE_LED);
    gpio_set_dir(BLUE_LED, GPIO_OUT);
    gpio_put(BLUE_LED, 0);
    
    gpio_init(RED_LED);
    gpio_set_dir(RED_LED, GPIO_OUT);
    gpio_put(RED_LED, 0);
    
    gpio_init(GREEN_LED);
    gpio_set_dir(GREEN_LED, GPIO_OUT);
    gpio_put(GREEN_LED, 0);
    
    // Configuração do botão
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_RISE, true, button_callback);
    
    while (1) {
        sleep_ms(100); // Pequeno atraso para evitar sobrecarga
    }
    
    return 0;
}
