#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class godzina{
    public:
        string NrL; //Nr godziny lekcyjnej
        string godz; //godziny w jakich trwa lekcja
        string pn,wt,sr,cz,pt; //numer sali w ktorej lekcje ma cala klasa lub grupa 1.
        string pn2,wt2,sr2,cz2,pt2; //numer sali w ktorej lekcje na 2. grupa (jezeli jest)
};
int main(){
    //NAGLOWEK
    cout<<"Program wymyslony i napisany przez Agate Majewska\n uczennice Zespolu Szkol Elektroniczno-Informatycznych im. Jana Szczepanika Lodz\n";
    cout<<"Pierwsza wersja programu 9.02.2024\n\n";
    //ZMIENNE
    int liczba_klas,lg; //liczba_klas = liczba klas w szkole, lg = najwieksza liczba godzin lekcyjnych
    int t=1,i=1,kk=1,kg,ke,poz,poz2; //kk = ktora klasa, kg = ktora godzina, ke = ktory element (dzien itp.)
    string tekst,nazwap="o1.html",pom; //tekst = obecnie rozpatrywana linijka tekstu, nazwap = nazwa pliku ktory jest aktualnie rozpatrywany, pom = zmienna pomocnicza
    bool nowy=1,gr2=0;    //nowy = czy to pierwsze przejscie programu po uruchomieniu nowego pliku, gr2 = czy o danej godzinie ma lekcje 2. grupa
    //*string dt; //dzien tygodnia
    //PROGRAM
    //przypisanie wartosci zmiennym
    liczba_klas = 14;
    lg = 12;
    //cout<<"Ile planow lekcji chcesz zaladowac do programu?\n";
    //cin>>liczba_klas;
    //cout<<"Jaki numer ma najpozniejsza lekcja (jezeli jest lekcja 0 to dolicz jedna godzine)?\n";
    //cin>>lg;
    godzina tab[30][15]; //tablica przechowujaca zapis sal z podzialem na klasy i godziny
    fstream plik; //strumien pliku
    while(kk<=liczba_klas){ //dopoki sa jeszcze nie wczytane pliki, wczytaj je
        //zerowanie zmiennych
        kg=0;
        ke=0;
        nowy=1;
        //nowa nazwa pliku do otwarcia, dla klasy kk
        nazwap.assign("o");
        nazwap.append(to_string(kk));
        nazwap.append(".html");
        plik.open(nazwap,ios::in); //otwarcie pliku w trybie tylko do odczytu
        //ODCZYTYWANIE DANYCH Z PLIKU
        if(plik.good()){
            cout<<"Uzyskano dostep do pliku o"<<kk<<".html\n";
            while(!plik.eof()){
                getline(plik, tekst);
                if(tekst.length()>3){
                    pom.assign(tekst.substr(1,2));
                    if(pom=="td"){
                        if(!nowy){
                            //cout<<tekst<<"\n";
                            poz = tekst.find(">",3);
                            poz2 = tekst.find("<",3);
                            poz++;
                            gr2 = 0; //wyzerowanie, czy 2. grupa ma teraz lekcje?
                            switch(ke){
                                case 0:
                                    tab[kk][kg].NrL.assign(tekst.substr(poz,poz2-poz));
                                    cout<<tab[kk][kg].NrL<<"\n";
                                    break;
                                case 1:
                                    tab[kk][kg].godz.assign(tekst.substr(poz,(poz2-poz)));
                                    cout<<tab[kk][kg].godz<<"\n";
                                    break;
                                case 2:
                                    if(tekst[poz]=='&'){
                                        tab[kk][kg].pn.assign("");
                                    }
                                    else{
                                        for(i=0;i<5;i++){
                                            poz2++;
                                            poz2 = tekst.find(">",poz2);
                                        }
                                        poz = poz2+1;
                                        poz2 = tekst.find("<",poz2);
                                        tab[kk][kg].pn.assign(tekst.substr(poz,(poz2-poz)));
                                    }
                                    cout<<tab[kk][kg].pn<<"\n";
                                    break;
                                case 3:
                                    if(tekst[poz]=='&'){
                                        tab[kk][kg].wt.assign("");
                                    }
                                    else{
                                        for(i=0;i<5;i++){
                                            poz2++;
                                            poz2 = tekst.find(">",poz2);
                                        }
                                        poz = poz2+1;
                                        poz2 = tekst.find("<",poz2);
                                        tab[kk][kg].wt.assign(tekst.substr(poz,(poz2-poz)));
                                    }
                                    cout<<tab[kk][kg].wt<<"\n";
                                    break;
                                case 4:
                                    if(tekst[poz]=='&'){
                                        tab[kk][kg].sr.assign("");
                                    }
                                    else{
                                        for(i=0;i<5;i++){
                                            poz2++;
                                            poz2 = tekst.find(">",poz2);
                                        }
                                        poz = poz2+1;
                                        poz2 = tekst.find("<",poz2);
                                        tab[kk][kg].sr.assign(tekst.substr(poz,(poz2-poz)));
                                    }
                                    cout<<tab[kk][kg].sr<<"\n";
                                    break;
                                case 5:
                                    if(tekst[poz]=='&'){
                                        tab[kk][kg].cz.assign("");
                                    }
                                    else{
                                        for(i=0;i<5;i++){
                                            poz2++;
                                            poz2 = tekst.find(">",poz2);
                                        }
                                        poz = poz2+1;
                                        poz2 = tekst.find("<",poz2);
                                        tab[kk][kg].cz.assign(tekst.substr(poz,(poz2-poz)));
                                    }
                                    cout<<tab[kk][kg].cz<<"\n";
                                    break;
                                case 6:
                                    if(tekst[poz]=='&'){
                                        tab[kk][kg].pt.assign("");
                                    }
                                    else{
                                        for(i=0;i<5;i++){
                                            poz2++;
                                            poz2 = tekst.find(">",poz2);
                                        }
                                        poz = poz2+1;
                                        poz2 = tekst.find("<",poz2);
                                        tab[kk][kg].pt.assign(tekst.substr(poz,(poz2-poz)));
                                    }
                                    cout<<tab[kk][kg].pt<<"\n\n";
                                    break;
                            }
                            if(ke>1){
                                poz2 = tekst.find("<br>",poz2);
                                if(poz2 != string::npos){
                                    gr2 = 1;
                                    poz2+=5;
                                    for(i=0;i<6;i++){
                                            poz2++;
                                            poz2 = tekst.find(">",poz2);
                                        }
                                        poz = poz2+1;
                                        poz2 = tekst.find("<",poz2);
                                        switch(ke){
                                            case 2:
                                               tab[kk][kg].pn2.assign(tekst.substr(poz,(poz2-poz)));
                                               break;
                                            case 3:
                                               tab[kk][kg].wt2.assign(tekst.substr(poz,(poz2-poz)));
                                               break;
                                            case 4:
                                               tab[kk][kg].sr2.assign(tekst.substr(poz,(poz2-poz)));
                                               break;
                                            case 5:
                                               tab[kk][kg].cz2.assign(tekst.substr(poz,(poz2-poz)));
                                               break;
                                            case 6:
                                               tab[kk][kg].pt2.assign(tekst.substr(poz,(poz2-poz)));
                                               break;
                                        }
                                        cout<<tekst.substr(poz,(poz2-poz))<<"\n";
                                }
                            }
                            ke++;
                            if(ke>6){
                                ke=0;
                                kg++;
                            }
                        }
                        else{
                            nowy=0;
                        }
                    }
                    //cout<<tekst<<"\n";
                }
            }
        }
        else{ //nie udalo sie otworzyc pliku o<kk>.html
            cout<<"Brak dostepu do pliku o"<<kk<<".html\n";
        }
    kk++;
    plik.close(); //zamkniecie pliku
    }
return 0;
}
