//
// Created by Christian Ledgard on 11/23/18.
//

#include "CPrendas.h"


Prendas::Prendas(float Cantidad, float Kg_Prenda):Cantidad(Cantidad),Kg_Prenda(Kg_Prenda){}
Prendas::~Prendas(){}

float Prendas::pedido() {
    return Cantidad*Kg_Prenda;
}

float Prendas::getCantidad() const {
    return Cantidad;
}

void Prendas::setCantidad(float Cantidad) {
    Prendas::Cantidad = Cantidad;
}

float Prendas::getKg_Prenda() const {
    return Kg_Prenda;
}

void Prendas::setKg_Prenda(float Kg_Prenda) {
    Prendas::Kg_Prenda = Kg_Prenda;
};


Polo::Polo() : Prendas(Cantidad, Kg_Prenda){

    cout<< "Ingrese la Cantidad: "; cin >> Cantidad;
    cout<< "Ingrese la KG Prenda: "; cin >> Kg_Prenda;
    cout << endl;

}
Polo::~Polo() = default; 


Camisa::Camisa() : Prendas(Cantidad, Kg_Prenda){
    cout<< "Ingrese la Cantidad: "; cin >> Cantidad;
    cout<< "Ingrese la KG Prenda: "; cin >> Kg_Prenda;
    cout << endl;
}
Camisa::~Camisa() = default;

Cuellos::Cuellos() : Prendas(Cantidad, Kg_Prenda){

    cout<< "Ingrese la Cantidad: "; cin >> Cantidad;
    cout<< "Ingrese la KG Prenda: "; cin >> Kg_Prenda;
    cout << endl;

}
Cuellos::~Cuellos() = default;
