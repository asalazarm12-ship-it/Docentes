#include <iostream>
#include "docente.h"

using namespace std;

// Cambia NOMBRE, TELEFONO y EDAD. El CODIGO no se toca.
bool MODIFICAR(DOCENTE DOC[], int N) {
    int COD;
    int POS;
    bool HECHO;

    HECHO = false;

    cout << "CODIGO: ";
    cin >> COD;
    cin.ignore();

    POS = BUSCA_CODIGO(DOC, N, COD);

    // El código está en alguna posición de 1 a N.
    if (POS > 0) {
        cout << DOC[POS].NOMBRE << " " << DOC[POS].TELEFONO << " "
             << DOC[POS].EDAD << endl;
        cout << "NOMBRE: ";
        cin.getline(DOC[POS].NOMBRE, 51);
        cout << "TELEFONO: ";
        cin.getline(DOC[POS].TELEFONO, 11);
        cout << "EDAD: ";
        cin >> DOC[POS].EDAD;

        HECHO = true;
        cout << "DATOS MODIFICADOS" << endl;
    } else {
        cout << "EL CODIGO NO EXISTE" << endl;
    }

    // Regresa verdadero solo si se cambiaron los datos.
    return HECHO;
}
