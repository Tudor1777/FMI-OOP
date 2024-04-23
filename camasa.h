#ifndef CAMASA_H
#define CAMASA_H
#include <iostream>
#include "articol.h"
#include "cos.h"
#include "client.h"
using namespace std;

class camasa: public articol 
{
    public:
        camasa(int price, string name, string color, string mat , int S, int M, int L); 
        camasa(const camasa& nou);
};

#endif