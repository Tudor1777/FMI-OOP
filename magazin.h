#ifndef MAGAZIN_H
#define MAGAZIN_H
#include <iostream>
#include "articol.h"
#include "cos.h"
#include "client.h"
#include "tricou.h"
#include "hanorac.h"
#include "camasa.h"
#include "geaca.h"
using namespace std;

class magazin 
{
    private:
        int castig = 0;
        tricou *tricouri[99] = {0};
        hanorac *hanorace[99] = {0};
        camasa *camasi[99] = {0};
        geaca *geci[99] = {0};
    public:
        ~magazin();
        friend ostream& operator<<(ostream& out, const magazin& m);
        void setCastig(int n);
        int getCastig() const;
        //tricouri
        void setTricouri(tricou *adresaTricou, int i);
        tricou *getTricouri(int i) const;
        void adaugaTricou(tricou &x);
        void veziTricouri(int discount) const;
        //hanorace
        void setHanorace(hanorac *adresaHanorac, int i);
        hanorac *getHanorace(int i) const;
        void adaugaHanorac(hanorac &x);
        void veziHanorace();
        //camasi
        void setCamasi(camasa *adresaCamasa, int i);
        camasa *getCamasi(int i) const;
        void adaugaCamasa(camasa &x);
        void veziCamasi();
        //geci
        void setGeci(geaca *adresaGeaca, int i);
        geaca *getGeci(int i) const;
        void adaugaGeaca(geaca &x);
        void veziGeci();
        //comanda
        void comanda(cos c, client user);
        //meniu
        void meniu();
        
};
#endif