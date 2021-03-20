#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

using namespace std;

#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

struct Zliczanie {

  int Poprawne;
  int Niepoprawne;
};
/*
 * Tu nalezy zdefiniowac funkcje, ktore definiuja model statystyki 
 */
void Wyniktestu(Zliczanie Pkt);

#endif
