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

  
/*
  LZespolona() : re( 0 ) {};
  LZespolona() : im( 0 ) {};

  void setre(LZespolona Skl2){
    re = Skl2.re;
  }
  void setim(LZespolona Skl2){
    im = Skl2.im;
  }
  double getre() const {return re;}
  double getim() const {return im;}

  

  LZespolona(double _re) : re(_re){}
  LZespolona(double _im) : im(_im){}
  LZespolona();
  explicit operator double() const { return re; }
  explicit operator double() const { return im; }
  */

  bool operator == ( const LZespolona  Skl2) const;

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

/*
 * 
 * friend std::ostream& operator << (std::ostream&, LZespolona&);
 * friend std::istream& operator >> (std::istream&, LZespolona&);
 * friend struct WyrazenieZesp;
 * friend bool PobierzNastpnePytanie( BazaTestu* , WyrazenieZesp*);
 * 
 */
};



std::ostream& operator << (std::ostream& STRwyj, const LZespolona& LZ );
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
