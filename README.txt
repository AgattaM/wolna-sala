Program "html-to-js-plan-lekcji.cpp" służy do przekonwertowania planów lekcji z formatu .html 
na tablicę .js, potrzebną do prawidłowego wyświetlenia danych na stronie "index.html".

OGÓLNE DZIAŁANIE PROGRAMU
Umieść plik "html-to-js-plan-lekcji.cpp" w folderze w którym masz plany lekcji wszystkich klas w formacie o0.html 
(0 - numer oddziału, numery oddziałów powinny zaczynać się od 1, np. o1.cpp lub o25.cpp)
Jeżeli w twojej szkole jest więcej klas niż 50 lub więcej godzin lekcyjnych jednego dnia niż 20, 
to otwórz plik "html-to-js-plan-lekcji.cpp" w programie pozwalającym na edycje plików tekstowych np. w notatniku, 
zmień linijkę 33 na "godzina tab[k][g];" jako "k" wstaw liczbę klas w twojej szkole, 
a jako "g" największą liczbę godzin lekcyjnych w ciągu dnia.
Po wprpwadzeniu jakichkolwiek zmian skompiluj program - jak nie wiesz jak przeczytaj punkt "Jak skompilować program?";

WARTOŚCI DOMYŚLNE
Obecnie program domyślnie zakłada, że jest 26 klas i maksymalnie 13 godzni lekcyjnych jednego dnia.
Aby to zmienić domyślną liczbę klas (oddziałów) przejdź do linijki 27 pliku "html-to-js-plan-lekcji.cpp" i w miejsce liczby 26 wpisz liczbę klas (oddziałów) w twojej szkole (pamiętaj, że na końcu linijki musi być średnik).
Aby zmienić domyślną liczbę godzin lekcyjnych przejdź do linijki 28 pliku "html-to-js-plan-lekcji.cpp" i w miejsce liczby 13 wstaw swoją wartość (pamiętaj, że na końcu linijki musi być średnik).
Po wprpwadzeniu jakichkolwiek zmian skompiluj program - jak nie wiesz jak przeczytaj punkt "Jak skompilować program?";

WYŁĄCZENIE WARTOŚCI DOMYŚLNYCH
Jeżeli chcesz by program za każym razem pytał cię o liczbę klas (oddziałów) i godzin lekcyjnych danego dnia,
wykasuj znaki "//" z początku następujących linijek: 29,30,31,32.

JAK SKOMPILOWAĆ PROGRAM?
Najłatwiej będie jak zainstalujesz program CodeBlocks, pobierając go ze strony producenta: https://www.codeblocks.org/downloads/binaries/
Postępuj według wskazówek autora programu. Koniecznie pobierz wersję zawierającą kompilator.
Po zainstalowaniu programu CodeBlocks otwór w nim plik "html-to-js-plan-lekcji.cpp" i kliknij na ikonkę z żółtą zębatką i zieloną strzałką.
Jeżeli program uruchomi się w trybie tekstowym, oznacza, że kompilacja się udała. Możesz teraz korzystać z programu.
Jeżeli program się nie uruchomi, oznacza to, że coś zrobiłeś nie tak, sprawdź czy postępowałeś wedle instrukcji podanych w tym pliku i spróbuj ponownie.

CHCĘ WYKASOWAĆ NR SALI Z LISTY
Może się zdarzyć, że jakaś sala występuje w planie lekcji części klas, ale nie chcesz jej umieszczać w tabeli wolnych sal.
Możesz wtedy po wygenerowaniu pliku "plany.js" otworzyć go i wprowadzić w nim zmiany.
Aby wykasować jakąś salę przejdź do linijki 2. i wykasuj jej numer razem z cudzysłowiami ją otaczającymi i przecinkiem występującym po niej. Jeżeli sala ta wystąpiła jako pierwsza, usuń przecinek ją poprzedzający.
Zmień również wartość zmiennej ls. W tym celu zmień liczbę która jest w pierwszej linijce po "ls=". Podaną tam liczba powinna odpowiadać liczbie sal wypisanych w linijce 2.
Czyli jak wykasowałeś jedną salę to pomniejsz tą liczbę o 1.

AUTOMATYCZNE KOŃCZENIE PROGRAMU
Aby program kończył swoje działanie bez interakcji z użytkownikiem, w pliku "html-to-js-plan-lekcji.cpp"
umieść na początku 262 linijki dwa ukośniki "//" i skompiluj program. 
Jeżeli nie wiesz jakskompilować program przeczytaj punkt "Jak skompilować Program?".

URUCHAMIANIE PLIKU "html-to-js-plan-lekcji.exe"
Jeżeli podczas uruchamiania pliku "html-to-js-plan-lekcji.exe" otrzymujesz informację, że brakuje jakichś plików o rozszerzeniu ".dll",
to przekopiuj te pliki, z miejsca w które je pobrałeś razem z cały programem, do folderu z plikiem ".exe" któr próbujesz uruchomić.
W katalogu powinieś mieć następujące pliki:
- pliki o nazwie o0.html (tyle plików ile masz klas, w iejsce 0 wstawiając numer oddziału, czyli kolejne liczby naturalne zaczynając od 1)  - są to pliki zawierające plany lekcji poszczególnych klas
- plik "html-to-js-plan-lekcji.cpp"     - kod programu konwertującego plany lekcji z postaci plików .html do tablcy w pliku plany.js
- plik "html-to-js-plan-lekcji.exe"     - program konwertujący plany lekcji z plików .html do tablicy w pliku plany.js
- plik "libgcc_s_seh-1.dll"     - biblioteka potrzebna do prawidłowego działania programu
- plik "libstdc++-6.dll"    - biblioteka potrzebna do prawidłowego działania programu
- plik "libwinpthread-1.dll"    - biblioteka potrzebna do prawidłowego działania programu
- plik "index.html"     - plik odpowiedzialny za wyświetlenie wolnych sal w postaci tabeli z podziałem na dni tygodnia i godziny
- po pierwszym udanym uruchomieniu pliku .exe plik "plany.js"   - plik przechowujący plany lekcji w postaci tablicy w 
opcjonalnie również plik "README.txt", nie jest on wymagany do poprawnego działania programu

Miłego korzystania.
Instrukcja napisana przez Agatę Majewską 28.02.2024 r.
Nowe wersje programu dostępne są na tej stronie: https://github.com/AgattaM/wolna-sala
