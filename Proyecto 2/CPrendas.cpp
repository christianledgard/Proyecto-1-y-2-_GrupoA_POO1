//
// Created by Christian Ledgard on 11/23/18.
//

#include "CPrendas.h"


Prendas::Prendas(float Cantidad, float Kg_Prenda):Cantidad(Cantidad),Kg_Prenda(Kg_Prenda){}
Prendas::~Prendas(){};


Polo::Polo() : Prendas(Cantidad, Kg_Prenda){

    cout<< "Ingrese la cantidad: "; cin >> Cantidad;
    cout<< "Ingrese la KG PRENDa: "; cin >> Kg_Prenda;



}
Polo::~Polo() = default;

/*
Camisa::Camisa(float _cantidad, float _kg_prenda) : Prendas(_cantidad, _kg_prenda){}
Camisa::~Camisa() = default;


Cuellos::Cuellos(float _cantidad, float _kg_prenda) : Prendas(_cantidad, _kg_prenda){}
Cuellos::~Cuellos() = default;
*/
