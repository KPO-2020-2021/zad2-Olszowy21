#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <cstring>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */



/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
private:
  
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

public:
  void set(LZespolona Skl2){
    re = Skl2.re;
    im = Skl2.im;
  }
  LZespolona get();

  bool operator == (LZespolona  Skl2);

  LZespolona  operator + (LZespolona  Skl2);
  LZespolona  operator - (LZespolona  Skl2);
  LZespolona  operator / (double  Skl2);
  LZespolona  operator / (LZespolona Skl2);
  LZespolona  operator * (LZespolona  Skl2);

  LZespolona sprzezenie();
  LZespolona sprzezenie(LZespolona Skl2);

  void wczytajLZ();
  double modul();
  double modul(LZespolona Skl2);
  void Sprawdzznak(std::istream &STRwej, char znak);

 // friend std::ostream& operator << (std::ostream&, LZespolona&);
  // friend std::istream& operator >> (std::istream&, LZespolona&);
};



std::ostream& operator << (std::ostream& STRwyj, LZespolona& LZ );
std::istream& operator >> (std::istream& STRwej, LZespolona& LZ );

/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 *

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  double  Skl2);
LZespolona  operator / (LZespolona  Skl1,  LZespolona Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);

std::ostream& operator << (std::ostream& STRwyj, LZespolona& LZ );
std::istream& operator >> (std::istream& STRwej, LZespolona& LZ );

LZespolona sprzezenie(LZespolona  Skl1);

void wczytajLZ(LZespolona  Skl1);
double modul(LZespolona Skl1);
void Sprawdzznak(std::istream &STRwej, char znak);

*/

#endif
