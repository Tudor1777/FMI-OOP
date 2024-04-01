#include <iostream>
using namespace std;
class articol
{
    protected:
        int pret;
        int stoc;
        int nrCos;
        string nume;
        string marime;
        string culoare;
        string material;
        string gen;
        int stocS;
        int stocM;
        int stocL; 
    public:
        virtual ~articol() {};
        friend ostream& operator<<(ostream& out, const articol& x)
        {
            cout <<"\n Nume: " << x.getNume() << "\n" << " Pret: " << x.getPret() << "\n Material: " << x.getMaterial() << "\n Culoare: " << x.getCuloare() << "\n";
            return out;
        }
        void afisareArticol(articol x);
        void setPret(int n)
        {
            pret = n;
        }
        int getPret() const
        {
            return pret;
        }
        void setStoc(string s, int n)
        {
            if ( s == "S" )
                stocS = n;
            if ( s == "M" )
                stocM = n;
            if ( s == "L" )
                stocL = n;
        }
        int getStoc(string s) const
        {
            if ( s == "S" )
                return stocS;
            if ( s == "M" )
                return stocM;
            if ( s == "L" )
                return stocL;
        }
        void setnrCos(int n)
        {
            nrCos = n;
        }
        int getnrCos() const
        {
            return nrCos;
        }
        void setNume(string s)
        {
            nume = s;
        }
        string getNume() const
        {
            return nume;
        }
        void setMarime(string s)
        {
            marime = s;
        }
        string getMarime() const
        {
            return marime;
        }
        void setCuloare(string s)
        {
            culoare = s;
        }
        string getCuloare() const
        {
            return culoare;
        }
        void setMaterial(string s)
        {
            material= s;
        }
        string getMaterial() const
        {
            return material;
        }
        void setGen(string s)
        {
            gen= s;
        }
        string getGen() const
        {
            return gen;
        }
};
    void articol :: afisareArticol(articol x)
{
    cout <<"\n Nume: " << x.getNume() << "\n" << " Pret: " << x.getPret() << "\n Material: " << x.getMaterial() << "\n Culoare: " << x.getCuloare() << "\n";
}

class cos
{
    private:
        articol *cumparaturi[99] = {0};
        int cost_total = 0;
        bool comandat;
        string adresa_livrare;
    public:
        ~cos() {}
        friend ostream& operator<<(ostream& out, const cos& c)
        {
            out << c.cost_total << "  " << c.adresa_livrare << " " << c.comandat;
            return out;
        }
        void adauga_in_Cos(articol &x,  int nrBucati, string m); 
        void golesteCosul();
        void veziCosul();
        void setCostTotal(int n)
        {
            cost_total = n;
        }
        int getCostTotal() const
        {
            return cost_total;
        }
        void setComandat(bool n)
        {
            comandat = n;
        }
        bool getComandat() const
        {
            return comandat;
        }
        void setAdresaLivrare(string s)
        {
            adresa_livrare= s;
        }
        string getAdresaLivrare() const
        {
            return adresa_livrare;
        }
        void setCumparaturi(articol* adresaArticol, int i)
        {
            cumparaturi[i] = adresaArticol;
        }
        articol *getCumparaturi(int i) const
        {
            return cumparaturi[i];
        }
};
    void cos :: adauga_in_Cos(articol &x,  int nrBucati, string m)
{
    if ( nrBucati > x.getStoc( m ))
        cout << "\nNu exista destule bucati in stoc! \n";
    else
    {
        for (int i = 0; i < 99; ++i)
        {
            if (getCumparaturi(i) == 0)
            {
                setCumparaturi(new articol(x), i);
                getCumparaturi(i)->setnrCos(nrBucati);
                getCumparaturi(i)->setMarime(m);
                break;
            }
        }
    }
    
}
    void cos :: golesteCosul()
{
    for (int i = 0; i < 99 && getCumparaturi(i) != 0; ++i)
    {
        string marime = getCumparaturi(i)->getMarime();
        getCumparaturi(i)->setStoc(marime, getCumparaturi(i)->getStoc(marime) - getCumparaturi(i)->getnrCos());
        // setCumparaturi(getCumparaturi(i), 0);
    }
}
    void cos :: veziCosul()
{
    int i = 0;
    while ( getCumparaturi(i) != 0 && i < 99 )
    {
        cumparaturi[i]->afisareArticol(*getCumparaturi(i));
        cout << " Marime: " << getCumparaturi(i)->getMarime() << "\n";
        cout << " Cantitate: " << getCumparaturi(i)->getnrCos() << "\n";
        ++i;
    }
    
    
        
}

class client
{
    private:
        string tara;
        string gen;
        string adresa;
        bool livrare_rapida;
        string metoda_plata;
    public:
        ~client() {};
        friend ostream& operator<<(ostream& out, const client& c)
        {
            out << c.tara << "  " << c.adresa << " " << c.livrare_rapida;
            return out;
        }
        void setTara(string s)
        {
            tara = s;
        }
        void setGen(string s)
        {
            gen = s;
        }
        string getGen() const
        {
            return gen;
        }
        void setAdresa(string s)
        {
            adresa = s;
        }
        void setLivrare(bool b)
        {
            livrare_rapida = b;
        }
        
};

class tricou: public articol 
{
    public:
        tricou(int price, string name, string color, string mat , int S, int M, int L)
        {
            setPret(price);
            setNume(name);
            setCuloare(color);
            setMaterial(mat);
            setStoc("S", S);
            setStoc("M", M);
            setStoc("L", L);
        }
        tricou(const tricou& nou) 
        {
            this->pret = nou.pret;
            this->stoc = nou.stoc;
            this->nrCos = nou.nrCos;
            this->nume = nou.nume;
            this->marime = nou.marime;
            this->culoare = nou.culoare;
            this->material = nou.material;
            this->gen = nou.gen;
            this->stocS = nou.stocS;
            this->stocM = nou.stocM;
            this->stocL = nou.stocL;
        }
};
class hanorac: public articol 
{
    public:
        hanorac(int price, string name, string color, string mat , int S, int M, int L)
        {
            setPret(price);
            setNume(name);
            setCuloare(color);
            setMaterial(mat);
            setStoc("S", S);
            setStoc("M", M);
            setStoc("L", L);
        }
        hanorac(const hanorac& nou) 
        {
            this->pret = nou.pret;
            this->stoc = nou.stoc;
            this->nrCos = nou.nrCos;
            this->nume = nou.nume;
            this->marime = nou.marime;
            this->culoare = nou.culoare;
            this->material = nou.material;
            this->gen = nou.gen;
            this->stocS = nou.stocS;
            this->stocM = nou.stocM;
            this->stocL = nou.stocL;
        }
};
class geaca: public articol 
{
    public:
        geaca(int price, string name, string color, string mat , int S, int M, int L)
        {
            setPret(price);
            setNume(name);
            setCuloare(color);
            setMaterial(mat);
            setStoc("S", S);
            setStoc("M", M);
            setStoc("L", L);
        }
        geaca(const geaca& nou) 
        {
            this->pret = nou.pret;
            this->stoc = nou.stoc;
            this->nrCos = nou.nrCos;
            this->nume = nou.nume;
            this->marime = nou.marime;
            this->culoare = nou.culoare;
            this->material = nou.material;
            this->gen = nou.gen;
            this->stocS = nou.stocS;
            this->stocM = nou.stocM;
            this->stocL = nou.stocL;
        }
};
class camasa: public articol 
{
    public:
        camasa(int price, string name, string color, string mat , int S, int M, int L)
        {
            setPret(price);
            setNume(name);
            setCuloare(color);
            setMaterial(mat);
            setStoc("S", S);
            setStoc("M", M);
            setStoc("L", L);
        }
        camasa(const camasa& nou) 
        {
            this->pret = nou.pret;
            this->stoc = nou.stoc;
            this->nrCos = nou.nrCos;
            this->nume = nou.nume;
            this->marime = nou.marime;
            this->culoare = nou.culoare;
            this->material = nou.material;
            this->gen = nou.gen;
            this->stocS = nou.stocS;
            this->stocM = nou.stocM;
            this->stocL = nou.stocL;
        }
};

class magazin 
{
    private:
        int castig = 0;
        tricou *tricouri[99] = {0};
        hanorac *hanorace[99] = {0};
        camasa *camasi[99] = {0};
        geaca *geci[99] = {0};
    public:
        ~magazin()
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
        friend ostream& operator<<(ostream& out, const magazin& m)
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
        void setCastig(int n)
        {
            castig = n;
        }
        int getCastig() const
        {
            return castig;
        }
        //tricouri
        void setTricouri(tricou *adresaTricou, int i)
        {
            tricouri[i] = adresaTricou;
        }
        tricou *getTricouri(int i) const
        {
            return tricouri[i];
        }
        void adaugaTricou(tricou &x);
        void veziTricouri() const;
        //hanorace
        void setHanorace(hanorac *adresaHanorac, int i)
        {
            hanorace[i] = adresaHanorac;
        }
        hanorac *getHanorace(int i) const
        {
            return hanorace[i];
        }
        void adaugaHanorac(hanorac &x);
        void veziHanorace();
        //camasi
        void setCamasi(camasa *adresaCamasa, int i)
        {
            camasi[i] = adresaCamasa;
        }
        camasa *getCamasi(int i) const
        {
            return camasi[i];
        }
        void adaugaCamasa(camasa &x);
        void veziCamasi();
        //geci
        void setGeci(geaca *adresaGeaca, int i)
        {
            geci[i] = adresaGeaca;
        }
        geaca *getGeci(int i) const
        {
            return geci[i];
        }
        void adaugaGeaca(geaca &x);
        void veziGeci();
        //comanda
        void comanda(cos c, client user);
        //meniu
        void meniu();
        
};
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
    void magazin :: veziTricouri() const
{
    int i = 0;
    while ( i < 99 && tricouri[i] != 0)
    {
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
        int n, y, nr_bucati;
        string s;
        cos c;
        client client1;
        cout << "Introduceti tara de origine : ";
        cin >> s;
        client1.setTara(s);
        while ( true )
        {
        cout << "Alegeti categoria: \n 1.Tricouri \n 2.Hanorace \n 3.Camasi \n 4.Geci \n 5.Vezi cosul \n";
        cin >> n;
        if ( n == 1 )
        {
            veziTricouri();
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
        }
        if ( n == 5 )
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
int main()
{
    magazin m;
    tricou tricou1(250, "tricou 1", "rosu", "bumbac", 200, 100, 300), tricou2(400, "tricou 2", "negru", "bumbac", 30, 10, 15);
    hanorac hanorac1(500, "hanorac 1", "alb", "bumbac", 100, 150, 100), hanorac2(650, "hanorac 2", "negru", "bumbac", 10, 15, 20);
    camasa camasa1(400, "camasa 1", "alb", "in", 50, 50, 50);
    geaca geaca1(1200, "geaca de piele", "negru", "piele naturala", 20, 30, 20);
    m.adaugaTricou(tricou1);
    m.adaugaTricou(tricou2);
    m.adaugaHanorac(hanorac1);
    m.adaugaHanorac(hanorac2);
    m.adaugaCamasa(camasa1);
    m.adaugaGeaca(geaca1);
    m.meniu();
    return 0;
}