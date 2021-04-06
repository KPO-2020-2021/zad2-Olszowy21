#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 *
 *
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct BazaTestu;

enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };

struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
  
  WyrazenieZesp() = default;
  
  
  WyrazenieZesp(LZespolona W1, Operator Op, LZespolona W2 ){
    this->Arg1 = W1;
    this->Op = Op;
    this->Arg2 = W2;
  }
  /*
  WyrazenieZesp(const WyrazenieZesp &coppy){
    Arg1 = coppy.Arg1;
    Op = coppy.Op;
    Arg2 = coppy.Arg2;
  }
*/

  void Wyswietl();
  LZespolona Oblicz();
  WyrazenieZesp WczytajWZ();
  void Sprawdzoperator(std::istream &STRwej);

};


/*
* Funkcje ponizej nalezy zdefiniowac w module.
*
*/    
std::istream& operator >> (std::istream& STRwej, WyrazenieZesp& WZ );
std::ostream& operator << (std::ostream& STRwyj, const WyrazenieZesp& WyrZ);
std::istream& operator >> (std::istream& STRwej, Operator& Operarator );
std::ostream& operator << (std::ostream& STRwyj, const Operator& Oper);

#endif