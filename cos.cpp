#include "cos.h"
#include "articol.h"
#include <memory>
#include <algorithm>


ostream& operator<<(ostream& out, const cos& c)
        {
            out << c.getCostTotal() << "  " << c.getAdresaLivrare() << " " << c.getComandat();
            return out;
        }

void cos:: setCostTotal(int n)
        {
            cost_total = n;
        }
int cos ::  getCostTotal() const
        {
            return cost_total;
        }
void cos :: setComandat(bool n)
        {
            comandat = n;
        }
bool cos :: getComandat() const
        {
            return comandat;
        }
void cos :: setAdresaLivrare(string s)
        {
            adresa_livrare= s;
        }
string cos :: getAdresaLivrare() const
        {
            return adresa_livrare;
        }
void cos :: setCumparaturi(articol* adresaArticol, int i)
        {
            cumparaturi[i] = adresaArticol;
        }
articol* cos:: getCumparaturi(int i) const
        {
            return cumparaturi[i];
        }

void cos :: adauga_in_Cos(articol x,  int nrBucati, string m)
{
    bool existaInCos = false;
    if ( nrBucati > x.getStoc( m ))
        cout << "\nNu exista destule bucati in stoc!!!!! \n";
    else
    {
        for (int i = 0; i < 99 && getCumparaturi(i) != 0 ; ++i) 
        {
            if (*getCumparaturi(i) == x ) 
            {
                getCumparaturi(i)->setnrCos(getCumparaturi(i)->getnrCos() + nrBucati);
                existaInCos = true;
                break;
            }
        }
        if( existaInCos == false)
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
    
    
}

void cos :: golesteCosul()
{
    for (int i = 0; i < 99 && getCumparaturi(i) != 0; ++i)
    {
        std :: unique_ptr<articol> articol_ptr(getCumparaturi(i));
        string marime = articol_ptr->getMarime();
        articol_ptr->setStoc(marime, getCumparaturi(i)->getStoc(marime) - getCumparaturi(i)->getnrCos());
    }
}
bool cos :: comparaPret(const articol* x, const articol* y)
{
    if (x->getPret() > y->getPret())
        return true;
    else 
        return false;
}
void cos :: veziCosul()
{
    std :: sort(cumparaturi, cumparaturi + 99, comparaPret);
    int i = 0;
    while (i < 99 &&  getCumparaturi(i) != 0 )
    {
        getCumparaturi(i)->afisareArticol(*getCumparaturi(i));
        cout << " Marime: " << getCumparaturi(i)->getMarime() << "\n";
        cout << " Cantitate: " << getCumparaturi(i)->getnrCos() << "\n";
        ++i;
    }        
}

