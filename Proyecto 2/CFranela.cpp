//
// Created by Carlos Reátegui on 11/10/18.
//

#include "CFranela.h"

CFranela::CFranela(unsigned int _cantidad, float _kgPrenda)
{
    cantidad = _cantidad;
    kgPrenda = _kgPrenda;
}

CFranela::~CFranela() = default;

void CFranela::setCantidad(unsigned int _cantidad)
{
    cantidad = _cantidad;
}

void CFranela::setKgPrenda(float _kgPrenda)
{
    kgPrenda = _kgPrenda;
}


unsigned int CFranela::getCantidad()
{
    return cantidad;
}

float CFranela::getKgPrenda()
{
    return kgPrenda;
}