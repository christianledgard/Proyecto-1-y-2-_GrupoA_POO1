#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;



void ingresar_pedidos(float pedido[3][3],string tipo_prenda[3],string tipo_pedido[3]){

    cout << "---- Ingrese su pedido a continuación: ----" << endl;

    int cantidad; float kg_prenda;

    for (int i = 0; i < 3 ; ++i) {

    cout << "Ingrese el pedido para " << tipo_pedido[i] << ":" << endl;
    cout << "\n";


        for (int j = 0; j < 3; ++j) {

            cout << tipo_prenda[j] << ":" << endl;
            cout << "\n";
            cout << "Cantidad (unidades)==> ";
            cin >> cantidad;
            cout << "Kg/Prenda==> ";
            cin >> kg_prenda;
            cout << "\n";

            pedido[i][j] = cantidad * kg_prenda;

        }
    }


    }

void visualizar_pedido(float pedido[3][3],string tipo_prenda[3],string tipo_pedido[3]){

    for (int i = 0; i < 3; ++i) {

        cout << "--- " << tipo_pedido[i] << " ---" << endl;

        for (int j = 0; j < 3; ++j) {

            cout << tipo_prenda[j] << ": ";
            cout << setw(5) <<"[" << pedido[i][j] << "]" << endl;

        }

        cout << "\n";
    }


}


void calculo_tiempos(float pedido[3][3], float velocidad[3][3][4],string tipo_pedido[3]){

    float tiempo_total = 0,temporal1, suma = 0;
    float tiempos_pedido[3];



    for (int k = 0; k < 3; ++k) {
        for (int j = 0; j < 3; ++j) {
            for (int i = 0; i < 4; i++) {

                temporal1 = velocidad[k][j][i] * pedido[k][j];
                suma += temporal1;

            }
        }

        tiempos_pedido[k] = suma;
        tiempo_total += suma;
        suma = 0;

        cout << "El tiempo de espera de la tela " << tipo_pedido[k] << ": " << tiempos_pedido[k] << " horas." << endl;
    }

    cout << "El tiempo de espera total es : " << tiempo_total << " horas." << endl;
    cout << "\n";

    // Calculo de la fecha de ENTREGA

    int dia,mes, anno, hoy_dia, hoy_mes, hoy_anno, dias_mes;

    time_t t = time(0); // TIEMPO ACTUAL
    tm* now = localtime(&t);


    for (int l = 0; l < 3; ++l) {
        dia = int((tiempos_pedido[l]/24));
        if(tiempos_pedido[l]/24!=dia)
            dia++;
        cout << "Recoger el pedido de " << tipo_pedido[l] << " en " << dia << " dias.";


    }






}

int main() {

    float pedido[3][3];

    string tipo_prenda[3] = {"Polo", "Camisa", "Cuellos"};
    string tipo_pedido[3] = {"Jersy", "Pique", "Franela"};

    float velocidad[3][3][4] = {

            {       //Jersy
                    {1,10,20,0.2},//Polos
                    {1,10,20,0.5},//Camisas
                    {1,10,20,0.05}//Cuellos

            },

            {       //Pique
                    {1,10,20,0.22},//Polos
                    {1,10,20,0.33},//Camisas
                    {1,10,20,0.04}//Cuellos

            },

            {       //Franela
                    {1,10,20,0.25},//Polos
                    {1,10,20,0.50},//Camisas
                    {1,10,20,0.05}//Cuellos

            }
    };


    ingresar_pedidos(pedido, tipo_prenda, tipo_pedido);
    visualizar_pedido(pedido, tipo_prenda, tipo_pedido);

    calculo_tiempos(pedido,velocidad, tipo_pedido);



    return 0;
}