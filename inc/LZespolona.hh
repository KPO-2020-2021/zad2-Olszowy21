#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <cmath>
#include <iostream>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */



/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};

/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

bool  operator== (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator+ (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator- (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator/ (LZespolona  Skl1,  double  Skl2);
LZespolona  operator* (LZespolona  Skl1,  LZespolona  Skl2);

std::ostream& operator<< (std::ostream&, LZespolona& );
std::istream& operator>> (std::istream&, LZespolona& );

LZespolona sprzezenie(LZespolona  Skl1);

void wczytajLZ(LZespolona  Skl1);
double modul(LZespolona Skl1);
void Sprawdzznak(std::istream &STRwej, char znak);




#endif
