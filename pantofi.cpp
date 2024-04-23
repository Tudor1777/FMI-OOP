#include "pantofi.h"
#include "magazin.h"
#include "articol.h"
#include "cos.h"
#include "client.h"


pantofi :: pantofi(int price, string name, string color, string mat , int S, int M, int L)
        {
            setPret(price);
            setNume(name);
            setCuloare(color);
            setMaterial(mat);
            setStoc("S", S);
            setStoc("M", M);
            setStoc("L", L);
        }
pantofi :: pantofi(const pantofi& nou) 
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