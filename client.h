#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
using namespace std;


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
        friend ostream& operator<<(ostream& out, const client& c);
        void setTara(string s);
        string getTara() const;
        void setGen(string s);
        string getGen() const;
        void setAdresa(string s);
        string getAdresa() const;
        void setLivrare(bool b);
        bool getLivrare() const;
        
};
#endif