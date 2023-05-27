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

/** \brief Brief description of the file
 **
 ** Full file description
 **
 ** \addtogroup name Module denomination
 ** \brief Brief description of the module
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "calculadora.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* === Macros definitions ====================================================================== */

#ifndef OPERACIONES
#define OPERACIONES 16
#endif

/* === Private data type declarations ========================================================== */

typedef struct operacion_s {
    char operador;
    funciont_t funcion;
} * operacion_t;

struct calculadora_s {
    struct operacion_s operaciones[OPERACIONES];
};

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

operacion_t BuscarOperacion(calculadora_t calculadora, char operador) {
    operacion_t op = NULL;

    for (int indice = 0; indice < OPERACIONES; indice++) {
        if (calculadora->operaciones[indice].operador == operador) {
            op = &calculadora->operaciones[indice];
            break;
        }
    }
    return op;
}

calculadora_t CrearCalculadora(void) {
    calculadora_t calc = malloc(sizeof(struct calculadora_s));
    if (calc) {
        memset(calc, 0, sizeof(struct calculadora_s));
    }
    return calc;
}

bool AgregarOperacion(calculadora_t calculadora, char operador, funciont_t funcion) {
    operacion_t operacion = BuscarOperacion(calculadora, 0);

    if ((operacion) && !BuscarOperacion(calculadora, operador)) {
        operacion->operador = operador;
        operacion->funcion = funcion;
    }
    return (operacion != NULL);
}

int Calcular(calculadora_t calculadora, char * cadena) {
    int a, b;
    char operador;
    int result = 0;

    for (int indice = 0; indice < strlen(cadena); indice++) {
        if (cadena[indice] < '0') {
            operador = cadena[indice];
            a = atoi(cadena);
            b = atoi(cadena + indice + 1);
            break;
        }
    }

    operacion_t operacion = BuscarOperacion(calculadora, operador);
    if (operacion) {
        result = operacion->funcion(a, b);
    }
    return result;
}

/* === Public function implementation ========================================================== */

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
