#include <iostream>
#include "docente.h"

using namespace std;

// Sube al docente al puesto inmediato siguiente, con tope en 7.
bool PROMOCION(DOCENTE DOC[], int N, char PUESTOS[][12]) {
    int COD;
    int POS;
    bool HECHO;

    HECHO = false;

    cout << "CODIGO: ";
    cin >> COD;

    POS = BUSCA_CODIGO(DOC, N, COD);

    // El código está en alguna posición de 1 a N.
    if (POS > 0) {
        cout << DOC[POS].NOMBRE << " " << PUESTOS[DOC[POS].PUESTO] << endl;

        // El puesto todavía no es Director.
        if (DOC[POS].PUESTO < 7) {
            DOC[POS].PUESTO = DOC[POS].PUESTO + 1;
            HECHO = true;
            cout << "DOCENTE PROMOVIDO A " << PUESTOS[DOC[POS].PUESTO] << endl;
        } else {
            cout << "EL DOCENTE YA TIENE EL PUESTO MAS ALTO (DIRECTOR)" << endl;
        }
    } else {
        cout << "EL CODIGO NO EXISTE" << endl;
    }

    // Regresa verdadero solo si el puesto subió.
    return HECHO;
}
