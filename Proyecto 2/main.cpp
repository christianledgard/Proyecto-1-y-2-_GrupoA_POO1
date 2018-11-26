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

void calculo_materia_prima(const float Kg_PRENDAS[3], float Kg_Hilos[3], float ANALISIS_MateriaPrima[3])
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
    Kg_Hilos[0]=hilo_jersey;

    hilo_pique = Kg_PRENDAS[1] / ingreso[1];
    Kg_Hilos[1]=hilo_pique;

    hilo_franela = Kg_PRENDAS[2] / ingreso[2];
    Kg_Hilos[2]=hilo_franela;

    cout<<"Seran necesarios "<<hilo_jersey<<" Kg de hilo de Jersey."<<endl;
    cout<<"Seran necesarios "<<hilo_pique<<" Kg de hilo de Pique."<<endl;
    cout<<"Seran necesarios "<<hilo_franela<<" Kg de hilo de Franela."<<endl;
    cout<<"\n";

    ANALISIS_MateriaPrima[0]=hilo_jersey;
    ANALISIS_MateriaPrima[1]=hilo_pique;
    ANALISIS_MateriaPrima[2]=hilo_franela;

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

void calculo_tiempos(float pedido[3][3], string tipo_pedido[3],Prendas *array[9],float ANALISIS_Tiempo[3]){
    int contador=0;
    float tiempo_total = 0,temporal1, suma = 0;
    float tiempos_pedido[3];

    for (int k = 0; k < 3; ++k) {
        for (unsigned int i = 0; i < 3; ++i) {
            suma +=  array[contador]->calculo_tiempos(i);
            contador++;
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




    for (int l = 0; l < 3; ++l) {
        dia = int((tiempos_pedido[l]/24));
        if(tiempos_pedido[l]/24!=dia)
            dia++;
        cout << "Si solo el producto " << tipo_pedido[l] << " cominza a fabricarse, podra recogerse el " << dia_a_fecha(dia) << ", en " << dia << " dias." <<  endl;
        ANALISIS_Tiempo[l] = dia;

    }




}

void calculo_costos(float pedido[3][3], float Kg_PRENDAS[3], float Kg_Hilos[3], float ANALISIS_Ganancias[3]){

    float ingreso[10];
    int contador = 0;

    string line;
    ifstream archivo ("/Users/christianledgard/Documents/GitHub/Proyecto1_GrupoA_POO1/Proyecto 2/inicio_costos.txt");
    if (archivo.is_open())
    {
        for (int j = 0; j < 10; ++j) {
            getline (archivo,line);
            ingreso[j]= stof(line);
        }
        archivo.close();
    }
    else cout << "--- Error al abrir el archivo ---";

    //Precios de Venta - Costos de Produccion
    float Costo_Hilos=ingreso[0];

    //Orden de Precio de venta: Polos, camisas y cuellos
    float Costos_Jersey[3] = {ingreso[1], ingreso[2], ingreso[3]};
    float Costos_Pique[3] = {ingreso[4], ingreso[5], ingreso[6]};
    float Costos_Franela[3] = {ingreso[7], ingreso[8], ingreso[9]};


    float Costo_Total=0, Ingreso_Total=0;
    float Ingreso_Jersey=0, Ingreso_Pique=0, Ingreso_Franela=0;
    float Costo_Jersey =0, Costo_Pique =0, Costo_Franela =0;


    for (int k = 0; k < 3; ++k) {
        Costo_Total+=Kg_Hilos[k]*Costo_Hilos;
    }

    Costo_Jersey=Kg_Hilos[1]*Costo_Hilos;
    Costo_Pique=Kg_Hilos[2]*Costo_Hilos;
    Costo_Franela=Kg_Hilos[3]*Costo_Hilos;



    for (int i = 0; i < 3 ; ++i) {
        for (int j = 0; j < 3 ; ++j) {
            if (i == 0) {
                Ingreso_Jersey += (pedido[i][j]*Costos_Jersey[i]);
            }
            else if (i == 1) {
                Ingreso_Pique += (pedido[i][j]*Costos_Pique[i]);
            }
            else if (i == 2) {
                Ingreso_Franela += (pedido[i][j]*Costos_Franela[i]);
            }
        }
    }



    Ingreso_Total=(Ingreso_Franela+Ingreso_Jersey+Ingreso_Pique);
    cout<< "\n";
    cout<< "--------------------------------------------------------";
    cout<< "\n";
    cout<<"El ingreso por la venta de las prendas de Jersey es: S/ "<<Ingreso_Jersey<<endl;
    cout<<"El ingreso por la venta de las prendas de Pique es: S/ "<<Ingreso_Pique<<endl;
    cout<<"El ingreso por la venta de las prendas de Franela es: S/ "<<Ingreso_Franela<<endl;
    cout<< endl;
    cout<< endl;
    cout<<"El ingreso TOTAL es: S/ "<<Ingreso_Total<<endl;
    cout<<"El costo TOTAL es: S/ "<<Costo_Total<<endl;

    cout<< "\n";
    cout<< "--------------------------------------------------------";
    cout<< "\n";

    cout<< endl;
    cout<< "Ganancias por productos: "<< endl;
    cout<< "La ganancia de las prendas de Jersey es: S/ "<<Ingreso_Jersey-Costo_Jersey<<endl;
    cout<< "La ganancia de las prendas de Pique es: S/ "<<Ingreso_Pique-Costo_Pique<<endl;
    cout<< "La ganancia de las prendas de Franela es: S/ "<<Ingreso_Franela-Costo_Franela<<endl;

    ANALISIS_Ganancias[0] = Ingreso_Jersey-Costo_Jersey;
    ANALISIS_Ganancias[1] = Ingreso_Pique-Costo_Pique;
    ANALISIS_Ganancias[2] = Ingreso_Franela-Costo_Franela;

    cout<<"Ganancia TOTAL: s/."<<Ingreso_Total-Costo_Total<<endl;

    cout<< "\n";
    cout<< "-------------------------------------------------------------------------"<< endl;
    cout<< "-------------------------- FIN DEL INFORME ------------------------------"<< endl;
    cout<< "-------------------------------------------------------------------------"<< endl;
    cout<< "\n";

    //        Polos      Camisas      Cuellos
    //Jersey   0,0        0,1            0,2
    //Pique    1,0        1,1            1,2
    //Franela  2,0        2,1            2,2
}

void ANALISIS_print_consola(string TipoPedido[3],float Tiempo[3], float MateriaPrima[3], float Ganancias[3]){

    cout << "//////////////////////////////////////////////////////////////////////" << endl;
    cout << "\n";
    cout << "-------- Inicio del Analisis ----------" << endl;
    cout << "\n";

    cout << "La fabrica se va a demorar:" << endl;
    cout << "\n";

    cout <<  "Tipo Pedido" << setw(15)<< "Tiempo" << setw(20) << "Ganancia" << setw(25) << "Ganancia/Tiempo" << setw(25)<< "Materia Prima"<< endl;

    for (int i = 0; i < 3; ++i) {

        cout <<  TipoPedido[i] << setw(15)<< fixed << setprecision(0) << Tiempo[i]<< " dias"<< setw(15) << "S/"<< fixed << setprecision(2) << Ganancias[i] << setw(20) << fixed << setprecision(2) << Ganancias[i]/Tiempo[i] << setw(25) << fixed << setprecision(2) << MateriaPrima[i]<< "Kg"<< endl;

    }

    //CALCULO DE EFECTIVIDAD: GANANCIA ENTRE TIEMPO

    cout << "\n";
    cout << "\n";


    float Eficiencia[3], OrdenRecomendado[3];
    for (int j = 0; j < 3; ++j) {
        Eficiencia[j] = Ganancias[j]/Tiempo[j];
    }

    float MAX = 0.0, MIN = INT8_MAX;

    for(int k = 0; k < 3; ++k) {
        if(Eficiencia[k]>MAX){
            MAX=Eficiencia[k];
            OrdenRecomendado[0]=k;
        }
    }

    for(int k = 0; k < 3; ++k) {
        if(Eficiencia[k]<MIN){
            MIN=Eficiencia[k];
            OrdenRecomendado[2]=k;
        }
    }

    for (int l = 0; l < 3; ++l) {
        if(Eficiencia[l]!=MAX and Eficiencia[l]!=MIN)
            OrdenRecomendado[1]=l;
    }

    cout << "El software recomienda priorizar las prendas por este orden: "<< endl;


    for (int m = 0; m < 3; ++m) {

        cout << m+1 << ". " << TipoPedido[int(OrdenRecomendado[m])]<< endl;

    }

    cout << "\n";
    cout << "-------- Cronograma de Produccion ----------" << endl;
    cout << "\n";

    int tiempo_a_cuenta=0, dia_transcurrido=0;


    for (int n = 0; n < 3; ++n) {

        cout << n+1 << ". "<< TipoPedido[int(OrdenRecomendado[n])] << " --- del "<< dia_a_fecha(tiempo_a_cuenta+dia_transcurrido) << " al " << dia_a_fecha((Tiempo[int(OrdenRecomendado[n])])+tiempo_a_cuenta+dia_transcurrido) << endl;
        tiempo_a_cuenta += Tiempo[int(OrdenRecomendado[n])];
        dia_transcurrido++;
    }

}

void ANALISIS_print_txt(string TipoPedido[3],float Tiempo[3], float MateriaPrima[3], float Ganancias[3]){

    ofstream myfile;
    myfile.open ("/Users/christianledgard/Documents/GitHub/Proyecto1_GrupoA_POO1/Proyecto 2/pedido.txt");

    myfile << "\n";
    myfile << "-------- Inicio del Analisis ----------" << endl;
    myfile << "\n";

    myfile << "La fabrica se va a demorar:" << endl;
    myfile << "\n";

    myfile <<  "Tipo Pedido" << setw(15)<< "Tiempo" << setw(20) << "Ganancia" << setw(25) << "Ganancia/Tiempo" << setw(25)<< "Materia Prima"<< endl;

    for (int i = 0; i < 3; ++i) {

        myfile <<  TipoPedido[i] << setw(15)<< fixed << setprecision(0) << Tiempo[i]<< " dias"<< setw(15) << "S/"<< fixed << setprecision(2) << Ganancias[i] << setw(20) << fixed << setprecision(2) << Ganancias[i]/Tiempo[i] << setw(25) << fixed << setprecision(2) << MateriaPrima[i]<< "Kg"<< endl;

    }

    //CALCULO DE EFECTIVIDAD: GANANCIA ENTRE TIEMPO

    myfile << "\n";
    myfile << "\n";


    float Eficiencia[3], OrdenRecomendado[3];
    for (int j = 0; j < 3; ++j) {
        Eficiencia[j] = Ganancias[j]/Tiempo[j];
    }

    float MAX = 0.0, MIN = INT8_MAX;

    for(int k = 0; k < 3; ++k) {
        if(Eficiencia[k]>MAX){
            MAX=Eficiencia[k];
            OrdenRecomendado[0]=k;
        }
    }

    for(int k = 0; k < 3; ++k) {
        if(Eficiencia[k]<MIN){
            MIN=Eficiencia[k];
            OrdenRecomendado[2]=k;
        }
    }

    for (int l = 0; l < 3; ++l) {
        if(Eficiencia[l]!=MAX and Eficiencia[l]!=MIN)
            OrdenRecomendado[1]=l;
    }

    myfile << "El software recomienda priorizar las prendas por este orden: "<< endl;


    for (int m = 0; m < 3; ++m) {

        myfile << m+1 << ". " << TipoPedido[int(OrdenRecomendado[m])]<< endl;

    }

    myfile << "\n";
    myfile << "-------- Cronograma de Produccion ----------" << endl;
    myfile << "\n";

    int tiempo_a_cuenta=0, dia_transcurrido=0;


    for (int n = 0; n < 3; ++n) {

        myfile << n+1 << ". "<< TipoPedido[int(OrdenRecomendado[n])] << " --- del "<< dia_a_fecha(tiempo_a_cuenta+dia_transcurrido) << " al " << dia_a_fecha((Tiempo[int(OrdenRecomendado[n])])+tiempo_a_cuenta+dia_transcurrido) << endl;
        tiempo_a_cuenta += Tiempo[int(OrdenRecomendado[n])];
        dia_transcurrido++;
    }
    myfile.close();

}


int main() {

    Prendas *array[9];
    float Kg_Hilos[3];
    float Kg_PRENDAS[3]={0,0,0};
    float pedido[3][3];
    float tiempo_total = 0;

    float ANALISIS_Tiempo[3];
    float ANALISIS_MateriaPrima[3];
    float ANALISIS_Ganancias[3];

    inicializar_desde_txt(pedido, Kg_PRENDAS, array);
    visualizar_pedido(pedido, tipo_prenda, tipo_pedido);
    calculo_materia_prima(Kg_PRENDAS,Kg_Hilos,ANALISIS_MateriaPrima);
    calculo_tiempos(pedido, tipo_pedido,array, ANALISIS_Tiempo);

    calculo_costos(pedido,Kg_PRENDAS, Kg_Hilos, ANALISIS_Ganancias);

    ANALISIS_print_consola(tipo_pedido, ANALISIS_Tiempo,ANALISIS_MateriaPrima,ANALISIS_Ganancias);
    ANALISIS_print_txt(tipo_pedido, ANALISIS_Tiempo,ANALISIS_MateriaPrima,ANALISIS_Ganancias);



    return 0;
}
