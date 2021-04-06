#include "BazaTestu.hh"

/*
 * Tablica, ktora jest widoczna tylko w tym module.
 * Zawiera ona tresc latwego testu.
 */

LZespolona BazaTestu::Oblicztest()
{
  switch (WyrZ.Op){
    case Op_Dodaj:
        return (WyrZ.Arg1 + WyrZ.Arg2);
        break;

    case Op_Odejmij:
        return (WyrZ.Arg1 - WyrZ.Arg2);
        break;

    case Op_Mnoz:
        return (WyrZ.Arg1 * WyrZ.Arg2);
        break;

    case Op_Dziel:
        return (WyrZ.Arg1 / WyrZ.Arg2);
        break;
    default:
      return (WyrZ.Arg1 - WyrZ.Arg1);
  }
}


bool BazaTestu::inicjalizujpliklatwy(){
  
  plik.open("./src/pliklatwy.txt", std::ios::in);
  if( plik.good() == false ){
    std::cerr << ":/ Niepowodzenie w otwarciu pliku latwego.";
    return false;
  }
  return true;
}

bool BazaTestu::inicjalizujpliktrudny(){
  
  plik.open("./src/pliktrudny.txt", std::ios::in);
  if( plik.good() == false ){
    std::cerr << ":/ Niepowodzenie w otwarciu pliku trudnego.";
    return false;
  }
  return true;
}

bool BazaTestu::pobierzpytanie(){
  plik >> WyrZ;
  while(plik.fail() && !plik.eof()){
    std::cerr << " >>> Nie udało się wczytać błędnego testu, został on pominięty <<< \n";
    plik.clear();
    plik.ignore(1000, '\n');
    plik >> WyrZ;
  }
  if(plik.eof()){
    std::cout << "Koniec zawartości pliku testowego. ";
    return false;
  }
  else{ 
    return true;
  }
}

void BazaTestu::zamknijplik(){
  plik.close();
}

