#include "magazin.h"
#include "articol.h"
#include "cos.h"
#include "client.h"

magazin :: ~magazin()
        {
            for (int i = 0; i < 99; ++i) 
            {
                delete tricouri[i]; 
                tricouri[i] = 0; 
                delete hanorace[i]; 
                hanorace[i] = 0;
                delete camasi[i]; 
                camasi[i] = 0;
                delete geci[i]; 
                geci[i] = 0;
            }
        } 
ostream& operator<<(ostream& out, const magazin& m)
        {
            out << m.castig << "  ";
            for (int i = 0; i < 99 && m.getTricouri(i) != 0; ++i)
            {
                out << *m.getTricouri(i);
            }
            for (int i = 0; i < 99 && m.getHanorace(i) != 0; ++i)
            {
                out << *m.getHanorace(i);
            }
            for (int i = 0; i < 99 && m.getCamasi(i) != 0; ++i)
            {
                out << *m.getCamasi(i);
            }
            for (int i = 0; i < 99 && m.getGeci(i) != 0; ++i)
            {
                out << *m.getGeci(i);
            }
            return out;
        }
void magazin :: setCastig(int n)
        {
            castig = n;
        }
int magazin :: getCastig() const
        {
            return castig;
        }
        //tricouri
void magazin :: setTricouri(tricou *adresaTricou, int i)
        {
            tricouri[i] = adresaTricou;
        }
tricou* magazin :: getTricouri(int i) const
        {
            return tricouri[i];
        }
        //hanorace
void magazin :: setHanorace(hanorac *adresaHanorac, int i)
        {
            hanorace[i] = adresaHanorac;
        }
hanorac* magazin :: getHanorace(int i) const
        {
            return hanorace[i];
        }
        //camasi
void magazin :: setCamasi(camasa *adresaCamasa, int i)
        {
            camasi[i] = adresaCamasa;
        }
camasa* magazin :: getCamasi(int i) const
        {
            return camasi[i];
        }
        //geci
void magazin :: setGeci(geaca *adresaGeaca, int i)
        {
            geci[i] = adresaGeaca;
        }
geaca* magazin :: getGeci(int i) const
        {
            return geci[i];
        }
void magazin :: adaugaTricou(tricou &x)
        {
            for ( int i = 0; i < 99; ++i )
            {
                if ( getTricouri(i) == 0)
                {
                    setTricouri(new tricou(x), i);
                    break;
                }
            }
        }
void magazin :: veziTricouri(int discount) const
{
    int i = 0;
    while ( i < 99 && tricouri[i] != 0)
    {
        getTricouri(i)->reducere(discount);
        tricouri[i]->afisareArticol(*getTricouri(i));
        ++i;
    }
}
void magazin :: adaugaHanorac(hanorac &x)
        {
            for ( int i = 0; i < 99; ++i )
            {
                if ( getHanorace(i) == 0)
                {
                    setHanorace(new hanorac(x), i);
                    break;
                }
            }
        }
void magazin :: veziHanorace()
{
    int i = 0;
    while ( i < 99 && hanorace[i] != 0)
    {

        hanorace[i]->afisareArticol(*getHanorace(i));
        ++i;
    }
}
void magazin :: adaugaCamasa(camasa &x)
        {
            camasa *p = &x;
            for ( int i = 0; i < 99; ++i )
            {
                if ( getCamasi(i) == 0)
                {
                    setCamasi(new camasa(x), i);
                    break;
                }
            }
        }
void magazin :: veziCamasi()
{
    int i = 0;
    while ( i < 99 && camasi[i] != 0)
    {
        camasi[i]->afisareArticol(*getCamasi(i));
        ++i;
    }
}
void magazin :: adaugaGeaca(geaca &x)
        {
            geaca *p = &x;
            for ( int i = 0; i < 99; ++i )
            {
                if ( getGeci(i) == 0)
                {
                    setGeci(new geaca(x), i);
                    break;
                }
            }
        }
void magazin :: veziGeci()
{
    int i = 0;
    while ( i < 99 && geci[i] != 0)
    {
        geci[i]->afisareArticol(*getGeci(i));
        ++i;
    }
}
void magazin :: comanda(cos c, client user)
        {
            int i = 0;
            while ( c.getCumparaturi(i) != 0 && i < 99 )
            {
                articol a = *c.getCumparaturi(i);
                setCastig(a.getPret() * a.getnrCos() + getCastig());
                ++i;
            }
            string adresa, livrare;
            bool b;
            cout << "\nAdresa: ";
            cin.ignore();
            getline(cin, adresa);
            user.setAdresa(adresa);
            cout << "\nDoriti livrare rapida? (+50RON) ";
            getline(cin, livrare);
            if ( livrare == "da" )
            {
                user.setLivrare( 1 );
                setCastig( getCastig() + 50 );
            }
            else 
            {
                user.setLivrare( 0 );
            }
            cout << "\nPretul total al comenzii este: " << getCastig() << "\nComanda a fost plasata.";
            // c.golesteCosul();
        }
void magazin :: meniu()
    {
        int n, y, nr_bucati, nr_oferta;
        string s, raspuns;
        cos c;
        client client1;
        cout << "Introduceti tara de origine : ";
        cin >> s;
        client1.setTara(s);
        while ( true )
        {
        cout << "Alegeti categoria: \n 1.Tricouri \n 2.Hanorace \n 3.Camasi \n 4.Geci \n 5.Oferte \n 6.Vezi cosul \n";
        cin >> n;
        if ( n == 1 )
        {
            veziTricouri(0);
            cout<< "Alegeti tricoul: ";
            cin >> y;
            cout << "Alegeti marimea: ";
            cin >> s;
            cout << "Alegeti cantitatea: ";
            cin >> nr_bucati;
        }
        if ( n == 2 )
        {
            veziHanorace();
            cout<< "Alegeti hanoracul: ";
            cin >> y;
            cout << "Alegeti marimea: ";
            cin >> s;
            cout << "Alegeti cantitatea: ";
            cin >> nr_bucati;
        }
        if ( n == 3 )
        {
            veziCamasi();
            cout<< "Alegeti camasa: ";
            cin >> y;
            cout << "Alegeti marimea: ";
            cin >> s;
            cout << "Alegeti cantitatea: ";
            cin >> nr_bucati;
        }
        if ( n == 4 )
        {
            veziGeci();
            cout<< "Alegeti geaca: ";
            cin >> y;
            cout << "Alegeti marimea: ";
            cin >> s;
            cout << "Alegeti cantitatea: ";
            cin >> nr_bucati;
            cout << "Deoarece ai cumparat o geaca, beneficiezi de o reducere de 50%. la tricourile albe (in valoare de mai putin de 150RON)!\nDoresti sa vezi selectia?\n";
            cin >> raspuns;
            if (raspuns == "da")
            {
                veziTricouri(50);
                cout<< "Alegeti tricoul: ";
                cin >> y;
                cout << "Alegeti marimea: ";
                cin >> s;
                cout << "Alegeti cantitatea: ";
                cin >> nr_bucati;
                c.adauga_in_Cos(*getTricouri(y - 1), nr_bucati, s);
            }
        }
        if ( n == 5 )
        {
            cout << "Alegeti oferta: \n1. Pentru orice geaca achizitionata primesti reducere 50%. la tricourile albe (in valoare de mai putin de 150RON)";
        }
        if ( n == 6 )
        {
            c.veziCosul();
            if ( c.getCumparaturi(0) == 0 )
            {
                cout << "\nCosul este gol!\n";
            }
            else
            {
                cout << "Comandati?\n";
                cin >> s;
                if ( s == "da" )
                    break;
            }
            
        }
        
        if ( n == 1 )
        {
            c.adauga_in_Cos(*getTricouri(y - 1), nr_bucati, s);
        }
        if ( n == 2 )
        {
            c.adauga_in_Cos(*getHanorace(y - 1), nr_bucati, s);
        }
        if ( n == 3 )
        {
            c.adauga_in_Cos(*getCamasi(y - 1), nr_bucati, s);
        }
        if ( n == 4 )
        {
            c.adauga_in_Cos(*getGeci(y - 1), nr_bucati, s);
        }
        
        
        
        }   
        comanda(c, client1);
    }
