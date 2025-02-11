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

** Archivo big_unsigned.h: Declaracion de la clase para representar
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      05/02/2025 - Creacion (primera version) del codigo
**/

#include <iostream>
#include <vector>

class BigUnsigned {
 private:
  std::vector<unsigned char> digits_;
 public:
  // Constructors
  BigUnsigned(unsigned n = 0); 
  BigUnsigned(const unsigned char* );
  BigUnsigned(const BigUnsigned& big_unsigned) : digits_(big_unsigned.getDigits()) {}; // Constructor de copia
  // Getters and setters
  std::vector<unsigned char> getDigits() const {return digits_;}
  void setDigits(const std::vector<unsigned char> digits) {digits_ = digits;}
  // Assignation operator 
  BigUnsigned& operator=(const BigUnsigned&);
  // Insertion and extraction operators
  friend std::ostream& operator<<(std::ostream&, const BigUnsigned&);
  friend std::istream& operator>>(std::istream&, BigUnsigned&);
  // Comparation operators
  friend bool operator<(const BigUnsigned&, const BigUnsigned&);
  // Arithmetic operators 
  friend BigUnsigned operator+(const BigUnsigned&, const BigUnsigned&);
  BigUnsigned operator-(const BigUnsigned&) const;
  BigUnsigned operator*(const BigUnsigned&) const;
  BigUnsigned operator%(const BigUnsigned&) const;
  friend BigUnsigned operator/(const BigUnsigned&, const BigUnsigned&);
  // Auxiliar methods
  void AddDigit (unsigned char digit) {digits_.push_back(digit);}
  void Clear() {digits_.clear();}
  void ProcessZeros();
};

// Comparation operators
bool operator==(const BigUnsigned&, const BigUnsigned&);
bool operator>=(const BigUnsigned& big_unsigned_1, const BigUnsigned& big_unsigned_2);
// Increment/Decrement operators
BigUnsigned& operator++(BigUnsigned&); // Pre-incremento
BigUnsigned operator++(BigUnsigned&, int); // Post-incremento
BigUnsigned& operator--(BigUnsigned&); // Pre-decremento
BigUnsigned operator--(BigUnsigned&, int); // Post-decremento

