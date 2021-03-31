
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



  WyrazenieZesp WyrZ_PytanieTestowe;
  LZespolona TYMCZ;
  Naliczanie Odpowiedzi;



  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    std::cout << "? Podaj wynik operacji:";
    std::cout << WyrZ_PytanieTestowe << std::endl;
    std::cin >> TYMCZ;
    std::cout << "Twoja odpowiedź: " << TYMCZ;
    while(std::cin.fail()){
      for(int i = 3; i > 0; i--){
      std::cin.clear();
      std::cin.ignore(100,'\n');
      std::cout << "'( Błędna forma Liczby zespolonej >>> Szablon: (12-2.5i) lub (3*2i)\n";
      std::cout << ")Pozostała ilość prób: " << i;
      std::cin >> TYMCZ;
      }
    }

    


    

  


}

  void Wynikitestu(Naliczanie Pkt);

  std::cout << std::endl;
  std::cout << " Koniec testu" << std::endl;
  std::cout << std::endl;

}
