#include "led_driver.h"

/**
 * @brief Inicializa el LED (pone pin en bajo).
 * @param led Puntero a la estructura del LED a inicializar.
 */
void led_init(led_handle_t *led) {
    HAL_GPIO_WritePin(led->port, led->pin, GPIO_PIN_RESET);
}

/**
 * @brief Enciende el LED (pone pin en alto).
 * @param led Puntero a la estructura del LED a encender.
 */
void led_on(led_handle_t *led) {
    HAL_GPIO_WritePin(led->port, led->pin, GPIO_PIN_SET);
}

/**
 * @brief Apaga el LED (pone pin en bajo).
 * @param led Puntero a la estructura del LED a apagar.
 */
void led_off(led_handle_t *led) {
    HAL_GPIO_WritePin(led->port, led->pin, GPIO_PIN_RESET);
}

/**
 * @brief Cambia el estado del LED (enciende si está apagado, apaga si está encendido).
 * @param led Puntero a la estructura del LED cuyo estado se va a cambiar.
 */
void led_toggle(led_handle_t *led) {
    HAL_GPIO_TogglePin(led->port, led->pin);
}
