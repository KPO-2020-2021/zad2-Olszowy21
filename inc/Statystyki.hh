#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH

#include "WyrazenieZesp.hh"

struct Naliczanie {
public:
  int Poprawne;
  int Niepoprawne;
  Naliczanie() : Poprawne( 0 ), Niepoprawne( 0 ){};

  LZespolona Wynikitestu();
};


#endif
