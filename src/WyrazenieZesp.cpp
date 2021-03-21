#include <iostream>
#include "BazaTestu.hh"
#include "LZespolona.hh"

using namespace std;

/*!
 * Funkcja:
 * Będzie sprawdzała zgodność operatorów
 * 
 */

void Sprawdzoperator(WyrazenieZesp  WyrZ, Operator xD )
{
  
}


/*!
 * Funkcja:
 * Wyświetla Wyrażenie algebraiczne.
 *
 */
void Wyswietl(WyrazenieZesp  WyrZ){
    
    cout << WyrZ.Arg1 << WyrZ.Op << WyrZ.Arg2;

}


LZespolona Oblicz(WyrazenieZesp  WyrZ);


LZespolona WczytajWZ(WyrazenieZesp  WyrZ){
    cout << "Podaj wyrażenie algebraiczne w postaci (2 + 3i)" << endl;
    


}
