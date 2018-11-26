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


Polo::Polo(float _cantidad, float _KGprendas) : Prendas(Cantidad, Kg_Prenda){

    Cantidad = _cantidad;
    Kg_Prenda = _KGprendas;

}
Polo::~Polo() = default;


Camisa::Camisa(float _cantidad, float _KGprendas) : Prendas(Cantidad, Kg_Prenda){
    Cantidad = _cantidad;
    Kg_Prenda = _KGprendas;

}
Camisa::~Camisa() = default;

Cuellos::Cuellos(float _cantidad, float _KGprendas) : Prendas(Cantidad, Kg_Prenda){
    Cantidad = _cantidad;
    Kg_Prenda = _KGprendas;

}
Cuellos::~Cuellos() = default;

float Polo::calculo_tiempos(unsigned int x)
{
    //Polo en pedido[i][0]

    float tiempo_polo = 0;

    for(int j = 0; j < 4; j++)
        tiempo_polo += Cantidad * Kg_Prenda  / Velocidad[x][j];

    return tiempo_polo;
}


float Camisa::calculo_tiempos(unsigned int x)
{
    float tiempo_camisa = 0;


    for(int j = 0; j < 4; j++)

        tiempo_camisa += Cantidad * Kg_Prenda  / Velocidad[x][j];


    return tiempo_camisa;
}


float Cuellos::calculo_tiempos(unsigned int x)
{
    float tiempo_cuellos = 0;


    for(int j = 0; j < 4; j++)
    {
        tiempo_cuellos += Cantidad * Kg_Prenda  / Velocidad[x][j];;
    }


    return tiempo_cuellos;
}
