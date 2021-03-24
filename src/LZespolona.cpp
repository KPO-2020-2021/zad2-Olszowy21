#include "LZespolona.hh"

#define MIN_DIFF 0.0001

using namespace std;
/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 * 
 * UWAGA! przy wpisywaniu wyniku należy uwzględniać 3 miejsca po przecinku!!!
 */

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2){
  if ((abs(Skl1.re - Skl2.re) <= MIN_DIFF) && (abs(Skl1.im - Skl2.im) <= MIN_DIFF))
    return true;
  else

    return false;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

/*!
 * Realizuje odjęcie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Różnice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

/*!
 * Realizuje przemnożenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik
 *    Skl2 - drugi skladnik
 * Zwraca:
 *    Przemnożone dwa skladniki przekazane jako parametry.
 */
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re*Skl2.re - Skl2.im*Skl1.im;
  Wynik.im = Skl1.re*Skl2.im + Skl2.re*Skl1.im;
  return Wynik;
}
/*!
 * Realizuje dzielenie liczby zespolonej przez skalar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 *
 */
LZespolona  operator / (LZespolona  Skl1,  double  Skl2)
{
  LZespolona  Wynik;
  if(Skl2 != 0){
    Wynik.re = Skl1.re / Skl2;
    Wynik.im = Skl1.im / Skl2;
  }
  cerr << "Dzielenie przez 0 proszę zmienić składową" << endl;
  return Wynik;
}

LZespolona  operator / (LZespolona  Skl1,  LZespolona Skl2)
{
  LZespolona  Wynik;
  if (Skl2.re == 0 || Skl2.im == 0)
{
   cerr << "Dzielenie przez 0 proszę zmienić składową" << endl;
}
  Wynik = operator * (Skl1, sprzezenie(Skl2));
  Wynik.re = Wynik.re/pow(modul(Skl2), 2);
  Wynik.im = Wynik.im/pow(modul(Skl2), 2);
  return Wynik;
}



/*!
 * Realizuje przeciążenie operatora wyjścia.
 * Wyświetla Liczbę zespoloną na wyjściu.
 *
 */
ostream& operator << (ostream &STRwyj, LZespolona &LZ)
{
  cout << "WESZŁO W wyswietlanie WYRZESP";
  STRwyj << "(" << LZ.re << showpos << LZ.im << "i)" << noshowpos;
  return STRwyj;
}

void Sprawdzznak(istream &STRwej, char znak){
  char Wejznak = ' ';
  STRwej >> Wejznak;
  if (Wejznak != znak){
    STRwej.setstate(ios::failbit);
  }
}

/*!
 * Realizuje przeciążenie operatora wejścia.
 * wczytuje liczbę zespoloną z wejścia, oraz sprawdza poprawność składni.
 *
 */
istream& operator >> (istream& STRwej, LZespolona& LZ )
{
  std::cout << "WESZŁO W wczytywanie dla LI ZESPOLONEJ" << endl;
  Sprawdzznak(STRwej, '(');
  STRwej >> LZ.re;
  STRwej >> LZ.im;
  Sprawdzznak(STRwej, 'i');
  Sprawdzznak(STRwej, ')');
  return STRwej;
}
/*!
 * Funkcja Realizuje sprzężenie składowej jaką mu zadamy.
 * 
 *
 */

LZespolona sprzezenie(LZespolona  Skl1)
{
  Skl1.im = -(Skl1.im);
  return Skl1;
}
/*!
 * Funkcja Realizuje moduł ze składowej jaką mu zadamy.
 * 
 *
 */
double modul(LZespolona Skl1){
  double Wynik;

  Wynik = sqrt(pow(Skl1.re, 2) + pow(Skl1.im, 2));
  return Wynik;
}
