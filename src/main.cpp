
#include "WyrazenieZesp.hh"
#include "BazaTestu.hh"
#include "Statystyki.hh"

int main(int argc, char **argv)
{

  if (argc < 2) {
    std::cout << std::endl;
    std::cout << " Brak opcji okreslajacej rodzaj testu." << std::endl;
    std::cout << " Dopuszczalne nazwy to:  latwy, trudny." << std::endl;
    std::cout << std::endl;
    return 1;
  }

/*
  if (InicjalizujTest(&BazaT, argv[1]) == false) {
    std::cerr << " Inicjalizacja testu nie powiodla sie." << std::endl;
    return 1;
  }
*/
  
  std::cout << std::endl;
  std::cout << " Start testu arytmetyki zespolonej: " << argv[1] << std::endl;
  std::cout << std::endl;



  WyrazenieZesp WyrZ_PytanieTestowe;
  LZespolona TYMCZ, x;
  Naliczanie Odpowiedzi;
  BazaTestu BazaT;

  BazaT.inicjalizujplik();


  while (!BazaT.plik.fail()) {
    BazaT.inicjalizujplik(); 
    std::cout << ":? Podaj wynik operacji: ";
    BazaT.pobierzpytanie();
    std::cout << BazaT.WyrZ;
    std::cin >> TYMCZ;
    std::cout << "Twoja odpowiedź: " << TYMCZ;
    while(std::cin.fail()){
      for(int i = 3; i > 0; i--){
      std::cin.clear();
      std::cin.ignore(100,'\n');
      std::cout << ":'( Błędna forma Liczby zespolonej >>> Szablon: (12-2.5i) lub (3*2i)\n";
      std::cout << ":)Pozostała ilość prób: " << i << std::endl;
      std::cin >> TYMCZ;
      }
    } // DO SKOPIOWANIA --------------------------------------------------
    x = BazaT.Oblicztest();
    if ( TYMCZ == x){
      std::cout << ":) Odpowiedz poprawna" << std::endl;
      ++Odpowiedzi.Poprawne;
    }
    else{
      std::cout << ":/ Odpowiedz niepoprawna" << std::endl;
      ++Odpowiedzi.Niepoprawne;
    }
}

  std::cout << std::endl;
  std::cout << " Koniec testu" << std::endl;
  std::cout << std::endl;

  Odpowiedzi.Wynikitestu();

}
