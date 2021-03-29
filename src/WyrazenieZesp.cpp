
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

std::ostream& operator << (std::ostream& STRwyj, const Operator& Oper)
{
    switch(Oper)
    {
        case Op_Dodaj:
        STRwyj << '+';
        break;
        case Op_Odejmij:
        STRwyj << '-';
        break;
        case Op_Mnoz:
        STRwyj << '*';
        break;
        case Op_Dziel:
        STRwyj << '/';
        break;
        default:
        STRwyj << "Błędny operator poprawne to + , - , * , /";
        break;
    }
    return (STRwyj);
}

void WyrazenieZesp::Sprawdzoperator(std::istream &STRwej){
    char ops1;
    STRwej >> ops1;
    if (ops1 != ('+'||'-'||'*'||'/')){
        STRwej.setstate(std::ios::failbit);
    }
}

std::istream& operator >> (std::istream& STRwej, Operator& Oper ){
    Oper.Sprawdzoperator(STRwej);
    STRwej >> Oper;
    return(STRwej);
}


std::istream& operator >> (std::istream& STRwej, WyrazenieZesp& WyrZ ){
    std::cout << std::endl;
    STRwej >> WyrZ.Arg1; // OGARNAC OPERATOR
    STRwej >> WyrZ.Op;
    STRwej >> WyrZ.Arg2;
    return(STRwej);
}

WyrazenieZesp WyrazenieZesp::WczytajWZ(){
    std::cout << std::endl;
    std::cin >> Arg1;
    std::cin >> Op;
    std::cin >> Arg2;
    return (*this);
}

void WyrazenieZesp::Wyswietl(){
    
    std::cout << Arg1;
    std::cout << Op;
    std::cout << Arg2;
}

