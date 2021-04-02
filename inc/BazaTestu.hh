#ifndef BAZATESTU_HH
#define BAZATESTU_HH

#include "WyrazenieZesp.hh"
#include <fstream>
#include <cstring>

/*
 * Modeluje pojecie baze testu z zestawem pytan w tablicy
 * oraz informacji o maksymalnej ilosci pytan, jak
 * tez indeksem nastepnego pytania, ktore ma byc pobrane
 * z bazy.
 * 
 */

struct BazaTestu {
public:
  /*
  WyrazenieZesp  *wskTabTestu;   * Wskaznik na tablice zawierajaca pytania testu *
  unsigned int    IloscPytan;    * Ilosc wszystkich pytan *
  unsigned int    IndeksPytania; * Numer pytania, ktore ma byc pobrane jako nastepne *
  */

  std::fstream plik;
  LZespolona Oblicztest();
  bool pobierzpytanie();
  bool inicjalizujplik();
  void zamknijplik();
  WyrazenieZesp  WyrZ;
};

/*
 * Inicjalizuje test powiazany z dana nazwa.
 *
bool InicjalizujTest( BazaTestu  *wskBazaTestu, const char*  sNazwaTestu );

 * Udostepnia nastepne pytanie z bazy.
 *
bool PobierzNastpnePytanie( BazaTestu  *wskBazaTestu,  WyrazenieZesp *wskWyr );
*/ 

#endif
