#include "Statystyki.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
void Wyniktestu(Zliczanie Pkt)
{
    double Wynik;
    Wynik = ((double)Pkt.Poprawne / ((double)Pkt.Poprawne + (double)Pkt.Niepoprawne)) * 100;
    cout << "Procentowa poprawność odpowiedzi: " << Wynik << "%" << endl;
    cout << "Dobre odpowiedzi: " << Pkt.Poprawne << endl;
    cout << "Złe odpowiedzi: " << Pkt.Niepoprawne << endl;
}
