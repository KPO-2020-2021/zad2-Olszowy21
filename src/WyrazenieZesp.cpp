#include <iostream>
#include "BazaTestu.hh"

using namespace std;

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */


void Wyswietl(WyrazenieZesp  WyrZ){
    
    cout << WyrZ.Arg1 << WyrZ.Op << WyrZ.Arg2;

}


LZespolona Oblicz(WyrazenieZesp  WyrZ);
