
#include "WyrazenieZesp.hh"
#include "LZespolona.hh"


/*!
 * Metoda:
 * Będzie sprawdzała zgodność operatorów
 * 
 */


LZespolona WyrazenieZesp::Oblicz ()
{
  switch (Op){
    case Op_Dodaj:
        return (Arg1 + Arg2);
        break;

    case Op_Odejmij:
        return (Arg1 - Arg2);
        break;

    case Op_Mnoz:
        return (Arg1 * Arg2);
        break;

    case Op_Dziel:
        return (Arg1 / Arg2);
        break;
    default:
        return (Arg1 - Arg1);
  }
}



/*!
 * Metoda:
 * Wyświetla Wyrażenie algebraiczne.
 
 */

std::ostream& operator << (std::ostream& STRwyj, const WyrazenieZesp& WyrZ)
{

    STRwyj << WyrZ.Arg1 << WyrZ.Op << WyrZ.Arg2 << std::noshowpos;
    return STRwyj;
}

/*!
 * Metoda:
 * Wyświetla operator wyrz.
 
 */

std::ostream& operator << (std::ostream& STRwyj, const Operator& Oper)
{
    switch(Oper)
    {
        case Op_Odejmij:
            STRwyj << '-';
            break;
        case Op_Dodaj:
            STRwyj << '+';
            break;
        case Op_Mnoz:
            STRwyj << '*';
            break;
        case Op_Dziel:
            STRwyj << '/';
            break;
        default:
            STRwyj.setstate(std::ios::failbit);
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

/*!
 * Realizuje przeciążenie operatora wejścia.
 * Wczytuje wyrażenie zespolone z pliku, oraz sprawdza poprawność składni.
 *  
 */

std::istream& operator >> (std::istream& STRwej, Operator& Oper ){
{
    char ops1;
    STRwej >> ops1;
    switch(ops1)
    {
        case '+':
            Oper = Op_Dodaj;
            break;
        case '-':
            Oper = Op_Odejmij;
            break;
        case '*':
            Oper = Op_Mnoz;
            break;
        case '/':
            Oper = Op_Dziel;
            break;
        default:
            STRwej.setstate(std::ios::failbit);
            break;
    }
    return (STRwej);
}
}

/*!
 * Realizuje przeciążenie operatora wejścia.
 * Wczytuje wyrażenie zespolone z pliku, oraz sprawdza poprawność składni.
 *  
 */


std::istream& operator >> (std::istream& STRwej, WyrazenieZesp& WyrZ ){
    std::cout << std::endl;
    STRwej >> WyrZ.Arg1;
    STRwej >> WyrZ.Op;
    STRwej >> WyrZ.Arg2;
    return(STRwej);
}

/*!
 * Realizuje przeciążenie operatora wejścia.
 * Wczytuje wyrażenie zespolone z palca, oraz sprawdza poprawność składni.
 *  
 */

WyrazenieZesp WyrazenieZesp::WczytajWZ(){
    std::cout << std::endl;
    std::cin >> Arg1;
    std::cin >> Op;
    std::cin >> Arg2;
    return (*this);
}

/*!
 * Metoda:
 * Wyświetla operator wyrz.
 */

void WyrazenieZesp::Wyswietl(){
    
    std::cout << Arg1;
    std::cout << Op;
    std::cout << Arg2;
}

