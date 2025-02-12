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
**      12/02/2025 - Finalizacion del codigo
**/


#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include "big_unsigned.h"

class BigInteger {
 private:
  BigUnsigned module_;
  bool sign_; // 1 if positive, 0 if negative
 public:
  // Constructors
  BigInteger(int n = 0);
  BigInteger(const BigUnsigned& module, bool sign = 1) : module_(module), sign_(sign) {};
  // Getters
  const BigUnsigned getModule() const {return module_;}
  const bool getSign() const {return sign_;}
  // Setters
  void setModule(const BigUnsigned& module) {module_ = module;}
  void setSign(const bool sign) {sign_ = sign;}
  // Assignation operator 
  BigInteger& operator=(const BigInteger&);
  // Insertion and extraction operators
  friend std::ostream& operator<<(std::ostream&, const BigInteger&);
  friend std::istream& operator>>(std::istream&, BigInteger&);
  // Comparation operators
  friend bool operator<(const BigInteger&, const BigInteger&);
  // Arithmetic operators 
  friend BigInteger operator+(const BigInteger&, const BigInteger&);
  BigInteger operator-(const BigInteger&) const;
  BigInteger operator*(const BigInteger&) const;
  BigInteger operator%(const BigInteger&) const;
  friend BigInteger operator/(const BigInteger&, const BigInteger&);
  BigInteger mcd(const BigInteger&, const BigInteger&) const;
};


// Comparation operators
bool operator==(const BigInteger&, const BigInteger&);
bool operator>=(const BigInteger& big_unsigned_1, const BigInteger& big_unsigned_2);
// Increment/Decrement operators
BigInteger& operator++(BigInteger&); // Pre-incremento
BigInteger operator++(BigInteger&, int); // Post-incremento
BigInteger& operator--(BigInteger&); // Pre-decremento
BigInteger operator--(BigInteger&, int); // Post-decremento

#endif