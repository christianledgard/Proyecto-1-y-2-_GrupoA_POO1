#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <string>

#include "CPrendas.h"

using namespace std;

string tipo_prenda[3] = {"Polo", "Camisa", "Cuellos"};
string tipo_pedido[3] = {"Jersy", "Pique", "Franela"};

void inicializar(float pedido[3][3], float Kg_PRENDAS[3])
{

    Prendas *array[9];
    int contador = 0;

    cout << "---- Ingrese su pedido a continuación: ----" << endl;
    cout << "\n";

    for (int i = 0; i < 3; i++) {

        cout << "Ingrese el pedido para " << tipo_pedido[i] << ":" << endl;
        cout << "\n";

        for(int j = 0; j < 3; j++)
        {
            cout << tipo_prenda[j] << ":" << endl;
            switch(j)
            {
                case 0:
                    array[contador] = new Polo();
                    Kg_PRENDAS[j] += array[contador]->getKg_Prenda();
                    pedido[i][j] = array[contador]->getCantidad() * array[contador]->getKg_Prenda();
                    break;
                case 1:
                    array[contador] = new Camisa();
                    Kg_PRENDAS[j] += array[contador]->getKg_Prenda();
                    pedido[i][j] = array[contador]->getCantidad() * array[contador]->getKg_Prenda();
                    break;
                case 2:
                    array[contador] = new Cuellos();
                    Kg_PRENDAS[j] += array[contador]->getKg_Prenda();
                    pedido[i][j] = array[contador]->getCantidad() * array[contador]->getKg_Prenda();
                    break;
            }
            contador += 1;
        }

    }
}


void calculo_tiempos(float pedido[3][3], string tipo_pedido[3]){

    float tiempo_total = 0,temporal1, suma = 0;
    float tiempos_pedido[3];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            tiempos_pedido[i] = pedido[i][j] /
        }
    }

    cout << "El tiempo de espera total es : " << tiempo_total << " horas." << endl;
    cout << "\n";

}


void calculo_materia_prima(float Kg_PRENDAS[3])
{
    float hilo_jersey;
    float hilo_pique;
    float hilo_franela;

    hilo_jersey = Kg_PRENDAS[0] / 0.7;
    hilo_pique = Kg_PRENDAS[1] / 0.5;
    hilo_franela = Kg_PRENDAS[2] / 0.3;

    cout<<"Seran necesarios "<<hilo_jersey<<" Kg de hilo de Jersey."<<endl;
    cout<<"Seran necesarios "<<hilo_pique<<" Kg de hilo de Pique."<<endl;
    cout<<"Seran necesarios "<<hilo_franela<<" Kg de hilo de Franela."<<endl;
}

int main() {


    float Kg_PRENDAS[3]={0,0,0};
    float pedido[3][3];

    inicializar(pedido, Kg_PRENDAS);
    calculo_materia_prima(Kg_PRENDAS);

    return 0;
}
