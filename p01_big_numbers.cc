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
**/

#include <iostream>

#include "big_unsigned.h"
#include "check_functions.h"

int main (int argc, char* argv[]) {
  ValidateCommand(argc, argv);

  BigUnsigned s;

  std::cout << "s: ";
  std::cin >> s;

  BigUnsigned s2;

  std::cout << "s2: ";
  std::cin >> s2;
  std::cout << s2 << std::endl;
  

  std::cout << std::endl;

  BigUnsigned result = s / s2;


  std::cout << result << std::endl;

  return 0;
}