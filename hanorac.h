#ifndef HANORAC_H
#define HANORAC_H
#include <iostream>
#include "articol.h"
#include "cos.h"
#include "client.h"
using namespace std;

class hanorac: public articol 
{
    public:
        hanorac(int price, string name, string color, string mat , int S, int M, int L);
        hanorac(const hanorac& nou);
};

#endif