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

float Polo::calculo_tiempos(float pedido[3][3])
{
    //Polo en pedido[i][0]

    float tiempo_polo = 0;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
            tiempo_polo += pedido[i][0] / Velocidad[i][j];
    }

    return tiempo_polo;
}


float Camisa::calculo_tiempos(float pedido[3][3])
{
    float tiempo_camisa = 0;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)

            tiempo_camisa += pedido[i][1] / Velocidad[i][j];
    }

    return tiempo_camisa;
}


float Cuellos::calculo_tiempos(float pedido[3][3])
{
    float tiempo_cuellos = 0;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            tiempo_cuellos += pedido[i][2] / Velocidad[i][j];
        }
    }

    return tiempo_cuellos;
}
