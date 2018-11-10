//
// Created by Carlos Reátegui on 11/10/18.
//

#include "CPique.h"

CPique::CPique(unsigned int _cantidad, float _kgPrenda)
{
    cantidad = _cantidad;
    kgPrenda = _kgPrenda;
}


void CPique::setCantidad(unsigned int _cantidad)
{
    cantidad = _cantidad;
}

void CPique::setKgPrenda(float _kgPrenda)
{
    kgPrenda = _kgPrenda;
}


unsigned int CPique::getCantidad()
{
    return cantidad;
}

float CPique::getKgPrenda()
{
    return kgPrenda;
}