#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH

#include "WyrazenieZesp.hh"
/*!
 * Struktura:
 * Posiada informacje o poprawnych i niepoprawnych odpowiedziach
 *
 */
struct Naliczanie {
public:
  int Poprawne;
  int Niepoprawne;

// Kontruktory

  Naliczanie() : Poprawne( 0 ), Niepoprawne( 0 ){};

// Metody

  double Wynikitestu();
};


#endif
