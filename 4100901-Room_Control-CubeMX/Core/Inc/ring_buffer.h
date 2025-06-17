#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

// Estructura que representa un ring buffer (buffer circular)
typedef struct {
    uint8_t *buffer;     // Puntero al arreglo de datos
    uint16_t head;       // Índice de escritura (cabeza)
    uint16_t tail;       // Índice de lectura (cola)
    uint16_t capacity;   // Capacidad total del buffer
    bool is_full;        // Indica si el buffer está lleno
} ring_buffer_t;

// Inicializa el ring buffer con un buffer externo y capacidad dada
void ring_buffer_init(ring_buffer_t *rb, uint8_t *buffer, uint16_t capacity);

// Escribe un dato en el ring buffer. Retorna true si tuvo éxito, false si está lleno
bool ring_buffer_write(ring_buffer_t *rb, uint8_t data);

// Lee un dato del ring buffer. Retorna true si tuvo éxito, false si está vacío
bool ring_buffer_read(ring_buffer_t *rb, uint8_t *data);

// Retorna la cantidad de elementos almacenados en el buffer
uint16_t ring_buffer_count(ring_buffer_t *rb);

// Retorna true si el buffer está vacío
bool ring_buffer_is_empty(ring_buffer_t *rb);

// Retorna true si el buffer está lleno
bool ring_buffer_is_full(ring_buffer_t *rb);

// Limpia el contenido del buffer (lo deja vacío)
void ring_buffer_flush(ring_buffer_t *rb);

#endif // RING_BUFFER_H
