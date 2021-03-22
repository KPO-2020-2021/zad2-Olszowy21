
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

  BazaTestu BazaT = { nullptr , 0, 0 };

  if (InicjalizujTest(&BazaT, argv[1]) == false) {
    std::cerr << " Inicjalizacja testu nie powiodla sie." << std::endl;
    return 1;
  }

  
  std::cout << std::endl;
  std::cout << " Start testu arytmetyki zespolonej: " << argv[1] << std::endl;
  std::cout << std::endl;



  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona TYMCZ;
  
  Naliczanie Odpowiedzi = {0 , 0}; 

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    std::cout << " Czesc rzeczywista pierwszego argumentu: ";
    std::cout << WyrZ_PytanieTestowe.Arg1.re << std::endl;
    
  }

  void Wyniktestu();

  std::cout << std::endl;
  std::cout << " Koniec testu" << std::endl;
  std::cout << std::endl;

}
