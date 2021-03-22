
#include "WyrazenieZesp.hh"
#include "LZespolona.hh"



/*!
 * Funkcja:
 * Będzie sprawdzała zgodność operatorów
 * 
 */

/*!
 * Funkcja:
 * Wyświetla Wyrażenie algebraiczne.
 
 */


WyrazenieZesp Oblicz(WyrazenieZesp  WyrZ);

/*!
 * Realizuje przeciążenie operatora wejścia.
 * wczytuje liczbę zespoloną z wejścia, oraz sprawdza poprawność składni.
 *  
 */
std::ostream& operator << (std::ostream& STRwyj, WyrazenieZesp& WyrZ)
{
    STRwyj << "(" << WyrZ.Arg1 << ")" << "(" << WyrZ.Arg2 << ")" << std::noshowpos;
    return STRwyj;
}

std::ostream& operator << (std::ostream& STRwyj, Operator& Oper)
{
    STRwyj << Oper.Opera;
    return STRwyj;
}

std::istream& operator >> (std::istream& STRwej, Operator& Oper ){
    Sprawdzoperator(STRwej);
    STRwej >> Oper.Opera;
    return(STRwej);
}


std::istream& operator >> (std::istream& STRwej, WyrazenieZesp& WyrZ ){
    std::cout << std::endl;
    STRwej >> WyrZ.Arg1; // OGARNAC OPERATOR
    STRwej >> WyrZ.Op;
    STRwej >> WyrZ.Arg2;
    return(STRwej);
}

WyrazenieZesp WczytajWZ(WyrazenieZesp  WyrZ){
    std::cout << std::endl;
    std::cin >> WyrZ.Arg1;
    std::cin >> WyrZ.Op;
    std::cin >> WyrZ.Arg2;
    return (WyrZ);
}

void Wyswietl(WyrazenieZesp  WyrZ){
    
    std::cout << WyrZ.Arg1;
    std::cout << WyrZ.Op;
    std::cout << WyrZ.Arg2;
}

void Sprawdzoperator(std::istream &STRwej){
    char ops1;
    STRwej >> ops1;
    if (ops1 != ('+'||'-'||'*'||'/')){
        STRwej.setstate(std::ios::failbit);
    }
}
