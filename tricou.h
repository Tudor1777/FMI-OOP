#ifndef TRICOU_H
#define TRICOU_H
#include <iostream>
#include "articol.h"
#include "cos.h"
#include "client.h"
using namespace std;

class tricou: public articol 
{
    public:
        tricou(int price, string name, string color, string mat , int S, int M, int L);
        tricou(const tricou& nou);
        void reducere(int procent);
};

#endif