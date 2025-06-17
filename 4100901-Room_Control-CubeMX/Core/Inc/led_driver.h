#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <stdint.h>
#include "main.h"

// Se muestra un Led conectado a un puerto y un pin específico
typedef struct {
    GPIO_TypeDef *port; //Puerto GPIO al que está conectado el LED
    uint16_t pin;       //Pin GPIO al que está conectado el LED
} led_handle_t;

// Inicializa el LED
void led_init(led_handle_t *led);

// Enciende el LED (pone pin en alto)
void led_on(led_handle_t *led);

// Apaga el LED (pone pin en bajo)
void led_off(led_handle_t *led);

// Cambia el estado del LED (enciende si está apagado, apaga si está encendido)
void led_toggle(led_handle_t *led);

#endif // LED_DRIVER_H