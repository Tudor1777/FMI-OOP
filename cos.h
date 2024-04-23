#ifndef COS_H
#define COS_H
#include <iostream>
#include "articol.h"
using namespace std;

class cos
{
    private:
        articol *cumparaturi[99] = {0};
        int cost_total = 0;
        bool comandat;
        string adresa_livrare;
    public:
        ~cos() {}
        friend ostream& operator<<(ostream& out, const cos& c);
        void adauga_in_Cos(articol x,  int nrBucati, string m); 
        void golesteCosul();
        void veziCosul();
        void setCostTotal(int n);
        int getCostTotal() const;
        void setComandat(bool n);
        bool getComandat() const;
        void setAdresaLivrare(string s);
        string getAdresaLivrare() const;
        void setCumparaturi(articol* adresaArticol, int i);
        articol* getCumparaturi(int i) const;
        static bool comparaPret(const articol* x, const articol* y);
};
#endif