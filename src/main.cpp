
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

  
  std::cout << std::endl;
  std::cout << " Start testu arytmetyki zespolonej: " << argv[1] << std::endl;
  std::cout << std::endl;



  WyrazenieZesp WyrZ_PytanieTestowe;
  LZespolona TYMCZ, x;
  Naliczanie Odpowiedzi;
  BazaTestu BazaT;
  

  if(strcmp( argv[1], "latwy") == 0){
    BazaT.inicjalizujpliklatwy();
  }
  else if(strcmp( argv[1], "trudny") == 0){
    BazaT.inicjalizujpliktrudny();
  }
  else{
    std::cout << " Podano błędną nazwę testu dozwolone to ( latwy / trudny ) \n ";
    std::cin.clear();
    std::cout << " Program nalezy ponownie uruchomic z poprawnym wywolaniem \n";
    exit (1);
  }


  while (BazaT.pobierzpytanie()) {
    int i = 4;
    
    std::cout << ":? Podaj wynik operacji: ";
    std::cout << BazaT.WyrZ << std::endl;
    std::cin >> TYMCZ;

    if(!std::cin.fail()){
      std::cout << ";3 Twoja odpowiedź: " << TYMCZ;
    }

    while(std::cin.fail()){
      std::cout << "\n:'( Błędna forma Liczby zespolonej >>> Szablon: (12-2.5i) lub (3+2i)" << std::endl;
      std::cout << "\n:| Pozostała ilość prób: " << (--i) << std::endl;
      if( i == 0){
        std::cout << "\n:< Wykorzystano wszystkie możliwe próby, może następnym razem się uda ;) " << std::endl;
        exit (-1);
      }
      std::cin.clear();
      std::cin.ignore(100,'\n');
      std::cin >> TYMCZ;
      
    }

    x = BazaT.Oblicztest();

    if ( TYMCZ == x){
      std::cout << "\n\t:) Odpowiedz poprawna" << std::endl;
      ++Odpowiedzi.Poprawne;
    }
    else{
      std::cout << "\n\t:/ Odpowiedz niepoprawna" << std::endl;
      ++Odpowiedzi.Niepoprawne;
    }
  }

  std::cout << std::endl;
  std::cout << " Koniec testu" << std::endl;
  std::cout << std::endl;

  BazaT.zamknijplik();

  Odpowiedzi.Wynikitestu();

}
