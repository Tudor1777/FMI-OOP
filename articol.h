#ifndef ARTICOL_H
#define ARTICOL_H

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
        articol(int price, string name, string color, string mat , int S, int M, int L);
        friend ostream& operator<<(ostream& out, const articol& x);
        virtual articol& operator=(const articol& nou);
        virtual bool operator==(const articol nou);
        void setPret(int n);
        int getPret() const;
        void setStoc(string s, int n);
        int getStoc(string s) const;
        void setnrCos(int n);
        int getnrCos() const;
        void setNume(string s);
        string getNume() const;
        void setMarime(string s);
        string getMarime() const;
        void setCuloare(string s);
        string getCuloare() const;
        void setMaterial(string s);
        string getMaterial() const;
        void setGen(string s);
        string getGen() const;

        virtual void afisareArticol(articol x);

        virtual void reducere(int procent);
       
};

#endif