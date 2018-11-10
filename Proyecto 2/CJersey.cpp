//
// Created by Christian Ledgard on 11/10/18.
//

#include "CJersey.h"

CJersey::CJersey(unsigned int _cantidad, float _kgPrenda) {

    setCantidad(_cantidad);
    setKgPrenda(_kgPrenda);

}


void CJersey::setCantidad(unsigned int _cantidad) {cantidad = _cantidad;}
void CJersey::setKgPrenda(float _kgPrenda) {kgPrenda = _kgPrenda;}

unsigned int CJersey::getCantidad() { return cantidad;}
float CJersey::getKgPrenda() { return kgPrenda;}