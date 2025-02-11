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

** Archivo big_integer.h: Declaracion de la clase para representar
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      05/02/2025 - Creacion (primera version) del codigo
**/

#include "big_unsigned.h"

class BigInteger {
 private:
  BigUnsigned number_;
  bool sign_; // 1 if negative, 0 if positive
 public:

 // Getters
 const BigUnsigned getNumber() const {return number_;}
 const bool getSign() const {return sign_;}
 // Setters
 void setNumber(const BigUnsigned& number) {number_ = number;}
 void setSign(const bool sign) {sign_ = sign;}
};