#include <iostream>
#include "docente.h"

using namespace std;

// Muestra el submenú de reportes hasta que se elige salir.
void REPORTES(DOCENTE DOC[], int N, char PUESTOS[][12]) {
    int OPR;

    OPR = 1;

    // Recorre el submenú mientras la opción siga entre 1 y 3.
    while (OPR >= 1 && OPR <= 3) {
        cout << "BIENVENIDO AL MENU DE REPORTES" << endl;
        cout << "1.) Reporte general de docentes" << endl;
        cout << "2.) Reporte de docentes por puesto" << endl;
        cout << "3.) Reporte de un docente" << endl;
        cout << "Otro.) Regresar al menu anterior" << endl;
        cin >> OPR;

        // cin falló: si no se limpia, OPR se queda en 1 y el reporte se repite solo.
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            OPR = 1;
            continue;
        }

        switch (OPR) {
            case 1:
                REPORTE_GENERAL(DOC, N, PUESTOS);
                break;
            case 2:
                REPORTE_POR_PUESTO(DOC, N, PUESTOS);
                break;
            case 3:
                REPORTE_DOCENTE(DOC, N, PUESTOS);
                break;
            default:
                break;
        }
    }

    // No devuelve nada: solo vuelve al menú principal.
}
