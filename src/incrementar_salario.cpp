#include <iostream>
#include "docente.h"

using namespace std;

// Muestra el docente y, si el monto es válido, cambia el salario.
bool INCREMENTAR_SALARIO(DOCENTE DOC[], int N, char PUESTOS[][12]) {
    int COD;
    int POS;
    float NSAL;
    bool HECHO;

    HECHO = false;

    cout << "CODIGO: ";
    cin >> COD;

    POS = BUSCA_CODIGO(DOC, N, COD);

    // El código está en alguna posición de 1 a N.
    if (POS > 0) {
        cout << DOC[POS].CODIGO << " " << DOC[POS].NOMBRE << " "
             << PUESTOS[DOC[POS].PUESTO] << " " << DOC[POS].SALARIO << endl;
        cout << "NSAL: ";
        cin >> NSAL;

        // El salario nuevo es mayor que cero.
        if (NSAL > 0) {
            DOC[POS].SALARIO = NSAL;
            HECHO = true;
            cout << "SALARIO ACTUALIZADO" << endl;
        } else {
            cout << "EL SALARIO DEBE SER MAYOR QUE CERO" << endl;
        }
    } else {
        cout << "EL CODIGO NO EXISTE" << endl;
    }

    // Regresa verdadero solo si el salario cambió.
    return HECHO;
}
