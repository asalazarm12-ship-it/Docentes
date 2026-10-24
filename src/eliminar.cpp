#include <iostream>
#include "docente.h"

using namespace std;

// Da de baja lógica: pone ESTADO en 0 si el usuario confirma.
bool ELIMINAR(DOCENTE DOC[], int N) {
    int COD;
    int POS;
    char CONF;
    bool HECHO;

    HECHO = false;

    cout << "CODIGO: ";
    cin >> COD;

    POS = BUSCA_CODIGO(DOC, N, COD);

    // El código está en alguna posición de 1 a N.
    if (POS > 0) {
        cout << DOC[POS].CODIGO << " " << DOC[POS].NOMBRE << " ";
        if (DOC[POS].ESTADO == 1) {
            cout << "ACTIVO" << endl;
        } else {
            cout << "INACTIVO" << endl;
        }
        cout << "CONFIRMA LA ELIMINACION? (S/N): ";
        cin >> CONF;

        // El usuario confirmó con S. ESTADO 0 es baja; no se pide al usuario.
        if (CONF == 'S') {
            DOC[POS].ESTADO = 0;
            HECHO = true;
            cout << "DOCENTE MARCADO COMO INACTIVO" << endl;
        } else {
            cout << "NO SE REALIZO NINGUN CAMBIO" << endl;
        }
    } else {
        cout << "EL CODIGO NO EXISTE" << endl;
    }

    // Regresa verdadero solo si el docente quedó con ESTADO 0.
    return HECHO;
}
