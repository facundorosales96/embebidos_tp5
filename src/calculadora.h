/************************************************************************************************
Copyright (c) 2023, Rosales Facundo Ezequiel <facundoerosales@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

#ifndef CALCULADORA_H
#define CALCULADORA_H

/** \brief Calculadora dinamica
 **
 ** \addtogroup calculadora CALCULADORA
 ** @{ */

/* === Headers files inclusions ================================================================ */
#include <stdbool.h>
#include <stdint.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */
/**
 * @brief Puntero a la estructura calculadora
 */
typedef struct calculadora_s * calculadora_t;

/**
 * @brief Puntero a la estructura operacion
 */
typedef struct operacion_s * operacion_t;

/**
 * @brief Tipo de dato que representa un puntero a una función de callback
 */
typedef int (*funciont_t)(int, int);

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * @brief Crea una instancia de una calculadora dinamica
 *
 * @return calculadora_t
 */
calculadora_t CrearCalculadora(void);

/**
 * @brief Busca una operacion en la calculadora
 *
 * @param calculadora calculadora en la cual buscar la operacion
 * @param operador caracter que representa la operacion
 * @return instancia de la operación encontrada, representada por un puntero de tipo operacion_t
 */
operacion_t BuscarOperacion(calculadora_t calculadora, char operador);

/**
 * @brief Agrega una operacion a la calculadora
 *
 * @param calculadora puntero a la calculadora a la cual agregar la operacion
 * @param operador caracter que representa la operacion
 * @param funcion funcion que realiza la operacion
 * @return true la operacion se agrego correctamente
 * @return false no se pudo agregar la operacion
 */

bool AgregarOperacion(calculadora_t calculadora, char operador, funciont_t funcion);

/**
 * @brief Realiza el calculo de una operacion
 *
 * @param calculadora puntero a la calculadora en la cual realiza el calculo
 * @param cadena expresion matematica a calcular
 * @return int resultado del calculo
 */

int Calcular(calculadora_t calculadora, char * cadena);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif /* CALCULADORA_H */
