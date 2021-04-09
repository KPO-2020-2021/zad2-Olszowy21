#include "LZespolona.hh"

#define MIN_DIFF 0.01


LZespolona  LZespolona::operator += (LZespolona const &Skl2){
  this->re = this->re + Skl2.re;
  this->im = this->im + Skl2.im;
  return (*this);
}

LZespolona  LZespolona::operator /= (LZespolona const &Skl2){
  this->re = this->re / Skl2.re;
  this->im = this->im / Skl2.im;
  return (*this);
}
/*!
 * Realizuje porównywanie dwoch liczb zespolonych.
 * Argumenty:
 *    Dane struktury - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */

bool LZespolona::operator == ( const LZespolona  Skl2)  const{
  if ((abs(this->re - Skl2.re) <= MIN_DIFF) && (abs(this->im - Skl2.im) <= MIN_DIFF))
    return true;
  else

    return false;
} 

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Dane struktury - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator + (LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = this->re + Skl2.re;
  Wynik.im = this->im + Skl2.im;
  return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Dane struktury - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Różnice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator - (LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = this->re - Skl2.re;
  Wynik.im = this->im - Skl2.im;

  return Wynik;
}

/*!
 * Realizuje przemnożenie dwoch liczb zespolonych.
 * Argumenty:
 *    Dane struktury - pierwszy skladnik
 *    Skl2 - drugi skladnik
 * Zwraca:
 *    Przemnożone dwa skladniki przekazane jako parametry.
 */
LZespolona  LZespolona::operator * (LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = this->re*Skl2.re - Skl2.im*this->im;
  Wynik.im = this->re*Skl2.im + Skl2.re*this->im;
  return Wynik;
}
/*!
 * Realizuje dzielenie liczby zespolonej przez skalar.
 * Argumenty:
 *    Dane struktury - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 *
 */
LZespolona  LZespolona::operator / (double  Skl2)
{
  LZespolona  Wynik;
  if(Skl2 != 0){
    Wynik.re = this->re / Skl2;
    Wynik.im = this->im / Skl2;
  }
  else if (Skl2 == 0){
    throw std::runtime_error("matematyczny error, dzielenie przez zero w double\n)");
  }
  return Wynik;
}

LZespolona  LZespolona::operator / (LZespolona Skl2)
{
  LZespolona  Wynik;
  if (Skl2.re == 0 || Skl2.im == 0)
{
  throw std::runtime_error("matematyczny error, dzielenie przez zero w LZespolona\n)");
}
  Wynik = operator * (LZespolona::sprzezenie(Skl2));
  Wynik.re = Wynik.re/pow(modul(Skl2), 2);
  Wynik.im = Wynik.im/pow(modul(Skl2), 2);
  return Wynik;
}

/*!
 * Realizuje przeciążenie operatora wyjścia.
 * Wyświetla Liczbę zespoloną na wyjściu.
 *
 */
std::ostream& operator << (std::ostream &STRwyj, const LZespolona &LZ)
{
  STRwyj << "(" << LZ.re << std::showpos << LZ.im << "i)" << std::noshowpos;
  return STRwyj;
}

void Sprawdzznak(std::istream &STRwej, char znak){
  char Wejznak = ' ';
  STRwej >> Wejznak;
  if (Wejznak != znak){
    STRwej.setstate(std::ios::failbit);
  }
}

/*!
 * Realizuje przeciążenie operatora wejścia.
 * wczytuje liczbę zespoloną z wejścia, oraz sprawdza poprawność składni.
 *
 */
std::istream& operator >> (std::istream& STRwej, LZespolona& LZ )
{  
  Sprawdzznak(STRwej, '(');
  STRwej >> LZ.re;
  STRwej >> LZ.im;
  Sprawdzznak(STRwej, 'i');
  Sprawdzznak(STRwej, ')');
  return STRwej;
}

/*!
 * Funkcje Realizują sprzężenie składowej jaką mu zadamy lub z klasy.
 * 
 *
 */

LZespolona LZespolona::sprzezenie()
{
  this->im = -(this->im);
  return *this;
} 

LZespolona LZespolona::sprzezenie(LZespolona Skl2)
{
  Skl2.im = -(Skl2.im);
  return Skl2;
}
/*!
 * Funkcje Realizują moduł ze składowej jaką mu zadamy lub z klasy.
 * 
 *
 */
double LZespolona::modul(LZespolona Skl2){
  double Wynik;

  Wynik = sqrt(pow(Skl2.re, 2) + pow(Skl2.im, 2));
  return Wynik;
}

double LZespolona::modul(){
  double Wynik;

  Wynik = sqrt(pow(re, 2) + pow(im, 2));
  return Wynik;
}
