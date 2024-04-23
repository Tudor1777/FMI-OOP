#ifndef GEACA_H
#define GEACA_H
#include <iostream>
#include "articol.h"
#include "cos.h"
#include "client.h"
using namespace std;

class geaca: public articol 
{
    protected:
        string impermeabil;
    public:
        geaca(int price, string name, string color, string mat , int S, int M, int L, string imp);
        geaca(const geaca& nou);
        void setImpermeabil(string s);
        string getImpermeabil() const;
        void afisareArticol(geaca x);
        void reducere(int procent);
       
};

#endif