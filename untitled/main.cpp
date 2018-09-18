#include <iostream>
#include <tgmath.h>

using namespace std;

int leerbase(int &base_a_convertir){

    cout << "Ingrese la base del numero: ";

    while (true){
        cin >>base_a_convertir;
        if(base_a_convertir>=2 and base_a_convertir<=9)
            break;
        cout << endl << " --- Ingresar un numero entre el 2 y el 9 --- " << endl << endl;
        cout << "Ingrese la base del numero: ";
    }

    return base_a_convertir;
}

int leernumero(int &numero){

    cout << "Ingrese el numero a convertir: ";
    cin >>numero;

    return numero;
}

int conversion(int &base_a_convertir,int &numero){

    int digito, r1 = 10, r2 = 1, suma, r3 = 0,operacion;



    for (int i=0;i<6;r1*=10,r2*=10,r3++,i++) {

        digito = numero % r1 / r2;

        operacion = digito * int(pow(base_a_convertir,r3));


        suma += operacion;

    }

    cout << endl << "El numero en base 10 es: "<< suma << endl;

    return numero;
}


int main() {

    int base_a_convertir, numero;

    leerbase(base_a_convertir);
    leernumero(numero);
    conversion(base_a_convertir,numero);

    return 0;
}