/**
** Universidad de La Laguna
** Escuela Superior de Ingenieria y Tecnologia
** Grado en Ingenieria Informatica
** Asignatura: Algoritmos y Estructuras de Datos Avanzadas
** Curso: 2º
** Practica 1: Representación de números grandes
** Autor: Marco Pérez Padilla
** Correo: alu0101469348@ull.edu.es
** Fecha: 05/02/2025

** Archivo p01_big_numbers.cc: programa cliente.
**      Contiene la funcion main del proyecto que usa las clases 
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      05/02/2025 - Creacion (primera version) del codigo
**      12/02/2025 - Version final del codigo
**/

#include <iostream>

#include "big_unsigned.h"
#include "big_integer.h"
#include "check_functions.h"

int main (int argc, char* argv[]) {
  ValidateCommand(argc, argv);

  std::cout << "Comprobaciones para Big Unsigned." << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "Caso en que el numerador es mayor al denominador: " << std::endl;
  std::cout << std::endl;

  BigUnsigned prueba_unsigned_1 (8);
  BigUnsigned prueba_unsigned_2 (7);

  std::cout << "Suma: " << prueba_unsigned_1 << "+" << prueba_unsigned_2 << " = " << prueba_unsigned_1 + prueba_unsigned_2 << std::endl;
  std::cout << "Resta: " << prueba_unsigned_1 << "-" << prueba_unsigned_2 << " = " << prueba_unsigned_1 - prueba_unsigned_2 << std::endl;
  std::cout << "Multiplicación: " << prueba_unsigned_1 << "*" << prueba_unsigned_2 << " = " << prueba_unsigned_1 * prueba_unsigned_2 << std::endl;
  std::cout << "División: " << prueba_unsigned_1 << "/" << prueba_unsigned_2 << " = " << prueba_unsigned_1 / prueba_unsigned_2 << std::endl;
  std::cout << "Módulo: " << prueba_unsigned_1 << "%" << prueba_unsigned_2 << " = " << prueba_unsigned_1 % prueba_unsigned_2 << std::endl;

  std::cout << std::endl;
  std::cout << "Introduzca dos números para el caso en que el numerador es menor al denominador: " << std::endl;
  std::cout << std::endl;

  BigUnsigned prueba_unsigned_3;
  std::cout << "Numerador: ";
  std::cin >> prueba_unsigned_3;
  BigUnsigned prueba_unsigned_4;
  std::cout << "Denominador: ";
  std::cin >> prueba_unsigned_4;

  std::cout << "Suma: " << prueba_unsigned_3 << "+" << prueba_unsigned_4 << " = " << prueba_unsigned_3 + prueba_unsigned_4 << std::endl;
  std::cout << "Resta: " << prueba_unsigned_3 << "-" << prueba_unsigned_4 << " = " << prueba_unsigned_3 - prueba_unsigned_4 << std::endl;
  std::cout << "Multiplicación: " << prueba_unsigned_3 << "*" << prueba_unsigned_4 << " = " << prueba_unsigned_3 * prueba_unsigned_4 << std::endl;
  std::cout << "División: " << prueba_unsigned_3 << "/" << prueba_unsigned_4 << " = " << prueba_unsigned_3 / prueba_unsigned_4 << std::endl;
  std::cout << "Módulo: " << prueba_unsigned_3 << "%" << prueba_unsigned_4 << " = " << prueba_unsigned_3 % prueba_unsigned_4 << std::endl;

  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "Comprobaciones para Big Integer." << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "Introduzca dos números BigInteger para realizar las comprobaciones: " << std::endl;
  std::cout << "  Casos posibles: " << std::endl;
  std::cout << "    - Numerador mayor que denominador, ambos positivos" << std::endl;
  std::cout << "    - Numerador mayor que denominador, ambos negativos" << std::endl;
  std::cout << "    - Numerador mayor que denominador, uno de ellos negativo, otro positivo" << std::endl;
  std::cout << "    - Numerador menor que denominador, ambos positivos" << std::endl;
  std::cout << "    - Numerador menor que denominador, ambos negativos" << std::endl;
  std::cout << "    - Numerador mayor que denominador, uno de ellos negativo, otro positivo" << std::endl;

  std::cout << std::endl;

  BigInteger numerador;
  std::cout << "Numerador: ";
  std::cin >> numerador;
  BigInteger denominador;
  std::cout << "Denominador: ";
  std::cin >> denominador;

  std::cout << std::endl;

  std::cout << "Suma: " << numerador << "+" << denominador << " = " << numerador + denominador << std::endl;
  std::cout << "Resta: " << numerador << "-" << denominador << " = " << numerador - denominador << std::endl;
  std::cout << "Multiplicación: " << numerador << "*" << denominador << " = " << numerador * denominador << std::endl;
  std::cout << "División: " << numerador << "/" << denominador << " = " << numerador / denominador << std::endl;
  std::cout << "Módulo: " << numerador << "%" << denominador << " = " << numerador % denominador << std::endl;
  std::cout << "Máximo común divisor: " << "mod(" << numerador << ", " << denominador << ") " << " = " << numerador.mcd(numerador, denominador) << std::endl;

  std::cout << std::endl;

  return 0;
}