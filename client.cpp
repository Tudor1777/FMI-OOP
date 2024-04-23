#include "client.h"


ostream& operator<<(ostream& out, const client& c)
        {
            out << c.getTara() << "  " << c.getAdresa() << " " << c.getLivrare();
            return out;
        }
void client :: setTara(string s)
        {
            tara = s;
        }
string client :: getTara() const
        {
            return tara;
        }
void client :: setGen(string s)
        {
            gen = s;
        }
string client :: getGen() const
        {
            return gen;
        }
void client :: setAdresa(string s)
        {
            adresa = s;
        }
string client :: getAdresa() const
        {
            return adresa;
        }
void client :: setLivrare(bool b)
        {
            livrare_rapida = b;
        }
bool client :: getLivrare() const
        {
            return livrare_rapida;
        }