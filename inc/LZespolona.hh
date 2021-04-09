#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


struct WyrazenieZesp;
/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
public:
  
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

// Kontruktory

  LZespolona(double _re, double _im) {re = _re; im = _im;};
  LZespolona() = default;
  
// Metody

  bool operator == ( const LZespolona  Skl2) const;

  LZespolona  operator + (LZespolona  Skl2);
  LZespolona  operator - (LZespolona  Skl2);
  LZespolona  operator / (double  Skl2);
  LZespolona  operator / (LZespolona Skl2);
  LZespolona  operator * (LZespolona  Skl2);

  LZespolona  operator += (LZespolona const &Skl2);
  LZespolona  operator /= (LZespolona const &Skl2);

  LZespolona sprzezenie();
  LZespolona sprzezenie(LZespolona Skl2);

  void wczytajLZ();
  double modul();
  double modul(LZespolona Skl2);
  void Sprawdzznak(std::istream &STRwej, char znak);


};

std::ostream& operator << (std::ostream& STRwyj, const LZespolona& LZ );
std::istream& operator >> (std::istream& STRwej, LZespolona& LZ );


#endif
