#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 *
 *    enum Operator { Op_Dodaj = 1, Op_Odejmij, Op_Mnoz, Op_Dziel };
 *
 *
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */

enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };


struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};


/*
* Funkcje ponizej nalezy zdefiniowac w module.
*
*/    
void Wyswietl(WyrazenieZesp  WyrZ);
WyrazenieZesp Oblicz(WyrazenieZesp  WyrZ);
WyrazenieZesp WczytajWZ(WyrazenieZesp  WyrZ);
void Sprawdzoperator(std::istream &STRwej);
std::istream& operator >> (std::istream& STRwej, WyrazenieZesp& WZ );
std::ostream& operator << (std::ostream& STRwyj, WyrazenieZesp& WyrZ);
std::istream& operator >> (std::istream& STRwej, const Operator& Operarator );

#endif
