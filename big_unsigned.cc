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

** Archivo big_unsigned.cc: Implementacion de la clase para representar
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      05/02/2025 - Creacion (primera version) del codigo
**/

#include "big_unsigned.h"


BigUnsigned::BigUnsigned(unsigned numero) {
  if (numero == 0) {
    digits_.push_back(0);
  } else {
    while (numero > 0) {
      unsigned char digit = static_cast<char>(numero % 10);
      digits_.push_back(digit);
      numero /= 10;
    }
  }
}



BigUnsigned::BigUnsigned(const unsigned char* char_array) {
  std::vector<unsigned char> temp_digits;
  unsigned i {0};
  while (char_array[i] != '\0') {
    if (char_array[i] < '0' || char_array[i] > '9') {
      std::cerr << "md" << std::endl;
      return;
    } else {
      unsigned char digit = char_array[i] - '0';;
      temp_digits.push_back(digit);
      ++i;
    }
  }

  for (int j = temp_digits.size() - 1; j >= 0; j--) {
    digits_.push_back(temp_digits[j]);
  }
}



BigUnsigned& BigUnsigned::operator=(const BigUnsigned& big_unsigned) {
  if (this != &big_unsigned) {
    digits_ = big_unsigned.getDigits();
  }
  return *this;
}



std::ostream& operator<<(std::ostream& os, const BigUnsigned& num) {
  if (num.getDigits().empty()) {
    os << '0';
  } else {
    for (int i {num.getDigits().size() - 1}; i >= 0; --i) {
      int digit = num.getDigits()[i];
      os << digit;
    }
  }
  return os;
}



std::istream& operator>>(std::istream& is, BigUnsigned& num) {
  std::string input;
  is >> input;
  num = BigUnsigned(reinterpret_cast<const unsigned char*>(input.data()));
  return is;
}



bool operator<(const BigUnsigned& big_unsigned_1, const BigUnsigned& big_unsigned_2) {
  if (big_unsigned_1.getDigits().size() != big_unsigned_2.getDigits().size()) {
    return big_unsigned_1.getDigits().size() < big_unsigned_2.getDigits().size();
  } else {
    for (int i = big_unsigned_1.getDigits().size() - 1; i >= 0; --i) {
      if (big_unsigned_1.getDigits()[i] < big_unsigned_2.getDigits()[i]) {
        return true;
      } else if (big_unsigned_1.getDigits()[i] > big_unsigned_2.getDigits()[i]) {
        return false;
      }
    }
    return false;
  }
}


bool operator==(const BigUnsigned& big_unsigned_1, const BigUnsigned& big_unsigned_2) {
  if (big_unsigned_1.getDigits().size() != big_unsigned_2.getDigits().size()) {
    return false;
  } else {
    for (long unsigned int i {0}; i < big_unsigned_1.getDigits().size(); ++i) {
      if (big_unsigned_1.getDigits()[i] != big_unsigned_2.getDigits()[i]) {
        return false;
      } 
    }
    return true;
  }
}


bool operator>=(const BigUnsigned& big_unsigned_1, const BigUnsigned& big_unsigned_2) {
  return !(big_unsigned_1 < big_unsigned_2) || (big_unsigned_1 == big_unsigned_2);
}


void BigUnsigned::ProcessZeros() {
  while (digits_.size() > 1 && digits_.back() == 0) {
    digits_.pop_back();
  }
}


BigUnsigned operator+(const BigUnsigned& big_unsigned_1, const BigUnsigned& big_unsigned_2) {
  BigUnsigned result;
  result.digits_.clear();
  bool carry = 0;
  if (big_unsigned_1.getDigits().size() == big_unsigned_2.getDigits().size()) {
    for (unsigned int i {0}; i < big_unsigned_1.getDigits().size(); ++i) {
      int partial_result = carry;
      partial_result += big_unsigned_1.getDigits()[i] + big_unsigned_2.getDigits()[i];
      if (partial_result / 10 == 1) {
        result.digits_.push_back(partial_result % 10);
        carry = 1;
      } else {
        result.digits_.push_back(partial_result % 10);
        carry = 0;
      }
    }
    if (carry) {
      result.digits_.push_back(carry);
    }
  }
  else if (big_unsigned_1.getDigits().size() > big_unsigned_2.getDigits().size()) {
    unsigned int i {0};
    while (i < big_unsigned_2.getDigits().size()) {
      int partial_result = carry;
      partial_result += big_unsigned_1.getDigits()[i] + big_unsigned_2.getDigits()[i];
      if (partial_result / 10 == 1) {
        result.digits_.push_back(partial_result % 10);
        carry = 1;
      } else {
        result.digits_.push_back(partial_result % 10);
        carry = 0;
      }
      ++i;
    }
    while (i < big_unsigned_1.getDigits().size()) {
      int partial_result = carry;
      partial_result += big_unsigned_1.getDigits()[i];
      if (partial_result / 10 == 1) {
        result.digits_.push_back(partial_result % 10);
        carry = 1;
      } else {
        result.digits_.push_back(partial_result % 10);
        carry = 0;
      }
      ++i;
    }

    if (carry) {
      result.digits_.push_back(carry);
    }
  } else {
    unsigned int i {0};
    while (i < big_unsigned_1.getDigits().size()) {
      int partial_result = carry;
      partial_result += big_unsigned_1.getDigits()[i] + big_unsigned_2.getDigits()[i];
      if (partial_result / 10 == 1) {
        result.digits_.push_back(partial_result % 10);
        carry = 1;
      } else {
        result.digits_.push_back(partial_result % 10);
        carry = 0;
      }
      ++i;
    }
    while (i < big_unsigned_2.getDigits().size()) {
      int partial_result = carry;
      partial_result += big_unsigned_2.getDigits()[i];
      if (partial_result / 10 == 1) {
        result.digits_.push_back(partial_result % 10);
        carry = 1;
      } else {
        result.digits_.push_back(partial_result % 10);
        carry = 0;
      }
      ++i;
    }
    
    if (carry) {
      result.digits_.push_back(carry);
    }
  }
  result.ProcessZeros();
  return result;
}



BigUnsigned& operator++(BigUnsigned& big_unsigned_1) {
  BigUnsigned unit (1);
  big_unsigned_1 = big_unsigned_1 + unit;
  return big_unsigned_1;
}




BigUnsigned operator++(BigUnsigned& big_unsigned_1, int) {
  BigUnsigned post_unsigned = big_unsigned_1;
  BigUnsigned unit (1);
  big_unsigned_1 = big_unsigned_1 + unit;
  return post_unsigned;
}



BigUnsigned BigUnsigned::operator-(const BigUnsigned& big_unsigned_2) const {
  BigUnsigned result;
  if (*this < big_unsigned_2) {
    return result;
  }
  result.Clear();
  bool carry = 0;
  if (digits_.size() == big_unsigned_2.getDigits().size()) {
    for (unsigned int i {0}; i < big_unsigned_2.getDigits().size(); ++i) {
      int partial_digit = carry;
      partial_digit += big_unsigned_2.getDigits()[i];
      if (digits_[i] < partial_digit) {
        partial_digit = 10 - (partial_digit - digits_[i]);
        if (partial_digit / 10 == 1) {
          result.AddDigit(partial_digit % 10);
        } else {
          result.AddDigit(partial_digit);
        }
        carry = 1;
      } else {
        partial_digit = digits_[i] - partial_digit; 
        result.AddDigit(partial_digit);
        carry = 0;
      }
    }
    if (carry) {
      result.digits_.push_back(carry);
    }
  } else if (digits_.size() > big_unsigned_2.getDigits().size()) {
      unsigned int i {0};
      while (i < big_unsigned_2.getDigits().size()) {
        int partial_digit = carry;
        partial_digit += big_unsigned_2.getDigits()[i];
        if (digits_[i] < partial_digit) {
          partial_digit = 10 - (partial_digit - digits_[i]);
          if (partial_digit / 10 == 1) {
            result.AddDigit(partial_digit % 10);
          } else {
            result.AddDigit(partial_digit);
          }
          carry = 1;
        } else {
          partial_digit = digits_[i] - partial_digit; 
          result.AddDigit(partial_digit);
          carry = 0;
        }
        ++i;
      }
      while (i < digits_.size()) {
        int partial_digit = carry;
        partial_digit = digits_[i] - partial_digit; 
        result.AddDigit(partial_digit);
        carry = 0;
        ++i;
      }
    }
  result.ProcessZeros();
  return result;
}



BigUnsigned& operator--(BigUnsigned& big_unsigned_1) {
  BigUnsigned unit (1);
  big_unsigned_1 = big_unsigned_1 - unit;
  return big_unsigned_1;
}




BigUnsigned operator--(BigUnsigned& big_unsigned_1, int) {
  BigUnsigned post_unsigned = big_unsigned_1;
  BigUnsigned unit (1);
  big_unsigned_1 = big_unsigned_1 - unit;
  return post_unsigned;
}


BigUnsigned BigUnsigned::operator*(const BigUnsigned& mult) const {
  BigUnsigned result;
  result.Clear();

  if (mult.getDigits().empty() || digits_.empty() || (mult.getDigits()[0] == 0 && mult.getDigits().size() == 1) || (digits_[0] == 0 && digits_.size() == 1)) {
    result.AddDigit(0);
    return result;
  }

  BigUnsigned counter;
  while (counter < mult) {
    result = result + *this; // Suma el número actual al resultado
    ++counter; // Incrementa el contador
  }

  return result;
}


BigUnsigned BigUnsigned::operator%(const BigUnsigned& big_unsigned) const {
  BigUnsigned temp_num;
  temp_num = *this;
  while (temp_num >= big_unsigned) {
    temp_num = temp_num - big_unsigned;
    temp_num.ProcessZeros();
  }

  return temp_num;
}


BigUnsigned operator/(const BigUnsigned& big_unsigned_1, const BigUnsigned& big_unsigned_2) {
  BigUnsigned temp_num;

  if ((big_unsigned_2.getDigits().size() == 1 && big_unsigned_2.getDigits()[0] == 0) || (big_unsigned_1.getDigits().size() == 1 && big_unsigned_1.getDigits()[0] == 0) || (big_unsigned_1.getDigits().empty()) || (big_unsigned_2.getDigits().empty())) {
    temp_num.AddDigit(0);
    return temp_num;
  }

  temp_num.Clear();
  BigUnsigned counter;
  temp_num = big_unsigned_1;
  while (temp_num >= big_unsigned_2) {
    temp_num = temp_num - big_unsigned_2;
    ++counter; // Incrementa el contador (resultado)
  }

  return counter;
}
