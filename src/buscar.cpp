#include <iostream>
#include <iomanip>
#include <cstring>
#include "docente.h"

using namespace std;

// Consulta un docente por código o por nombre y lo muestra.
void BUSCAR(DOCENTE DOC[], int N, char PUESTOS[][12]) {
    int OPB;
    int COD;
    int POS;
    char NOM[51];
    char EST[11];

    POS = 0;

    cout << "BUSCAR DOCENTE" << endl;
    cout << "1.) Por codigo" << endl;
    cout << "2.) Por nombre" << endl;
    cout << "Otro.) Regresar" << endl;
    cin >> OPB;

    // OPB 1 busca por el código.
    if (OPB == 1) {
        cout << "CODIGO: ";
        cin >> COD;
        POS = BUSCA_CODIGO(DOC, N, COD);
    // OPB 2 busca por el nombre.
    } else if (OPB == 2) {
        cout << "NOM: ";
        cin.ignore();
        cin.getline(NOM, 51);
        POS = BUSCA_NOMBRE(DOC, N, NOM);
    }

    // Hay una posición válida entre 1 y N.
    if (POS > 0) {
        cout << left
             << setw(8) << "CODIGO"
             << setw(22) << "NOMBRE"
             << setw(12) << "TELEFONO"
             << setw(6) << "EDAD"
             << setw(13) << "PUESTO"
             << right << setw(10) << "SALARIO"
             << "  " << left << setw(8) << "ESTADO" << endl;
        cout << left
             << setw(8) << DOC[POS].CODIGO
             << setw(22) << DOC[POS].NOMBRE
             << setw(12) << DOC[POS].TELEFONO
             << setw(6) << DOC[POS].EDAD;
        if (DOC[POS].PUESTO >= 1 && DOC[POS].PUESTO <= 7) {
            cout << setw(13) << PUESTOS[DOC[POS].PUESTO];
        } else {
            cout << setw(13) << "INVALIDO";
        }
        if (DOC[POS].ESTADO == 1) {
            strcpy(EST, "ACTIVO");
        } else {
            strcpy(EST, "INACTIVO");
        }
        cout << right << setw(10) << fixed << setprecision(2)
             << DOC[POS].SALARIO
             << "  " << left << setw(10) << EST << endl;
    } else {
        cout << "DOCENTE NO ENCONTRADO" << endl;
    }

    // No devuelve nada: solo vuelve al menú.
}
