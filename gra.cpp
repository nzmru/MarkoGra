#include <iostream>
using namespace std;

string imie;
int wybor;
int pojemnoscPlecaka = 100;
int rozimarPoletka = 16;
int dniWRoku = 100;

struct ObjCzas {
  int godzina = 6;
  int dzien = 0;
  int rok = 2019;
};

void ruszCzasDzien(ObjCzas czas){
  if(czas.dzien+1 >= dniWRoku){
    czas.dzien=0;
    czas.rok++;
  }
}

void ruszCzas(ObjCzas czas){
  if(czas.godzina == 23){
    czas.godzina = 0;
    ruszCzasDzien(czas);
  } else {
    czas.godzina++;
  }
}

struct ObjPlecak {
  int drewno = 0;
  int kamien = 0;
  int metal = 0; 
  int zloto = 0;
  int pszenica = 0;
  int chleb = 0;
  int mieso = 0;
};

void pokazPlecak(ObjPlecak plecak){
  cout << "Masz " << plecak.drewno << " drewna\n";
  cout << "Masz " << plecak.kamien << " kamienia\n";
  cout << "Masz " << plecak.metal << " metalu\n";
  cout << "Masz " << plecak.zloto << " złota\n";
  cout << "Masz " << plecak.pszenica << " pszenicy\n";
  cout << "Masz " << plecak.chleb << " chleba\n";
  cout << "Masz " << plecak.mieso << " miesa\n";
}

struct ObjPoletko {
  int poziomNawodnienia = 0;
  /*
    0 - suche
  */
  int poziomWyrosniecia = 0;
  /* 
    0 - brak
    1-4 rośnie
    5 - urosło
  */
};

void siejPszenice(ObjPoletko poletka[]){
  int nr = -1;
  for(int i=0; i<rozimarPoletka; i++){
    if(poletka[i].poziomWyrosniecia = 0){
      nr = i;
      break;
    }
  }
  if(nr >= 0){
    poletka[nr].poziomWyrosniecia = 1; 
  }
}

void podlejPszenice(ObjPoletko poletka[]){
  //Jedno czy wszystkie na raz?
}

void zbierzPszeince(ObjPoletko poletka[]){
  //Jedno czy wszystkie na raz?
}

bool czyMamMiejsceWPlecaku(ObjPlecak plecak){
  return (plecak.drewno + plecak.kamien + plecak.metal + plecak.zloto + plecak.pszenica + plecak.chleb + plecak.mieso < pojemnoscPlecaka);
}

void info(string s){
  for(int i=0;i < s.length()+2; i++){
    if(s[i]<0){
      i++;
    }
    cout << '-';
  }
  cout << "\n " << s << "\n";
  for(int i=0;i < s.length()+2; i++){
    if(s[i]<0){
      i++;
    }
    cout << '-';
  }
  cout << "\n";
}

// void str2bytes(string s){
//   for(int i=0;i < 5; i++){
//     cout << (int)s[i] << endl;
//   }
// }

void upieczChleb(ObjPlecak plecak){
  if(plecak.pszenica >= 3){
    plecak.chleb++;
    plecak.pszenica-=3;
    info("Upiekłeś chleb!");
  } else {
    info("Nie masz 3 sztuk pszenicy!");
  }
}

int dom(ObjPlecak plecak){
  while(true){
    cout << "Jesteś w domu!\n";
    cout << "Co chcesz zrobić?\n";
    cout << "1. Zjedz coś\n";
    cout << "2. Idź spać\n";
    cout << "3. Upiecz chleb\n";
    cout << "4. Wyjdź z domu\n";
    cout << "5. Spójrz w plecak\n";
    cin >> wybor;
    switch (wybor){
      case 1:
        break;
      case 2:
        break;
      case 3:
        upieczChleb(plecak);
        break;
      case 4:
        return 2;
        break;  
      case 5:
        pokazPlecak(plecak);
        break;
      default:
        break;
    }
  }
}

int podworko(ObjPlecak plecak){
  while(true){
    cout << "Jesteś na podwórku!\n";
    cout << "Co chcesz zrobić?\n";
    cout << "1. Idź do domu\n";
    cout << "2. Idź na farmę\n";
    cout << "3. Idź do lasu\n";
    cout << "4. Idź do kopalni\n";
    cin >> wybor;
    switch (wybor)
    {
      case 1:
        return 1;
        break;
      case 2:
        return 3;
        break;
      case 3:
        return 4;
        break;
      case 4:
        return 5;
        break;
      default:
        break;
    }
  }
}

int farma(ObjPlecak plecak, ObjPoletko poletka[]){
  while(true){
    cout << "Jesteś na farmie!\n";
    cout << "Co chcesz zrobić?\n";
    cout << "1. Siej pszenice\n";
    cout << "2. Podlej\n";
    cout << "3. Zbierz pszenice\n";
    cout << "4. Idź na podwórko\n";
    cin >> wybor;
    switch (wybor)
    {
      case 1:
        siejPszenice(poletka);
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        return 2;
        break;
      default:
        break;
    }
  }
}

int main(){
  ObjPlecak plecak;
  ObjPoletko poletka[rozimarPoletka];
  ObjCzas czas;
  
  //testy
  // string strrr="dupppp  1d73kd9swerd";
  // cout << strrr.length() << endl;
  // info("Ała miała kota!");
  // siejPszenice(poletka);
  //testy

  cout << "Jak masz na imię?\n";
  cout << "Mam na imie ";
  cin >> imie;

  int wiek;
  do
  {
    cout << "Ile masz lat?\n";
    cout << "Mam lat ";
    cin >> wiek;
  } while (wiek < 18);

  cout << "Witaj " << imie << "!\n";
  cout << "Masz " << wiek << " lat\n";
  wybor = 1;

  do{
    switch (wybor)
    {
      case 1:
        wybor = dom(plecak);
        break;
      case 2:
        wybor = podworko(plecak);
        break;
      case 3:
        wybor = farma(plecak, poletka);
        break;
    
      default:
        info("Umarłeś!");
        return 0;
    }
  } while(true);

  // do{
    // pokazPlecak(plecak);
    // cout << "Co chcesz zrobić?\n";
    // cout << "1.Drewno, 2.Kamień, 3.Metal, 4.Złoto, 5.Pszenica, 6.Chleb, 7.Mieso\n";

    // cin >> wybor;
    // switch (wybor)
    // {
    //   case 1:
    //     if()
    //     drewno++;
    //     break;
    //   case 2:
    //     kamien++;
    //     break;
    //   case 3:
    //     metal++;
    //     break;
    //   case 4:
    //     zloto++;
    //     break;
    //   case 5:
    //     pszenica++;
    //     break;
    //   case 6:
    //     if(pszenica >= 3){
    //       chleb++;
    //       pszenica-=3;
    //     } else {
    //       cout << "Nie masz 3 sztuk pszenicy!\n";
    //     }
    //     break;
    //   case 7:
    //     mieso++;
    //     break;
    //   default:
    //     break;
    // }

  // } while (true);
  return 0;
}