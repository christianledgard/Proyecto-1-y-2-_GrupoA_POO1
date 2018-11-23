//
// Created by Christian Ledgard on 11/23/18.
//
#include <iostream>
using namespace std;

#ifndef PY01_CPRENDAS_H
#define PY01_CPRENDAS_H

class Prendas
{
protected:
    float Cantidad, Kg_Prenda;
    float Velocidad[3][4];
public:
    Prendas(float Cantidad, float Kg_Prenda);
    virtual ~Prendas();
};

class Polo : public Prendas
{
private:
    const float  Velocidad[3][4]{
            {1,10,20,0.2},//Jersey
            {1,10,20,0.22},//Pique
            {1,10,20,0.25}}; //Franela
public:

    Polo();
    ~Polo();
};

class Camisa : public Prendas
{
private:
    const float  Velocidad[3][4]{
            {1, 10, 20, 0.5},//Jersey
            {1, 10, 20, 0.33},//Pique
            {1, 10, 20, 0.50},//Franela
    };
public:
    Camisa();
    ~Camisa();


};

class Cuellos:public Prendas
{
private:
    const float Velocidad[3][4]{
            {1,10,20,0.5},//Jersey
            {1,10,20,0.33},//Pique
            {1,10,20,0.50},//Franela
    };
public:
    Cuellos();
    ~Cuellos();


};

#endif //PY01_CPRENDAS_H
