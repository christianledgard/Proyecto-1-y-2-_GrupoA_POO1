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

    virtual float pedido();

    virtual float getCantidad() const;
    virtual void setCantidad(float Cantidad);

    virtual float getKg_Prenda() const;
    virtual void setKg_Prenda(float Kg_Prenda);

    virtual float calculo_tiempos(float pedido[3][3]) = 0;
};

class Polo : public Prendas
{
public:
    const float  Velocidad[3][4]{
            {1, 10, 20, 0.2},//Jersey
            {1, 10, 20, 0.22},//Pique
            {1, 10, 20, 0.25}}; //Franela
public:

    Polo(float, float);
    virtual ~Polo();

    float calculo_tiempos(float pedido[3][3]) override;
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
    Camisa(float, float);
    virtual ~Camisa();

    float calculo_tiempos(float pedido[3][3]) override;
};

class Cuellos:public Prendas
{
private:
    const float Velocidad[3][4]{
            {1, 10, 20, 0.5},//Jersey
            {1, 10, 20, 0.33},//Pique
            {1, 10, 20, 0.50},//Franela
    };
public:
    Cuellos(float, float);
    virtual ~Cuellos();

    float calculo_tiempos(float pedido[3][3]) override;
};


#endif //PY01_CPRENDAS_H
