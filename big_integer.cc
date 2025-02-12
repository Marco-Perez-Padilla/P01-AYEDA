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

** Archivo big_integer.cc: Implementacion de la clase para representar
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      05/02/2025 - Creacion (primera version) del codigo
**/

#include "big_integer.h"


BigInteger::BigInteger(int numero) {
  if (numero == 0) {
    module_.AddDigit(0);
  } else {
    if (numero < 0) {
      numero = numero * (-1);
      while (numero > 0) {
        unsigned char digit = static_cast<char>(numero % 10);
        module_.AddDigit(digit);
        numero /= 10;
      }
      sign_ = 0;
    } else {
      while (numero > 0) {
        unsigned char digit = static_cast<char>(numero % 10);
        module_.AddDigit(digit);
        numero /= 10;
      }
    }
  }
}


BigInteger& BigInteger::operator=(const BigInteger& big_integer) {
  if (this != &big_integer) {
    module_ = big_integer.getModule();
    sign_ = big_integer.getSign();
  }
  return *this;
}


std::ostream& operator<<(std::ostream& os, const BigInteger& num) {
  if (num.getModule().getDigits().empty()) {
    os << '0';
  } else {
    if (num.getSign() == 0) {
      os << "-";
    }
    for (int i {num.getModule().getDigits().size() - 1}; i >= 0; --i) {
      int digit = num.getModule().getDigits()[i];
      os << digit;
    }
  }
  return os;
}



std::istream& operator>>(std::istream& is, BigInteger& num) {
  std::string input;
  is >> input;
  bool negative = false;
  if (!(input.empty()) && input[0] == '-') {
    negative = true;
    input.erase(0, 1);
  }
  num = BigInteger(BigUnsigned(reinterpret_cast<const unsigned char*>(input.data())), negative);
  return is;
}



bool operator<(const BigInteger& big_integer_1, const BigInteger& big_integer_2) {
  if (big_integer_1.getSign() == 0 && big_integer_2.getSign() == 0) {
    return !(big_integer_1.getModule() < big_integer_2.getModule());
  } else if (big_integer_1.getSign() == 1 && big_integer_2.getSign() == 1) {
    return big_integer_1.getModule() < big_integer_2.getModule();
  } else if (big_integer_1.getSign() == 0 && big_integer_2.getSign() == 1) {
    return true;
  } else {
    return false;
  }
}


bool operator==(const BigInteger& big_integer_1, const BigInteger& big_integer_2) {
  if (big_integer_1.getSign() == big_integer_2.getSign() && big_integer_1.getModule() == big_integer_2.getModule()) {
    return true;
  } else {
    return false;
  }
}



bool operator>=(const BigInteger& big_integer_1, const BigInteger& big_integer_2) {
  return !(big_integer_1 < big_integer_2) || (big_integer_1 == big_integer_2);
}


BigInteger operator+(const BigInteger& big_integer_1, const BigInteger& big_integer_2) {
  if (big_integer_1.getSign() == 0 && big_integer_2.getSign() == 0) {
    BigUnsigned sum = big_integer_1.getModule() + big_integer_2.getModule();
    BigInteger result (sum, 0);
    return result;
  } else if (big_integer_1.getSign() == 1 && big_integer_2.getSign() == 1) {
    BigUnsigned sum = big_integer_1.getModule() + big_integer_2.getModule();
    BigInteger result (sum, 1);
    return result;
  } else if (big_integer_1.getSign() == 0 && big_integer_2.getSign() == 1) {
    if (big_integer_1.getModule() >= big_integer_2.getModule()) {
      BigUnsigned sum = big_integer_1.getModule() - big_integer_2.getModule();
      BigInteger result (sum, 0);
      return result;
    } else {
      BigUnsigned sum = big_integer_2.getModule() - big_integer_1.getModule();
      BigInteger result (sum, 1);
      return result;
    }
  } else {
    if (big_integer_1.getModule() >= big_integer_2.getModule()) {
      BigUnsigned sum = big_integer_1.getModule() - big_integer_2.getModule();
      BigInteger result (sum, 1);
      return result;
    } else {
      BigUnsigned sum = big_integer_2.getModule() - big_integer_1.getModule();
      BigInteger result (sum, 0);
      return result;
    }
  }
}


BigInteger BigInteger::operator-(const BigInteger& big_integer_2) const {
  if (sign_ == 0 && big_integer_2.getSign() == 0) {
    BigInteger seg_term (big_integer_2.getModule(), 1);
    BigInteger result = *this + seg_term;
    return result;
  } else if (sign_ == 1 && big_integer_2.getSign() == 1) {
    if (module_ >= big_integer_2.getModule()) {
      BigUnsigned sum = module_ - big_integer_2.getModule();
      BigInteger result (sum, 1);
      return result;
    } else {
      BigUnsigned sum = big_integer_2.getModule() - module_;
      BigInteger result (sum, 0);
      return result;
    }
  } else if (sign_ == 0 && big_integer_2.getSign() == 1) {
    BigUnsigned sum = module_ + big_integer_2.getModule();
    BigInteger result (sum, 0);
    return result;
  } else {
    BigInteger seg_term (big_integer_2.getModule(), 1);
    BigInteger result = *this + seg_term;
    return result;
  }
}


BigInteger& operator++(BigInteger& big_integer_1) {
  BigInteger unit (1);
  big_integer_1 = big_integer_1 + unit;
  return big_integer_1;
}




BigInteger operator++(BigInteger& big_integer_1, int) {
  BigInteger post_integer = big_integer_1;
  BigInteger unit (1);
  big_integer_1 = big_integer_1 + unit;
  return post_integer;
}



BigInteger& operator--(BigInteger& big_integer_1) {
  BigInteger unit (1);
  big_integer_1 = big_integer_1 - unit;
  return big_integer_1;
}




BigInteger operator--(BigInteger& big_integer_1, int) {
  BigInteger post_integer = big_integer_1;
  BigInteger unit (1);
  big_integer_1 = big_integer_1 - unit;
  return post_integer;
}



BigInteger BigInteger::operator%(const BigInteger& big_integer) const {
  BigUnsigned mod = module_ % big_integer.getModule();
  BigInteger result (mod, 1);
  return result;
}


BigInteger BigInteger::operator*(const BigInteger& mult) const {
  BigUnsigned prod = module_ * mult.getModule();
  if ((sign_ == 0 && mult.getSign() == 0) || (sign_ == 1 && mult.getSign() == 1)) {
    BigInteger result (prod, 1);
    return result;
  } else {
    BigInteger result (prod, 0);
    return result;
  }
}


BigInteger operator/(const BigInteger& big_integer_1, const BigInteger& big_integer_2) {
  BigUnsigned div = big_integer_1.getModule() / big_integer_2.getModule();
  if ((big_integer_1.getSign() == 0 && big_integer_2.getSign() == 0) || (big_integer_1.getSign() == 1 && big_integer_2.getSign() == 1)) {
    BigInteger result (div, 1);
    return result;
  } else {
    BigInteger result (div, 0);
    return result;
  }
}
