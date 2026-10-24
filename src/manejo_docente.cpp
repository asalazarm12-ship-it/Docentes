#include <iostream>
#include "docente.h"

using namespace std;

// Abre el submenú de promoción o de incremento de salario.
bool MANEJO_DOCENTE(DOCENTE DOC[], int N, char PUESTOS[][12]) {
    int OPM;
    bool HECHO;

    HECHO = false;

    cout << "MANEJO DE DOCENTE" << endl;
    cout << "1.) Promocion" << endl;
    cout << "2.) Incrementar salario" << endl;
    cout << "Otro.) Regresar" << endl;
    cin >> OPM;

    // OPM 1 sube el puesto.
    if (OPM == 1) {
        HECHO = PROMOCION(DOC, N, PUESTOS);
    // OPM 2 cambia el salario.
    } else if (OPM == 2) {
        HECHO = INCREMENTAR_SALARIO(DOC, N, PUESTOS);
    }

    // Regresa el resultado del submódulo, o falso si no se eligió ninguno.
    return HECHO;
}
