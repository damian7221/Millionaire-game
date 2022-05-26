#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <limits>
#include <cctype>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

class gra
{
private:
    int a_nr_lini = 0, tab[12], numer_kwoty = 0, numer_pytania = 1, ktory_raz = 0, ktory_raz_pol=0, ktory_raz_pol2=0, ktory_raz_telefon=0;
public:
    void sprawdzenie(string poprawnaodpowiedz, string odpowiedz);
    //__
    void otrzymaniepytania();
    //__
    void odliczanie(int czas);
    //__
    void zamiana_pytania();
    //__
    void kola_ratunkowe();
    //__
    string numer_pytania2(int x);
	//__
	void ak_linia();
	//__
	void gotoxy(int x, int y);
	//__
	int kwota();
	//__
    void pytania_do_tablicy();
	//__
	void pol_na_pol();
	//__
	void telefon_do_przyjaciela();
	//__
};

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//		FUNKCJA SPRAWDZAJĄCA POPRAWNOŚĆ PODANEJ ODPOWIEDZI

void gra::sprawdzenie(string poprawnaodpowiedz, string odpowiedz)		//sprawdzanie czy podana odpowiedz jest poprawna
{
    for(;;) //nieskonczona petla
	{

		//odpowiedz = toupper(odpowiedz);

		string poprawna1, poprawna2;
		poprawna1 = poprawnaodpowiedz[0];			//zapisanie poprawnej odpowiedzi z wielkiej litery
		poprawna2 = poprawnaodpowiedz[1];			//zapisanie poprawnej odpowiedzi z malej litery

		//odliczanie(3);

		if (odpowiedz == poprawna1)					//sprawdzenie czy podana odpowiedz jest poprawna z wielkiej litery
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			numer_pytania++;
			cout << "------------------------------------------------------------------------------------------------" << endl;
			cout << "Poprawna odpowiedz! Wygrywasz: " << kwota() << " złoty!" << endl << endl;
			numer_kwoty++;
            cout << "Przechodzisz do pytania numer " << numer_pytania << endl;
            break;
		}

		else if (odpowiedz == poprawna2)			//sprawdzenie czy podana odpowiedz jest poprawna z malej litery
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			numer_pytania++;
			cout << "------------------------------------------------------------------------------------------------" << endl;
			cout << "Poprawna odpowiedz! Wygrywasz: " << kwota() << " złoty!" << endl << endl;
			numer_kwoty++;
            cout << "Przechodzisz do pytania numer " << numer_pytania << endl;
            cout << endl;
            break;
		}

		else if (odpowiedz == "1")					//przejście do kola ratunkowego
		{
            cout << endl;
			kola_ratunkowe();
			break;
		}

		else										//zakończenie gry przez podanie niepoprawnej odpowiedzi
		{	SetConsoleTextAttribute(hOut, FOREGROUND_RED |FOREGROUND_INTENSITY);
			cout << "------------------------------------------------------------------------------------------------" << endl;
		 	cout << "Nieprawidłowa odpowiedz! To koniec gry!" << endl;
            cout << endl;
		 	exit(0);

		}
	}
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//  %%% FUNKCJA WYŚWIETLAJĄCA WYLOSOWANE PYTANIE %%%

void gra::otrzymaniepytania()						//otrzymanie wylosowanego pytania
{
	if(numer_pytania==13)							//sprawdzenie czy użytkownik odpowiedział na 12 pytań, jeżeli tak zakończenie gry
	{
		cout << "Gratulację! Udało Ci się odpowiedzieć poprawnie na 12 pytań!" << endl;
		cout << "Wygrywasz MILION ZŁOTY!!!" << endl;
		exit(0);
	}

    string odpowiedz;

	string numerpytania = numer_pytania2(numer_pytania);			//wylosowanie numeru pytania

    ifstream f(numerpytania);						//odczytanie z pliku txt
    string s, poprawna;

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN |FOREGROUND_INTENSITY);

	cout << "------------------------------------------------------------------------------------------------" << endl;

    for (int i = 2; i <= 2; i++)					//wyświetlenie wylosowanego pytania
    {
        getline(f, s);
		cout << s << endl;
    }

	for (int i = 3; i <= 4; i++)					//pominięcie drugiej oraz trzeciej linijki tekstu
    {
        getline(f, s);
    }

	for (int i = 5; i <= 8; i++)					//wyświetlenie odpowiedzi 
    {
        getline(f, s);
		cout << s << endl;
    }
	cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "Jeżeli chcesz skorzystać z koła ratunkowego wpisz '1' " << endl << endl;

	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE |FOREGROUND_INTENSITY);
	cout << "Podaj odpowiedź: ";
	cin >> odpowiedz;

	for (int i = 9; i <= 9; i++)					//odczytanie poprawnej odpowiedzi
    {
        getline(f, poprawna);
    }

	sprawdzenie(poprawna, odpowiedz);				//sprawdzenie czy podana odpowiedz jest prawidłowa
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//	%%% FUNKCJA ODLICZAJĄCA CZAS %%%

void gra::odliczanie(int czas)						//odliczanie podanego czasu
{
    for (int czas = 3; czas > 0; czas--)
    {
              cout << czas << "\n";
              ak_linia();
              gotoxy(1, a_nr_lini);
              Sleep(1000);
              if (czas == 1) cout << endl;
    }
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//	%%% FUNKCJA POBIERAJĄCA KORDY W TERMINALU (potrzebne do usuwania odliczającego czasu TYLKO W .EXE!!!) %%%

void gra::gotoxy(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//	%%% FUNKCJA ZAMIENIAJĄCA PYTANIE (jedno z kół ratunkowych) %%%

void gra::zamiana_pytania()
{
		if(ktory_raz == 0)                                                  //sprawdzenie czy koło ratunkowe jest wykorzystywane po raz pierwszy 
    	{
        	ktory_raz=ktory_raz+1;                                          //dodanie liczby 1, aby koło nie zostało wykorzystane po raz drugi 

			cout << "Pytanie zostało zamienione! Nowe pytanie: " << endl;
        	tab[numer_pytania] = (rand()%(50-1)) + 1;                       //wylosowanie nowego pytania 
            otrzymaniepytania();
    	}
    	else if(ktory_raz==1)                                            
    	{
        	cout << "To kolo ratunkowe zostało wykorzystane! Wracasz do poprzedniego pytania: " << endl;
            otrzymaniepytania();
    	}

}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//	%%% FUNKCJA ODRZUCAJĄCA DWIE BŁĘDNE ODPOWIEDZI (jedno z kół ratunkowych) %%%

void gra::pol_na_pol()
{
		if(ktory_raz_pol == 0)                                                  //sprawdzenie czy koło ratunkowe jest wykorzystywane po raz pierwszy 
    	{
        	ktory_raz_pol=ktory_raz_pol+1;                                          //dodanie liczby 1, aby koło nie zostało wykorzystane po raz drugi 

			cout << "Pytanie po odrzuceniu dwóch błędnych odpowiedzi: " << endl;

        	string odpowiedz;

			string numerpytania = numer_pytania2(numer_pytania);			//wylosowanie numeru pytania

    		ifstream f(numerpytania);						//odczytanie z pliku txt
    		string s, poprawna;

			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN |FOREGROUND_INTENSITY);

			cout << "------------------------------------------------------------------------------------------------" << endl;

    		for (int i = 2; i <= 2; i++)					//wyświetlenie wylosowanego pytania
    		{	
        		getline(f, s);
				cout << s << endl;
    		}

			for (int i = 3; i <= 4; i++)					//wyświetlenie pierwszej i drugiej pozostałej odpowiedzi
    		{
        		getline(f, s);
				cout << s << endl;
    		}

			for (int i = 4; i <= 7; i++)					//pominięcie linijek zawierających odpowiedzi 
    		{
        		getline(f, s);
    		}

			cout << "------------------------------------------------------------------------------------------------" << endl;
    		cout << "Jeżeli chcesz skorzystać z koła ratunkowego wpisz '1' " << endl << endl;

			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE |FOREGROUND_INTENSITY);
			cout << "Podaj odpowiedź: ";
			cin >> odpowiedz;

			for (int i = 9; i <= 9; i++)					//odczytanie poprawnej odpowiedzi
    		{
        		getline(f, poprawna);
    		}

			sprawdzenie(poprawna, odpowiedz);				//sprawdzenie czy podana odpowiedz jest prawidłowa
    	}

    	else if(ktory_raz_pol==1)                                            
    	{
        	cout << "To kolo ratunkowe zostało wykorzystane! Wracasz do poprzedniego pytania: " << endl;
            otrzymaniepytania();
    	}

}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%% FUNKCJA TELEFON DO PRZYJACIELA %%%

void gra::telefon_do_przyjaciela()
{
	if(ktory_raz_telefon == 0)
	{
		ktory_raz_telefon=ktory_raz_telefon+1;

		int wybor_tekstu;
		string tekst, poprawna_przyjaciela;

		wybor_tekstu = (rand()%(6-1)) + 1;

		ifstream f("pytania/przyjaciel.txt");

		for (int i = 1; i <= wybor_tekstu; i++)					//wybór tekstu przyjaciela
    	{
        	getline(f, tekst);
    	}

		int numer_aktualnego_pytania1 = tab[numer_pytania];

		string numer_aktualnego_pytania2 = to_string(numer_aktualnego_pytania1);

		string numerpytania3 = "pytania/";

		numerpytania3.append(numer_aktualnego_pytania2);

		numerpytania3.append(".txt");

		ifstream d(numerpytania3);

	
		for (int i = 1; i <= 8; i++)							//odczytanie poprawnej odpowiedzi
    	{
        	getline(d, poprawna_przyjaciela);
    	}

		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN |FOREGROUND_INTENSITY);				//zamiana koloru tekstu w konsoli
		cout << "-Halo halo, z tej strony Hubert Urbański! MILIONERZY!" << endl;
		Sleep(2000);
		cout << "-O wow, jestem w szoku! Pozdrawiam wszystkich widzów!" << endl;
		Sleep(2000);
		cout << "-Co tam u Ciebie? Wszystko dobrze?" << endl;
		Sleep(2000);
		cout << "-Tak, tylko trochę się stresuję." << endl;
		Sleep(2000);
		cout << "-Za chwilę usłyszysz pytanie oraz 4 możliwe odpowiedzi" << endl;
		Sleep(2000);
		cout << "-Eeeeee......." << endl;
		Sleep(3000);
		cout << tekst << " " << poprawna_przyjaciela[0] << endl;
	}

	else if(ktory_raz_telefon == 1)
	{
		cout << "To kolo ratunkowe zostało wykorzystane! Wracasz do poprzedniego pytania: " << endl;
        otrzymaniepytania();
	}

}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%% FUNKCJA Z KOŁAMI RATUNKOWYMI %%%

void gra::kola_ratunkowe()							//wybór koła ratunkowego
{
    int wybor_kola;
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "Masz do wykorzystania 3 kola ratunkowe:" << endl;
	cout << "1. Zamiana pytania!" << endl << endl;
	cout << "2. Odrzucenie dwóch błędnych odpowiedzi!" << endl << endl;
	cout << "3. Telefon do przyjaciela!" << endl << endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;

	cout << "Ktore kolo wybierasz: ";
	cin >> wybor_kola;
    cout << endl;

	if(wybor_kola == 1)
	{
		zamiana_pytania();
	}

	else if(wybor_kola == 2)
	{
		pol_na_pol();
	}

	else if(wybor_kola == 3)
	{
		telefon_do_przyjaciela();
	}
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//	%%% FUNKCJA ZWRACAJĄCA NUMER PYTANIA JAKO TEKST %%%

string gra::numer_pytania2(int x)						//funkcja losująca numer pytania
{   
	int numer_liczby_tablicy;
	numer_liczby_tablicy = tab[x];

    string numerpytania = to_string(numer_liczby_tablicy);

	string numerpytania3 = "pytania/";

	numerpytania3.append(numerpytania);
	return numerpytania3.append(".txt");
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//	%%% FUNKCJA ZAPISUJĄCA LICZBY PYTAŃ DO TABLICY %%%

void gra::pytania_do_tablicy()							//wybór kola ratunkowego
{
    srand(time(NULL));

    for (int i = 0; i<12; i++)
    {
        tab[i] = (rand()%(50-1)) + 1 ;				//wpisanie do tablicy losowych liczb
        for (int j = 0; j<i; j++)
        {
            if (tab[j] == tab[i])
            {
                tab[i] = (rand()%(50-1)) + 1 ;
                j = -1; // bo zaraz j zostanie zinkrementowane
            }
            // o tutaj następuje j++ (na końcu pętli, bo postinkrementacja)
        }
    }

}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//	%%% FUNKCJA DO USUWANIA TEKSTU PODCZAS ODLICZANIA (program trzeba uruchomić w .exe) %%%

void gra::ak_linia()
{
	HANDLE hOutt;
	hOutt = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;
		GetConsoleScreenBufferInfo(hOutt, &SBInfo);
		a_nr_lini = SBInfo.dwCursorPosition.Y;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%% FUNKCJA ZWRACAJĄCA WYGRANĄ KWOTĘ %%%

int gra::kwota()
{
	int tab2[12];
	tab2[0] = 500, tab2[1] = 1000, tab2[2] = 2000, tab2[3] = 5000, tab2[4] = 10000, tab2[5] = 20000, tab2[6] = 40000, tab2[7] = 75000;
	tab2[8] = 125000, tab2[9] = 250000, tab2[10] = 500000, tab2[11] = 10000000;

	return tab2[numer_kwoty];
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int main()
{	setlocale( LC_ALL, "" ); 			//polskie znaki w konsoli
    gra gra1;

	cout << "==========================================================\n"
		<< "                       Milionerzy!                         \n"
		<< "                   Autor: Damian Łojko                     \n"
		<< "==========================================================\n";

    	//wstęp
		cout << "Podaj swoje imię: ";
		string imie;
		cin >> imie;
		cout << endl;


		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN |FOREGROUND_INTENSITY);				//zamiana koloru tekstu w konsoli
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "Cześć " << imie << " bierzesz udział w grze, w której możesz wygrać MILION zloty!!!" << endl;
		cout << "Naciśnij dowolny klawisz, aby kontynuować..." << endl;
		cout << "------------------------------------------------------------------------------------------------" << endl;
        getch();
		gra1.odliczanie(3);
		cout << endl;

		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "ZASADY:" << endl;
		cout << "1. Aby ukończyć gre trzeba odpowiedzieć poprawnie na 15 pytań" << endl;
		cout << "2. Masz trzy kola ratunkowe: telefon do przyjaciela, zamiana pytania oraz odrzucenie dwóch błędnych odpowiedzi." << endl;
		cout << "3. Odpowiedzi możesz zapisywać z wielkiej oraz malej litery"<<endl;
		cout << "------------------------------------------------------------------------------------------------" << endl << endl;

		cout << "Naciśnij dowolny klawisz, aby kontynuować..." << endl;
        getch();
		gra1.odliczanie(3);

        gra1.pytania_do_tablicy();

        for(;;)
        {
            gra1.otrzymaniepytania();		//pierwsze pytanie
        }



	//system("pause");
    return 0;
}