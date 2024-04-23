#include "tricou.h"
#include "magazin.h"
#include "articol.h"
#include "cos.h"
#include "client.h"


tricou :: tricou(int price, string name, string color, string mat , int S, int M, int L) : articol(price, name, color, mat , S, M, L)
        {
            setPret(price);
            setNume(name);
            setCuloare(color);
            setMaterial(mat);
            setStoc("S", S);
            setStoc("M", M);
            setStoc("L", L);
        }
tricou :: tricou(const tricou& nou) : articol(nou)
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
void tricou :: reducere(int procent)
{
    if ( culoare == "alb" && pret < 150 )
    {
        int pret_nou = pret - (pret * procent)/100;
        pret = pret_nou;
    }
}