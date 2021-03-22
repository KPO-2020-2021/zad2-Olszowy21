#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include "Statystyki.hh"

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

void Wynikitestu(Naliczanie Pkt)
{
    double Wynik;
    Wynik = ((double)Pkt.Poprawne / ((double)Pkt.Poprawne + (double)Pkt.Niepoprawne)) * 100;
    std::cout << "Procentowa poprawność odpowiedzi: " << Wynik << "%" << std::endl;
    std::cout << "Dobre odpowiedzi: " << Pkt.Poprawne << std::endl;
    std::cout << "Złe odpowiedzi: " << Pkt.Niepoprawne << std::endl;
}
