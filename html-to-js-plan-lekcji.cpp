#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
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
    int liczba_klas,lg,lk; //liczba_klas = liczba klas w szkole, lg = najwieksza liczba godzin lekcyjnych
    int j,i,vec,kk=1,kg,ke,poz,poz2; //kk = ktora klasa, kg = ktora godzina, ke = ktory element (dzien itp.), vec = takie i tylko do vectora
    string tekst,nazwap="o1.html",pom; //tekst = obecnie rozpatrywana linijka tekstu, nazwap = nazwa pliku ktory jest aktualnie rozpatrywany, pom = zmienna pomocnicza
    bool nowy=1,gr2=0,byl;    //nowy = czy to pierwsze przejscie programu po uruchomieniu nowego pliku, gr2 = czy o danej godzinie ma lekcje 2. grupa, byl = czy dany element jest juz w wectorze sale
    //*string dt; //dzien tygodnia
    vector <string> sale;
    //PROGRAM
    //przypisanie wartosci zmiennym
    liczba_klas = 26;
    lg = 14;
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
            cout<<"Nr.L:\tGodziny\t\tPn\tWt\tSr\tCz\tPt\n";
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
                            if(ke==0){ //Nr. lekcji
                                tab[kk][kg].NrL.assign(tekst.substr(poz,poz2-poz));
                                cout<<tab[kk][kg].NrL<<"\t";
                            }
                            else if(ke==1){ //godziny trwania lekcji
                                tab[kk][kg].godz.assign(tekst.substr(poz,(poz2-poz)));
                                cout<<tab[kk][kg].godz<<" ";
                            }
                            else{ //ktorys z dni tygodnia
                                if(tekst[poz]=='&'){
                                    switch(ke){
                                        case 2:
                                            tab[kk][kg].pn.assign("");
                                            break;
                                        case 3:
                                            tab[kk][kg].wt.assign("");
                                            break;
                                        case 4:
                                            tab[kk][kg].sr.assign("");
                                            break;
                                        case 5:
                                            tab[kk][kg].cz.assign("");
                                            break;
                                        case 6:
                                            tab[kk][kg].pt.assign("");
                                            break;
                                    }
                                    cout<<"\t";
                                }
                                else{
                                    poz = tekst.find("\"s\"",poz2);
                                    poz +=4;
                                    poz2 = tekst.find("<",poz);
                                    switch(ke){
                                        case 2:
                                            tab[kk][kg].pn.assign(tekst.substr(poz,(poz2-poz)));
                                            break;
                                        case 3:
                                            tab[kk][kg].wt.assign(tekst.substr(poz,(poz2-poz)));
                                            break;
                                        case 4:
                                            tab[kk][kg].sr.assign(tekst.substr(poz,(poz2-poz)));
                                            break;
                                        case 5:
                                            tab[kk][kg].cz.assign(tekst.substr(poz,(poz2-poz)));
                                            break;
                                        case 6:
                                            tab[kk][kg].pt.assign(tekst.substr(poz,(poz2-poz)));
                                            break;
                                    }
                                    cout<<"\t"<<(tekst.substr(poz,(poz2-poz)));
                                    //uzupelnianie vectora sala o sale, ktore wczesniej sie nie pojawily
                                    byl=0;
                                    pom.assign(tekst.substr(poz,(poz2-poz)));
                                    for(vec=0;vec<sale.size();vec++){
                                        if(pom == sale[vec]){
                                            byl=1;
                                            break;
                                        }
                                    }
                                    if(!byl){
                                        sale.push_back(pom);
                                    }
                                }
                            }
                            if(ke>1){
                                poz2 = tekst.find("\"s\"",poz2);
                                if(poz2 != string::npos){
                                    gr2 = 1;
                                        poz = poz2+4;
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
                                        cout<<","<<tekst.substr(poz,(poz2-poz));
                                        //uzupelnianie vectora sala o sale, ktore wczesniej sie nie pojawily
                                        byl=0;
                                        pom.assign(tekst.substr(poz,(poz2-poz)));
                                        for(vec=0;vec<sale.size();vec++){
                                            if(pom == sale[vec]){
                                                byl=1;
                                                break;
                                            }
                                        }
                                        if(!byl){
                                            sale.push_back(pom);
                                        }
                                }
                                else{
                                    switch(ke){
                                        case 2:
                                            tab[kk][kg].pn2.assign("");
                                            break;
                                        case 3:
                                            tab[kk][kg].wt2.assign("");
                                            break;
                                        case 4:
                                            tab[kk][kg].sr2.assign("");
                                            break;
                                        case 5:
                                            tab[kk][kg].cz2.assign("");
                                            break;
                                        case 6:
                                            tab[kk][kg].pt2.assign("");
                                            break;
                                    }
                                }
                            }
                            ke++;
                            if(ke>6){
                                ke=0;
                                kg++;
                                cout<<"\n";
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

    //wyswietlenie sal
    sort(sale.begin(),sale.end());
    cout<<"\nWszystkie sale dostepne w szkole ("<<sale.size()<<"):\n";
    for(vec=0;vec<sale.size();vec++){
        cout<<sale[vec]<<", ";
    }
    cout<<"\n";

    //EKSPORT DO JS
    nazwap = "plany.js";
    plik.open(nazwap,ios::out);
    lk=liczba_klas;
    if(plik.good()){
        //utworzenie zmiennych w JS
        plik<<"const lk="<<lk<<",lg="<<lg<<",ld=10,ls="<<sale.size()<<";\n";
        plik<<"let i,j;\n";
        //plik<<"let sale = [];";
        //deklaracja tablicy w JS
        plik<<"let tab = [];\n";
        plik<<"for(i=0;i<=lk;i++){\n";
        plik<<"\ttab[i] = [];\n";
        plik<<"\tfor(j=0;j<lg;j++){\n";
        plik<<"\t\ttab[i][j] = [];\n";
        plik<<"\t}\n";
        plik<<"}\n";
        //uzupelnienie tablicy w JS
        for(i=1;i<=lk;i++){
            plik<<"//oddzial "<<i<<"\n";
            for(j=0;j<lg;j++){
                plik<<"//"<<tab[i][j].NrL<<" "<<tab[i][j].godz<<"\n";
                plik<<"tab["<<i<<"]["<<j<<"][0] = \""<<tab[i][j].pn<<"\";\n";
                plik<<"tab["<<i<<"]["<<j<<"][1] = \""<<tab[i][j].wt<<"\";\n";
                plik<<"tab["<<i<<"]["<<j<<"][2] = \""<<tab[i][j].sr<<"\";\n";
                plik<<"tab["<<i<<"]["<<j<<"][3] = \""<<tab[i][j].cz<<"\";\n";
                plik<<"tab["<<i<<"]["<<j<<"][4] = \""<<tab[i][j].pt<<"\";\n";
                plik<<"tab["<<i<<"]["<<j<<"][5] = \""<<tab[i][j].pn2<<"\";\n";
                plik<<"tab["<<i<<"]["<<j<<"][6] = \""<<tab[i][j].wt2<<"\";\n";
                plik<<"tab["<<i<<"]["<<j<<"][7] = \""<<tab[i][j].sr2<<"\";\n";
                plik<<"tab["<<i<<"]["<<j<<"][8] = \""<<tab[i][j].cz2<<"\";\n";
                plik<<"tab["<<i<<"]["<<j<<"][9] = \""<<tab[i][j].pt2<<"\";\n";
            }
            plik<<"\n";
        }
        plik<<"const sale = [";
        for(vec=0;vec<sale.size()-1;vec++){
            plik<<"\""<<sale[vec]<<"\",";
        }
        plik<<"\""<<sale[sale.size()-1]<<"\"];\n";
        plik<<"let zajete = [];\n";
        plik.close();
    }
    else{
        cout<<"Nie udalo sie otworzyc / utworzyc pliku "<<nazwap<<"\n";
    }
return 0;
}
