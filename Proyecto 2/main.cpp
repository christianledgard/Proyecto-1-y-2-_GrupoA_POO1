#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>

#include "CPrendas.h"

using namespace std;

string tipo_prenda[3] = {"Polo", "Camisa", "Cuellos"};
string tipo_pedido[3] = {"Jersy", "Pique", "Franela"};


void inicializar_desde_txt(float pedido[3][3], float Kg_PRENDAS[3], Prendas *array[9])
{

    float ingreso[3][6];
    int contador = 0;

    string line;
    ifstream archivo ("/Users/christianledgard/Documents/GitHub/Proyecto1_GrupoA_POO1/Proyecto 2/inicio_pedido.txt");
    if (archivo.is_open())
    {
        for (int j = 0; j < 3; ++j) {
            for (int i = 0; i < 6; ++i) {
                getline (archivo,line);
                ingreso[j][i]= stof(line);
            }
        }

        archivo.close();
    }
    else cout << "--- Error al abrir el archivo ---";


    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++)
        {
            switch(j)
            {
                case 0:
                    array[contador] = new Polo(ingreso[i][j],ingreso[i][j+1]);
                    Kg_PRENDAS[j] += array[contador]->getKg_Prenda();
                    pedido[i][j] = array[contador]->getCantidad() * array[contador]->getKg_Prenda();
                    break;
                case 1:
                    array[contador] = new Camisa(ingreso[i][j+1],ingreso[i][j+2]);
                    Kg_PRENDAS[j] += array[contador]->getKg_Prenda();
                    pedido[i][j] = array[contador]->getCantidad() * array[contador]->getKg_Prenda();
                    break;
                case 2:
                    array[contador] = new Cuellos(ingreso[i][j+2],ingreso[i][j+3]);
                    Kg_PRENDAS[j] += array[contador]->getKg_Prenda();
                    pedido[i][j] = array[contador]->getCantidad() * array[contador]->getKg_Prenda();
                    break;
            }
            contador += 1;
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

void calculo_materia_prima(const float Kg_PRENDAS[3])
{
    double hilo_jersey;
    double hilo_pique;
    double hilo_franela;

    float ingreso[3];
    int contador = 0;

    string line;
    ifstream archivo ("/Users/christianledgard/Documents/GitHub/Proyecto1_GrupoA_POO1/Proyecto 2/inicio_precio.txt");
    if (archivo.is_open())
    {
        for (int j = 0; j < 3; ++j) {
            getline (archivo,line);
            ingreso[j]= stof(line);
        }
        archivo.close();
    }
    else cout << "--- Error al abrir el archivo ---";

    hilo_jersey = Kg_PRENDAS[0] / ingreso[0];
    hilo_pique = Kg_PRENDAS[1] / ingreso[1];
    hilo_franela = Kg_PRENDAS[2] / ingreso[2];

    cout<<"Seran necesarios "<<hilo_jersey<<" Kg de hilo de Jersey."<<endl;
    cout<<"Seran necesarios "<<hilo_pique<<" Kg de hilo de Pique."<<endl;
    cout<<"Seran necesarios "<<hilo_franela<<" Kg de hilo de Franela."<<endl;
}


int dias_en_mes(int mes, int anno){

    int dias_x_mes;

    switch (mes)
    {
        case 4:
        case 6:
        case 9:
        case 11:
            dias_x_mes = 30;
            break;

        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dias_x_mes = 31;
            break;

        case 2:{
            if(anno%4==0 and anno%100!=0 or anno%400==0)
                dias_x_mes = 29;
            else
                dias_x_mes = 28;
            break;
        }

    }

    return dias_x_mes;
}

string dia_a_fecha(int dias_a_sumar) {

    //FECHA ACTUAL

    time_t t = time(0);   // get time now
    tm* now = localtime(&t);

    int anno_actual, mes_actual, dia_actual;
    int dias_x_mes, dia, mes, anno;

    anno_actual = (now->tm_year + 1900);
    mes_actual = (now->tm_mon + 1);
    dia_actual = (now->tm_mday);

    dia = dia_actual;
    mes = mes_actual;
    anno = anno_actual;


    for (int i=0;i<dias_a_sumar;i++)
    {
        dia++;
        if (dia > dias_en_mes(mes,anno))
        {
            dia = 1;
            mes++;
            if (mes==13)
            {
                mes = 1;
                anno++;
            }
        }
    }

    string resultado;

    string s_dia = to_string(dia);
    string s_mes = to_string(mes);
    string s_anno = to_string(anno);


    resultado = s_dia + '-' + s_mes + '-' + s_anno;


    return resultado;
}

void calculo_tiempos(float pedido[3][3], string tipo_pedido[3],Prendas *array[9]){

    float tiempo_total = 0,temporal1, suma = 0;
    float tiempos_pedido[3];

    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < 3; ++i) {
            temporal1 = array[i]->calculo_tiempos(pedido);
            suma += temporal1;
        }
        tiempos_pedido[k] = suma;
        tiempo_total += suma;
        suma = 0;

        cout << "El tiempo de espera de la tela " << tipo_pedido[k] << ": " << tiempos_pedido[k] << " horas." << endl;
    }

    cout << "El tiempo de espera total es : " << tiempo_total << " horas." << endl;
    cout << "\n";

    // Calculo de la fecha de ENTREGA

    int dia;


    /*

    for (int l = 0; l < 3; ++l) {
        dia = int((tiempos_pedido[l]/24));
        if(tiempos_pedido[l]/24!=dia)
            dia++;
        cout << "Si solo el producto " << tipo_pedido[l] << " cominza a fabricarse, podra recogerse el " << dia_a_fecha(dia) << ", en " << dia << " dias." <<  endl;
        ANALISIS_Tiempo[l] = dia;

    }
     */



}


int main() {

    Prendas *array[9];
    float Kg_PRENDAS[3]={0,0,0};
    float pedido[3][3];
    float tiempo_total = 0;

    inicializar_desde_txt(pedido, Kg_PRENDAS, array);
    visualizar_pedido(pedido, tipo_prenda, tipo_pedido);
    calculo_materia_prima(Kg_PRENDAS);

    for(int i = 0; i < 3; i++)
    {
        tiempo_total += array[i]->calculo_tiempos(pedido);
    }

    cout << tiempo_total;

    calculo_tiempos(pedido, tipo_pedido,array);

    return 0;
}
