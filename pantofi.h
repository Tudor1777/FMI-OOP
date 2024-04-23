#ifndef PANTOFI_H
#define PANTOFI_H
#include <iostream>
#include "articol.h"
#include "cos.h"
#include "client.h"
using namespace std;

class pantofi: public articol 
{
    public:
        pantofi(int price, string name, string color, string mat , int S, int M, int L); 
        pantofi(const pantofi& nou);
};

#endif