#include "ring_buffer.h"

/**
 * @brief Inicializa un ring buffer con un buffer externo y una capacidad dada.
 * @param rb Puntero a la estructura del ring buffer a inicializar.
 * @param buffer Puntero al buffer externo a utilizar para el ring buffer.
 * @param capacity La capacidad total del ring buffer.
*/
void ring_buffer_init(ring_buffer_t *rb, uint8_t *buffer, uint16_t capacity) 
{
    rb->buffer = buffer;
    rb->capacity = capacity;
    rb->head = 0;
    rb->tail = 0;
    rb->is_full = false; // Inicialmente el buffer no está lleno
}

/**
 * @brief Escribe un dato en el ring buffer, descarta los datos más antiguos si el buffer está lleno.
 * @param rb Puntero a la estructura del ring buffer.
 * @param data El dato a escribir en el buffer.
 * @return true si se escribió el dato correctamente, false si el buffer está lleno.
 */
bool ring_buffer_write(ring_buffer_t *rb, uint8_t data)
{
    if (rb->is_full) {
        // Si el buffer está lleno, sobrescribimos el dato más antiguo
        rb->tail = (rb->tail + 1) % rb->capacity; // Avanzamos la cola
    }
    
    rb->buffer[rb->head] = data; // Escribimos el dato en la cabeza
    rb->head = (rb->head + 1) % rb->capacity; // Avanzamos la cabeza

    // Verificamos si el buffer está lleno
    if (rb->head == rb->tail) {
        rb->is_full = true; // El buffer está lleno
    }

    return true;
}

/**
 * @brief Lee un dato del ring buffer.
 * @param rb Puntero a la estructura del ring buffer.
 * @param data Puntero donde se almacenará el dato leído.
 * @return true si se leyó el dato correctamente, false si el buffer está vacío.
 */
bool ring_buffer_read(ring_buffer_t *rb, uint8_t *data)
{
    if (rb->head == rb->tail && !rb->is_full) {
        // Buffer vacío
        return false;
    }
    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % rb->capacity;
    rb->is_full = false; // Al leer, el buffer no puede estar lleno
    return true;
}

/**
 * @brief Retorna la cantidad de elementos almacenados en el ring buffer.
 * @param rb Puntero a la estructura del ring buffer.
 * @return La cantidad de elementos en el buffer.
 */
uint16_t ring_buffer_count(ring_buffer_t *rb)
{
    if (rb->is_full) {
        return rb->capacity; // Si está lleno, retornamos la capacidad total
    }
    if (rb->head >= rb->tail) {
        return rb->head - rb->tail;
    } else {
        return rb->capacity - rb->tail + rb->head;
    }
}

/**
 * @brief Verifica si el ring buffer está vacío.
 * @param rb Puntero a la estructura del ring buffer.
 * @return true si el buffer está vacío, false en caso contrario.
 */
bool ring_buffer_is_empty(ring_buffer_t *rb)
{
    return (rb->head == rb->tail);
}

/**
 * @brief Verifica si el ring buffer está lleno.
 * @param rb Puntero a la estructura del ring buffer.
 * @return true si el buffer está lleno, false en caso contrario.
 */
bool ring_buffer_is_full(ring_buffer_t *rb)
{
    return (((rb->head + 1) % rb->capacity) == rb->tail);
}

/**
 * @brief Limpia el contenido del ring buffer, dejándolo vacío.
 * @param rb Puntero a la estructura del ring buffer.
 */
void ring_buffer_flush(ring_buffer_t *rb)
{
    rb->head = 0;
    rb->tail = 0;
}