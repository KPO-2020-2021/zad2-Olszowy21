#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include "Statystyki.hh"

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

double Naliczanie::Wynikitestu()
{
    double Wynik;
    Wynik = ((double)this->Poprawne / ((double)this->Poprawne + (double)this->Niepoprawne)) * 100;
    std::cout << "Procentowa poprawność testu: " << Wynik << "%" << std::endl;
    std::cout << "Dobre odpowiedzi: " << this->Poprawne << std::endl;
    std::cout << "Złe odpowiedzi: " << this->Niepoprawne << std::endl;
    return Wynik;
}
