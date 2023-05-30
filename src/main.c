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

/** \brief Implementacion de un programa de una Calculadora dinamica
 **
 ** Este archivo contiene la implementacion de una calculadora dinamica,la cual realiza
 ** operaciones de suma, resta y multiplicacion.
 **
 ** \addtogroup calculadora CALCULADORA
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "calculadora.h"
#include <stdio.h>

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

int suma(int a, int b);     //! Funcion para la suma
int resta(int a, int b);    //! Funcion para la resta
int producto(int a, int b); //! Funcion para la multiplicacion

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */
/**
 * @brief Realiza la suma de dos numeros enteros
 *
 * @param a primer entero a sumar
 * @param b segundo entero a sumar
 * @return resultado de la suma
 */

int suma(int a, int b) {
    return (a + b);
}
/**
 * @brief Realiza la resta de dos numeros enteros
 *
 * @param a primer numero entero
 * @param b segundo numero entero
 * @return resultado de la resta
 */

int resta(int a, int b) {
    return (a - b);
}
/**
 * @brief Realiza la multiplicacion de dos numeros enteros
 *
 * @param a primer numero entero
 * @param b segundo numero entero
 * @return resultado de la multiplicacion
 */

int producto(int a, int b) {
    return (a * b);
}

int main(void) {

    int resultado;

    //! Crea una instancia de la calculadora

    calculadora_t calculadora = CrearCalculadora();

    //! Agrega las operacioes a la calculadora

    AgregarOperacion(calculadora, '+', suma);
    AgregarOperacion(calculadora, '-', resta);
    AgregarOperacion(calculadora, '*', producto);

    printf("==== Dados los numeros: 5 y 3 =====\r\n");

    resultado = Calcular(calculadora, "5+3");
    printf("La suma es %i\r\n", resultado);

    resultado = Calcular(calculadora, "5-3");
    printf("La resta es %i\r\n", resultado);

    resultado = Calcular(calculadora, "5*3");
    printf("El producto es %i\r\n", resultado);
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
