#include "geaca.h"
#include "magazin.h"
#include "articol.h"
#include "cos.h"
#include "client.h"


geaca :: geaca(int price, string name, string color, string mat , int S, int M, int L, string imp) : articol(price, name, color, mat , S, M, L)
        {
            setPret(price);
            setNume(name);
            setCuloare(color);
            setMaterial(mat);
            setStoc("S", S);
            setStoc("M", M);
            setStoc("L", L);
            setImpermeabil(imp);
        }
geaca :: geaca(const geaca& nou) : articol(nou)
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
            this->impermeabil = nou.impermeabil;
        }
void geaca :: setImpermeabil(string s)
{
    impermeabil = s;
}
string geaca :: getImpermeabil() const
{
    return impermeabil;
}
void geaca :: afisareArticol(geaca x)
{
    cout <<"\n Nume: " << x.getNume() << "\n" << " Pret: " << x.getPret() << "\n Material: " << x.getMaterial() << "\n Culoare: " << x.getCuloare() << "\n Produs impermeabil: "<< x.getImpermeabil() << "\n";
}

void geaca :: reducere(int procent)
{
    if ( impermeabil != "da" )
    {
        int pret_nou = pret - (pret * procent)/100;
        pret = pret_nou;
    }
}