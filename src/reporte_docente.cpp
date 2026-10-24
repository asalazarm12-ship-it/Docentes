#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#include <sys/types.h>
#endif
#include "docente.h"

using namespace std;

// Muestra la ficha de un docente y, si se pide, la escribe en el TXT.
void REPORTE_DOCENTE(DOCENTE DOC[], int N, char PUESTOS[][12]) {
    int COD;
    int POS;
    char ARCH;
    char EST[11];
    bool ABIERTO;
    ofstream DAT;

    cout << "CODIGO: ";
    cin >> COD;

    POS = BUSCA_CODIGO(DOC, N, COD);

    // El código está en alguna posición de 1 a N.
    if (POS > 0) {
        // El docente sigue activo.
        if (DOC[POS].ESTADO == 1) {
            strcpy(EST, "ACTIVO");
        } else {
            strcpy(EST, "INACTIVO");
        }

        cout << "DATOS DEL DOCENTE " << DOC[POS].CODIGO << endl;
        cout << left
             << setw(22) << "NOMBRE"
             << setw(12) << "TELEFONO"
             << setw(6) << "EDAD"
             << setw(13) << "PUESTO"
             << right << setw(10) << "SALARIO"
             << "  " << left << setw(10) << "ESTADO" << endl;
        cout << left
             << setw(22) << DOC[POS].NOMBRE
             << setw(12) << DOC[POS].TELEFONO
             << setw(6) << DOC[POS].EDAD;
        if (DOC[POS].PUESTO >= 1 && DOC[POS].PUESTO <= 7) {
            cout << setw(13) << PUESTOS[DOC[POS].PUESTO];
        } else {
            cout << setw(13) << "INVALIDO";
        }
        cout << right << setw(10) << fixed << setprecision(2)
             << DOC[POS].SALARIO
             << "  " << left << setw(10) << EST << endl;

        cout << "DESEA GENERAR EL ARCHIVO DE TEXTO? (S/N): ";
        cin >> ARCH;

        // El usuario pidió el archivo de texto.
        if (ARCH == 'S') {
            // Crea report si falta, para poder escribir el TXT.
#ifdef _WIN32
            if (_mkdir("report") != 0) {
                ABIERTO = false;
            }
#else
            if (mkdir("report", 0755) != 0) {
                ABIERTO = false;
            }
#endif
            DAT.open("report/REPORTE_DOCENTE.TXT");
            ABIERTO = DAT.is_open();

            // El TXT se pudo crear.
            if (ABIERTO == true) {
                DAT << left
                    << setw(8) << DOC[POS].CODIGO
                    << setw(22) << DOC[POS].NOMBRE
                    << setw(12) << DOC[POS].TELEFONO
                    << setw(6) << DOC[POS].EDAD;
                if (DOC[POS].PUESTO >= 1 && DOC[POS].PUESTO <= 7) {
                    DAT << setw(13) << PUESTOS[DOC[POS].PUESTO];
                } else {
                    DAT << setw(13) << "INVALIDO";
                }
                DAT << right << setw(10) << fixed << setprecision(2)
                    << DOC[POS].SALARIO
                    << "  " << left << EST << endl;
                DAT.close();
            } else {
                cout << "NO SE PUDO CREAR EL ARCHIVO DE TEXTO" << endl;
            }
        }
    } else {
        cout << "EL DOCENTE NO EXISTE" << endl;
    }

    // No devuelve nada: solo vuelve al menú de reportes.
}
