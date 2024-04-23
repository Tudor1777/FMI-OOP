#include "articol.h"
articol :: articol(int price, string name, string color, string mat , int S, int M, int L)
        {
            setPret(price);
            setNume(name);
            setCuloare(color);
            setMaterial(mat);
            setStoc("S", S);
            setStoc("M", M);
            setStoc("L", L);
        }
ostream& operator<<(ostream& out, const articol& x)
        {
            cout <<"\n Nume: " << x.getNume() << "\n" << " Pret: " << x.getPret() << "\n Material: " << x.getMaterial() << "\n Culoare: " << x.getCuloare() << "\n";
            return out;
        }
articol& articol::operator=(const articol& nou) 
{
    if (this != &nou) 
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
    return *this;
}
bool articol :: operator==(const articol nou)
{
    if (this->pret == nou.pret && 
        this->nume == nou.nume &&
        this->marime == nou.marime && 
        this->culoare == nou.culoare &&
        this->material == nou.material
        )
        return 1;
    else return 0;
    
}
void articol :: setPret(int n)
        {
            pret = n;
        }
int articol :: getPret() const
        {
            return pret;
        } 
void articol :: setStoc(string s, int n)
        {
            if ( s == "S" )
                stocS = n;
            if ( s == "M" )
                stocM = n;
            if ( s == "L" )
                stocL = n;
        }
int articol :: getStoc(string s) const
        {
            if ( s == "S" )
                return stocS;
            if ( s == "M" )
                return stocM;
            if ( s == "L" )
                return stocL;
            return -1;
        }

void articol ::setnrCos(int n)
        {
            nrCos = n;
        }
int articol :: getnrCos() const
        {
            return nrCos;
        }
void articol :: setNume(string s)
        {
            nume = s;
        }
string articol :: getNume() const
        {
            return nume;
        }
void articol :: setMarime(string s)
        {
            marime = s;
        }
string articol :: getMarime() const
        {
            return marime;
        }
void articol :: setCuloare(string s)
        {
            culoare = s;
        }
string articol :: getCuloare() const
        {
            return culoare;
        }
void articol :: setMaterial(string s)
        {
            material= s;
        }
string articol :: getMaterial() const
        {
            return material;
        }
void articol :: setGen(string s)
        {
            gen= s;
        }
string articol :: getGen() const
        {
            return gen;
        }

void articol :: afisareArticol(articol x)
{
    cout <<"\n Nume: " << x.getNume() << "\n" << " Pret: " << x.getPret() << "\n Material: " << x.getMaterial() << "\n Culoare: " << x.getCuloare() << "\n";
}

void articol :: reducere(int procent)
{
    int pret_nou = pret - (pret * procent)/100;
    pret = pret_nou;
}